# ADT7410
## Description
C++ API for the ADT7410 16-Bit Digital I2C Temperature Sensor
## Platform
BeagleBone Black, Rev C, running Debian 9.4 (iot-armhf)
## Details
The ADT7410 has a number of configuration options. This API is written
with the assumption that most of these will be set when power is applied
and not changed during operation.

Exceptions to this include the T-Low, T-High, T-Crit, and Hysteresis setpoints.
## Status
* In development, nearing completion.
* Consider writing this for an 8-bit mcu linked to an I2C display.
* Christmas is also coming soon. Better get that shopping done.
