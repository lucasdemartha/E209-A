#include <stdio.h>
#include <stdlib.h>

#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

#define FOSC 16000000U
#define BAUD 9600
#define MYUBRR FOSC / 16 / (BAUD - 1)
#define TAMANHO

#define PINO 0 //Definição de 0 a 5 para leitura de um único pino
#define AMOSTRAS 50

char msg_tx[20];
char msg_rx[32];
int pos_msg_rx = 0;
int tamanho_msg_rx = TAMANHO;

int PINO; //Variável para armazenar o pino que será lido no conversor
unsigned int leitura_AD;

void UART_config(unsigned int ubrr);
void UART_Transmit(char *dados);

int main() {

  //Inicialização da Serial
  UART_config(MYUBRR);

  //Declaração das Saídas
  DDRB  //Pinos de Saída do Portal B
  DDRC  //Pinos de Saída do Portal C
  DDRD  //Pinos de Saída do Portal D

  //Declaração de Pull-up
  PORTB //Botões NF no Portal B
  PORTC //Botões NF no Portal C
  PORTD //Botões NF no Portal D

  //Configurações das Interrupções Externas (INT0 e INT1)
  EICRA //Modo de Funcionamento de INT0 e INT1
  EIMSK //Habilitador de Interrupção INT0 e INT1

  //Configurações das Interruções PCINT
  PCICR //Quais Portais terão interrupção?
  PCMSK0 //Quais pinos do Portal B terão interrupção?
  PCMSK1 //Quais pinos do Portal C terão interrupção?
  PCMSK2 //Quais pinos do Portal D terão interrupção?

  //Configurações dos Timers
  TCCR0A //Modo de Funcionamento do Temporizador 0
  TCCR0B //Frequência do Clock do Temporizador 0
  TIMSK0 //Quais interrupções serão geradas no Temporizador 0

  //Configuração do Conversor AD
  ADMUX = BIT6; //Determinação da tensão de referência de 5V
  ADCSRA = (BIT7 + BIT2 + BIT1 + BIT0); //Habilitação do Conversor e Prescaler de 128
  ADCSRB = 0; //Garantia de conversão única
  DIDR0 //Desabilitação dos PINOS usados no AD para entrada digital - Não obrigatório

  //Interrupção global
  sei();

  //LOOP INFINITO
  for (;;) {

    //Leitura de Botão NA (PD0) ativando um pino (PD3)
    if (PIND & BIT0 == BIT0) {

      PORTD |= (BIT3);
    }

    //Leitura de Botão NF (PD0) desativando um pino (PD3)
    if (PIND & BIT0 == 0) {

      PORTD &= ~(BIT3);
    }

    //Transmissão Serial de Texto
    UART_Transmit("Mensagem a ser transmitida \n");

    //Transmissão Serial de Números
    int X = 0;
    itoa(X, msg_tx, 10);
    UART_Transmit(msg_tx);

    //Leitura de dados numéricos da serial (exemplo de 3 casas)
    int VALOR = 0;
    valor = ((msg_rx[0] - 48) * 100) + ((msg_rx[1] - 48) * 10) + ((msg_rx[2] - 48) * 1);

    //Conferência de texto digitado na serial
    UART_Transmit("Digite 'ola':\n");
    int x = 0;
    while (x == 0) {
      if ((msg_rx[0] == 'o') && (msg_rx[1] == 'l') && (msg_rx[2] == 'a')) {
        x = 1;
      }
    }

    //Determinação do pino de leitura do conversor AD
    ADMUX = ((ADMUX & 0xF8) | PINO);

    //Leitura do Conversor AD sem interrupção e com única conversão
    ADCSRA |= BIT6;
    while((ADCSRA & BIT6) == BIT6);
    Leitura_AD = (ADCL | (ADCH << 8)); //Ou leitura_AD = ADC;
    
    //Leitura do Conversor AD com interrupção e com única conversão
    ADCSRA |= (BIT6 + BIT3);

    //Leitura do Conversor AD com média de conversão
    unsigned int SomaLeitura = 0, MediaLeitura;
    for(int i = 0, i < AMOSTRAS, i++){
      
      ADCSRA |= BIT6;
      while((ADCSRA & BIT6) == BIT6);
      
      Leitura_AD = (ADCL | (ADCH << 8)); //Ou leitura_AD = ADC;
      SomaLeitura += Leitura_AD;

    }
    MediaLeitura = SomaLeitura / AMOSTRAS;

  }
}

//Interrupção PD2 (INT0)
ISR(INT0_vect) {
}

//Interrupção PD3 (INT1)
ISR(INT1_vect) {
}

//Interrupção Portal B
ISR(PCINT0_vect) {
}

//Interrupção Portal C
ISR(PCINT1_vect) {
}

//Interrupção Portal D
ISR(PCINT2_vect) {
}

//Interrupção Comparador A do Temporizador 0
ISR(TIMER0_COMPA_vect) {
}

//Interrupção Comparador B do Temporizador 0
ISR(TIMER0_COMPB_vect) {
}

//Interrupção de Overflow no Temporizador 0
ISR(TIMER0_OVF_vect) {
}

//Interrupção de Recebimento da Serial
ISR(USART_RX_vect) {

  // Escreve o valor recebido pela UART na posição pos_msg_rx do buffer msg_rx
  msg_rx[pos_msg_rx++] = UDR0;

  if (pos_msg_rx == tamanho_msg_rx)
    pos_msg_rx = 0;
}

//Transmissão de Dados Serial
void UART_Transmit(char *dados) {

  // Envia todos os caracteres do buffer dados ate chegar um final de linha
  while (*dados != 0) {
    while ((UCSR0A & BIT5) == 0)
      ;  // Aguarda a transmissão acabar

    // Escreve o caractere no registro de tranmissão
    UDR0 = *dados;
    // Passa para o próximo caractere do buffer dados
    dados++;
  }
}

//Configuração da Serial
void UART_config(unsigned int ubrr) {

  // Configura a  baud rate
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;
  // Habilita a recepcao, tranmissao e interrupcao na recepcao */
  UCSR0B = (BIT7 + BIT4 + BIT3);
  // Configura o formato da mensagem: 8 bits de dados e 1 bits de stop */
  UCSR0C = (BIT2 + BIT1);
}

//Interrução de Conversão AD
ISR(ADC_vect){

  Leitura_AD = (ADCL | (ADCH << 8)); //Ou leitura_AD = ADC;
} 