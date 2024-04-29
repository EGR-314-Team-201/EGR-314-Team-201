
// Adapted from (https://github.com/redkite-electronics/Bosch-BME280-C-Library-for-Microchip-16bit-Processors/tree/master)

/*
Bosch BME280 humidity, temperature & pressure sensor
Based on the adafruit BME280 breakout board driver
----> http://www.adafruit.com/products/2650
This driver supports IC2 mode only, as is based on the adafruit BME280 Driver

Adafruit invests time and resources providing this open source code,
please support Adafruit andopen-source hardware by purchasing products
from Adafruit!
Written by Limor Fried & Kevin Townsend for Adafruit Industries.
BSD license, all text above must be included in any redistribution

------------------------------------------------------------------------------

Modified for Microchip PIC24 Processors by Ian Stewart Feburay 2017

I. Stewart Version 1 26/02/2017

Temperture Reading and Compension Working as of 05/02/2017
Pressure Reading and Compension Working as of 05/02/2017
Humidity Reading and Compension Working as of 26/02/2017

 */
#include "mcc_generated_files/mcc.h"
#include <xc.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "BME280.h"


int32_t t_fine;

int BME280_id_Check() { //check if sensor is present, returns 0 if not
    unsigned char BME280_id;
    BME280_id = i2c_read1ByteRegister(BME280_ADDRESS, BME280_CHIP_ID_REG); //read BME280 ID byte, should be 0x60
    //put_serial_st("\r\rBME280 id: ");
    //putchhex(BME280_id);
    if (BME280_id == 0x60) {
        //put_serial_st(" OK\n\n");
        return 1;
    } else {
        //put_serial_st(" ERROR Not Found\n\n");
        return 0;
    }
}

int32_t read24(char address) { //reads in a 24bit value in Big Endlain
    int32_t value[3];
    value[0] = i2c_read1ByteRegister(BME280_ADDRESS, address);
    value[1] = i2c_read1ByteRegister(BME280_ADDRESS, address + 1);
    value[2] = i2c_read1ByteRegister(BME280_ADDRESS, address + 2);
    return (value[0] << 16) | (value[1] << 8) | (value[2]);
}

uint16_t read16_LE(char address) { //reads in a 16bit unsigned value Little Endlian
    uint16_t value[2];
    value[0] = i2c_read1ByteRegister(BME280_ADDRESS, address);
    value[1] = i2c_read1ByteRegister(BME280_ADDRESS, address + 1);
    return (value[1] << 8 | value[0]);
}

int16_t readS16_LE(char address) { //reads in a signed 16bit value Little Endlain
    int16_t value[2];
    value[0] = i2c_read1ByteRegister(BME280_ADDRESS, address);
    value[1] = i2c_read1ByteRegister(BME280_ADDRESS, address + 1);
    //return (value[1] >> 8) | (value[0] << 8);
    return (value[1] << 8 | value[0]);
}

uint16_t read16(char address) { //reads in a 16bit unsigned value Little Endlian
    uint16_t value[2];
    value[0] = i2c_read1ByteRegister(BME280_ADDRESS, address);
    value[1] = i2c_read1ByteRegister(BME280_ADDRESS, address + 1);
    return (value[0] << 8 | value[1]);
}

int read8(char address) { //reads in a 8bit value
    int value;
    value = i2c_read1ByteRegister(BME280_ADDRESS, address);
    return value;
}

int BME280_read_Coefficients() { //reads in Factory set Coefficients used for calculations
    bme280_calib_dig_T1 = read16_LE(BME280_DIG_T1_LSB_REG);
    bme280_calib_dig_T2 = readS16_LE(BME280_DIG_T2_LSB_REG);
    bme280_calib_dig_T3 = readS16_LE(BME280_DIG_T3_LSB_REG);

    bme280_calib_dig_P1 = read16_LE(BME280_DIG_P1_LSB_REG);
    bme280_calib_dig_P2 = readS16_LE(BME280_DIG_P2_LSB_REG);
    bme280_calib_dig_P3 = readS16_LE(BME280_DIG_P3_LSB_REG);
    bme280_calib_dig_P4 = readS16_LE(BME280_DIG_P4_LSB_REG);
    bme280_calib_dig_P5 = readS16_LE(BME280_DIG_P5_LSB_REG);
    bme280_calib_dig_P6 = readS16_LE(BME280_DIG_P6_LSB_REG);
    bme280_calib_dig_P7 = readS16_LE(BME280_DIG_P7_LSB_REG);
    bme280_calib_dig_P8 = readS16_LE(BME280_DIG_P8_LSB_REG);
    bme280_calib_dig_P9 = readS16_LE(BME280_DIG_P9_LSB_REG);
    
    bme280_calib_dig_H1 = read8(BME280_DIG_H1_REG);
    bme280_calib_dig_H2 = readS16_LE(BME280_DIG_H2_LSB_REG);
    bme280_calib_dig_H3 = read8(BME280_DIG_H3_REG);
    bme280_calib_dig_H4 = (read8(BME280_DIG_H4_MSB_REG) << 4) | (read8(BME280_DIG_H4_LSB_REG) & 0x0F);
    //bme280_calib_dig_H5 = (read8(BME280_DIG_H4_LSB_REG) << 4) | (read8(BME280_DIG_H5_MSB_REG) >> 4); //0xE5 and 0xE6
    bme280_calib_dig_H5 = (read8(0xE5) << 4) | (read8(0xE6)); //0xE5 and 0xE6
    bme280_calib_dig_H6 = (int) read8(BME280_DIG_H6_REG);
    return 0;
}

