
# Bevright Home <br>


![Bevrightgreen](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/2ce0591b-60eb-445a-9d97-fcb8faf81895)<br>



Bevright  
EGR 314 Team 201 Spring 2024  
Team Members: Erik Alegria, Hunter Janisch, Joseph Pelle, Houyu Zhang  
Preparation Date: 2/26/2024  
ASU Poly, EGR 314 Mon/Wed, Dr. Kelly  

## Team Organization
Team Goals:
- Create a functional, safe, and reliable design.
- Develop an attractive design.
- Establish a dependable design.
- Give priority to safety.
- Craft a user-friendly design.
- Implement quality assurance for both the design prototype and the final product.

Our goal is to design a cup able to detect temperature in a drink and be able to regulate its temperature using serial sensor and outside actuators. Our goal is to not only meet academic requirements but to pioneer innovative, impactful solutions in environmental monitoring, broadcasting valuable data over the internet through MQTT. Join us in shaping a future where technology leads to a smarter world.

[Rest of Team Organization](/Checkpoint1/TeamOrganization.md)

## User Needs

For our user needs, we compiled a list of similar products to the one we wanted to create and went through various positive and negative reviews. We then examined each review what needs the customer was praised or  wanting from the product. More details for our process is in the following link.  

[VOC Benchmarking](/Checkpoint1/VOC.md)

## Product Requirements
Dive into the core specifications of our innovative product by exploring our Product Requirement Document. Follow the link to gain insights into the essential features, design considerations, functionality, customization options, manufacturing guidelines, and safety standards that define our portable beverage temperature control device.  
[Product Requirements Document](/Checkpoint1/Product-Requirements.md)

## Design Ideation
Explore our product's design journey through our ideation process. Click the link to delve into the evolution of ideas, collaborative efforts, and creative solutions that shaped our portable beverage temperature control device. Discover the insights into hardware and software design, user experience, customization, manufacturing, and safety considerations.  
[Design Ideation Document](/Checkpoint1/Design-Ideation.md)

