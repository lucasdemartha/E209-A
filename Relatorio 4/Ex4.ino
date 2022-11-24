//https://www.tinkercad.com/things/lNHG92p268j
#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

unsigned int leitura_AD;
float tensao;

int main(){

Serial.begin(9600);

//Configuração do Conversor AD
ADMUX = BIT6;
ADCSRA = (BIT7 + BIT2 + BIT1 + BIT0); //Habilitação do Conversor e Prescaler de 128
ADCSRB = 0; //Garantia de conversão única
DIDR0; //Desabilitação dos PINOS usados no AD para entrada digital - Não obrigatório

for (;;){

	//Leitura do Conversor AD com média de conversão
	unsigned int SomaLeitura = 0, MediaLeitura;
	for(int i = 0; i < 6; i++){
	  
	ADMUX = ((ADMUX & 0xF8) | i); 	

	ADCSRA |= BIT6;
	while((ADCSRA & BIT6) == BIT6);

	leitura_AD = (ADCL | (ADCH << 8)); //Ou leitura_AD = ADC;
	SomaLeitura += leitura_AD;

	}
	MediaLeitura = SomaLeitura / 6;
	tensao = (MediaLeitura * 5) / 1023.0;
	Serial.print("tensao: ");
	Serial.println(tensao);
  	Serial.println("--------------");

	_delay_ms(100);
  
} 

}
