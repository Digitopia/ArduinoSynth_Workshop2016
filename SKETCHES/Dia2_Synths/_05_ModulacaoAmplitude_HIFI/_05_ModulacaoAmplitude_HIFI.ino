/*
  Simples modulaçao de amplitude (AM e RM)
  
  AM - onda unipolar (apenas com valores positivos)
  RM - onda bipolar (oscila entre valores negativos e positivos)
  
  circuito:
    potenciometro na porta analogica 0 controla a frequencia da moduladora
*/

#include <MozziGuts.h> // adiciona o basico da biblioteca Mozzi
#include <Oscil.h> // adiciona a classe 'Oscil' para criarmos osciladores
#include <tables/SIN8192_int8.h> // incluimos a tabela com a forma de onda sinusoidal  

#define CONTROL_RATE 512

Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> aPortadora(SIN8192_DATA); 
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> aModuladora(SIN8192_DATA);

void setup() {
  startMozzi(CONTROL_RATE);
  aPortadora.setFreq(220); // definimos uma freq. estatica para a portadora de 220Hz
  aModuladora.setFreq(0); // começamos com uma freq. moduladora de 0Hz, o que significa que nao ha modulaçao
}

void updateControl() { // Funçao onde podemos controlar os nossos osciladores
  aModuladora.setFreq(mozziAnalogRead(0)/4.f);// controlamos a freq. da moduladora (entre 0 e 127 Hz, dai dividir por 4 pq a entrada e de 0~1023)
  // 4.f e o mesmo que 4.0, portanto e do tipo 'flot'
  // se usassemos um inteiro iriiamos obter menos "degraus"
  // experimente a divisao com um inteiro e ouça a diferença
}

int updateAudio() { // Funcao que calcula o sinal de saida 
  // AMPLITUDE MODULATION
  int saida = aModuladora.next() * (aPortadora.next() + 128); // para criar uma mod. de amp. multiplica-se um sinal portador por um modulador
  // RING MODULATION
  //int saida = aModuladora.next() * aPortadora.next();
  
  //NOTA a funçao next() da classe oscilador serve para ler o proximo valor na tabela! 
  
  return saida>>4; // '>>' Le-se bitshift right e e o mesmo que efectuar uma divisao mas e mais eficiente
  // na pasta do workshop ~/utilitarios/_calculadoras/ abra o ficheiro "calculadora_bitshift.pd" e experimente com diferentes valores
  // aqui usamos >>8 porque a portadora (cujo valor max. e 127) vezes a moduladora (cujo valor max. e 255)
  // e igual a 32385, o que iria causar distorçao (digital), uma vez que a saida do Mozzi tem que ser entre -244 e 243
  // portanto 32385>>8 = 128 e portanto menor que 243, evitando assim um sinal distorcido (clipping)
}

void loop() {
  audioHook(); // fills the audio buffer
}

