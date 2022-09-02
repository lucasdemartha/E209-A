#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main (void){

  DDRD = BIT0 + BIT1 + BIT2 + BIT3; //MOTORES E LAMPADA
  
  PORTC |= BIT0; //botao liga
  PORTC |= BIT1; //botao desliga
  
  //desligando os leds
  PORTD &= ~(BIT0);
  PORTD &= ~(BIT1);
  PORTD &= ~(BIT2);
  PORTD &= ~(BIT3);
  
  char tempo = 0;
  
  for(;;){
	
    if((PINC&BIT1) == 0){
      PORTD &= ~(BIT0);
  	  PORTD &= ~(BIT1);
  	  PORTD &= ~(BIT2);
  	  PORTD &= ~(BIT3);
    }
    else{
      if((PINC&BIT0) == 0){
        PORTD |= BIT0;
      }
      else if((PINB&BIT0) == BIT0){
        PORTD &= ~(BIT0);
        _delay_ms(3000);
        PORTD |= BIT2;
      }
      else if((PINB&BIT1) == BIT1){
        PORTD &= ~(BIT2);
        PORTD |= BIT1;
      }
      else if((PINB&BIT2) == BIT2){
        PORTD &= ~(BIT1);
        while(tempo < 3){
              if((PINC&BIT1) == BIT1){
                  PORTD |= BIT3;
                  _delay_ms(500);
                  PORTD &= ~(BIT3);
                  _delay_ms(500);
                  tempo++;
              }
              else{
                  PORTD &= ~(BIT3+BIT1);
                  break;
              }
        }
        PORTD |= BIT1;
      }
      else if((PINB&BIT3) == BIT3){
        PORTD &= ~(BIT0);
        PORTD &= ~(BIT1);
        PORTD &= ~(BIT2);
        PORTD &= ~(BIT3);
      }

    }
  }

}