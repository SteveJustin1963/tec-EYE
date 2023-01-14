# tec-EYE


![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/eye-ball-bw.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/chip1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/lens1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/pinout1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/CCD.jpg)

The ADNS-2610 is an optical mouse sensor chip and it is designed to track the movement of a surface, and it can be used to capture basic images with very limited resolution and image quality compared to a typical camera. The ADNS-2610 sensor is based on optical navigation technology, which measures changes in position by optically acquiring `sequential surface images (frames)` and mathematically determining the `direction and magnitude` of movement. It is designed to track movement rather than capturing still images, it would require additional hardware and software modifications to repurpose the ADNS2610 as a camera.

The ADNS2610 is an optical mouse sensor chip that is perfect for use with the slow TEC-1 due to its limited processing ability. It can be easily obtained by removing it from an old optical mouse. To improve its functionality, a cheap adjustable lens can be mounted on the front as the existing mouse lens is only useful for close range and not useful for capturing images. The chip's output circuit is simple as the data is sent out serially on SDIO (serial data in and out) and SCK (serial clock). This slow serial data stream can be buffered and analyzed. The sensor has an 8x8 pixel matrix, providing 64-bit frames or 8 bytes of data. The optical navigation technology, including the built-in DSP feature, can be later exploited for more complex uses.
