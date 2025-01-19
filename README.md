# Controle de Pinos GPIO com Teclado Matricial

Este repositório contém o projeto de controle de pinos GPIO usando um teclado matricial 4x4 em conjunto com LEDs RGB e um buzzer. O objetivo é permitir o acionamento de LEDs e a configuração da frequência do buzzer através do teclado matricial. 

## Funcionalidades

- Controle de um buzzer com frequência configurável.
- Acionamento individual de LEDs RGB (Vermelho, Verde e Azul).
- Identificação de faixas de frequência com sinalização por LEDs:
  - **LED Azul**: Frequências inaudíveis (abaixo de 20 Hz).
  - **LED Verde**: Frequências audíveis (entre 20 Hz e 20 kHz).
  - **LED Vermelho**: Frequências inaudíveis (acima de 20 kHz).
- Reset de configurações por meio do teclado matricial.
- Teste individual de LEDs e som do buzzer por comandos específicos.

## Estrutura do Projeto

### Principais Componentes
- **Teclado Matricial 4x4**: Utilizado para a inserção de comandos.
- **LEDs RGB**: Indicadores visuais para estados do sistema.
- **Buzzer**: Gera sons na frequência definida.
- **Microcontrolador Raspberry Pi Pico W**: Processa os comandos e controla os periféricos.

### Configuração do Teclado
- Teclas numéricas (0-9): Inserção da frequência.
- `*`: Reseta a configuração atual.
- `#`: Confirma a frequência digitada.
- Tecla `A`: Testa o LED Vermelho.
- Tecla `B`: Testa o LED Verde.
- Tecla `C`: Testa o LED Azul.
- Tecla `D`: Toca o buzzer por 2,5 segundos com a frequência configurada.

### Demonstração de Execução
Confira o funcionamento do sistema assistindo ao vídeo demonstrativo: [Demonstração no YouTube](https://youtu.be/K5tzPIKYAQI).

## Como Usar

### Requisitos
- Ambiente de desenvolvimento **VS Code**.
- **Simulador Wokwi** para simulação do hardware.
- Kit de desenvolvimento **Pico SDK**.

### Passos para Execução
1. Clone este repositório:
   ```bash
   git clone <URL-do-repositório>
   ```
2. Instale as dependências necessárias para o Pico SDK.
3. Importe o projeto no **VS Code** e configure o simulador Wokwi.
4. Compile o código e inicie a simulação.

### Observação
A prática pode ser realizada apenas com o simulador Wokwi, sem necessidade de hardware real.

## Estrutura do Código

O programa principal está estruturado em:

### Funções Principais
- **`lerTeclado`**: Captura comandos do teclado matricial.
- **`desligaTodosLEDs`**: Desliga todos os LEDs.
- **`tocaBuzzer`**: Toca o buzzer na frequência especificada.
- **`acionaLED_Sinalizando`**: Acende o LED correspondente à faixa de frequência configurada.
- **Funções auxiliares para controle individual de LEDs** (e.g., `acionaLED_R`, `acionaLED_G`, `acionaLED_B`).

### Inicialização
- Configuração inicial do buzzer, LEDs e teclado matricial.

### Execução
- Loop principal que monitora entradas do teclado e executa os comandos configurados.

## Estrutura de Branches

Cada desenvolvedor deve trabalhar em uma branch específica, garantindo commits regulares com mensagens descritivas. O líder do projeto será responsável por revisar e aprovar pull requests.

## Contribuição

Contribuições são bem-vindas! Siga os passos abaixo para colaborar:
1. Faça um fork do repositório.
2. Crie uma branch para sua feature/correção:
   ```bash
   git checkout -b minha-feature
   ```
3. Faça o commit de suas alterações:
   ```bash
   git commit -m "Descrição da alteração"
   ```
4. Envie as alterações para sua branch remota:
   ```bash
   git push origin minha-feature
   ```
5. Abra um pull request no GitHub.

## Links Relacionados
- Vídeo de simulação no Wokwi: [Dropbox Link 1](https://www.dropbox.com/scl/fi/va5dp18ahzarjyd6z8boh/2025-01-09-16-29-53.mkv?rlkey=j93icbgjf3m080d1tyde33fxz&dl=0)
- Vídeo de demonstração com BitDogLab: [Dropbox Link 2](https://www.dropbox.com/scl/fi/oakfs3evgysjt6dmtel60/VID-20250109-WA0043.mp4?rlkey=03s40wpvjx5hhjipdoi2q8uky&dl=0)

## Licença

Este projeto está sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.

---

**Equipe de Desenvolvimento:**
- Desenvolvedores:
    - Alícia
    - André Lima
    - Cláudio
    - David
    - Edcarllos (líder)
    - James
    - Tiago
