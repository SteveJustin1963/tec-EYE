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



## software
```
Write a function named "read" that takes in an "address" variable.
Declare a variable named "value" and set it to 0.
Set the pin mode for the SDA line to OUTPUT and the clock line to INPUT.
Set the clock line to HIGH.
AND the "address" variable with 0x7F and store the result in "address."
Begin a loop that iterates 8 times.
Within the loop, set the clock line to LOW.
Set the pin mode for the SDA line to OUTPUT.
If the current bit of "address" is 1, set the SDA line to HIGH. If not, set it to LOW.
Delay for 10 microseconds.
Set the clock line to HIGH.
Delay for 10 microseconds.
Repeat steps 7-12 for all 8 bits of the "address" variable.
Delay for 120 microseconds.
Set the pin mode for the SDA line to INPUT and enable the internal pull-up.
Begin a loop that iterates 8 times.
Within the loop, set the clock line to LOW.
Delay for 10 microseconds.
Set the clock line to HIGH.
Delay for 10 microseconds.
If the value read from the SDA line is HIGH, OR "value" with the current bit of the loop.
Repeat steps 16-21 for all 8 bits of the "value" variable.
Return the "value" variable.
```
## sudo 
```
// Initialize serial port with a baud rate of 4800
Serial.begin(4800);

// Define function to read from sensor
int read(int address) {
  // Declare variable to hold sensor output
  int value = 0;

  // Set pin modes for SDIO and SCK lines
  pinMode(SDIO, OUTPUT);
  pinMode(SCK, INPUT);

  // Set SDIO and SCK lines to initial states
  digitalWrite(SDIO, HIGH);
  digitalWrite(SCK, LOW);

  // AND the address with 0x7F to ensure MSB is 0
  address &= 0x7F;

  // Loop through each bit of the address
  for (int i = 0; i < 8; i++) {
    // Set SCK line to LOW
    digitalWrite(SCK, LOW);

    // Set SDIO line to current bit of address
    digitalWrite(SDIO, bitRead(address, i));

    // Delay for 10 microseconds
    delayMicroseconds(10);

    // Set SCK line to HIGH
    digitalWrite(SCK, HIGH);

    // Delay for 10 microseconds
    delayMicroseconds(10);
  }

  // Delay for 120 microseconds
  delayMicroseconds(120);

  // Set pin mode for SDIO line to INPUT and enable internal pull-up
  pinMode(SDIO, INPUT_PULLUP);

  // Loop through each bit of the sensor output
  for (int i = 0; i < 8; i++) {
    // Set SCK line to LOW
    digitalWrite(SCK, LOW);

    // Delay for 10 microseconds
    delayMicroseconds(10);

    // Set SCK line to HIGH
    digitalWrite(SCK, HIGH);

    // Read SDIO line and OR it with current bit of value
    value |= (digitalRead(SDIO) << i);

    // Delay for 10 microseconds
    delayMicroseconds(10);
  }

  // Send sensor output over serial port
  Serial.write(value);

  // Return sensor output
  return value;
}
```

## C code for reading data from the ADNS2610 sensor using integer logic and bit shifting:
```
// Initialize serial port with a baud rate of 4800
Serial.begin(4800);

// Define function to read from sensor
int read(int address) {
  // Declare variable to hold sensor output
  int value = 0;

  // Set pin modes for SDIO and SCK lines
  pinMode(SDIO, OUTPUT);
  pinMode(SCK, INPUT);

  // Set SDIO and SCK lines to initial states
  digitalWrite(SDIO, HIGH);
  digitalWrite(SCK, LOW);

  // AND the address with 0x7F to ensure MSB is 0
  address &= 0x7F;

  // Loop through each bit of the address
  for (int i = 0; i < 8; i++) {
    // Set SCK line to LOW
    digitalWrite(SCK, LOW);

    // Set SDIO line to current bit of address
    digitalWrite(SDIO, (address >> i) & 1);

    // Delay for 10 microseconds
    delayMicroseconds(10);

    // Set SCK line to HIGH
    digitalWrite(SCK, HIGH);

    // Delay for 10 microseconds
    delayMicroseconds(10);
  }

  // Delay for 120 microseconds
  delayMicroseconds(120);

  // Set pin mode for SDIO line to INPUT and enable internal pull-up
  pinMode(SDIO, INPUT_PULLUP);

  // Loop through each bit of the sensor output
  for (int i = 0; i < 8; i++) {
    // Set SCK line to LOW
    digitalWrite(SCK, LOW);

    // Delay for 10 microseconds
    delayMicroseconds(10);

    // Set SCK line to HIGH
    digitalWrite(SCK, HIGH);

    // Read SDIO line and OR it with current bit of value
    value |= (digitalRead(SDIO) << i);

    // Delay for 10 microseconds
    delayMicroseconds(10);
  }

  // Send sensor output over serial port
  Serial.write(value);

  // Return sensor output
  return value;
}
```
## forth code
```
\ Define constants for SDIO and SCK pins
: SDIO 4 ;
: SCK 5 ;

: init-serial 4800 serial-begin ;

: set-pin-modes
  SDIO OUTPUT pin-mode
  SCK INPUT pin-mode ;

: set-initial-states
  SDIO HIGH digital-write
  SCK LOW digital-write ;

: send-address ( addr -- )
  0x7F and
  0 8 0 do
    SCK LOW digital-write
    SDIO swap i rshift 1 and digital-write
    10 us delay
    SCK HIGH digital-write
    10 us delay
  loop ;

: delay-120
  120 us delay ;

: set-sdio-input
  SDIO INPUT_PULLUP pin-mode ;

: read-sensor-output ( -- n )
  0
  0 8 0 do
    SCK LOW digital-write
    10 us delay
    SCK HIGH digital-write
    SDIO digital-read swap i lshift or swap
    10 us delay
  loop ;

: read ( addr -- n )
  set-pin-modes
  set-initial-states
  send-address
  delay-120
  set-sdio-input
  read-sensor-output
  dup serial-write ;

: read-sensor ( addr -- value )
  init-serial
  read ;
```
