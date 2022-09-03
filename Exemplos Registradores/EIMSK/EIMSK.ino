#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main (){

  //EIMSK - External Interrupt Mask Register
  /*
  EIMSK habilita o funcionamento das interrupções INT0 (PD2) e INT1 (PD3)

  BIT0 habilita a INT0
  BIT1 habilita a INT1
  */

  //Exemplo

  EICRA = BIT0 + BIT3; //EICRA = 0b00001001 
  /*
  Ativa interrupção no PD3 para transição de descida
  Ativa interrupção no PD2 para toda mudança de estado
  */
  EIMSK = BIT0 + BIT1; //Habilita a geração de interrupções em PD2 e PD3

  //EIMSK = BIT0; Habilita geração de interrupções somente em PD2
    
  //EIMSK = BIT1; Habilita geração de interrupções somente em PD3

  
    
  for(;;){



    
  }


}