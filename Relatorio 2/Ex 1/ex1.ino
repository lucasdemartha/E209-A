#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

//https://www.tinkercad.com/things/17siutj23si

ISR (PCINT0_vect)
{
	PORTB |= BIT4;
  	_delay_ms(2000);
  	PORTB &= ~(BIT4);
}
ISR (PCINT1_vect)
{
 	PORTB |= BIT4;
  	_delay_ms(2000);
  	PORTB &= ~(BIT4);        

}
ISR (PCINT2_vect)
{
 	PORTB |= BIT4;
  	_delay_ms(2000);
  	PORTB &= ~(BIT4);        

}
int main()
{
  DDRB = BIT4;
  
  PORTD |= BIT6+BIT2;
  PORTC |= BIT4;
  PORTB |= BIT2;
  
  PCICR |= BIT2 + BIT1 + BIT0;
  PCMSK2 |= BIT6+BIT2;
  PCMSK0 |= BIT2;
  PCMSK1 |= BIT4;
  
  PORTB &= ~(BIT4); 
  
  sei();
  
  for(;;){
  }
  
}