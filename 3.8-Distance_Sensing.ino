//
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}
void loop() 
{
  
 //Red
 if(distance >= 0 && distance <= 10){
 analogWrite(11,255);
 analogWrite(10,0);
 analogWrite(9,0);
 }

 //yellow
 else if (distance >= 11  && distance <= 30){
 analogWrite(11,255);
 analogWrite(10,75);
 analogWrite(9,0);
 }
 //Green
 else if(distance >=31 && distance <=400){
 analogWrite(11,0);
 analogWrite(10,255);
 analogWrite(9,0);
}
  //Unkown
  if(distance >=400 ){
  Serial.println("Distance: unkown ");
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,0);
}
  else{
  // Displays the distance on the Serial Monitor
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
}
  
