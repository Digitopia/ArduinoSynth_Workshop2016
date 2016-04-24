/*
  Le um sample em loop e controla o final do loop com um potenciometro
  
  circuito: 
    ligar o potenciometro na entrada analogica 0
*/

#include <MozziGuts.h>
#include <Sample.h> // incluir sampler
#include <samples/burroughs1_18649_int8.h> // incluir o sample desejado

#include <IntMap.h>
const IntMap aMap(0,1023,10,18649);

Sample <BURROUGHS1_18649_NUM_CELLS, AUDIO_RATE> aSample(BURROUGHS1_18649_DATA);

void setup() {
  startMozzi();
  aSample.setFreq(BURROUGHS1_18649_SAMPLERATE / (float) BURROUGHS1_18649_NUM_CELLS); // tocar ficheiro na velocidade com que foi gravado e exportado
  aSample.setLoopingOn();
  aSample.start();
}

void updateControl(){
  aSample.setEnd(aMap(mozziAnalogRead(0)));
}

int updateAudio(){
  return aSample.next()<<4;
}

void loop() {
  audioHook();
}
