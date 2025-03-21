#include "funcoes.h"


// Definições das variáveis globais
volatile bool movimentoDetectado = false;
bool myFlag = false;  
unsigned long previousMillis = 0;
const unsigned long interval = 5; // Intervalo de tempo entre aumentos de brilho
unsigned long startTime = 0;
unsigned long delayTime = 100000; // Tempo de duração da lâmpada (100 segundos)

// Variaveis para conexão com a internet
WiFiClient client;

const char* ssid = "Wokwi-GUEST";
const char* senha = "";
unsigned long channelID = 2884497;
const char* writeAPIKey = "H39UCHX655KFTXM6"; // Substitua pela sua chave de escrita

// Configurações do sensor DHT
DHT dht(DHT_PIN, DHT_TYPE);

// Definição do LCD (RS, E, D4, D5, D6 e D7)
LiquidCrystal lcd(19, 18, 5, 21, 2, 15);

// Configuração dos NeoPixels
Adafruit_NeoPixel strip(PIXEL_COUNT, LAMP_PIXEL_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripAir(PIXEL_COUNT, AIR_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void inicializarSistema() {
  pinMode(PIR_PIN, INPUT);
  pinMode(DHT_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(LAMP_PIXEL_PIN, OUTPUT);
  pinMode(AIR_PIXEL_PIN, OUTPUT);
  
  dht.begin();
  lcd.begin(20, 4);

  // Inicializa NeoPixels
  strip.begin();
  strip.show();     // Inicializa com os LED off  
  stripAir.begin();
  stripAir.show(); 

  conectarWiFi(ssid, senha);

  inicializarThingSpeak();

  // Exibe mensagem inicial no LCD
  lcd.setCursor(2, 0);
  lcd.print("  Monitoramento  ");
  delay(2000);
  lcd.clear();
}

void controleArDHT(float temperatura) {
  uint32_t cor;
  if (temperatura > 25) {            // RGB: Red, Green, Blue valor máximo 255.
    cor = stripAir.Color(0, 0, 255); // Azul: ar-condicionado ligado no frio
  } else if (temperatura < 20) {
    cor = stripAir.Color(255, 0, 0); // Vermelho: ar-condicionado ligado no quente
  } else {
    stripAir.clear();
    stripAir.show();
    return;
  }

  // Acende todos os LEDs do NeoPixel do ar-condicionado
  for (int i = 0; i < PIXEL_COUNT; i++) {
    stripAir.setPixelColor(i, cor);
  }
  stripAir.show();
}

void controleLampadasPIR() {
  int brightness;
  float lux = getLux();

  if (myFlag) {
    if (lux <= 400) {  
      brightness = map(lux, 0, 400, 255, 150);
      uint32_t whiteColor = strip.ColorHSV(0, 0, brightness);
      for (int i = 0; i < PIXEL_COUNT; i++) {
        strip.setPixelColor(i, whiteColor);
      }
    } else if (lux > 400 && lux <= 3000) {
      brightness = map(lux, 400, 3000, 150, 0);
      uint32_t yellowColor = strip.ColorHSV(40 * 65536 / 360, 255, brightness);
      for (int i = 0; i < PIXEL_COUNT; i++) {
        strip.setPixelColor(i, yellowColor);
      }
    } else {
      strip.clear();
    }
  
    strip.show();
  } else {
    strip.clear();
    strip.show();
  }
}

void exibirNoLCD(float temperatura) {
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C    ");  

  lcd.setCursor(0, 1);
  lcd.print("Mov: ");
  lcd.print(myFlag ? "DETECTADO" : "NENHUM    ");

  lcd.setCursor(0, 2);
  lcd.print("Lampadas: ");
  lcd.print(myFlag ? "LIGADAS   " : "DESLIGADAS");
  
  lcd.setCursor(0, 3);
  lcd.print("Ar Cond: ");
  lcd.print((temperatura < 20 || temperatura > 25) && myFlag ? "LIGADO   " : "DESLIGADO");
}

float getLux() {
  int analogValue = analogRead(LDR_PIN);
  float voltage = analogValue / 4095.0 * 5;  
  float resistance = 2000 * voltage / (1 - voltage / 5);  
  float lux = pow(50 * 1e3 * pow(10, 0.7) / resistance, (1 / 0.7));
  return lux;
}

void conectarWiFi(const char* ssid, const char* senha) {
  Serial.begin(115200);
  WiFi.begin(ssid, senha);
  lcd.setCursor(5, 0);
  lcd.print("CONECTANDO     ");
  lcd.setCursor(9,1);
  lcd.print("AO         ");
  lcd.setCursor(8,2);
  lcd.print("WIFI        ");
  delay(4000);

  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  if (WiFi.status() == WL_CONNECTED) {
    lcd.clear();
  }
  Serial.println();
  Serial.println("Conectado ao WiFi");
  lcd.setCursor(5, 0);
  lcd.print("CONECTADO      ");
  delay(4000);
}

void enviarDadosThingSpeak(float temperatura) {
  ThingSpeak.setField(1, temperatura);

  // Enviar os dados
  int httpCode = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (httpCode == 200) {
    Serial.println("Dados enviados com sucesso");
  } else {
    Serial.println("Falha ao enviar dados");
  }
}

void inicializarThingSpeak() {
  ThingSpeak.begin(client);
}