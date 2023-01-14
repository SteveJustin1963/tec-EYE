# tec-EYE


![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/eye-ball-bw.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/chip1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/lens1.png)


The ADNS2610 is an optical mouse sensor chip that is perfect for use with the slow TEC-1 due to its limited processing ability. It can be easily obtained by removing it from an old optical mouse. To improve its functionality, a cheap adjustable lens can be mounted on the front as the existing mouse lens is only useful for close range and not useful for capturing images. The chip's output circuit is simple as the data is sent out serially on SDIO (serial data in and out) and SCK (serial clock). This slow serial data stream can be buffered and analyzed. The sensor has an 8x8 pixel matrix, providing 64-bit frames or 8 bytes of data. The optical navigation technology, including the built-in DSP feature, can be later exploited for more complex uses.

from the SparkFun ElectronicS example `adns2620-explain` we can see the part of the code that handles the serial data communication between the ATmega328 (Arduino) microcontroller and the ADNS2620 sensor is the following: `data.c`

the steps are
```
1. Declare a function named "read" that takes in a variable "address"
2. Declare a variable "value" and set it to 0
3. Set the pin mode for the SDA line to OUTPUT and the clock line to INPUT
4. Set the clock line to HIGH
5. AND the "address" variable with 0x7F and store the result in "address"
6. Begin a loop that iterates 8 times
    7. Within the loop, set the clock line to LOW
    8. Set the pin mode for the SDA line to OUTPUT
    9. If the current bit of "address" is 1, set the SDA line to HIGH. If not, set it to LOW
    10. Delay for 10 microseconds
    11. Set the clock line to HIGH
    12. Delay for 10 microseconds
13. Delay for 120 microseconds
14. Set the pin mode for the SDA line to INPUT and enable the internal pull-up
15. Begin a loop that iterates 8 times
    16. Within the loop, set the clock line to LOW
    17. Delay for 10 microseconds
    18. Set the clock line to HIGH
    19. Delay for 10 microseconds
    20. If the value read from the SDA line is HIGH, OR "value" with the current bit of the loop
21. Return the "value" variable
```


 

