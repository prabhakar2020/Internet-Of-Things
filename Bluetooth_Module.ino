// @Author: Prabhakar G
// Arduino code snippet for controll the LEDs using bluetooth module.
// Requirements : Bluetooth HC-05 modules
//              : Ardunio Uno
//              : 3 LEDs 
//              : Mobiles Application (Optional)
char incomingByte;  // incoming data
int  LED = 12;      // LED pin
int  GREEN = 8;      // LED pin
int  RED = 10;      // LED pin

void setup() {
  // Sets the data rate in bits per second (baud) for serial data transmission. For communicating with the computer, use one of these rates: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200
  Serial.begin(9600); // initialization
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.println("Press 1 to LED ON or 0 to LED OFF...");
}

void loop() {
  if (Serial.available() > 0) {  // if the data came
    incomingByte = Serial.read(); // read byte
    if(incomingByte == '0') {
       digitalWrite(BLUE, LOW);  // if 1, switch LED Off
       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
    }
    if(incomingByte == '1') {
       digitalWrite(BLUE, HIGH); // if 0, switch LED on
       Serial.println("LED ON. Press 0 to LED OFF!");
    }
    if(incomingByte == '0') {
       digitalWrite(GREEN, LOW);  // if 1, switch LED Off
       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
    }
    if(incomingByte == '1') {
       digitalWrite(GREEN, HIGH); // if 0, switch LED on
       Serial.println("LED ON. Press 0 to LED OFF!");
    }
    if(incomingByte == '0') {
       digitalWrite(RED, LOW);  // if 1, switch LED Off
       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
    }
    if(incomingByte == '1') {
       digitalWrite(RED, HIGH); // if 0, switch LED on
       Serial.println("LED ON. Press 0 to LED OFF!");
    }
  }
}
