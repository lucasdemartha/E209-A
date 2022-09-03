#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main (){

  //EICRA - External Interrupt Control Register A
  /*
  EICRA controla o funcionamento das interrupções INT0 (PD2) e INT1 (PD3)

  BITS 0 e 1 controlam a INT0
  BITS 2 e 3 controlam a INT1
  
  00 -> Ativa interrupção se o pino estiver em nível lógico baixo
  01 -> Ativa interrupção na mudança de estado do pino
  10 -> Ativa interrupção na transição de descida do pino
  11 -> Ativa interrupção na transição de subida do pino

  */

  //Exemplo

  EICRA = BIT0 + BIT3; //EICRA = 0b00001001 
  /*
  Ativa interrupção no PD3 para transição de descida
  Ativa interrupção no PD2 para toda mudança de estado
  */

  //Exercício

  /*
  Ativar interrupção enquanto PD2 tiver em nível lógico baixo
  Ativar interrupção enquanto PD3 sofrer uma transição de subida
  */
    
  EICRA = 0b00001100; //EICRA = BIT2 + BIT3;

  
    
  for(;;){



    
  }


}