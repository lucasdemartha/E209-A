#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int main (){
  /*
  Registradores TCCR -> São utilizados para configurar o modo de funcionamento e a frequência do temporizador
  */
  //Configuração do modo de funcionamento
  TCCR0A = 0b00000010; //Temporizador no modo de comparação
  TCCR0A = 0b00000000; //Temporizador no modo normal
  TCCR0A = 0b10000011; //Temporizador no modo PWM não-invertido
  TCCR0A = 0b11000011; //Temporizador no modo PWM invertido

  //Definição do Clock - TCCR0B
  /*
  TCCR0B = 0b00000001 - Prescaler de 1 - Frequencia de 16 MHz - Período de 62,5 ns
  TCCR0B = 0b00000010 - Prescaler de 8 - Frequencia de 2 MHz - Período de 500 ns
  TCCR0B = 0b00000011 - Prescaler de 64 - Frequencia de 250 kHz - Período de 4 us
  TCCR0B = 0b00000100 - Prescaler de 256 - Frequencia de 62,5 kHz - Período de 16 us
  TCCR0B = 0b00000101 - Prescaler de 1024 - Frequencia de 15,625 kHz - Período de 64 us
  */  

  TCCR0B = 0b00000100; //Clock de 62,5 KHz, ou seja, um prescaler de 256;

  //Definição do limite de comparação - Modo de Comparação

  OCR0A = Limite de comparação A
  OCR0B = Limite de comparação B

  //Definição do Duty Cycle - Modo PWM não-invertido

  OCR0A = (DutyCycle Desejado / 256) * 100; //(DC em Porcentagem)
  OCR0B = (DutyCycle Desejado / 256) * 100; //(DC em Porcentagem)

  //Definição do Duty Cycle - Modo PWM invertido

  OCR0A = 255 - ((DutyCycle Desejado / 256) * 100); //(DC em Porcentagem)
  OCR0B = 255 - ((DutyCycle Desejado / 256) * 100); //(DC em Porcentagem)

  //Declaração de Interrupção - Não precisa no PWM
  TIMSK0 = 0b00000100; //Ativa interrupção de comparação B
  TIMSK0 = 0b00000010; //Ativa interrupção de comparação A
  TIMSK0 = 0b00000001; //Ativa interrupção de estouro em 255

  sei();

 
  for(;;){  }
}

ISR(TIMER0_COMPA_vect){

  //O que acontece se estourar o limite do comparador A?

}

ISR(TIMER0_COMPB_vect){

  //O que acontece se estourar o limite do comparador B?

}

ISR(TIMER0_OVF_vect){

  //O que acontece se estourar o limite 255?

}

//Exercício - Criar um firmware para que cada vez que o botão NA (PB4 - Interrupção) 
//for pressionado, o DC de um PWM (PD6) é aumentado em 10%

ISR(PCINT0_vect){



 auxiliar =+ 10;
  DC = (auxiliar / 256) * 100;
  OCR0A = DC;
  
}
