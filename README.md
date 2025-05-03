# 💡💡Automatic room light controller with people counter (For single entry/exit)💡💡
## ⚙️ Components required
*  Arduino Uno (1) - Main controller
*  IR sensors (2) - One close to the entry and one slightly inside room
*  Relay module (1) - To turn on and off the AC LED bulb on trigger from arduino
*  AC-DC 12W LED Bulb - To be connected to AC power supply via relay module
*  Connection wires - For AC Current supply
*  0.96 inch I2C OLED Display (1) - To display the count (Number of people in room) 
*  Breadboard (1)
*  Jumper wires 

## 🔗Connections
## IR Sensor 1 (Entry sensor)
* VCC --> 5V 
* Ground --> Gnd pin
* Out --> digital pin 2
## IR sensor 2 (Exit sensor)
* VCC --> 5V
* Ground --> Gnd pin
* Out --> digital pin 3
## 5V 1 channel Relay module (Normally open config.)
* VCC --> 5V
* Ground --> Gnd pin
* In --> digital pin 7
## OLED Display 
* VCC --> 5V
* Ground --> Gnd pin
* SDA --> A4
* SCL --> A5
       
## ⚙️⚙️ How it works:
When a person enters, IR sensor 1 (Entrance sensor) is triggerred, indicating person entered the room, Count goes from 0 to 1 in OLED display as well as in serial monitor, thus the
bulb turns ON. As people enters, count increases. When person exits the room, IR sensor 2 triggers, hence count decreases. The bulb turns off only when no people are in the room, i.e, when
count = 0.Since both sensors are placed a little close to each other (Both inside the room), a delay is set between two sensors in such a way that when one sensor activates (Entrance),
the other (Exit) one remains deactivated for a very small instance of time, preventing from simultaneous change in the count and false triggers.
       
## ⭕Note: Here, the two IR sensors are placed 3.5 cm apart from each other. If distance is to be varied in different cases, try changing the delay in the code for precise count control.
       


       
       
       


