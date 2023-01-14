# tec-EYE


![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/eye-ball-bw.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/chip1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/lens1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/pinout1.png)
![](https://github.com/SteveJustin1963/tec-EYE/blob/master/pics/CCD.jpg)
![image](https://user-images.githubusercontent.com/58069246/212500085-2060f0c6-c37e-4ae9-bb69-3b08d08ecb71.png)


The ADNS-2610 is an optical mouse sensor chip and it is designed to track the movement of a surface, and it can be used to capture basic images with very limited resolution and image quality compared to a typical camera. The ADNS-2610 sensor is based on optical navigation technology, which measures changes in position by optically acquiring `sequential surface images (frames)` and mathematically determining the `direction and magnitude` of movement. It is designed to track movement rather than capturing still images, it would require additional hardware and software modifications to repurpose the ADNS2610 as a camera.

The ADNS2610 is an optical mouse sensor chip that is perfect for use with the slow TEC-1 due to its limited processing ability. It can be easily obtained by removing it from an old optical mouse. To improve its functionality, a cheap adjustable lens can be mounted on the front as the existing mouse lens is only useful for close range and not useful for capturing images. The chip's output circuit is simple as the data is sent out serially on SDIO (serial data in and out) and SCK (serial clock). This slow serial data stream can be buffered and analyzed. The sensor has an 8x8 pixel matrix, providing 64-bit frames or 8 bytes of data. The optical navigation technology, including the built-in DSP feature, can be later exploited for more complex uses.

from the SparkFun ElectronicS example we can see the part of the code that handles the serial data communication between the ATmega328 (Arduino) microcontroller and the ADNS2620 sensor is the following:
```
char ADNS2620::read(char address)
{
    char value=0;
    pinMode(_sda, OUTPUT); //Make sure the SDIO pin is set as an output.
    digitalWrite(_scl, HIGH); //Make sure the clock is high.
    address &= 0x7F;    //Make sure the highest bit of the address byte is '0' to indicate a read.
 
    //Send the Address to the ADNS2620
    for(int address_bit=7; address_bit >=0; address_bit--){
        digitalWrite(_scl, LOW);  //Lower the clock
        pinMode(_sda, OUTPUT); //Make sure the SDIO pin is set as an output.
        
        // If the current bit is a 1, set the SDIO pin. If not, clear the SDIO pin
        // sets the SDA line to the value of the bit being sent (either HIGH or LOW), then pulses the SCL line to send the bit.
	
	    if(address & (1<<address_bit)){
            digitalWrite(_sda, HIGH);
        }
        else{
            digitalWrite(_sda, LOW);
        }
        delayMicroseconds(10);
        digitalWrite(_scl, HIGH);
        delayMicroseconds(10);
    }
    
    delayMicroseconds(120);   //Allow extra time for ADNS2620 to transition the SDIO pin (per datasheet)
    //Make SDIO an input on the microcontroller
    pinMode(_sda, INPUT);	//Make sure the SDIO pin is set as an input.
	digitalWrite(_sda, HIGH); //Enable the internal pull-up
        
    // Send the Value byte to the ADNS2620
    for(int value_bit=7; value_bit >= 0; value_bit--){
        digitalWrite(_scl, LOW);  //Lower the clock
        delayMicroseconds(10); //Allow the ADNS2620 to configure the SDIO pin
        digitalWrite(_scl, HIGH); //Raise the clock
        delayMicroseconds(10); //Allow the ADNS2620 to configure the SDIO pin
        if(digitalRead(_sda)){
            value |= (1<<value_bit);
        }
    }
    return value;
}
```
This code is for the read() function which is used for reading data from a register of the ADNS2620 sensor. The function takes an address as input, sets the pin mode for the SDA line to output and the clock line to input. It also sets the clock line high. The address is then ANDed with 0x7F to ensure the highest bit is set to '0' to indicate a read. After that it sends the address to the ADNS2620 by iterating over the bits of the address and sending each one using delayMicroseconds() function to create a pause between setting and reading the SDIO pin, then it reads the value byte from the ADNS2620 by iterating over the bits of the value byte and reading each one using digitalRead() function to read the voltage level of the specified pin.

