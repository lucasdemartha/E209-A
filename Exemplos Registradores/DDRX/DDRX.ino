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
  DDRX -> Definir se os pinos serão de entrada ou de saída
    Se o bit = 0 - Entrada / Se o bit = 1 - Saída
  
  DDRB -> Definição dos pinos do portal B
  DDRC -> Definição dos pinos do portal C
  DDRD -> Definição dos pinos do portal D
  */  

  DDRB = 0h65; //Pinos 1, 3, 4 e 7 são de entrada e Pinos 0, 2, 5 e 6 são de saída 
  DDRB = 0b01100101; //DDRB = BIT0 + BIT2 + BIT5 + BIT6
  //Colocar os pinos 2, 4 e 6 do D como saída
  DDRD = 0b01010100; //DDRD = BIT2 + BIT4 + BIT6
  //Colocar os pinos 1, 5 e 6 do Portal C como Saída
  DDRC = 0b01100010; //DDRC = BIT1 + BIT5 + BIT6

  for(;;){

    //Nessa seção (dentro do loop infinito), devem ser feitas as instruções
    //correspondentes à void loop


  }

}