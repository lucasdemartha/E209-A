//https://www.tinkercad.com/things/eIsVFtUASar

#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int sensor1 = PINB & BIT0;
int sensor2 = PINB & BIT4;

ISR (INT0_vect)
{
 PORTD |= BIT1;
  if (sensor1 == 0) 
  {
    PORTD &= ~(BIT1);
  }
  if (sensor2 == BIT4) 
  {
    PORTD &= ~(BIT1);
  }
}

ISR (INT1_vect)
{
 PORTD &= ~(BIT3);
 PORTD |= BIT2;
      
  if (sensor1 == BIT0) 
  {
    PORTD |= BIT1;
  }
}

int main()
{
  DDRD = BIT1 + BIT2+ BIT3;
  PORTC |= BIT1;
  
  EICRA = BIT0+BIT1;
  EIMSK = BIT0;
  
  PORTD &= ~(BIT1);
  PORTD &= ~(BIT2);
  PORTD &= ~(BIT3);
  
  sei();
  
  for(;;)
  {   
 	if((PINC & BIT0) == BIT0) 
      {
        PORTD |= BIT3;
      }

      if((PINC & BIT1) == BIT1) 
      {
        PORTD &= ~(BIT3);
      }  
  }
}