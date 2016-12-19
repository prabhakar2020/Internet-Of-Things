// @Author: Prabhakar G
// Initialize the Arduino ports
int trig=9;
int echo=10;
int blue=7;
int green=6;
int red=5;

void setup() {
    // put your setup code here, to run once:
    // Sets the data rate in bits per second (baud) for serial data transmission. For communicating with the computer, use one of these rates: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200
    
    Serial.begin(9600);
    // Register the Arduino ports for OUTPUT and INPUT operations
    pinMode(blue,OUTPUT);
    pinMode(trig,OUTPUT);
    // echo pin which will read the ultra sonic pulses, so it should be INPUT pin
    pinMode(echo,INPUT);  
    digitalWrite(blue,LOW);
    pinMode(green,OUTPUT);
    pinMode(red,OUTPUT);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
}

void loop() {
    // put your main code here, to run repeatedly:
    int duration,distance;
    digitalWrite(trig,HIGH);
    delay(100);
    digitalWrite(trig,LOW);
    
    // Find the duration require to receive the ultra sonic pulses
    duration = pulseIn(echo,HIGH); 
    // Covert the duration into Distance 
    distance = (duration/2)/29.1;
    Serial.print(distance);
    Serial.println("CM");
    delay(100);
    // Run the user logic if the Distance is <= 15 centimeeters
    if((distance<=15)){
      if((distance>=1)){
          digitalWrite(blue,HIGH);
          digitalWrite(green,LOW);
          digitalWrite(red,HIGH);
      }
    }else{
      digitalWrite(blue,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
    }
}
