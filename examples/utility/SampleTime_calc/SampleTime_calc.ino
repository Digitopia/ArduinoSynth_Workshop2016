// Prints a delay time to the console given a number of samples

#include <MozziGuts.h>

float sampleTime; 
void setup(){
  Serial.begin(9600);
}

void loop(){
  int samples = Serial.parseInt();
  if(samples!=0){
    Serial.print("delay time for ");
    Serial.print(samples);
    Serial.print(" samples is ");
    Serial.print((float)samples/AUDIO_RATE * 1000.f);
    Serial.println(" ms");
  }
}

