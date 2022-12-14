//https://www.tinkercad.com/things/9tUyNyY3lgI

#include <Arduino.h>

#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000


ISR(ADC_vect){
  unsigned int leitura = ADC;
  float tensao = ((5*leitura)/1023.0);
  float temperatura = ((tensao*200)/5);
  
  Serial.begin(9600);
  Serial.println(temperatura);
  
  ADCSRA |= (1 << ADSC);
}

int main (void){

  EICRA |= BIT1 + BIT0;
  EIMSK |= BIT0;
  
  ADMUX = 0b01000010; //A2
  ADCSRA |= (1<< ADPS2) | (1<< ADPS1) | (1<< ADPS0) | (1<< ADIE) | (1<< ADEN); //ADPS CONFIGURA PRESCALER //ADIE HABILITA INTERRUPCAO //ADEN HABILITA ADC
  ADCSRA |= (1 << ADSC); //ENTRA NA INTERRUPCAO
  ADCSRB = 0;

  sei();

  for(;;){
    
  } 
}