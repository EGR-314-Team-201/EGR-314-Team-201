![Software Proposal_team201-Main Loop (3)](https://github.com/EGR-314-Team-201/EGR-314-Team-201/assets/156974933/0be1d3f6-65ad-4b9c-baf1-b15735e26527)


## Software Functionality

The software for BevRight satisfies user needs by providing the following key features:

1. **Temperature Control:** The software implements code to read the temperature sensor data and adjust heating or cooling elements to maintain the desired temperature.
2. **LCD Display:** Updates the LCD display with relevant information, such as current temperature, humidity, allowing users to monitor their beverage.
3. **User Input Handling:** The software manages user input from Pushbuttons, enabling the user to specificy their desired temperature.
4. **Timer Functionality:** Timer functionality in the software allows for changing screens or performing tasks at specific times, enhancing the user experience.
5. **ESP32 Integration:** The software includes ESP32 serial input to change the desired temperature, providing users with remote adjustment capabilities.


### Changes Since Proposal

1. **Removing the humidity interrupt:** Simplified the software and reduced the complexity.
2. **Changing the Temperature control interrupts to timer interrupts:** Improved timing and efficiency of temperature control tasks.
3. **Changing Button polling to interrupts:** Enhanced responsiveness and helped to reduce processing power.
4. **Changing screens depending on time instead of all at once:** Provided a more dynamic and informative user interface.   
5. **Including ESP32 serial input to change Desired Temperature:** Added convenient remote adjustment capability for users.




If you were to create a "Version 2.0" of your software design, discuss what could be improved in the software design and why it should be improved. Use the UML diagrams above to support the discussion. Consider using a graphical representation of the flow that your updated software would take. What functions would you create? How would you divide up your code? How would you improve its debuggability? What peripherals or system features would you like to use or set up to make your system more reliable, stable, functional, or robust? How would you simplify, improve, or update your protocol design to support this in software? (½ page minimum)
