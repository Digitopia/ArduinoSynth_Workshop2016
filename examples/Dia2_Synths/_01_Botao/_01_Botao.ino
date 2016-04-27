/*
  Ler o valor de um botao
  Para tal e necessario usar uma resitencia (10KΩ por ex.)
  ligado num circuito pull-down (ou pull-up se quisermos receber por defeito
  o valor "1" e, ao carregarmos no botao, obter o valor "0")
*/
#define BUTTONPIN 14// definir o pin (digital) para o botao

void setup(){
  Serial.begin(9600); // comecar comunicacao serial
  // Baud Rate = 9600 (9600 simbolos por segundo)  
  
  pinMode(BUTTONPIN, INPUT); // define o pin como entrada
}

void loop(){
  boolean val = digitalRead(BUTTONPIN); // ler o valor no pin
  // boolean e a variavel mais pequena, ocupa apenas 1-bit
  // 0 = false e 1 = true
  // variable scope: uma variavel declarada no ciclo loop apenas 
  // e visivel dentro do bloco de codigo para a funcao loop
  Serial.println(val);  
}
