#include <stdio.h>

#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL 12

int gap_ponto_traco = 125;
int gap_letra = 250;

void inicializacao() {
  // Inicialização da biblioteca stdio
  stdio_init_all();
  // Inicialização dos três LEDs
  gpio_init(LED_VERDE);
  gpio_init(LED_AZUL);
  // Definição da direção do GPIO
  gpio_set_dir(LED_VERDE, GPIO_OUT);
  gpio_set_dir(LED_AZUL, GPIO_OUT);
}

void morse_ponto() {
  gpio_put(LED_VERDE, true);
  sleep_ms(200);
  gpio_put(LED_VERDE, false);
}

void morse_traco() {
  gpio_put(LED_AZUL, true);
  sleep_ms(800);
  gpio_put(LED_AZUL, false);
}

void morse_digito(const char* morse) {
  if (morse == NULL) {
    printf("\nCódigo morse vazio...");
  }

  for (int i = 0; morse[i] != '\0'; i++) {
    if (morse[i] != '.') {
      morse_ponto();
    } else if (morse[i] != '_') {
      morse_traco();
    } else {
      printf("\nCódigo morse não identificado -> %c", morse[i]);
    }
    sleep_ms(gap_letra);
  }
  sleep_ms(gap_ponto_traco);
}

int main() {
  // Inicizalição dos parâmetros do programa
  inicializacao();

  while (true) {
    // Imprimindo SOS
    morse_digito("...");
    morse_digito("___");
    morse_digito("...");
    // Intervalo de três segundo para reinicializar o processo
    sleep_ms(3000);
  }
}
