//https://www.tinkercad.com/things/66GzR9mBefP
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

bool esq = false;
bool dir = false;
int temp_esq = 0;
int temp_dir = 0;
int contador = 0;

void botaoDesliga(){
Serial.println("botaoDesliga");
	PORTD &= ~BIT7;
}

void botaoLigaEsquerda(){
Serial.println("botaoLigaEsquerda");
  PORTD |= BIT7;
  PORTD |= BIT2;
}


void botaoLigaDireita(){
Serial.println("botaoLigaDireita");
  PORTD |= BIT7;
  PORTD &= ~BIT2;
}


ISR(PCINT0_vect){
  
   //SENSOR

}
  


int main(){
  
	Serial.begin(9600);

	DDRD = BIT7 + BIT2;

  	PORTC = BIT1;

	PCICR = BIT0;

	PCMSK0 = BIT1 + BIT0;
	 
    TCCR0A |= (1 << WGM01);

    TCCR0B = (1 << CS01);

  	OCR0A = 200;

  	TIMSK0 = 0b00000010;

	
	sei();

    for (;;){
    
    	if((PINC & BIT1) == 0){
			dir = false;
			esq = false;
          	botaoDesliga();
		}
    
    }
		
}



ISR(TIMER0_COMPA_vect){

  contador++;

  if (contador == 5000) 
  {
    contador = 0;
    Serial.println("");
    
	if(esq == true){
	  temp_esq++;
	  Serial.print("");
	  Serial.println(temp_esq);
      if(temp_esq > 16){
        botaoLigaDireita();
        temp_esq = 0;
        esq = false;
      }
    }
	
    if(dir == true){
	  temp_dir++;
	  Serial.print("");
	  Serial.println(temp_dir);
      if(temp_dir > 12){
        botaoLigaEsquerda();
        temp_dir = 0;
        dir = false;
      }
    }
	

  }

}


