# Automatização e controle inteligente de iluminação e climatização do ambiente.

> O projeto desenvolvido nas aulas de Internet das Coisas (IoT) no SENAI visa automatizar o controle de lâmpadas e do ar-condicionado, otimizando o consumo de energia. Com conectividade e coleta de dados, o sistema monitora a iluminação e a temperatura do ambiente, permitindo uma gestão mais eficiente e sustentável dos recursos.

## 📌 Índice
- [Sobre o Projeto](#sobre-o-projeto)
- [Como Funciona](#como-funciona)
- [Foto do Projeto](#foto-projeto)
- [Configuração do Ambiente](#configuração-do-ambiente)
- [Rodando o Projeto](#rodando-o-projeto)
- [Integração do Wokwi ao VS Code](#integração-do-wokwi-ao-vs-code)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Contribuindo](#contribuindo)
- [Licença](#licença)

  
<a id="sobre-o-projeto"></a>
## 🧐 Sobre o Projeto

### 🎯 Objetivo do Projeto
O projeto tem como objetivo automatizar o controle de lâmpadas e do ar-condicionado por meio da **Internet das Coisas (IoT)**, promovendo uma gestão eficiente do consumo de energia. Através da conectividade e da coleta de dados, o sistema monitora a iluminação e a temperatura do ambiente, ajustando automaticamente os dispositivos para otimizar o uso dos recursos.

### ⚡ Problema que o Projeto Resolve
O desperdício de energia em ambientes onde lâmpadas e ar-condicionado permanecem ligados desnecessariamente é um problema comum. Esse projeto busca solucionar essa questão ao implementar um **sistema inteligente** que aciona e desliga os dispositivos conforme a presença de pessoas e as condições do ambiente. Dessa forma, reduz-se o consumo excessivo de eletricidade, promovendo **economia e sustentabilidade**.


<a id="como-funciona"></a>
## 🚀 Como Funciona

O projeto utiliza **sensores IoT** para monitorar a presença de pessoas, a iluminação do ambiente e a temperatura, ajustando automaticamente o funcionamento das lâmpadas e do ar-condicionado. O sistema opera da seguinte forma:

1. **Coleta de Dados**  
   - Sensores de presença detectam a ocupação do ambiente.  
   - Sensores de luminosidade identificam a necessidade de iluminação artificial.  
   - Sensores de temperatura monitoram as condições térmicas.  

2. **Processamento e Decisão**  
   - Os dados coletados são enviados para um microcontrolador ESP32.  
   - Com base em algoritmos pré-definidos, o sistema decide quando ligar ou desligar os dispositivos.  

3. **Automação dos Dispositivos**  
   - Se uma pessoa for detectada no ambiente e a iluminação natural for insuficiente, as lâmpadas serão acesas.  
   - Se a temperatura ultrapassar um limite definido, o ar-condicionado será ativado automaticamente.  
   - Quando o ambiente estiver vazio, os dispositivos serão desligados para evitar desperdício de energia.  

4. **Interface e Controle Remoto**  
   - O usuário pode monitorar e ajustar o sistema via uma interface web ou aplicativo.  
   - Os dados podem ser armazenados em nuvem para análise de consumo e otimização em platataformas como https://thingspeak.mathworks.com/.  

Esse fluxo garante **eficiência energética**, **automação inteligente** e **conforto**, reduzindo custos e impactos ambientais.  

<a id="foto-projeto"></a>
### Foto do projeto
![Image](https://github.com/user-attachments/assets/bbb9f1c9-ce50-42f8-b542-7cdf37cede9c)


<a id="configuração-do-ambiente"></a>
## 🛠 Configuração do Ambiente

1. Instale o [VS Code](https://code.visualstudio.com/)
2. Instale as extensões necessárias: PlatformIO.
3. Para criar um novo projeto ou abrir um projeto siga o passo a passo.
   * Abra a extensão do PLataformIO como na figura abaixo:

      ![Image](https://github.com/user-attachments/assets/895a8be8-e98c-47f8-bf7d-7f4b928bb168)
   * Aperte F1 e abra o PlataformIO: PlatFormIO Home:
     
      ![Image](https://github.com/user-attachments/assets/2ba931d2-86f7-4714-8836-f9c6c42ea66a)
   * Escolha New Project para um novo projeto ou Open Project para abrir uma pasta de projeto:
     
     ![Image](https://github.com/user-attachments/assets/0be7694b-f0b4-4688-90d8-714e2637f94a)
  
5. Para Rodar meu projeto, primeiro Clone este repositório pelo Git Bash:
  ```
   git clone https://github.com/jonathaneichenberger/iot-esp32-lighting-and-temperature-control-commercial-building-project.git
  ```
4. Acesse a Pasta do Projeto pelo Git Bash:
  ```
   cd iot-esp32-lighting-and-temperature-control-commercial-building-project
  ```
5. Abra o VS Code pelo Git Bash:
  ```
   code .
  ```
6. Use o comando ```CTRL + '``` para abrir o terminal do VS Code e para compilar use o comando:
  ```
   pio run
  ```

