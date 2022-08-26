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
  O PORTX é o registrador utilizado para definir os estados dos pinos colocados
  como saída e o estado do resistor de pull-up para os pinos definidos como entrada.
  Obrigatoriamente, antes de registrador, deve ser declarado quais são os pinos 
  de entrada e saída.
  */

  //Exemplo
  DDRB = BIT1 + BIT4 + BIT7; // Pinos 1, 4 e 7 do Portal B são de saída
  //Para acionar um pino, basta colocar seu bit do registrador em nível lógico alto
  //e para desacioná-lo, basta colocar seu bit do registrador em nível lógico baixo

  //Acionar o pino 4 do portal B
  PORTB = BIT4;
  //Porém, a instrução acima desliga os outros pinos de saída
  
  //Utilizando o conceito de máscara
  /*
  PORTB = 0b10000010 (Acionados os Pinos 1 e 7)
  Desejo = 0b00010000 (Ativar o Pino 4)
  */  

  PORTB = PORTB | BIT4; //Mantém o que está no PORTB alterando somente o Pino 4
  //PORTB |= BIT4;

  DDRC = BIT3 + BIT5;
  //Acionar o pino 5 mantendo o estado dos outros
  PORTC |= BIT5;

  //Desacionar o pino 4 do Portal B, mantendo os pinos 1 e 7 acionados
  PORTB = PORTB & ~(BIT4); 
  PORTB &= ~(BIT4);

  /*
  PORTB =  0b10010010 (Acionados os Pinos 1, 4 e 7)
  Desejo = 0b1XX0XX1X (Desacionar o Pino 4)
  */     
  
  for(;;){

    //Nessa seção (dentro do loop infinito), devem ser feitas as instruções
    //correspondentes à void loop


  }

}