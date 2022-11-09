//https://www.tinkercad.com/things/7z1a8OiX1ka-ex1-relatorio-4/editel

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
  float tensao = ((5*leitura)/1023);
  
  Serial.begin(9600);
  Serial.println(tensao);
  
  ADCSRA |= (1 << ADSC);
}


int main (void){
  
  
  Serial.begin(9600);
  
  ADMUX = 0b01000100; //A4
  ADCSRA |= (1<< ADPS2) | (1<< ADPS1) | (1<< ADPS0) | (1<< ADIE) | (1<< ADEN); //ADPS CONFIGURA PRESCALER //ADIE HABILITA INTERRUPCAO //ADEN HABILITA ADC
  ADCSRA |= (1 << ADSC); //ENTRA NA INTERRUPCAO
  ADCSRB = 0;

  sei();

  for(;;){
    
  } 
}