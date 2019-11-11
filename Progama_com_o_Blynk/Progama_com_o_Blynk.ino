// Projeto – ESP32, Button Blynk
//-------- Bibliotecas -----------
#define BLYNK_PRINT Serial // Blynk Serial Print
#include <WiFi.h> // Wi-Fi
#include <WiFiClient.h> // Wi-Fi client 
#include <BlynkSimpleEsp32.h> // Blynk-ESP32
//-------- Token de Autenticação -----------
char auth[] = "vNd2aAXRlbZnR3sSozHSOwSK0VGI6F4R";
//-------- Configurações de Wi-Fi -----------
char ssid[] = "SUA_REDE";
char pass[] = "SENHA_DE_ACESSO";
void setup() {
  Serial.begin(115200);     // Taxa de transmissão 115200
  pinMode("PINO_DO_PROGRAMA", OUTPUT);           // Relé
  Blynk.begin(vNd2aAXRlbZnR3sSozHSOwSK0VGI6F4R, Bueno, Bueno302); // TOKEN+REDE+SENHA

}

void loop() {
  Blynk.run();

}
