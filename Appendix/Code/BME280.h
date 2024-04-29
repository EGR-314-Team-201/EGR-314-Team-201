// Adapted from (https://github.com/redkite-electronics/Bosch-BME280-C-Library-for-Microchip-16bit-Processors/tree/master)

#ifndef BME280_H
#define	BME280_H

#include <xc.h>   
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

Modified for Microchip PIC24 Processors by Ian Stewart Feburay 2017

I. Stewart Version 1 26/02/2017

Temperture Reading and Compension Working as of 05/02/2017
Pressure Reading and Compension Working as of 05/02/2017
Humidity Reading and Compension Working as of 26/02/2017

 BME280.h Header file for BME280.c

 */
int BME280_id_Check();
int32_t read24(char address);
uint16_t read16_LE(char address);
int16_t readS16_LE(char address);
uint16_t read16(char address);
int16_t read8(char address);
int16_t BME280_read_Coefficients();
int16_t BME280_Setup();
float BME280_readTemperature(void);
float BME280_readPressure(void);
float BME280_readHumidity(void);
float BME280_readAltitude(float seaLevel);
float BME280_seaLevelForAltitude(float altitude, float atmospheric);

// IC2 Register names:
#define BME280_ADDRESS                          0x76

#define BME280_DIG_T1_LSB_REG			0x88
#define BME280_DIG_T1_MSB_REG			0x89
#define BME280_DIG_T2_LSB_REG			0x8A
#define BME280_DIG_T2_MSB_REG			0x8B
#define BME280_DIG_T3_LSB_REG			0x8C
#define BME280_DIG_T3_MSB_REG			0x8D

#define BME280_DIG_P1_LSB_REG			0x8E
#define BME280_DIG_P1_MSB_REG			0x8F
#define BME280_DIG_P2_LSB_REG			0x90
#define BME280_DIG_P2_MSB_REG			0x91
#define BME280_DIG_P3_LSB_REG			0x92
#define BME280_DIG_P3_MSB_REG			0x93
#define BME280_DIG_P4_LSB_REG			0x94
#define BME280_DIG_P4_MSB_REG			0x95
#define BME280_DIG_P5_LSB_REG			0x96
#define BME280_DIG_P5_MSB_REG			0x97
#define BME280_DIG_P6_LSB_REG			0x98
#define BME280_DIG_P6_MSB_REG			0x99
#define BME280_DIG_P7_LSB_REG			0x9A
#define BME280_DIG_P7_MSB_REG			0x9B
#define BME280_DIG_P8_LSB_REG			0x9C
#define BME280_DIG_P8_MSB_REG			0x9D
#define BME280_DIG_P9_LSB_REG			0x9E
#define BME280_DIG_P9_MSB_REG			0x9F

#define BME280_DIG_H1_REG			0xA1

#define BME280_CHIP_ID_REG			0xD0 //Chip ID

#define BME280_RST_REG				0xE0 //Softreset Reg

#define BME280_DIG_H2_LSB_REG			0xE1
#define BME280_DIG_H2_MSB_REG			0xE2
#define BME280_DIG_H3_REG			0xE3
#define BME280_DIG_H4_MSB_REG			0xE4
#define BME280_DIG_H4_LSB_REG			0xE5
#define BME280_DIG_H5_MSB_REG			0xE6
#define BME280_DIG_H6_REG			0xE7

#define BME280_CTRL_HUMIDITY_REG		0xF2 //Ctrl Humidity Reg
#define BME280_STAT_REG				0xF3 //Status Reg
#define BME280_CTRL_MEAS_REG			0xF4 //Ctrl Measure Reg
#define BME280_CONFIG_REG			0xF5 //Configuration Reg

#define BME280_PRESSURE_MSB_REG			0xF7 //Pressure MSB
#define BME280_PRESSURE_LSB_REG			0xF8 //Pressure LSB
#define BME280_PRESSURE_XLSB_REG		0xF9 //Pressure XLSB

#define BME280_TEMPERATURE_MSB_REG		0xFA //Temperature MSB
#define BME280_TEMPERATURE_LSB_REG		0xFB //Temperature LSB
#define BME280_TEMPERATURE_XLSB_REG		0xFC //Temperature XLSB

#define BME280_HUMIDITY_MSB_REG			0xFD //Humidity MSB
#define BME280_HUMIDITY_LSB_REG			0xFE //Humidity LSB

uint16_t bme280_calib_dig_T1;
int16_t bme280_calib_dig_T2;
int16_t bme280_calib_dig_T3;

uint16_t bme280_calib_dig_P1;
int16_t bme280_calib_dig_P2;
int16_t bme280_calib_dig_P3;
int16_t bme280_calib_dig_P4;
int16_t bme280_calib_dig_P5;
int16_t bme280_calib_dig_P6;
int16_t bme280_calib_dig_P7;
int16_t bme280_calib_dig_P8;
int16_t bme280_calib_dig_P9;

uint16_t bme280_calib_dig_H1;
int16_t bme280_calib_dig_H2;
uint16_t bme280_calib_dig_H3;
uint16_t bme280_calib_dig_H4;
uint16_t bme280_calib_dig_H5;
uint16_t bme280_calib_dig_H6;

uint16_t T = 0;
uint16_t P = 0;
double H = 0;

unsigned short dig_T1 = 0;
signed short dig_T2 = 0;
signed short dig_T3 = 0;

unsigned short dig_P1 = 0;
signed short dig_P2 = 0;
signed short dig_P3 = 0;
signed short dig_P4 = 0;
signed short dig_P5 = 0;
signed short dig_P6 = 0;
signed short dig_P7 = 0;
signed short dig_P8 = 0;
signed short dig_P9 = 0;

unsigned char dig_H1 = 0;
signed short dig_H2 = 0;
unsigned char dig_H3 = 0;
signed short dig_H4 = 0;
signed short dig_H5 = 0;
unsigned char dig_H6 = 0;
 

#endif	/* XC_HEADER_TEMPLATE_H */

