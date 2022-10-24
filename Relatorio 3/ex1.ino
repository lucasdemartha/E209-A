//https://www.tinkercad.com/things/0Saj81m2BUZ
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

int HH = 0;
int MM = 0;
int SEG = 0;
int contador = 0; 

int main(void){

Serial.begin(9600);

TCCR0A = (1 << COM0A0); //COMPARAÇÃO

TCCR0B = (1 << CS01); //Prescaler = 8

OCR0A = 200; // 200*500ns = 100us

TIMSK0 = 0b0000010; //interrupção de comparação A

sei();
for (;;){

}

}

void cronometro(){
  if(HH < 10)
    Serial.print("0");
    Serial.print(HH);
    Serial.print(":");
  if(MM < 10)
    Serial.print("0");
    Serial.print(MM);
    Serial.print(":");
  if(SEG < 10)
    Serial.print("0");
    Serial.println(SEG);

}

ISR(TIMER0_COMPA_vect){

    contador++;

    if (contador == 10000)
    {
      contador=0;
      SEG++;
      if(SEG == 60){
        SEG = 0;
        MM++;
      }
      if(MM == 60){
        MM=0;
        HH++;
      }
      cronometro();
    }
    

}