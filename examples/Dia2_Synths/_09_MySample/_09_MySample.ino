/*
  Le um sample em loop e controla o final do loop com um potenciometro
  
  circuito: 
    ligar o potenciometro na entrada analogica 0
*/

#include <MozziGuts.h>
#include <Sample.h> // incluir sampler
#include "bike.h" // incluir o sample desejado

#include <IntMap.h>
const IntMap aMap(0,1023,10,18649);

Sample <BIKE_20608_NUM_CELLS, AUDIO_RATE> aSample(BIKE_20608_DATA);

void setup() {
  startMozzi();
  aSample.setFreq(BIKE_20608_SAMPLERATE / (float) BIKE_20608_NUM_CELLS); // tocar ficheiro na velocidade com que foi gravado e exportado
  aSample.setLoopingOn();
  aSample.start();
}

void updateControl(){
  aSample.setEnd(aMap(mozziAnalogRead(0)));
}

int updateAudio(){
  return aSample.next();
}

void loop() {
  audioHook();
}
