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

int TECLADO[16] = {
    1, 2 , 3, 10,
    4, 5 , 6, 11,
    7, 8 , 9, 12,
    13, 0 , 14, 15
};

// COMENTEM O CÓDIGO!!!!!!!!!!

// David + Vídeo
void inicializacaoLEDs();

void inicializacaoBuzzer();

void inicializacaoTeclado();


void lerTeclado(){
// Função para ler o teclado matricial
// Verifica qual tecla foi pressionada, identifica a linha e a coluna correspondentes
// e define a tecla pressionada com base no índice da matriz.
// Após identificar a tecla, chama a função avaliaComando() para executar a ação correspondente.

  int col=-1;
  // Identifica qual coluna do teclado foi ativada
  for(int i=0;i<4;i++){
    if(gpio_get(columns[i])){
      col=i;
    }
  }
  int row=-1;
  if(col!=-1){
    // Inicialmente, desativa todas as linhas
    for(int i=0;i<4;i++){
      gpio_put(rows[i],false);
    }
    
    // Ativa uma linha por vez para identificar a tecla pressionada
    for(row=0;row<4;row++){
      gpio_put(rows[row],true);
      if(gpio_get(columns[col])){
        break;
      }
    }
    // Restaura as linhas desativadas para evitar interferências
    for(int i=row+1;i<4;i++){
      gpio_put(rows[i],true);
    }
  }
  
  // Calcula o índice da tecla pressionada com base na linha e coluna identificadas
  tecla = row*4+col;

  // Pequeno atraso para evitar leituras repetidas
  busy_wait_us(50000);

  // Avalia o comando correspondente à tecla pressionada
  avaliaComando();
}

// Função para desligar todos os LEDs
// Garante que todos os LEDs (vermelho, verde e azul) estão apagados
// Chamado após o uso dos LEDs para evitar que fiquem ligados indevidamente.
void desligaTodosLEDs(){
  gpio_put(GPIO_LED_R,false); // Desliga o LED vermelho
  gpio_put(GPIO_LED_G,false); // Desliga o LED verde
  gpio_put(GPIO_LED_B,false); // Desliga o LED azul
}


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
    gpio_put(rows[i], true);
  }
}
