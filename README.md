# 📡 Automatização e Controle Inteligente de Iluminação e Climatização do Ambiente

> Projeto desenvolvido nas aulas de **Internet das Coisas (IoT)** no **SENAI**, com o objetivo de automatizar o controle de lâmpadas e ar-condicionado, otimizando o consumo de energia. Através da conectividade e coleta de dados, o sistema monitora a iluminação e a temperatura do ambiente, permitindo uma gestão mais eficiente e sustentável dos recursos.

---

## 📌 Índice
- [Sobre o Projeto](#sobre-o-projeto)
- [Como Funciona](#como-funciona)
- [Foto do Projeto](#foto-do-projeto)
- [Configuração do Ambiente](#configuração-do-ambiente)
- [Rodando o Projeto](#rodando-o-projeto)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)

---

<a id="sobre-o-projeto"></a>
## 🧐 Sobre o Projeto

### 🎯 Objetivo do Projeto
O projeto tem como objetivo automatizar o controle de lâmpadas e do ar-condicionado por meio da **Internet das Coisas (IoT)**, promovendo uma gestão eficiente do consumo de energia. Através da conectividade e da coleta de dados, o sistema monitora a iluminação e a temperatura do ambiente, ajustando automaticamente os dispositivos para otimizar o uso dos recursos.

### ⚡ Problema que o Projeto Resolve
O desperdício de energia em ambientes onde lâmpadas e ar-condicionado permanecem ligados desnecessariamente é um problema comum. Esse projeto busca solucionar essa questão ao implementar um **sistema inteligente** que aciona e desliga os dispositivos conforme a presença de pessoas e as condições do ambiente. Dessa forma, reduz-se o consumo excessivo de eletricidade, promovendo **economia e sustentabilidade**.

---

<a id="como-funciona"></a>
## 🚀 Como Funciona

O projeto utiliza **sensores IoT** para monitorar a presença de pessoas, a iluminação do ambiente e a temperatura, ajustando automaticamente o funcionamento das lâmpadas e do ar-condicionado. O sistema opera da seguinte forma:

1. **Coleta de Dados**  
   - Sensores de presença detectam a ocupação do ambiente.  
   - Sensores de luminosidade identificam a necessidade de iluminação artificial.  
   - Sensores de temperatura monitoram as condições térmicas.  

2. **Processamento e Decisão**  
   - Os dados coletados são enviados para um **microcontrolador ESP32**.  
   - Com base em algoritmos pré-definidos, o sistema decide quando ligar ou desligar os dispositivos.  

3. **Automação dos Dispositivos**  
   - Se uma pessoa for detectada no ambiente e a iluminação natural for insuficiente, as **lâmpadas serão acesas**.  
   - Se a temperatura ultrapassar um limite definido, o **ar-condicionado será ativado automaticamente**.  
   - Quando o ambiente estiver vazio, os dispositivos serão **desligados** para evitar desperdício de energia.  

4. **Interface e Controle Remoto**  
   - O usuário pode monitorar e ajustar o sistema via **interface web** ou **aplicativo**.  
   - Os dados podem ser armazenados em **nuvem** para análise de consumo e otimização em plataformas como [ThingSpeak](https://thingspeak.mathworks.com/).  

Esse fluxo garante **eficiência energética**, **automação inteligente** e **conforto**, reduzindo custos e impactos ambientais.  

---

<a id="foto-do-projeto"></a>
## 🖼️ Foto do Projeto
![Imagem do Projeto](https://github.com/user-attachments/assets/bbb9f1c9-ce50-42f8-b542-7cdf37cede9c)

---

<a id="configuração-do-ambiente"></a>
## 🛠 Configuração do Ambiente

1. Instale o [VS Code](https://code.visualstudio.com/)
2. Instale as extensões **Wokwi Simulator** e **PlatformIO**.  

    ![Extensão Wokwi](https://github.com/user-attachments/assets/3666f874-bbf5-4638-826c-ded0b49a78c4)  
    ![Extensão PlatformIO](https://github.com/user-attachments/assets/0f6cd5ce-d0f4-431e-87ce-f0d144ada96f)  

3. Para criar ou abrir um projeto no PlatformIO, siga os passos abaixo:  
   - **Abra a extensão do PlatformIO**:  
      ![PlatformIO](https://github.com/user-attachments/assets/895a8be8-e98c-47f8-bf7d-7f4b928bb168)  

   - **Aperte F1 e abra o PlatformIO Home**:  
      ![PlatformIO Home](https://github.com/user-attachments/assets/2ba931d2-86f7-4714-8836-f9c6c42ea66a)  

   - **Escolha "New Project" para criar um novo ou "Open Project" para abrir um existente**:  
      ![Novo Projeto](https://github.com/user-attachments/assets/0be7694b-f0b4-4688-90d8-714e2637f94a)  

   - **Configure o novo projeto** escolhendo a placa *Espressif ESP32 Dev Module*:  
      ![Configuração ESP32](https://github.com/user-attachments/assets/7599e8ca-0919-473d-b9ca-4e0af926e86c)  

4. **Montando o Circuito na Plataforma Wokwi**  
   - Acesse [Wokwi](https://wokwi.com/arduino), faça login e crie um novo projeto.  
   - Monte seu circuito eletrônico de acordo com o projeto.  
   - No Wokwi, copie o conteúdo do arquivo `diagram.json`:  
      ![Diagrama Wokwi](https://github.com/user-attachments/assets/00c177b2-f32d-4aa4-bcb8-3d6658b285c0)  
   - No VS Code, **crie um arquivo `diagram.json`** dentro da pasta do seu projeto e cole os dados copiados.  

5. **Criando o arquivo de configuração Wokwi**  
   - No VS Code, crie o arquivo `wokwi.toml` e adicione:  
     ```toml
     [wokwi]
     version = 1
     elf = ".pio/build/esp32dev/firmware.elf"
     firmware = ".pio/build/esp32dev/firmware.bin"
     ```

Agora é só programar no arquivo **src/main.cpp** e rodar a simulação! 🚀  

---

<a id="rodando-o-projeto"></a>
## ▶️ Rodando o Projeto

1. **Clone este repositório pelo Git Bash**:
   ```
   git clone https://github.com/jonathaneichenberger/iot-esp32-lighting-and-temperature-control-commercial-building-project.git
   ```
2. Acesse a Pasta do Projeto pelo Git Bash:
   ```
   cd iot-esp32-lighting-and-temperature-control-commercial-building-project
   ```
3. Abra o VS Code pelo Git Bash:
   ```
   code .
   ```
4. Use o comando ```CTRL + '``` para abrir o terminal do VS Code e para compilar use o comando:
   ```
   pio run
   ```


<a id="tecnologias-utilizadas"></a>
## 🔧 Tecnologias Utilizadas

Wokwi - Simulador de circuitos IoT

VS Code - Editor de código

PlatformIO - Ambiente de desenvolvimento para microcontroladores

ESP32 - Microcontrolador utilizado no projeto

ThingSpeak - Plataforma de análise e visualização de dados IoT

