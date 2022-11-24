//https://www.tinkercad.com/things/3tJWLJI3wrw?sharecode=dRGMR9hltqn7Nukik1hSx_WEfSb6TBtKB6Qm-_Nva04
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int cont = 0;
bool direita = false;
bool esquerda = false;
int timer_dir = 0;
int timer_esq = 0;

void desliga_motor(){
Serial.println("desliga_motor");
	PORTD &= ~BIT7;
}

void liga_motor_esquerda(){
Serial.println("liga_motor_esquerda");
  PORTD |= BIT7;
  PORTD |= BIT2;
}


void liga_motor_direita(){
Serial.println("liga_motor_direita");
  PORTD |= BIT7;
  PORTD &= ~BIT2;
}


ISR(PCINT0_vect){
  
   Serial.println("PCINT0_vect");
  
  //SENSOR 1 (PARA POR 5.5seg)
  if((PINB & BIT0) == BIT0){
	  Serial.println("direita = true");
    direita = true;
    desliga_motor();
  }
  
  ////SENSOR 1 (PARA POR 7.5seg)
  if((PINB & BIT1) == 0){
	  Serial.println("esquerda = true;");
    esquerda = true;
    desliga_motor();
  } 
  
}
  


int main(){
  
	Serial.begin(9600);

	//DECLARANDO SAIDA
	DDRD = BIT7 + BIT2;
	//PULL UP EM PB1 e PC1
	PORTB = BIT1;
  	PORTC = BIT1;

	//CONFIGURANDO B1 + B2 INTERRUPÇÃO
	PCICR = BIT0;
	PCMSK0 = BIT1 + BIT0;
	
    //CONFIGURANDO MODO DE FUNCIONAMENTO
    TCCR0A = 0b00000010; //comparação
    TCCR0B = 0b00000010; //ps de 8
  	OCR0A = 200;
  	TIMSK0 = 0b00000010;

	//habilita interrupção
	sei();
    for (;;){
    
    	if((PINC & BIT1) == 0){
			direita = false;
			esquerda = false;
          	desliga_motor();
		}
		
		if((PINC & BIT0) == BIT0)
          	liga_motor_direita();
    
    }
		
}



ISR(TIMER0_COMPA_vect){

  //o que acontece quando estourar 100us
  cont++;

  if (cont == 5000) // foi contato 5000 estouros que é 0.5s
  {
    cont=0;
    Serial.println("0.5 segundo");
    
	//se bateu no sensor da direita fica 5.5 segundos parados
    if(direita == true){
	  timer_dir++;
	  Serial.print("Timer direita: ");
	  Serial.println(timer_dir);
      if(timer_dir == 11){
        liga_motor_esquerda();
        timer_dir = 0;
        direita = false;
      }
    }
	
	//se bateu no sensor da esquerda fica 5.5 segundos parados
	if(esquerda == true){
	  timer_esq++;
	  Serial.print("Timer esq: ");
	  Serial.println(timer_esq);
      if(timer_esq == 15){
        liga_motor_direita();
        timer_esq = 0;
        esquerda = false;
      }
    }

  }

}


