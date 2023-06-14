; extracted from sparkfun

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
 
