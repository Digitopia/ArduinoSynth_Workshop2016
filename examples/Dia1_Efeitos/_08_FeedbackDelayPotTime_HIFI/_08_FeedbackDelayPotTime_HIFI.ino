/*  
  Controlar o tamanho do delay com outro potenciometro (versao HIFI, AUDIO_RATE=16384)
*/

#include <MozziGuts.h>
#include <Oscil.h>

#define CONTROL_RATE 64
#define FBKPIN 1 // analog input pin to control feedback
#define DLYPIN 2 // analog input pin to control delay size

#include <AudioDelayFeedback.h>

#define MAXDELAY 256 // maximum delay size
AudioDelayFeedback <MAXDELAY> meuDelay;

Q16n16 delaySize; 
int feedback = -127;

void setup(){
  startMozzi(CONTROL_RATE);
  //setupFastAnalogRead(FASTER_ADC); // use faster analogReads
  meuDelay.setFeedbackLevel(feedback);
}

void updateControl(){
  feedback = (mozziAnalogRead(FBKPIN) >> 2) -128;
  meuDelay.setFeedbackLevel(feedback);
  delaySize = Q8n0_to_Q16n16(mozziAnalogRead(DLYPIN)>>2);
}

int updateAudio(){
  char asig = (getAudioInput() >>2) - 128;
  return meuDelay.next(asig, delaySize) << 5; // the same as the commented line below but more efficient
  // return meuDelay.next(asig, delaySize)  
}

void loop(){
  audioHook();
}
