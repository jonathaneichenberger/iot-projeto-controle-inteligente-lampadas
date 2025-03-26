// Inclusão das funções e definições do sistema
#include <Arduino.h>
#include "funcoes.h"

// Interrupção acionada pelo sensor PIR
void IRAM_ATTR isMotionDetected() {
  motionDetected = true;
}

void setup() {
  Serial.begin(115200); // Inicializa comunicação serial
  initializeSystem(); // Configura os sensores e dispositivos
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), isMotionDetected, RISING); // Configura interrupção do PIR
}

void loop() {
  static unsigned long lastUpdate = 0;      // Controle de tempo para atualização
  static unsigned long lastUpdateTS = 0; 
  bool mustUpdateLCD = false;            // Flag para atualizar o LCD
  unsigned long currentMillis = millis();   // Obtém tempo atual
  float lastTemperature = -999;           // variavel de controle para mudanças de temperatura           

  // Verifica se houve detecção de movimento
  if (motionDetected) {
    myFlag = true;
    startTime = currentMillis; 
    motionDetected = false;
    Serial.println("Movimento detectado!");
    mustUpdateLCD = true;
  }

  // Verifica se o tempo limite expirou
  if (myFlag && (currentMillis - startTime >= delayTime)) {
    myFlag = false;
    Serial.println("Tempo expirado, desligando lâmpadas e ar condicionado.");
    startTime = 0;
    mustUpdateLCD = true;
  }

  // Atualiza temperatura a cada 1 segundo
  if (currentMillis - lastUpdate >= 1000) {
    lastUpdate = currentMillis;
    float temperature = dht.readTemperature();
    if (!isnan(temperature) && temperature != lastTemperature) {
      lastTemperature = temperature;
      if (myFlag) {
        airControlDHT(temperature); // Liga/desliga o NeoPixel do ar-condicionado
      } else {   
        stripAir.clear();
        stripAir.show();
      }

      if (currentMillis - lastUpdateTS >= 15000) {
        lastUpdateTS = currentMillis;
        sendDataThingSpeak(temperature);
      } 
      mustUpdateLCD = true;
    }
    lampControlPIR(); // Atualiza controle das lâmpadas
  }

  // Atualiza informações no LCD caso necessário
  if (mustUpdateLCD) {
    displayOnLCD(lastTemperature);
  }
}
