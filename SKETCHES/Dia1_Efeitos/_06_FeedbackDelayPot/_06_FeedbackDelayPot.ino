/*  
  Controlar a quantidade de feedback com um potenciometro
*/

#include <MozziGuts.h>
#include <mozzi_fixmath.h> // needed for other variable types used by AudioDelayFeedback

#include <AudioDelayFeedback.h>

AudioDelayFeedback <128> meuDelay;

int feedback;

void setup(){
  startMozzi();
  meuDelay.setFeedbackLevel(-124); // maximo = -128, minimo = 127
}

void updateControl(){
  // FEEDBACK CONTROL
  // read analog pin 1 
  feedback = (mozziAnalogRead(1) >> 2) - 128;
  //feedback = (mozziAnalogRead(1) / 4) - 128; // similar to the above calculation but less eficient
  // set feedback level
  meuDelay.setFeedbackLevel(feedback);
}

int updateAudio(){
  char asig = (getAudioInput() >>2) - 128; // converting from 0~1023 to -244~243
  return meuDelay.next(asig); // read delay line
}

void loop(){
  audioHook();
}



