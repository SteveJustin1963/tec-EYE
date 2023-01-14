# tec-EYE


![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/eye-ball-bw.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/chip1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/lens1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/pinout1.png)

Give the TEC-1 the ability to crudely see using a ADNS2610 chip ripped out of an old optical mouse or spare a few dollars and get a new one. A mounted adjustable lens is a must as the lens in the mouse is for mm range thus useless. can rip a lens off another cheap camera module.

The idea is the capture the serial steam and send it to buffer for analysis. The sensor looks at 8x8 pixels, thus 64 bit frames or 8 bytes. There are some sophisticated DSP features in this chip that can be later exploited for more complex uses. The circuit is also very simple as the data is sent out serially on SDIO (serial data in and out) and SCK (serial port clock).

See this diagram ![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/CCD.jpg)

