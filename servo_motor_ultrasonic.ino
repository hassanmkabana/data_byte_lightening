/*code by Hassan
 written on 4/02/2020
 */
// include the servo library
  #include <Servo.h>
// declare the servo pin
 int servoPin = 8;
 int delay_time = 1000;
 const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
 const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
 
// define variables
 long duration;
 int distance;
 int safetyDistance;
 
   // create a servo object
 Servo servo1;

   void setup() {
    Serial.begin(9600); // starting Serial Terminal
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
    // we need to attach the servo to the used pin number
    servo1.attach(servoPin);
 }

void loop() {
    // clears the trigpin
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  //sets the trigpin on high state for 10 microseconds
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  //duration
  duration = pulseIn(echoPin, HIGH);
  // calculate the distance
  distance = duration*0.034/2;
  safetyDistance = distance;
  if(safetyDistance<=20){
    digitalWrite(servoPin, HIGH);
    servo1.write(0);
     delay(delay_time);
  }
  else{
    digitalWrite(servoPin,LOW);
    servo1.write(90);
     delay(delay_time);
  }
  Serial.print("Distance:  ");
  Serial.print(distance);
}
  //prints the distance on the serial monitor
 /* Serial.print("Distance:  ");
  Serial.print(distance);
  // make servo go to 0 degrees
  servo1.write(0);
  delay(delay_time);
  // make servo go to 90 degrees
  servo1.write(90);
  delay(delay_time);
  // make servo go to 180 degrees
  servo1.write(180);
  delay(delay_time);
  // make servo go to 90 degrees
  servo1.write(90);
  delay(delay_time);
}*/
