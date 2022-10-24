//https://www.tinkercad.com/things/472KkMsTUx3
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

bool motor_on = false;
float AUX  = 0;

ISR(PCINT0_vect){

  if((PINB & BIT1) == BIT1){
    motor_on = true;
    PORTD |= BIT3;
    OCR0A = AUX;
  }
  
  if((PINB & BIT2) == 0){
	AUX = 0;
    motor_on = false;
    PORTD &= ~(BIT3);
  } 
  
}
  
int main(){
  
	Serial.begin(9600);

	DDRD = BIT3;

	PORTB = BIT2;

	PCICR = BIT0;

	PCMSK0 = BIT1 + BIT2;

    TCCR0A |= (1 << COM0A1 | 1 << WGM01) | (1 << WGM00);

    TCCR0B = (1 << CS02);

	sei();

	for (;;){
		
      if(motor_on){
		  
		  if(AUX <= 254){
			AUX += 31.875; //12,5%
			Serial.print("Velocidade (0 a 255): ");
            Serial.println(AUX);
			_delay_ms(1000);
            if(motor_on == false)
              break;
		  }
          else{
		    OCR0A = 0;
		    motor_on = false;
            PORTD &= ~(BIT3);
            AUX = 0;
        }
	  }
		
	}
  
}



