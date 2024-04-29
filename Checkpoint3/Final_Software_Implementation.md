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




### "Version 2.0"

If a 2.0 version were to be done, we would like to spend more time working on the dispalyed information and UI. Currently we have it so that the screen switches bewtween the temperature, desired temperature and humidity based on timers. We would like to make it so all information is shown at the same time so that the user can just look at the information they need without needing to wait. Especially for the desired temperature it was difficult to show changes made with our original UI and want to make it so it is always visable. Additionally, readding the shutoff protection using either the humidity sensor or a liquid sensor would be good for keeping the circuitry intact.
