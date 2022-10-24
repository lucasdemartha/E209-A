//https://www.tinkercad.com/things/6U0iG4F33Ee
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000
#define pwm_out (1 << PD6)

int brightness = 0;

ISR(PCINT0_vect){
  if(brightness < 255){
    brightness += 25;
  }
  else
    brightness = 0;

  OCR0A = brightness;
}

int main (void){

  DDRD |= pwm_out;

  PORTD &= ~(pwm_out);
  
  PCICR |= BIT0;
  PCMSK0 = BIT4;

  TCCR0A |= (1 << COM0A1 | 1 << WGM01) | (1 << WGM00);
  TCCR0B = (1 << CS00);
  

  sei();

  for(;;){
    
  } 
}