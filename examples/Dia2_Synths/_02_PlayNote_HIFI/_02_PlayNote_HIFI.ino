/*
  Este sketch usa o botao para tocar uma nota
  e um potenciometro para seleccionar a altura da nota 
  (OUTPUT MODE = HIFI)
*/
#include <MozziGuts.h> // incluir Mozzi
#include <Oscil.h> // incluir classe para osciladores
#include <tables/sin2048_int8.h> // tabela de uma onda sinusoidal
#include <ADSR.h> // incluir classe para envolvente ADSR (Attacl, Decay, Sustain, Release)

#define CONTROL_RATE 128
#define BUTTONPIN 2 // definir o pin (digital) para o botao

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> oscillator(SIN2048_DATA); // construtor da classe "Oscil": cira um objecto do tipo Oscil chamado oscillator
ADSR <CONTROL_RATE, AUDIO_RATE> envelope; // construtor da classe ADSR: cria um objecto to tipo ADSR chamado envelope

boolean button; // variavel booleana para guardar o estado do botao

unsigned int attack_ms = 25; // attack time (ms)
unsigned int decay_ms = 100; // decay time (ms)
unsigned int sustain_ms = 100; // must be bigger than 0 (see Mozzi ref > Class List > ADSR > setSustainTime)
unsigned int release_ms = 2000; // release time (ms) 

void setup(){
  startMozzi(CONTROL_RATE);
  pinMode(BUTTONPIN, INPUT); // define o pin como entrada
  oscillator.setFreq(220); // definir a frequencia do oscilador
  envelope.setADLevels(255,64); // definir ganho do ataque e decay (0~255) ver tambe setAttackLevel(), setDecayLevel(), etc...
  envelope.setTimes(attack_ms,decay_ms,sustain_ms,release_ms); // definir tempos de A D S R 
}

void updateControl(){
  button = digitalRead(BUTTONPIN);
  // esta estrutura "if" corre a funcao "envelope.noteOn()" se o botao for pressionado E(&&) a envolvente estiver desactivada
  if(button == true){ // short version: if(botao){...}
      envelope.noteOn(); // activa a envolvente 
  }
  else{
    envelope.noteOff();
  }
}

int updateAudio(){
  return (oscillator.next() * envelope.next()) >> 4; // return an int signal centred around 0
}

void loop(){
  audioHook();
}
