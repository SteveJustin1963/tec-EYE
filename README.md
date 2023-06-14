# tec-EYE


![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/eye-ball-bw.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/chip1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/lens1.png)


## hardware
- Obtain an ADNS2610 sensor by removing it from an old optical mouse.
- Acquire a cheap adjustable lens and mount it on the front of the sensor to improve its functionality.
- Connect the SDA and SCK pins of the ADNS2610 sensor to the corresponding pins on the Arduino microcontroller.

## Enhancing the TEC-1 with the ADNS2610 Optical Mouse Sensor Chip and Adjustable Lens
The ADNS2610 is an optical mouse sensor chip that is perfect for use with the slow TEC-1 due to its limited processing ability. It can be easily obtained by removing it from an old optical mouse. To improve its functionality, a cheap adjustable lens can be mounted on the front as the existing mouse lens is only useful for close range and not useful for capturing images. The chip's output circuit is simple as the data is sent out serially on SDIO (serial data in and out) and SCK (serial clock). This slow serial data stream can be buffered and analyzed. The sensor has an 8x8 pixel matrix, providing 64-bit frames or 8 bytes of data. The optical navigation technology, including the built-in DSP feature, can be later exploited for more complex uses.

## example Serial Data ADNS2620 to ATmega328 using SDA Line
from the SparkFun ElectronicS example `adns2620-explain` we can see the part of the code that handles the serial data communication between the ATmega328 (Arduino) microcontroller and the ADNS2620 sensor is the following: `data.c` .
SDA stands for Serial Data Line. It is a data line used in serial communication protocols such as I2C, SPI, and UART. In the context of the ADNS2620 sensor, the SDA line is used to send and receive data between the microcontroller and the sensor. The microcontroller sends the address of the register to be read to the sensor over the SDA line, and receives the data from the sensor over the same line. The SDA line is often used in conjunction with a clock line (SCL) to synchronize the communication between the devices.

## code for reading data from the ADNS2610 sensor.

The code defines a function called "read" that takes in an integer value representing the register address to read from. The function returns an integer value representing the data read from the sensor.

The function begins by setting the pin modes for the SDIO and SCK lines to OUTPUT and INPUT, respectively. It also sets the SDIO line to HIGH and the SCK line to LOW, which are the initial states required for the sensor's two-wire serial interface.

Next, the function ANDs the address value with 0x7F to ensure that the most significant bit is 0. It then enters a loop that iterates 8 times, with each iteration corresponding to a bit in the address value. Within the loop, the function sets the SCK line to LOW, sets the SDIO line to the value of the current bit in the address value, delays for 10 microseconds, sets the SCK line to HIGH, and delays for another 10 microseconds.

After sending the address value to the sensor, the function delays for 120 microseconds to allow the sensor to respond. It then sets the pin mode for the SDIO line to INPUT_PULLUP to prepare for reading the data from the sensor.

The function enters another loop that iterates 8 times, with each iteration corresponding to a bit in the data value. Within the loop, the function sets the SCK line to LOW, delays for 10 microseconds, sets the SCK line to HIGH, reads the current bit of the data value from the SDIO line, ORs it with the current value of the data variable using bitwise OR, and delays for another 10 microseconds.

Finally, the function sends the data value over the serial port using the Serial.write() function and returns the data value.

Overall, the code uses the two-wire serial interface of the ADNS2610 sensor to send an address value to the sensor and read a data value from it. It then sends the data value over the serial port for further processing.



