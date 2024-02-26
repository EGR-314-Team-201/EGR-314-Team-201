## Components

| Component                           | Description                                                      | 
|-------------------------------------|------------------------------------------------------------------|
| Humidity Sensor                     | Used to measure humidity levels in the environment               |
| Temperature Sensor                  | Used to measure temperature in the environment                   |
| LCD Display                         | Display for showing temperature, humidity, and other information |
| Microcontroller                     | Controls the operation of the device                             |
| Heating Element                     | Provides heat for warming or boiling liquids                     |
| Switching Voltage Regulator         | Regulates voltage for various components                         |
| Cooling Unit                        | Cools the device or maintains a specific temperature             |
| Fans                                | Provide airflow for cooling                                      |
| Liquid Spill Protection Interrupt   | Prevents damage from spills or contact with liquids              |
| Push Buttons                        | User Interface, Allow users to interact with LCD Display         |
| Heat Sink                           | Prevent Overheating, Dissipate Heat                              |


## Component Selection
### Humidity Sensor
![Capture1](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/676155ce-70c1-4b1a-8d82-1d44bcc1102f)


| Solution                   | Pros                                                                         | Cons                                                              |
|----------------------------|------------------------------------------------------------------------------|-------------------------------------------------------------------|
|  Part # 1528-214         |    Low Power Consumption                                 |       Low Max Supply Voltage(Max 3.6V)                                       |
| [Product Link](https://www.digikey.com/en/products/detail/sensirion-ag/SHT30-DIS-B2-5KS/5872250)       |    I2C
|                            |    Temperature + Humidity Tracking Capabilites                                 |                     |
                                                           













### LCD Display
![Capture3](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/89263135-7588-4af4-bc7b-f91fc1a3d26d)

| Solution                   | Pros                                                                         | Cons                                                              |
|----------------------------|------------------------------------------------------------------------------|-------------------------------------------------------------------|
|  Part # 	
NHD-C0220BIZ-FSW-FBW-3V3M-ND       | - I2c                                      | - Size                                          |
| [Product Link](https://www.digikey.com/en/products/detail/adafruit-industries-llc/642/7244935](https://www.digikey.com/en/products/detail/newhaven-display-intl/NHD-C0220BIZ-FSW-FBW-3V3M/2626407 )               | - 2.7-3.6V Supply Voltage                                                               | - Limited Color Selection                          |
|                            | - Sustainable with higher temperatures                                      | - Slightly more expensive                 |
|                            | - White Backlight(Black Letters)                                                  |                                                         |
|                            | - Can Ship Immediately                                           |                                                                  |
|                            | - 16x2(characters/line)                                          |                                                                 |
|                            |                                        |                                                                 |
|                            |                                                        |                                                                  |



### Temperature Sensor
![Capture](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/fa50dd98-fdc1-481f-8c3d-18cd185b0c0a)

| Solution                   | Pros                                                                         | Cons                                                              |
|----------------------------|------------------------------------------------------------------------------|-------------------------------------------------------------------|
|  Part # 1528-214         | - Wide operating range (-55°C - 125°C)                                       | - Not surface mounted                                            |
| [Product Link](https://www.digikey.com/en/products/detail/adafruit-industries-llc/642/7244935)               | - Waterproof                                                                | - Bit more expensive                                             |
|                            | - Sustainable with higher temperatures                                      | - Might be a bit trivial to get working with code                 |
|                            | - Can ship immediately                                                      | - ±0.5°C                                                          |
|                            | - Usable with 3.0-5.0V systems                                              |                                                                  |
|                            | - Temperature-limit alarm system                                            |                                                                 |
|                            | - Multiple sensors can share one pin                                       |                                                                 |
|                            | - Temperature Probe                                                        |                                                                  |


### Heating Element
![Heater](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/d659f6dd-6a02-4e4b-bb62-f251d042227d)

| Solution                   | Pros                                                                         | Cons                                                              |
|----------------------------|------------------------------------------------------------------------------|-------------------------------------------------------------------|
|  Part # 	
1738-FIT0844-ND        |               Can ship immediately                       |       No Datasheet                                       |
| [Product Link](https://www.digikey.com/en/products/detail/sensirion-ag/SHT30-DIS-B2-5KS/5872250](https://www.digikey.com/en/products/detail/dfrobot/FIT0844/15848103 )        |  Inexpensive  | Small Heating area 35 x 15 mm  
|                            |       AC/DC capable                              |   Lacks useful documentation from manufacturer              |
|                            |       High heat transfer Rate                                              |                                                        |
|                            |               Low Power Consumption
                              






### Switching Voltage Regulator
![Reg](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/1b38c35b-3765-4868-93df-429d267c72fb)

| Solution                   | Pros                                                                         | Cons                                                              |
|----------------------------|------------------------------------------------------------------------------|-------------------------------------------------------------------|
|  Part # MIC4575WU         |   Output has a wide range (1.2-37V)                             |            Larger in Size compared to others                               |
| [Product Link](https://www.digikey.com/en/products/detail/microchip-technology/MIC4575WU-TR/1029999)               | Familiarity- previously used                                                         |            Low Stock                                 |
|                            |      Adjustable output                               |            Expensive      |
                                    





### Cooling Unit
![Cooler](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/0cea92ff-58d0-4856-ae9f-d0ea27a3c161)

| Solution                   | Pros                                                                         | Cons                                                              |
|----------------------------|------------------------------------------------------------------------------|-------------------------------------------------------------------|
|  Part # 	
345-1739-ND         |      Low Current                                 |       Least Surface Area                                    |
| [Product Link](https://www.digikey.com/en/products/detail/wakefield-vette/TEC-40-36-127/9741967 )               |     Inexpensive                                                        |                                             |
|                            |                                     |                  |






### Fan
![Fan](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/cbf01ae9-2543-4064-9e3a-ed5d23832137)
| Solution                   | Pros                                                                         | Cons                                                              |
|----------------------------|------------------------------------------------------------------------------|-------------------------------------------------------------------|
|  Part #   603-1159-ND       |    PWM Control                                   |  On the more expensive end                                         |
| [Product Link]( https://www.digikey.com/en/products/detail/delta-electronics/EFC0812DB-F00/1850528)              |     Ball Bearing which increases longevity                                                        |     Noise level at 41 dBA                                        | 
|                            |         Air Flow at 48.8 CFM                        |  Draws more power and current than similar fans                |
|                            |        Proportional size of 80 x 80 mm                                              |                                                      |
|                            |      Has a speed sensor feature (Tach)                                         |                                                                  |                                                                                                                 





















































### Power Budget
For detailed information on the power budget, including a list of major components, assignment to power rails, voltage regulator selection, external power source details, and battery life calculation, please refer to the [Power Budget Document](https://docs.google.com/spreadsheets/d/1HUIY-lxApwEYJuugOoQeQohUKihOL6_E/edit#gid=1442980976 )
