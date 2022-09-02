#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main (void){

  DDRD = BIT6 + BIT2; //alarme //motor
  
  PORTB |= BIT1; //botao desliga
  PORTD = PORTD &~ (BIT6);
  PORTD = PORTD &~ (BIT2);
  
  
  
  for(;;){
	
    if ((PINB & BIT0) == BIT0){//Logica pra ligar motor
    
      PORTD |=  BIT2; //PULLDOWN ACIONA EM 1
      PORTD &= ~(BIT6);
    }
    if ((PINB & BIT1) == 0){//Logica pra desligar motor
    
      PORTD = PORTD &~ (BIT2); //PULLUP ACIONA EM 0
    }   
     if ((PINB & BIT3) == BIT3){//Logica pra desligar motor e ligar alarme
    
      PORTD |=  BIT6;
      PORTD = PORTD &~ (BIT2);
    }
  
  }

}