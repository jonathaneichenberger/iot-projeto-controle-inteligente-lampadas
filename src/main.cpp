// Inclusão das funções e definições do sistema
#include <Arduino.h>
#include "funcoes.h"

// Interrupção acionada pelo sensor PIR
void IRAM_ATTR detectarMovimento() {
  movimentoDetectado = true;
}

void setup() {
  Serial.begin(115200); // Inicializa comunicação serial
  inicializarSistema(); // Configura os sensores e dispositivos
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), detectarMovimento, RISING); // Configura interrupção do PIR
}

void loop() {
  static unsigned long lastUpdate = 0;      // Controle de tempo para atualização
  static unsigned long lastUpdateTS = 0; 
  bool lcdDeveAtualizar = false;            // Flag para atualizar o LCD
  unsigned long currentMillis = millis();   // Obtém tempo atual
  float ultimaTemperatura = -999;           // variavel de controle para mudanças de temperatura
  float temperatura;           

  // Verifica se houve detecção de movimento
  if (movimentoDetectado) {
    myFlag = true;
    startTime = currentMillis; 
    movimentoDetectado = false;
    Serial.println("Movimento detectado!");
    lcdDeveAtualizar = true;
  }

  // Verifica se o tempo limite expirou
  if (myFlag && (currentMillis - startTime >= delayTime)) {
    myFlag = false;
    Serial.println("Tempo expirado, desligando lâmpadas e ar condicionado.");
    startTime = 0;
    lcdDeveAtualizar = true;
  }

  // Atualiza temperatura a cada 1 segundo
  if (currentMillis - lastUpdate >= 1000) {
    lastUpdate = currentMillis;
    float temperatura = dht.readTemperature();
    if (!isnan(temperatura) && temperatura != ultimaTemperatura) {
      ultimaTemperatura = temperatura;
      if (myFlag) {
        controleArDHT(temperatura); // Liga/desliga o NeoPixel do ar-condicionado
      } else {
        stripAir.clear();
        stripAir.show();
      }
      lcdDeveAtualizar = true;
    }
    controleLampadasPIR(); // Atualiza controle das lâmpadas
  }
  if (currentMillis - lastUpdateTS >= 15000) {
    lastUpdateTS = currentMillis;
    enviarDadosThingSpeak(temperatura);
  }

  // Atualiza informações no LCD caso necessário
  if (lcdDeveAtualizar) {
    exibirNoLCD(ultimaTemperatura);
  }
}
