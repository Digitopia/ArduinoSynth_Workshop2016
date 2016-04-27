/*  
  Adicionar feedback com delay aos sons captados pelo piezo
*/

#include <MozziGuts.h>
#include <mozzi_fixmath.h> // needed for other variable types used by AudioDelayFeedback

#include <AudioDelayFeedback.h>

AudioDelayFeedback <128> meuDelay;

void setup(){
  startMozzi();
  meuDelay.setFeedbackLevel(-124); // maximo = -128, minimo = 127
}

void updateControl(){
}

int updateAudio(){
  int asig = getAudioInput() / (1024/488) - 244; // convertin from 0~1023 to -244~243
  return meuDelay.next(asig); // read delay line
}

void loop(){
  audioHook();
}