## Checkpoint 1 Presentation
Watch our presentation to get a better look at our ideas and thought processes for our product.  
[Watch Presentation](https://www.youtube.com/embed/ELKO8Bcwy7k?si=6Dyh1avTQ3MYCgBe)
## Selected Design

![Chosen Design: Device holding cup with heating pad on bottom and peltier coolers and heatsink on side](/Checkpoint2/DesignScreenshot.png)    
Description: This concept acts as something to place your drink in. The panel on the side will be used to set the desired temperature for your drink. Depending on whether the drink should be heated or cooled. The heat pad on the bottom and the fan and coolant on the side will activate. To get to the correct temperature, a probe is used to check the current temperature of the drink and see once the drink reaches the desired temperature.    

## Block Diagram

![Block Diagram-314 (4)](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/d6b83346-4201-40fb-bf4d-6f6310e31d1d)

Full Description of Team member roles  [Block Diagram](/Checkpoint2/Block-Diagram.md)
## Microcontroller Selection
![PIC24FJ64GA702](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974555/5558f557-7318-44fb-9041-7ebc4dd5bd85)    
Final Microcontroller Choice: PIC24FJ64GA702    
Rationale: Has the most bits of the selections as well as the most cost effective option out of the three choices. Also has multiple EUSART peripherals to support any debug while maintaining a small footprint and low power usage. The benefit of multiple I2C ports will support our sensors.  

Full Description of Process
[Microcontroller Selection](/Checkpoint2/Microcontroller-Selection.md)

## Final Component Selection

### Humidity Sensor
![bme280](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/4218ed1d-7fee-49be-9b0d-031ca21b2fb2)<br>
BOSCH BME280 Humidity sensor <br>
Usable with 1.7-3.6V <br>
8 pins, 1 second Response Time <br>


### LCD Display
![Capture3](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/89263135-7588-4af4-bc7b-f91fc1a3d26d)   
NHD-C0220BIZ-FSW-FBW-3V3M LCD Display<br>
Usable with 2.7-3.6V <br>



### Temperature Sensor
![Capture](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/fa50dd98-fdc1-481f-8c3d-18cd185b0c0a)<br>
DS18B20 OneWire Tmeperature Sensor
Usable with 3.0-5.5V<br>
±0.5°C Accuracy from -10°C to +85°C<br> 
Temperature Range: -55°C ~ 125°C <br>

### Heating Element
![fit0844](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/65b572f5-4d83-4025-bff8-3c8338ef8b40)<br>
FIT0844 Heating Element <br>
Usable with 5V, 8 W <br>
Max Temperature: 100°C <br>


### Switching Voltage Regulator
![Reg](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/1b38c35b-3765-4868-93df-429d267c72fb)    
MIC4575WU Buck Regulator<br>
Adjustable Output Voltage Regulator<br>
4-24V Input; 1.23v-20V Output<br>

### Cooling Element    
![Cooler](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/1e6cd210-a69a-40d5-a426-fd1ccd611983)    
PELTIER TEC 40X40X3.8MM 6.0A <br>
Peltier Module 51.4W @ 27°C 6 A 90°C <br>


### Fan
![Fan](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/cbf01ae9-2543-4064-9e3a-ed5d23832137)    
FAN AXIAL 80mm L x 80mm H <br>
12VDC, 4 Wire Leads, 3.96W <br>



### Additional Details
[Component Selection](/Checkpoint2/Component-Selection.md)



### Power Budget

![Power Budget 1](/Checkpoint2/Power-Budget_Page_1.png)    
![Power Budget 2](/Checkpoint2/Power-Budget_Page_2.png)    




## Final Hardware Implementation
To explore our Final Hardware Implementaion in greater detail, please refer to the [Final Hardware Implementation Document](/Checkpoint3/Final_Hardware_Implementation.md)



![EGR314_Team201_TeamSchematic 1](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/fad725d7-cb15-40a9-99fd-68837a511370)


[Bill Of Materials](/Checkpoint2/Bill_of_Materials.pdf)


### Team Final PCB
#### PCB Without Components
![Resized_20240425_173439](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/c8b822ca-5a4a-4210-929f-9941cdda1393)

#### PCB With Components
![IMG_1231](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/bd8c12b8-8d1d-426e-8115-28a43e108205)

#### Final Prototype
![IMG_1230 (1)](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/8edec8d2-95a4-45e5-810d-136949d0143d)

## Final Software Implementation
![Software Proposal_team201-Main Loop (3)](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/0be1d3f6-65ad-4b9c-baf1-b15735e26527)

To get a more in-depth look at our Final Software Implementation please refer to [Final Software Implementation Document](/Checkpoint3/Final_Software_Implementation.md)

## System Verification Document
[System Verification](/Checkpoint3/System_Verification.md)

## Recommendations for future students
### Top 5
1. Start both individual and team assignments early to stay ahead of the workload and avoid feeling overwhelmed.
2. Double-check the parts selected for your project when they arrive to ensure they meet the project requirements aswell as you recieved all the correct parts.
3. Utilize office hours, communicate with classmates, the professor, and TAs when assistance is needed.
4. Get comfortable with communicating with your teammates, conduct progress checks, and establish a steady design process for the project.
5. Keep your project idea realistic and achievable, ensuring it is innovative but not overly ambitious and meets all project criteria.



## Lessons Learned
1. Verify that selected parts are correct and will work with the other components.
2. Acquired surface mount soldering techniques.
3. Gained proficiency in navigating MPLAB XIDE and Cadence software.
4. Learned to use advanced serial communication protocols such as I2C and SPI.
5. Implemented timer and button interrupts to add more flow to program.
6. Utilized the ESP32 for connecting to the MQTT server via WiFi.
7. Found how best to market product to desired audience.
8. Read datasheets to get a better understanding of the internal functions of our parts.
9. Went through signals transmitted by each device to debug both hardware and software issues.
10. Built device with user needs at the forefront.




In the [Appendix](/Appendix/), you will find a detailed list of all our code and the MPLAB setup we utilized to make our device work.
