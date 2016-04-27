/*  ENTRADA DE SOM UTILIZANDO UM PIEZO
  
  Mozzi by Tim Barrass 2013, CC by-nc-sa.
*/

#include <MozziGuts.h>

void setup(){
  startMozzi();
}

void updateControl(){
}

int updateAudio(){
  int asig = getAudioInput(); // range 0-1023
  // output range in STANDARD mode is -244 to 243, 
  asig = asig / (1024/488) - 244; // convertin from 0~1023 to -244~243
    
  return asig;
}


void loop(){
  audioHook();
}





