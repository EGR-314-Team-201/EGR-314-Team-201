
# Home

Cup Warmer/Cooler  
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

![Block Diagram-314 (1)](/Checkpoint2/BlockDiagram.png)    
Full Description of Team member roles  [Block Diagram](/Checkpoint2/Block-Diagram.md)
## Microcontroller Selection
![PIC24FJ64GA702](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974555/5558f557-7318-44fb-9041-7ebc4dd5bd85)    
Final Microcontroller Choice: PIC24FJ64GA702    
Rationale: Has the most bits of the selections as well as the most cost effective option out of the three choices. Also has multiple EUSART peripherals to support any debug while maintaining a small footprint and low power usage. The benefit of multiple I2C ports will support our sensors.  

Full Description of Process
[Microcontroller Selection](/Checkpoint2/Microcontroller-Selection.md)

## Component Selection

### Humidity Sensor
![Capture1](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/676155ce-70c1-4b1a-8d82-1d44bcc1102f)    
Sensirion AG Humidity Sensor

### LCD Display
![Capture3](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/89263135-7588-4af4-bc7b-f91fc1a3d26d)    
NHD-C0220BIZ-FSW-FBW-3V3M LCD Display

### Temperature Sensor
![Capture](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/fa50dd98-fdc1-481f-8c3d-18cd185b0c0a)    
DS18B20 OneWire Tmeperature Sensor

### Heating Element
![Heater](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/4aee586e-7047-4cad-b90e-76cc118e12db)    
FIT0844 Heating Element

### Switching Voltage Regulator
![Reg](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/1b38c35b-3765-4868-93df-429d267c72fb)    
MIC4575WU Buck Regulator

### Cooling Element    
![Cooler](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/1e6cd210-a69a-40d5-a426-fd1ccd611983)    
PELTIER TEC 40X40X3.8MM 6.0A


### Fan
![Fan](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/cbf01ae9-2543-4064-9e3a-ed5d23832137)    
FAN AXIAL 80X15MM 12VDC WIRE



### Additional Details
[Component Selection](/Checkpoint2/Component-Selection.md)

### Power Budget

![Power Budget 1](/Checkpoint2/Power-Budget_Page_1.png)    
![Power Budget 2](/Checkpoint2/Power-Budget_Page_2.png)    

### Bill of Materials
![Bill of Materials](/Checkpoint2/BillofMaterials.png)
## Hardware Proposal

![1708993377669-685aaf96-a387-49b2-9b43-d82ece39cacf_1](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/23f246a0-71f4-4b4b-8c47-dc12821e881c)

[Hardware Proposal Document](Checkpoint2/Hardware_Prop_A3.pdf)
## Software Proposal

![Software Proposal_team201-Main Loop](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/f19ee060-efd7-4802-85d5-40dc412f816f)


