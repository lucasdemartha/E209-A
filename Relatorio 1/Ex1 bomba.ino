#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main (){

  DDRB = BIT0;
  PORTC |= BIT1;
  
  
  for(;;){
	
    //MANUAL
    
    if((PIND&BIT3) == 0){ //CHAVE SELETORA == 0 
      if((PINC&BIT0) == BIT0){
       	 PORTB |= BIT0;
      }
      if((PINC&BIT1) == BIT1){
         PORTB &= ~(BIT0);
      }
    }
    
    //AUTOMATICO
    
    if((PIND&BIT3) == BIT3){ //CHAVE SELETORA == 1
      if((PIND&BIT4) == 0){
      	PORTB |= BIT0;
      }
      if((PIND&BIT5) == BIT5){
       	PORTB &= ~(BIT0); 
      }
    }

  }

}