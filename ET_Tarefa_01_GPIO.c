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
