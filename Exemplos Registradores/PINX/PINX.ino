/*
Acima da Main, podemos fazer as definições de constantes, import de bibliotecas,
declaração de variações e funções
*/
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main (){

  //Nessa seção (antes do loop infinito), devem ser feitas as instruções
  //correspondentes à void setup (declaração de pinos, habilitação dos resistores
  //de pull-up e declaração da condição inicial das saídas)

  /*
  PINX -> Registrador utilizado para ler os estados das entradas especificadas pelo
  DDRD.
  Pré-requisitos -> Utilizar o DDRD para definir as entradas e Habilitar o resistor
  de Pull-up para estabilizar as entradas.
  Durante a execução do LOOP INFINITO, o PINX armazenará os estados das estradas
  
  */

  /*
  Como verificar se as entradas estão acionadas?
  Se aciona com LOW
    if((PINX & BITX) == 0)

  Se aciona com HIGH
    if((PINX & BITX) == BITX)
  
  */  




  for(;;){

    //Nessa seção (dentro do loop infinito), devem ser feitas as instruções
    //correspondentes à void loop


  }

}