# 🚀 **Projeto: Controle de Servomotor com PWM e Movimentação Suave**  
(Daniel Silva de Souza - Danngas)  

### [Vídeo Demonstrativo do Projeto](https://)

## 📌 **Descrição**  

Este projeto utiliza um RP2040 (Raspberry Pi Pico) para controlar a movimentação de um servomotor usando PWM (Pulse Width Modulation). O servomotor gira suavemente de 0° a 180°, com o controle do ângulo sendo feito ajustando o tempo de pulso. A movimentação é gradual, aumentando ou diminuindo o ângulo em pequenos incrementos para garantir um movimento contínuo e suave.

---

## 🛠 **Construído com**  

- **Microcontrolador:** *Raspberry Pi Pico W*  
- **Linguagem:** *C*  
- **Frameworks:** *Pico SDK*  
- **Componentes:** Servomotor, GPIOs  

## 🎯 **Funcionalidade**  

✔️ **PWM** controla o servo com precisão!  
✔️ Movimentação de 0° a 180° de forma suave.  
✔️ Pulos pequenos! Incremento de 5 microsegundos por vez!  
✔️ A cada ciclo, o servo move com feedback do terminal.  

---

## 📁 **Estrutura do Projeto**  

### 🔹 **Arquivo Principal**  

- `controle_servo.c` – Controle do servo, lógica principal.  

### 🛠 **Auxiliares**  

- `CMakeLists.txt` – Para compilar o projeto, tudo certo.  
- `pico_sdk` – O SDK, para tudo funcionar direito no RP2040.  

## 🛠️ **Estrutura do Código**  

### `main()`

- Inicializa o pino do servo, faz o **PWM**.
- Muda de 0° a 180°, com paciência.
- Movimento suave, a cada 5 microsegundos!

### `set_servo_position()`

- Define o **pulso** para um ângulo, suave e certinho.  
- Calcula, ajusta, e vai.

### `movimentar_suavemente()`

- Movimento contínuo, incrementa aos poucos o **pulso**, sem pressa.  

---

## 🚀 **Funcionalidades**  

- **Movimento suave** entre 0°, 90° e 180°.
- A cada vez, incrementa 5 microsegundos, suave, contínuo.
- Exibe o **ângulo** e o **pulso** no terminal, feedback direto!

---

## 🎥 **Demonstração**  

**Vídeo** que mostra o movimento suave, o controle do servo e mais!

---

## ⚙️ **Instruções para Execução**  

### 📌 **Requisitos**  

- **Placa compatível:** Raspberry Pi Pico W  
- **Ambiente de Desenvolvimento:**  
  - *Pico SDK* instalado  
  - Compilador **ARM GCC**  
  - Ferramenta **CMake**  
  - Interface serial para upload do código  

### 🚀 **Passos para Execução**  

1. **Clonar o repositório**  
   ```sh
   git clone https://github.com/Danngas/Controle_Servomotor_PWM.git
   cd Controle_Servomotor_PWM
