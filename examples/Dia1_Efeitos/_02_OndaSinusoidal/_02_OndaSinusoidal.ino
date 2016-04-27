/*  
    Circuit: Audio output on digital pin 9 on a Uno or similar, pin 11 on MEGA
    check the README or http://sensorium.github.com/Mozzi/
  
    Tim Barrass 2012, CC by-nc-sa.
*/

#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);
#define CONTROL_RATE 64 // powers of 2 please


void setup(){
  startMozzi(CONTROL_RATE); // set a control rate of 64 (powers of 2 please)
  aSin.setFreq(440); // set the frequency
}


void updateControl(){
  // put changing controls in here
}


int updateAudio(){
  return aSin.next(); // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here
}



