/*
  Sintese aditiva (simples) com 8 osciladores
  Pressionar botao no pin 2 (ou alterar BUTTONPIN) para randomizar frequencias
*/

#include <MozziGuts.h> // adiciona o basico da biblioteca Mozzi
#include <Oscil.h> // adiciona a classe 'Oscil' para criarmos osciladores
#include <tables/SIN8192_int8.h> // incluimos a tabela com a forma de onda sinusoidal  
#include <mozzi_rand.h>

#define CONTROL_RATE 64
#define BUTTONPIN 2

Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador1(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador2(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador3(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador4(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador5(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador6(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador7(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> oscilador8(SIN8192_DATA);

byte gain[ ] = {255, 0, 0, 0, 0, 0, 0, 0}; // ver 'array' na documentaçao do Arduino
boolean button;
// byte = 8 bits (0 a 255)

void setup() {
  startMozzi(CONTROL_RATE);
  // pressionar o botao 'reset' na placa Arduino para iniciar com freq. aleatoria
  randSeed(); // sem esta linha de codigo o Arduino iria reiniciar sempre com o mesmo valor, para mais info ver referencia da funçao random() 
  pinMode(BUTTONPIN, INPUT);
  
  oscilador1.setFreq((int)random(110, 4400));
  oscilador2.setFreq((int)random(110, 4400));
  oscilador3.setFreq((int)random(110, 4400));
  oscilador4.setFreq((int)random(110, 4400));
  oscilador5.setFreq((int)random(110, 4400));
  oscilador6.setFreq((int)random(110, 4400));
  oscilador7.setFreq((int)random(110, 4400));
  oscilador8.setFreq((int)random(110, 4400));
  /*random() e uma funçao do Arduino  
    para gerar numeros aleatorios nas funçoes updateControl() ou updateAudio()
    e preferivel usar a funçao rand() da biblioteca Mozzi
    mas nao se esqueçam de incluir o header file com a seguinte linha de codigo antes do 'void setup()' juntamente com os outros #include:
    #include <mozzi_rand.h>
  */  
}

void updateControl() { 
  button = digitalRead(BUTTONPIN);
  if(button){
    oscilador1.setFreq((int)random(110, 4400));
    oscilador2.setFreq((int)random(110, 4400));
    oscilador3.setFreq((int)random(110, 4400));
    oscilador4.setFreq((int)random(110, 4400));
    oscilador5.setFreq((int)random(110, 4400));
    oscilador6.setFreq((int)random(110, 4400));
    oscilador7.setFreq((int)random(110, 4400));
    oscilador8.setFreq((int)random(110, 4400));
  }
}

int updateAudio() { 
  int saida = oscilador1.next() 
              + oscilador2.next()
              + oscilador3.next()
              + oscilador4.next()
              + oscilador5.next()
              + oscilador6.next()
              + oscilador7.next()
              + oscilador8.next();  
  return saida;  
}

void loop() {
  audioHook(); // fills the audio buffer
}

