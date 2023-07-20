# Fish farming system, using IoT
About
=================
System that has an ESP32 and integrated with it are ph, temperature and turbidity sensors. 
After collection, these parameters are sent via the MQTT protocol to a RaspBerry Pi 0 w, 
which provides the graphical user interface via the node-red API and also serves as a dedicated server. 
All sensors were validated and calibrated according to industrial sensors.

<img src="https://img.shields.io/badge/c++-esp32-blue"/> <img src="https://img.shields.io/badge/raspberryPi0W-NodeRed-orange"/>

Table of Contents
=================
<!--ts-->
   * [About](#About)
   * [Table of Contents](#table-of-contents)
   * [How to use](#how-to-use)
      * [Pre Requirements](#pre-requirements)
      * [Operation](#operation)
   * [Tests](#tests)
      * [Final result of the system with the data shown in the Node-Red API](#final-result)
   * [Project status](#project-status)
   * [Technologies](#technologies)
<!--te-->

How to use
=================

Pre Requirements
----
```bash
To run the system you will need to install
*Arduino IDE, configured with the ESP32 library
*Configuration of ips and wifi network passwords
*Raspberry Pi, mosquito installation
*Installing Node-Red API on Raspberry Pi
```

Operation
----
```bash
Sensor data will be automatically collected and sent to the Raspberry Pi
```

Tests
=================
Final result of the system with the data shown in the Node-Red API
----
<div align="center">
<img src="https://user-images.githubusercontent.com/43474214/148824888-47212901-dafc-491a-bc55-f5975c9cb330.png" width="700px" />
</div>


Project status
=================

<h4 align="center"> 
	🚧  Low cost fish farming system 🚀 under development 🚧
</h4>

Technologies
=================

<img src="https://img.shields.io/badge/c++-esp32-blue"/> <img src="https://img.shields.io/badge/raspberryPi0W-NodeRed-orange"/> <img src="https://img.shields.io/badge/Mosquito-Broker-MQTT"/> <img src="https://img.shields.io/badge/IDE-Arduino-orange"/> <img src="https://img.shields.io/badge/Instrumentação-Sensores-orange"/>

Author
---

Made by Railson Martins 👋🏽!







		

