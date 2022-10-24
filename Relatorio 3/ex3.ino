//https://www.tinkercad.com/things/ju7qwfTRcJ5
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int temp = 0;
int contador = 0;
bool press = false;

void motor_off(){
    PORTD &= ~(BIT3);
    Serial.println("BOTÃO OFF PRESSIONADO");
}

void motor_on(){
     PORTD |= BIT3;
}

int main(){
  
  Serial.begin(9600);

  DDRD = BIT3;
  
  PORTD &= ~(BIT3);

  PORTB = BIT2;

  PCICR = BIT0;

  PCMSK0 = BIT1 + BIT2;

  TCCR0A = (1 << COM0A0); //COMPARAÇÃO

  TCCR0B = (1 << CS01); //Prescaler = 8

  OCR0A = 200; //100us (200*500ns)

  TIMSK0 = 0b00000010; //interrupção de comparação A

  sei();

  for (;;){
  } 

}

ISR(PCINT0_vect){
  
  if((PINB & BIT1) == BIT1 && !press){
    press = true;
    Serial.println("BOTÃO ON PRESSIONADO");
  }
  else{
    press = false;
  }
  
  if((PINB & BIT2) == 0){
      motor_off();
  } 
  
}
  

ISR(TIMER0_COMPA_vect){

  contador++;

  if (contador == 10000)
  {
    contador=0;

    if(press == true){
      temp++;
      Serial.print("Contador: ");
      Serial.println(temp);
      if(temp == 10)
        motor_on();
    }
    else{
      temp=0;
    }
  }

}

