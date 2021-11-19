# tec-EYE


![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/eye-ball-bw.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/chip1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/lens1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/pinout1.png)

Give the TEC-1 the ability to crudely see using a ADNS2610 chip ripped out of an old optical mouse or spare a few dollars and get a new one. A mounted adjustable lens is a must as the lens in the mouse is for mm range thus useless.

The idea is the capture the serial steam and send it to buffer for analysis. The sensor looks at 8x8 pixels, thus 64 bit frames or 8 bytes. There are some sophisticated DSP features in this chip that can be later exploited for more complex uses. The circuit is also very simple as the data is sent out serially on SDIO (serial data in and out) and SCK (serial port clock).

See this diagram ![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/CCD.jpg)

For vision perhaps we want to recognise, edges, tone, changes between pixels and apply this to AI or motor control. 




## Ref

https://www.sparkfun.com/products/retired/10026

https://hackaday.com/2016/11/21/diy-optical-sensor-breakout-board-makes-diy-optical-mouse/

https://github.com/Tom101222/Adns-3050-Optical-Sensor

https://hackaday.com/2013/04/03/adding-an-optical-mouse-sensor-to-an-autonomous-vehicle/

https://hackaday.com/2009/06/05/ds-optical-mouse-camera/

http://codinglab.blogspot.com/2009/06/nintendods-uses-optical-mouse-as-camera.html

https://www.aliexpress.com/item/32824366788.html

https://www.aliexpress.com/wholesale?catId=0&initiative_id=SB_20200216203520&SearchText=ADNS2610

https://www.homofaciens.de/technics-base-circuits-computer-mouse_en.htm

https://blog.kitware.com/diy-microscopy-optical-mouse-lens-ipad/

https://link.springer.com/chapter/10.1007/978-3-540-89393-6_9

https://en.wikipedia.org/wiki/Odometry

https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DsmxNdfO1eBw&psig=AOvVaw1gd9B_jWds6SV50MgjKuE_&ust=1587609884398000&source=images&cd=vfe&ved=0CA0QjhxqFwoTCOCiquuB--gCFQAAAAAdAAAAABBT

https://www.aliexpress.com/item/4000029077937.html?spm=a2g0o.productlist.0.0.3cca4fecz8coeb&algo_pvid=5d667c4c-dcd7-44d0-8dc9-8f824b6c12be&algo_exp_id=5d667c4c-dcd7-44d0-8dc9-8f824b6c12be-3&pdp_ext_f=%7B%22sku_id%22%3A%2210000000065696039%22%7D


