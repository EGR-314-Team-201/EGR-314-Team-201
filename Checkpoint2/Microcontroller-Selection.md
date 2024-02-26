
## Design Considerations

### Team Project-Specific Requirements
| Requirement                                     | Details                                                                 |
|-------------------------------------------------|-------------------------------------------------------------------------|
| Able to control current for switching regulator | For cooler                                                              |
| I2C Onewire Compatibility                       | Temperature Sensor                                                       |
| Minimum of 3 I2C connections                    | LCD, Onewire, Additional temp sensor for cooler                        |
| Minimum of 1 SPI Connection                     | Motor                                                                   |
| 2 PWM                                           |  Fans/Heater                                                              |
| High current and voltage application           | 12 V 6A for cooler                                                      |
| Able to withstand high temperatures            | Potentially high temperature around device                             |
| Protection against spills                      | Potential Spills, contact with liquids                                  |
| Ability to handle interrupts                   |  Humidity Sensor                                                         |
| Ability to connect via Phone                   | Wifi                                                                    |
| Compatible with MPLAB x IDE                    | Programming Software                                                    |

---

## Microcontroller Considerations

| Instructions                                     | PIC Option 1                  | PIC Option 2                  | PIC Option 3                  |
|--------------------------------------------------|-------------------------------|-------------------------------|-------------------------------|
| Part Number                                      | PIC24FJ64GA702               | PIC18F26K40-I/SO            | PIC18F47Q10                  |
| Link (URL) to product page                       | [Product](https://www.microchip.com/en-us/product/PIC24FJ64GA702)               | [Product](https://www.digikey.com/en/products/detail/microchip-technology/PIC18F26K40-I%2FMV/6208255?utm_adgroup=Battery%20Products&utm_source=google&utm_medium=cpc&utm_campaign=Dynamic%20Search_EN_Product&utm_term=&utm_content=Battery%20Products)  | [Product](https://www.google.com/url?q=https://www.microchip.com/en-us/product/PIC18F47Q10&sa=D&source=docs&ust=1708823414483230&usg=AOvVaw1r-fcljHHEobvwuxAafbKU)               |
| Links (URL) to Data Sheets                       | [Datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU16/ProductDocuments/DataSheets/PIC24FJ256GA705-Family-Data-Sheet-DS30010118E.pdf)             | [Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC18LF26-45-46K40-Data-Sheet-DS40001816F.pdf)             | [Datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC18F27-47Q10-Data-Sheet-40002043E.pdf)             |
| Links (URL) to Application Notes                  | [Notes](https://www.microchip.com/en-us/product/PIC24FJ64GA702)                 | [Notes](https://www.microchip.com/en-us/product/PIC18F26K40#sampling-options)                 | [Notes](https://www.microchip.com/en-us/product/PIC18F47Q10)                 |
| Links (URL) to Code Examples                     | [Code](https://www.microchip.com/en-us/product/PIC24FJ64GA702#document-table)                  | [Code](Link)                  | [Code](Link)                  |
| Links (URL) to External Resources                | [Link](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/UserGuides/release_notes_pic24_dspic_pic32mm_v1_105.pdf)                  | [Link](Link)                  | [Link](Link)                  |
| Production Unit Cost                             | $ 1.88                        | $ 2.04                        | $ 1.95                        |
| Supply Voltage Range                             | 2V-3.6V                       | 1.8V-3.6V                     | 1.8V – 5.5V                   |
| Absolute Maximum Current for entire IC           | 200mA                         | 200mA                         | 350mA                         |
| Maximum GPIO Pin Current (Source/Sink)           | 25mA                          | 50mA                          | 50mA                          |
| 8-bit or 16-bit Architecture                     | 16-bits                       | 8-bit                         | 8-bit                         |
| Available IC Packages / Footprints               | SOIC28, SSOP28, QFN28, UQFN28 | SPDIP, SOIC, SSOP, QFN, UQFN, PDIP | SPDIP28, SOIC28, SSOP28, VQFN28, QFN28 |
| Supports External Interrupts?                   | 5 external                    | 3 external                    | 3 external                    |
| In-System Programming Capability and Type       | ICSP, 2 pins                  | ICSP                          | ICSP                          |
| Programming Hardware, Cost, and URL             | [Link](Link)                  | [Link](Link)                  | [Link](Link)                  |
| Works with MPLAB® X Integrated Development Environment (IDE)? | YES                   | YES                           | YES                           |
| Works with Microchip Code Configurator?         | YES                           | YES                           | YES                           |

---

## Overall Pros and Cons for Chosen Microcontrollers

| Microcontroller         | PIC24FJ64GA702              | PIC18F26K40-I/SO            | PIC18F47Q10                  |
|-------------------------|-----------------------------|-----------------------------|------------------------------|
| **Pros**                | High Max Current rating     | All necessary pins          | Robust and reliable         |
|                         | In circuit programming      | Low power consumption       |                              |
| **Cons**                | Low program memory size     | Insufficient number of EUSARTs | 8-bit                      |
|                         | Only three external interrupts | No code example          | No code example              |
|                         |                    | No max current for IC (only individual pins) |                           |


---
# Final Microcontroller Choice: PIC24FJ64GA702
Rationale: Has the most bits of the selections as well as the most cost effective option out of the three choices. Also has multiple EUSART peripherals to support any debug while maintaining a small footprint and low power usage. The benefit of multiple I2C ports will support our sensors.


![Microcontroller](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/a904a863-83e1-453f-9e37-92894ca83592)

