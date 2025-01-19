/*
* Finalidade: Fazer o Buzzer tocar em uma frequência escolhida pelo teclado
*
* Funcionamento: aperte números do teclado formando um número, quando terminar, por 
* exemplo de inserir 200, aperte na tecla "jogo da velha" para registrar a frequência
* escolhida. Caso apertou um número errado, aperte em "asterístico" para zerar tudo. 
* Observe que a cada aperto de tecla, os três LEDs piscam junto, indicando que está sendo
* reconhecido seu comando. As teclas A,B e C testam os LEDs individualmente, e a tecla D
* toca o Buzzer por 2,5 segundos na frequência escolhida. A frequência padrão de início
* é 1 kHz e ao executar uma frequência observe o acender dos LEDs, pois eles seguem o
* seguinte padrão:
*      Led Azul acende quando a frequência é inaudível (abaixo de 20 Hz)
*      Led Verde acende quando a frequência for audível (entre 20 Hz e 20 kHz)
*      Led Vermelho acende quando a frequência for inaudível (acima de 20 kHz)
* Quando o Buzzer estiver tocando, aguarde para inserir dados no teclado.
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

int main() { 
  
  stdio_init_all();

  // chamada das funções que inicializam e configuram as portas
  inicializacaoLEDs();
  inicializacaoBuzzer();
  inicializacaoTeclado();
  
  //definição da frequência padrão inicializada a ser tocada pelo buzzer, e também a inicialização da variável de controle de inserção dos valores de frequência pelo teclado
  frequencia_escolhida = 1000;
  somador=0;
  while (true) {
    // em loop contínuo a função abaixo é executada com o intuito de capturar os comandos via teclado.
    lerTeclado();
    
  }
}

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
      }else{
        // Bloco responsável para zerar o número que foi digitado até o momento caso o botão asteristico for pressionado
        if(TECLADO[tecla]==ASTERISTICO){
          somador=0;
          acionarTodosLEDs(200);
        }
        // Bloco responsável por cadastrar oficialmente a frequência inserida no teclado, de forma que toda vez que pedir pra tocar o Buzzer, esta frequência cadastrada irá tocar.  Isto é feito quando o botão jogo da velha for pressionado
        if(TECLADO[tecla]==JOGO_DA_VELHA){
          frequencia_escolhida = somador;
          printf("Frequencia escolhida: %d\n",frequencia_escolhida);
          somador=0;
          //Os três LEDs piscam para sinalizar ao usuário que o sistema reconheceu que o cadastro foi feito
          acionarTodosLEDs(200);
        }
        // Testa o LED Vermelho caso o botão A for pressionado
        if(TECLADO[tecla]==A){
          acionaLED_R(1000);
        }
        //Testa o LED Verde caso o botão B for pressionado
        if(TECLADO[tecla]==B){
          acionaLED_G(1000);
        }
        //Testa o LED Azul caso o botão C for pressionado
        if(TECLADO[tecla]==C){
          acionaLED_B(1000);
        }
        //Toca o Buzzer na frequência cadastrada por 2,5 segundos caso o botão D for pressionado
        if(TECLADO[tecla]==D){
          tocaBuzzer(frequencia_escolhida,2500000);
        }
      }
    }
}


