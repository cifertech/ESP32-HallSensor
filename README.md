# ESP32-HallSensor
I want to introduce you to one of the hidden features of this chip, namely the ESP32 internal effect sensor.

## What it DO!
A Hall effect sensor can detect changes in the magnetic field in its surroundings. The higher the magnetic field, the higher the output voltage of the sensor. For example, the Hall effect sensor can be combined with a threshold detector to act as a switch. In addition, Hall effect sensors are mainly used for things like proximity detection, counting wheel speeds, door closures and more.


### Items needed
-ESP32
-Oled0.96

### Required libraries
-Wire
-Adafruit_SSD1306

## Conclusion
In this tutorial, by calling the hallRead () function and storing the values obtained in a variable and finally displaying them, we can use these values and detect the magnetic field close to the chip. In this tutorial, we will display these values in a graphic graph using the OLED display.


 Full Tutorial at http://cifertech.net/
