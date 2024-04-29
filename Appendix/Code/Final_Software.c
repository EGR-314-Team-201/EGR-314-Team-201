/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ64GA702
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
 
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/system.h"
#include <libpic30.h>
#include <string.h>
#define LCD_ADDRESS 0x3C
#define BME280_ADDRESS 0x76 // BME280 I2C address
#define register 0x00 

uint8_t initData[] = {0x00,0x38,0x39,0x14,0x71,0x5E,0x6D,0x0F,0x01,0x06,0x80,0x4E};
uint8_t testData[] = {0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49, 0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53};
uint8_t returnHome[3] = {0x00,0x01, 0x02};
uint8_t clear[2] = {0x00, 0x01};
uint8_t linetwo[2] = {0x00, 0xC0};

float BME280_readHumidity(void);

// For I2C Screen
void init_LCD()
{
i2c_writeNBytes(LCD_ADDRESS,initData,sizeof(initData));
}

// For Humidity Sensor ()
float h;
char humidstr[20];


// For Temperature Sensor (Adapted from https://simple-circuit.com/mplab-xc8-ds18b20-pic-microcontroller/)
uint16_t raw_temp;
char tempstr[20];
char temp[] = "000.0000";
float TempVal = 0;
float RoomT = 20;
float DesiredT = 0;
char DTstr[20];
uint16_t ds18b20_read(uint16_t raw_temp_value)
{
  ow_reset();

  ow_write_byte(0xCC);   // send skip ROM command
  ow_write_byte(0x44);   // send start conversion command

  while(ow_read_byte() == 0);  // wait for conversion complete
  
  ow_reset();
  
  DELAY_milliseconds(50);
  
  ow_write_byte(0xCC);  // send skip ROM command
  ow_write_byte(0xBE);  // send read command
  
  DELAY_milliseconds(50);
  // read temperature LSB byte and store it on raw_temp_value LSB byte
  
  raw_temp_value  = ow_read_byte();
  // read temperature MSB byte and store it on raw_temp_value MSB byte
  raw_temp_value |= (uint16_t)(ow_read_byte() << 8);
  raw_temp_value = (raw_temp_value << 4) >> 4;
  
  
  return raw_temp_value;   // OK --> return 1
}

void TempRead()
{
     raw_temp = ds18b20_read(raw_temp);
        if(raw_temp & 0x8000)  // if the temperature is negative
      {
        temp[0] = '-';             // put minus sign (-)
        raw_temp = (~raw_temp) + 1;  // change temperature value to positive form
      }
 
      else
      {
        if((raw_temp >> 4) >= 100)  // if the temperature >= 100 °C
          temp[0] = '1';            // put 1 of hundreds
        else                        // otherwise
          temp[0] = ' ';            // put space ' '
      }
 
      // put the first two digits ( for tens and ones)
      temp[1] = ( (raw_temp >> 4) / 10 ) % 10 + '0';  // put tens digit
      temp[2] =   (raw_temp >> 4)        % 10 + '0';  // put ones digit
 
      // put the 4 fraction digits (digits after the point)
      // why 625?  because we're working with 12-bit resolution (default resolution)
      temp[4] = ( (raw_temp & 0x0F) * 625) / 1000 + '0';          // put thousands digit
      temp[5] = (((raw_temp & 0x0F) * 625) / 100 ) % 10 + '0';    // put hundreds digit
      temp[6] = (((raw_temp & 0x0F) * 625) / 10 )  % 10 + '0';    // put tens digit
      temp[7] = ( (raw_temp & 0x0F) * 625) % 10 + '0';            // put ones digit
      

      
}


// Timer Interrupts
// ISR for activating Heating Element or Fan + Peltier Cooler
void timer_callback(void)
{
    if(DesiredT < (TempVal - 2.5))
    {
        Fan_SetHigh();
        Peltier_SetHigh();
        Heat_SetLow();
    }
    else if(DesiredT > (TempVal + 2.5))
    { 
        Heat_SetHigh();
        Fan_SetLow();
        Peltier_SetLow();
    }
    else
    {
        Fan_SetLow();
        Peltier_SetLow();
        Heat_SetLow();
    }
}

// For up button to increase desired temperature
void DT_up(void)
{
    DesiredT++;
}

// For down button to decrease desired temperature
void DT_down(void)
{
    DesiredT--;
}

// For Uart to recieve and set desired temperature
void DT_Receive_ISR()
{
    UART1_Receive_CallBack();
    
    if(UART1_IsRxReady())
    {
        DesiredT = UART1_Read();
    }
    
        
}
/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_Initialize();
    INTERRUPT_GlobalEnable();
    
    TMR1_Initialize();
    TMR1_Start();
    TMR1_SetInterruptHandler(&timer_callback);
    Button_Up_SetInterruptHandler(&DT_up);
    Button_Down_SetInterruptHandler(&DT_down);
    UART1_Initialize();
    UART1_SetRxInterruptHandler(&DT_Receive_ISR);
    
    // initialize LCD display
    LCD_Reset_SetLow();
    DELAY_milliseconds(1000);
    LCD_Reset_SetHigh();
    DELAY_milliseconds(1000);
    init_LCD();
    i2c_writeNBytes(LCD_ADDRESS, returnHome, 2);
    
    // Enable Humidity
    BME280_Setup();
    
    while (1)
    {
        // Reset Display to Clean Slate
        
        i2c_writeNBytes(LCD_ADDRESS, returnHome, 3);
        
        // Take and display temperature
        TempRead();
        TempVal = atoll(temp);
        printf("CT = %s C ;", temp);
        sprintf(tempstr, "xCT = %s C",temp);
        i2c_writeNBytes(LCD_ADDRESS, 0x40, 1);
        i2c_writeNBytes(LCD_ADDRESS, tempstr, sizeof(tempstr));
        strcpy(tempstr,"");
        
        
        // Go to next line on display
        //Convert Desired Temperature to string then display
        i2c_writeNBytes(LCD_ADDRESS, linetwo, sizeof(linetwo));
        printf("DT = %3.4f C ;", DesiredT);
        sprintf(DTstr, "xDT = %3.4f C", DesiredT);
        i2c_writeNBytes(LCD_ADDRESS, 0x40, 1);
        i2c_writeNBytes(LCD_ADDRESS, DTstr, sizeof(DTstr));
        strcpy(DTstr,"");
        DELAY_milliseconds(1000);
        
        // Reset Display to Clean Slate
       i2c_writeNBytes(LCD_ADDRESS, clear, 2);
       i2c_writeNBytes(LCD_ADDRESS, returnHome, 2);
       
       // Get humidity value and display to screen
       h = BME280_readHumidity();
       sprintf(humidstr, "xH = %3.4f %",h);
       i2c_writeNBytes(LCD_ADDRESS, humidstr, sizeof(humidstr));
       strcpy(tempstr,"");
       printf("H = %3.4f % \r",h);
       
       DELAY_milliseconds(1000);
        
    }

    return 1;
}
/**
 End of File
*/

