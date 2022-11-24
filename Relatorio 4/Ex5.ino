//https://www.tinkercad.com/things/bhxtapcfGAP
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
float tensao_GLOBAL;

int main(){

Serial.begin(9600);

//Configuração do Conversor AD
ADMUX = BIT6;
ADCSRA = (BIT7 + BIT2 + BIT1 + BIT0); //Habilitação do Conversor e Prescaler de 128
ADCSRB = 0; //Garantia de conversão única
DIDR0; //Desabilitação dos PINOS usados no AD para entrada digital - Não obrigatório

for (;;){

	//Leitura do Conversor AD com média de conversão
	unsigned int SomaLeitura_GLOBAL = 0, MediaLeitura_GLOBAL;
	for(int i = 0; i < 6; i++){
	  
		ADMUX = ((ADMUX & 0xF8) | i);
		//leitura pino a pino com 50 amostras
		unsigned int SomaLeitura = 0, MediaLeitura;
		for(int j = 0; j < 50; j++){
			ADCSRA |= BIT6;
			while((ADCSRA & BIT6) == BIT6);

			leitura_AD = (ADCL | (ADCH << 8)); //Ou leitura_AD = ADC;
			SomaLeitura += leitura_AD;
		}
		MediaLeitura = SomaLeitura / 50;
		tensao = (MediaLeitura * 5) / 1023.0;
		Serial.print("tensao_PINO[");
		Serial.print(i);
		Serial.print("]");
		Serial.println(tensao);
		Serial.println("---------------");
		_delay_ms(500);
		SomaLeitura_GLOBAL += MediaLeitura;
	}
	
	MediaLeitura_GLOBAL = SomaLeitura_GLOBAL / 6;
	tensao_GLOBAL = (MediaLeitura_GLOBAL * 5) / 1023.0;
	Serial.print("===tensao_GLOBAL: ");
	Serial.println(tensao_GLOBAL);
  	Serial.println("=============");

	_delay_ms(500);
  
} 

}
