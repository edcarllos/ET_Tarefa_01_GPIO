/*
 * Finalidade: Fazer o Buzzer tocar em uma frequência escolhida pelo teclado
 */

#include <stdio.h>

#include "pico/stdlib.h"

#define GPIO_BUZZER 21
#define GPIO_LED_R 13
#define GPIO_LED_B 12
#define GPIO_LED_G 11
#define ASTERISTICO 13
#define JOGO_DA_VELHA 14
#define A 10
#define B 11
#define C 12
#define D 15

int32_t frequencia_escolhida;
int tecla;
int somador;
uint columns[4] = {4, 3, 2, 28};
uint rows[4] = {8, 7, 6, 5};

// COMENTEM O CÓDIGO!!!!!!!!!!

// David + Vídeo
void inicializacaoLEDs();

void inicializacaoBuzzer();

void inicializacaoTeclado();

// James
void lerTeclado();

void desligaTodosLEDs();

//  Tiago
void tocaBuzzer(uint32_t frequencia_h, uint32_t intervalo_us);

// Alícia
void acionaLED_R(uint32_t tempo);

void acionaLED_G(uint32_t tempo);

void acionaLED_B(uint32_t tempo);

// Cláudio
void acionarTodosLEDs(uint32_t tempo);

void acionaLED_Sinalizando(uint32_t frequencia_h);

// André Lima + main + Descrição
void avaliaComando();

int main() { return 0; }

// Função responsável por inicializar os LEDs
void inicializacaoLEDs(){
  //inicializa o pino do LED vermelho
  gpio_init(GPIO_LED_R);
    //configura o pino do LED vermelho como saída
  gpio_set_dir(GPIO_LED_R,GPIO_OUT);
    //inicializa o pino do LED azul
  gpio_init(GPIO_LED_B);
    //configura o pino do LED azul como saída
  gpio_set_dir(GPIO_LED_B,GPIO_OUT);
    //inicializa o pino do LED verde
  gpio_init(GPIO_LED_G);
    //configura o pino do LED verde como saída
  gpio_set_dir(GPIO_LED_G,GPIO_OUT);
}

// Função responsável por inicializar o buzzer
void inicializacaoBuzzer(){
  //inicializa o pino do buzzer
  gpio_init(GPIO_BUZZER);
    //configura o pino do buzzer como saída
  gpio_set_dir(GPIO_BUZZER,GPIO_OUT);
}

// Função responsável por inicializar o teclado
void inicializacaoTeclado(){
  tecla=-1;
  for(int i=0;i<4;i++){
    //inicializa os pinos das colunas
    gpio_init(columns[i]);
    //initializa os pinos das linhas
    gpio_init(rows[i]);
    //configura os pinos das colunas como entrada
    gpio_set_dir(columns[i],GPIO_IN);
    //configura os pinos das linhas como saída
    gpio_set_dir(rows[i],GPIO_OUT);
    //configura pull up
    gpio_put(rows[i], true);
  }
}

// Função que decide após cada aperto de tecla o que vai acontecer
void avaliaComando(){
  // Verifica se houve alguma tecla válida apertada
  if(tecla>=0){
      // Verifica se a tecla pressionada é um dos números
      if(TECLADO[tecla]<10){
        // Esse bloco é responsável por concatenar os números formando um numero com unidades, dezenas, centenas, etc.
        if(somador==0){
          somador = TECLADO[tecla];
        }else{
          somador = somador*10+TECLADO[tecla]; 
        }
        // Os três LEDs piscam para sinalizar ao usuário que o sistema reconheceu que a tecla foi pressionada
        acionarTodosLEDs(200);
      }
    }
}
