//https://www.tinkercad.com/things/lNHG92p268j

#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

ISR(ADC_vect){
  Serial.begin(9600);
  
  float Leitura_AD;
  float SomaLeitura;
  float MediaLeitura;
  
  for(int i=0; i <=5; i++){
   ADMUX = ((ADMUX & 0xF8) | i);
   ADCSRA |= BIT6;
   while((ADCSRA & BIT6) == BIT6);
   Leitura_AD = (ADCL | (ADCH << 8));
   SomaLeitura += Leitura_AD;
  }
  MediaLeitura = SomaLeitura/6;
  
  Serial.println(MediaLeitura);
  
  ADCSRA |= (1 << ADSC);
}


int main (void){
  
  
  Serial.begin(9600);
  
  ADMUX = BIT6; //A1
  ADCSRA |= (1<< ADPS2) | (1<< ADPS1) | (1<< ADPS0) | (1<< ADIE) | (1<< ADEN); //ADPS CONFIGURA PRESCALER //ADIE HABILITA INTERRUPCAO //ADEN HABILITA ADC
  ADCSRA |= (1 << ADSC); //ENTRA NA INTERRUPCAO
  ADCSRB = 0;

  sei();

  for(;;){
    
  } 
}