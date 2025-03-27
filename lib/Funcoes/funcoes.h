// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

#include <DHT.h>
#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <ThingSpeak.h>


// Definição dos pinos
#define PIR_PIN 23          // Pino do sensor de movimento PIR
#define DHT_PIN 16          // Pino do sensor de temperatura DHT22
#define LAMP_PIXEL_PIN 6    // Pino do NeoPixel das lâmpadas
#define AIR_PIXEL_PIN 32    // Pino do NeoPixel do ar-condicionado
#define DHT_TYPE DHT22      // Tipo do sensor DHT
#define PIXEL_COUNT 16      // Quantidade de LEDs nos NeoPixels
#define LDR_PIN 33          // Pino do sensor de luz ambiente (LDR)

// Protótipos das funções
void initializeSystem();
void conectWiFi(const char* ssid, const char* password, const int wifiChannel);
void bootThingSpeak();
void sendDataThingSpeak(float temperature);
void airControlDHT(float temperature);
void lampControlPIR();
void displayOnLCD(float temperature);
float getLux();

// Variáveis globais
extern volatile bool motionDetected;
extern bool myFlag;
extern bool stopPixel;
extern unsigned long startTime;
extern unsigned long delayTime;
extern DHT dht;
extern Adafruit_NeoPixel strip;
extern Adafruit_NeoPixel stripAir;
extern LiquidCrystal lcd;

#endif