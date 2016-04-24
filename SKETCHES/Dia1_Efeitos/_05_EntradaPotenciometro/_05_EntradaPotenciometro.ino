int potPin = 1; // set analog pin to read values from

void setup(){
  Serial.begin(9600); // Start serial communication between PC and Arduino
}

void loop(){
  int val = analogRead(potPin); // read voltage on analog pin 
  Serial.println(val); // print to console
}
