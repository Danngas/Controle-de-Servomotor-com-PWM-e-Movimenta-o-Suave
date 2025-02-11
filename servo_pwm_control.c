#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22  // Pino do servomotor

// Parâmetros do PWM
const float FREQ_PWM = 50.0;        // Frequência do PWM (50 Hz)
const float FREQ_CLOCK = 125000000; // Frequência do clock do RP2040 (125 MHz)
const float CLK_DIV = 125.0;        // Divisor de clock fixo para simplificar

// Cálculo do WRAP automático (Período de 20ms -> 50Hz)
const uint WRAP = (uint)(FREQ_CLOCK / (CLK_DIV * FREQ_PWM));

// Definição dos tempos ativos para cada posição do servo
const float POS_0_US = 500.0;   // Tempo ativo para 0 graus (500µs)
const float POS_90_US = 1470.0; // Tempo ativo para 90 graus (1470µs)
const float POS_180_US = 2400.0;// Tempo ativo para 180 graus (2400µs)

const int TEMPO_ESPERA_MS = 5000; // Tempo de espera antes de mudar de posição (5s)
const int INCREMENTO_US = 5;      // Incremento suave de 5µs
const int DELAY_MOV_MS = 10;      // Atraso entre cada incremento (10ms)

// Função para definir o ângulo do servomotor
void set_servo_position(uint slice, float tempo_ativo_us) {
    uint duty_cycle = (uint)((tempo_ativo_us / (1000000.0 / FREQ_PWM)) * WRAP);
    pwm_set_gpio_level(PWM_PIN, duty_cycle);
    printf("Servo ajustado para %.0f µs (Duty: %d)\n", tempo_ativo_us, duty_cycle);
}

// Função para movimentação suave do servo
void movimentar_suavemente(uint slice, float inicio, float fim) {
    if (inicio < fim) {
        for (float pos = inicio; pos <= fim; pos += INCREMENTO_US) {
            set_servo_position(slice, pos);
            sleep_ms(DELAY_MOV_MS);
        }
    } else {
        for (float pos = inicio; pos >= fim; pos -= INCREMENTO_US) {
            set_servo_position(slice, pos);
            sleep_ms(DELAY_MOV_MS);
        }
    }
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    sleep_ms(100); // Pequeno atraso para garantir que stdio esteja pronto

    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_set_clkdiv(slice, CLK_DIV);
    pwm_set_wrap(slice, WRAP);
    pwm_set_enabled(slice, true);

    printf("PWM configurado para %f Hz\n", FREQ_PWM);
    printf("WRAP: %d\n", WRAP);
    fflush(stdout); // Garante que a saída seja exibida

    // Ajusta o servo para 180° e aguarda
    printf("\nPOSICAO 180 - ", FREQ_PWM);
    set_servo_position(slice, POS_180_US);
    fflush(stdout); // Força a exibição no terminal
    sleep_ms(TEMPO_ESPERA_MS);

    printf("\nPOSICAO 90 - ", FREQ_PWM);
    set_servo_position(slice, POS_90_US);
    sleep_ms(TEMPO_ESPERA_MS);

    printf("\nPOSICAO 0 - ", FREQ_PWM);
    set_servo_position(slice, POS_0_US);
    sleep_ms(TEMPO_ESPERA_MS);

    // Movimento contínuo
    while (true) {
        movimentar_suavemente(slice, POS_0_US, POS_180_US);
        movimentar_suavemente(slice, POS_180_US, POS_0_US);
    }
}
