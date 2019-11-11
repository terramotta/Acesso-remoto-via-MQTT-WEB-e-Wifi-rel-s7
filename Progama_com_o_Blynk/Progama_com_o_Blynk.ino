// Projeto – ESP32, Button Blynk
//-------- Bibliotecas -----------
#define BLYNK_PRINT Serial // Blynk Serial Print
#include <WiFi.h> // Wi-Fi
#include <WiFiClient.h> // Wi-Fi client 
#include <Blynk.h> // Blynk-ESP32
//-------- Token de Autenticação -----------
char auth[] = "vNd2aAXRlbZnR3sSozHSOwSK0VGI6F4R";
//-------- Configurações de Wi-Fi -----------
char ssid[] = "NOME_DA_REDE";
char pass[] = "SENHA";
//-------- Pino Virtual -----------
BLYNK_CONNECTED()
{         // Se conectar com Blynk
  Blynk.syncVirtual(V1);    // Sincroniza com o pino virtual V1
}
BLYNK_WRITE(V1){
  int pinValue = param.asInt();
  //Serial.println(pinValue);
  if (pinValue == 1) {
    digitalWrite(23, HIGH); // liga o relé
  }else{
    digitalWrite(23, LOW); // desliga o relé
  }
}



void setup() {
  Serial.begin(115200);     // Taxa de transmissão 115200
  pinMode(23, OUTPUT);           // Relé
  Blynk.begin(auth, ssid, pass); // TOKEN+REDE+SENHA

}

void loop() {
  Blynk.run();

}
