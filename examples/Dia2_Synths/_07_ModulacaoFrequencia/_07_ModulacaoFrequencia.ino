/*
  Simples modulaçao de frequncia (FM)
  
  circuito:
    potenciometro na porta analogica 0 controla a intensidade de modulaçao
*/

#include <MozziGuts.h> // adiciona o basico da biblioteca Mozzi
#include <Oscil.h> // adiciona a classe 'Oscil' para criarmos osciladores
#include <tables/SIN8192_int8.h> // incluimos a tabela com a forma de onda sinusoidal  

#define CONTROL_RATE 512
#define POTPIN 1

Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> aPortadora(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> aModuladora(SIN8192_DATA);
int freqMod;
int freq = 440;

void setup() {
  startMozzi(CONTROL_RATE);
  //randomSeed(analogRead(5));
  
  aPortadora.setFreq(freq); // definimos uma freq. estatica para a portadora de 220Hz
  aModuladora.setFreq(0); // começamos com uma freq. moduladora de 0Hz, o que significa que nao ha modulaçao
}

void updateControl() { // Funçao onde podemos controlar os nossos osciladores
  aModuladora.setFreq(mozziAnalogRead(POTPIN));
}

int updateAudio() { 
  aPortadora.setFreq(freq+aModuladora.next());
  return aPortadora.next(); 
}

void loop() {
  audioHook(); // fills the audio buffer
}

