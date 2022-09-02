#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000
#define DESLIGADO 0
#define LIGADO 1
#define ELEVADOR 2
#define TRANSPORTE 3
#define VERIFICACAO 4
#define TRANSPORTE_SAIR 5
char tempo = 0;
char state = DESLIGADO;

void tick(){
    switch(state){
      
        case DESLIGADO:
            PORTD &= ~(BIT0);
            PORTD &= ~(BIT1);
            PORTD &= ~(BIT2);
            PORTD &= ~(BIT3);

            if((PINC & BIT1) == 0){
                state = DESLIGADO;
            }
            else if((PINC & BIT0) == 0){
                state = LIGADO;
            }

            break;

        case LIGADO:
            PORTD |= BIT0;
            if((PINB&BIT0) == BIT0){
                state = ELEVADOR;
                PORTD &= ~(BIT0);
                _delay_ms(3000);
            }
            break;
        case ELEVADOR:
            PORTD |= BIT2;
            if((PINB & BIT1) == BIT1){
                PORTD &= ~(BIT2);
                state = TRANSPORTE;
            }
            break;
        case TRANSPORTE:
            PORTD |= BIT1;
            if((PINB&BIT2) == BIT2){
                state = VERIFICACAO;
            }
            break;
        case VERIFICACAO:
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
            tempo = 0;
            state = TRANSPORTE_SAIR;
            break;
        case TRANSPORTE_SAIR:
            PORTD |= BIT1;
            if((PINB & BIT3) == BIT3){
                state = DESLIGADO;
            }
            break;
      }
}


int main (void){

  DDRD = BIT0 + BIT1 + BIT2 + BIT3; //MOTORES E LAMPADA
  
  PORTC |= BIT0; //botao liga
  PORTC |= BIT1; //botao desliga
  
  //desligando os leds
  PORTD &= ~(BIT0);
  PORTD &= ~(BIT1);
  PORTD &= ~(BIT2);
  PORTD &= ~(BIT3);
  
  
  
  for(;;){
	
    if((PINC & BIT1) == 0){
        state = DESLIGADO;
    }
    
    tick();

  } 
  }