int BME280_Setup() { //setup the Sensor
    if (!BME280_id_Check()) {
        return 0;
    }
    BME280_read_Coefficients();
    
    //i2c_write1ByteRegister(BME280_ADDRESS, BME280_CTRL_HUMIDITY_REG, 0x03); //16x oversampling
    //i2c_write1ByteRegister(BME280_ADDRESS, BME280_CONFIG_REG, 0x27); // 16x ovesampling, normal mode
    

    //Setting Below are for 1 second sample rate.
    i2c_write1ByteRegister(BME280_ADDRESS, BME280_CTRL_HUMIDITY_REG, 0x01); //normal mode
    i2c_write1ByteRegister(BME280_ADDRESS, BME280_CTRL_MEAS_REG, 0b00100111); //normal mode
    i2c_write1ByteRegister(BME280_ADDRESS, BME280_CONFIG_REG, 0xA0); //sample once per second
    return 1;
}

float BME280_readTemperature(void) {
    int32_t var1, var2;
    int32_t adc_T;
    
    adc_T = read24(BME280_TEMPERATURE_MSB_REG);

    adc_T >>= 4;

    var1 = ((((adc_T >> 3) - ((int32_t) bme280_calib_dig_T1 << 1))) * ((int32_t) bme280_calib_dig_T2)) >> 11;

    var2 = (((((adc_T >> 4) - ((int32_t) bme280_calib_dig_T1)) * ((adc_T >> 4) - ((int32_t) bme280_calib_dig_T1))) >> 12) * ((int32_t) bme280_calib_dig_T3)) >> 14;

    t_fine = var1 + var2;

    float T = (t_fine * 5 + 128) >> 8;
  
    //return T / 100;
    return T;
}

float BME280_readPressure(void) {
    int64_t var1, var2, p;
    int32_t adc_P;

    BME280_readTemperature(); // must be done first to get t_fine

    adc_P = read24(BME280_PRESSURE_MSB_REG);
    adc_P >>= 4;

    var1 = ((int64_t) t_fine) - 128000;
    var2 = var1 * var1 * (int64_t) bme280_calib_dig_P6;
    var2 = var2 + ((var1 * (int64_t) bme280_calib_dig_P5) << 17);
    var2 = var2 + (((int64_t) bme280_calib_dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t) bme280_calib_dig_P3) >> 8) +
            ((var1 * (int64_t) bme280_calib_dig_P2) << 12);
    var1 = (((((int64_t) 1) << 47) + var1))*((int64_t) bme280_calib_dig_P1) >> 33;

    if (var1 == 0) {
        return 0; // avoid exception caused by division by zero
    }
    p = 1048576 - adc_P;
    p = (((p << 31) - var2)*3125) / var1;
    var1 = (((int64_t) bme280_calib_dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t) bme280_calib_dig_P8) * p) >> 19;

    p = ((p + var1 + var2) >> 8) + (((int64_t) bme280_calib_dig_P7) << 4);
    //return (float) p / 256;
    return (float) p/256/100;
}

float BME280_readHumidity(void) {

    BME280_readTemperature(); // must be done first to get t_fine

    int32_t adc_H = read16(BME280_HUMIDITY_MSB_REG);

    double var_H;
    var_H = (((double) t_fine) - 76800.0);
    var_H = (adc_H - (((double) bme280_calib_dig_H4) * 64.0 + ((double) bme280_calib_dig_H5) / 16384.0 * var_H)) *
            (((double) bme280_calib_dig_H2) / 65536.0 * (1.0 + ((double) bme280_calib_dig_H6) / 67108864.0 * var_H *
            (1.0 + ((double) bme280_calib_dig_H3) / 67108864.0 * var_H)));

    var_H = var_H * (1.0 - ((double) bme280_calib_dig_H3) * var_H / 524288.0);
    if (var_H > 100.0)
        var_H = 100.0;
    else if (var_H < 0.0)
        var_H = 0.0;
    return var_H;
    
  }

/**************************************************************************/
/*!
    Calculates the altitude (in meters) from the specified atmospheric
    pressure (in hPa), and sea-level pressure (in hPa).

    @param  seaLevel      Sea-level pressure in hPa
    @param  atmospheric   Atmospheric pressure in hPa
 */

/**************************************************************************/
float BME280_readAltitude(float seaLevel) {
    // Equation taken from BMP180 datasheet (page 16):
    //  http://www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf

    // Note that using the equation from wikipedia can give bad results
    // at high altitude.  See this thread for more information:
    //  http://forums.adafruit.com/viewtopic.php?f=22&t=58064

    float atmospheric = BME280_readPressure() / 100.0F;
    return 44330.0 * (1.0 - pow(atmospheric / seaLevel, 0.1903));
}

/**************************************************************************/
/*!
    Calculates the pressure at sea level (in hPa) from the specified altitude
    (in meters), and atmospheric pressure (in hPa).
    @param  altitude      Altitude in meters
    @param  atmospheric   Atmospheric pressure in hPa
 */

/**************************************************************************/
float BME280_seaLevelForAltitude(float altitude, float atmospheric) {
    // Equation taken from BMP180 datasheet (page 17):
    //  http://www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf

    // Note that using the equation from wikipedia can give bad results
    // at high altitude.  See this thread for more information:
    //  http://forums.adafruit.com/viewtopic.php?f=22&t=58064

    return atmospheric / pow(1.0 - (altitude / 44330.0), 5.255);
}

