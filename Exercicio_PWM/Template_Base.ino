#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main() {

  //Declaração das Saídas
  DDRD = BIT1 + BIT2 + BIT3; //Avanço PD1 | Recuo PD2 | Motor PD3

  //Declaração de Pull-up
  PORTC = BIT1;

  //Configurações das Interrupções Externas (INT0 e INT1)

  //Configurações das Interruções PCINT
  PCICR = BIT0; //Habilita interrupções nos portal B
  PCMSK0 = BIT0 + BIT1; //Habilita interrupção nos pinos 0 e 1 do Portal B
  
  //Configurações dos Timers

  

  //Interrupção global
  sei();

  //LOOP INFINITO
  for (;;) {

    //Botão Liga
    if(PINC & BIT0 == BIT0){

      PORTD |= BIT3;

    }

    //Botão Desliga
    if(PINC & BIT1 == 0){

      PORTD &= ~BIT3;

    }
  }
}

 //Interrupção PB0 e PB1
ISR(PCINT0_vect){

  //S1 Acionado
  if((PINB & BIT0 == BIT0) && (PORTD & BIT2 == 0)){

    PORTD |= BIT1; //Ativa o Sinalizador de Avanço

  }

  //S1 Desacionado
  if(PINB & BIT0 == 0){

    PORTD &= ~(BIT1 + BIT2); //Desativa o Sinalizador de Avanço e de Recuo
  
  }

  //S2 Acionado
  if(PINB & BIT1 == BIT1){

    PORTD &= ~(BIT1 + BIT3); //Desativa o Sinalizador de Avanço e Motor
    PORTD |= BIT2; // Ativa o Sinalizador de Recuo

  }

}