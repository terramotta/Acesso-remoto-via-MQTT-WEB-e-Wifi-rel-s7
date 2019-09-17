# Projeto: Acesso remoto à lâmpadas usando wifi

O projeto consiste no uso de um micro-controlador ESP-32 para o acionamento de relés que, por meio do uso Wi-fi, se comunicam com o celular de alguém.

### Pré-requisitos

  Primeiramente, faz-se necessário:
  - ESP32 e sua IDE (em conjunto com a biblioteca <ESP8266WiFi.h>)
  - Módulo de relé 5v
  - Cabos Jumper
  
 ### Instalação
 
 Em primeiro lugar, deve-se conectar o relé de forma paralela ao interruptor da lâmpada.
 Devemos então conectar o relé ao micro-controlador e dar upload no programa.

### Conhecendo o NodeMCU-32S ESP32
A chegada do ESP8266 ao mercado causou uma grande reviravolta, pois possibilitou que projetos envolvendo comunicação WiFi pudessem ser desenvolvidos sem a necessidade de se gastar muito dinheiro. Com os avanços e exigências do mercado ioT, a Espressif se supera mais uma vez e em janeiro de 2017 coloca oficialmente no mercado o ESP32, uma solução tecnológica que possui WiFi, Bluetooth, microprocessador dual core e muitos outros pontos que o tornam uma solução diferenciada.

![img00_conhecendo_o_nodemcu-32s_esp32_esp-32_wifi_bluetooth_esp8266_arduino_iot_esp-wroom-32](https://user-images.githubusercontent.com/53986050/65087560-98941080-d98c-11e9-9675-800b9a8c3c71.jpg)

O ESP32 é um dispositivo ioT (Internet das Coisas) que consiste de um microprocessador de baixa potência dual core Tensilica Xtensa 32-bit LX6 com suporte embutido à rede WiFi, Bluetooth v4.2 e memória flash integrada. Essa arquitetura permite que ele possa ser programado de forma independente, sem a necessidade de outras placas microcontroladoras como o Arduino, por exemplo. Dentre as principais características deste dispositivo, podemos citar: baixo consumo de energia, alto desempenho de potência, amplificador de baixo ruído, robustez, versatilidade e confiabilidade.

Na tabela abaixo temos um breve comparativo entre o ESP32, ESP8266 e o Arduino Uno R3:

![img01_conhecendo_o_nodemcu-32s_esp32_esp-32_wifi_bluetooth_esp8266_arduino_esp-wroom-32_iot](https://user-images.githubusercontent.com/53986050/65087630-dc871580-d98c-11e9-82c4-55650286c673.jpg)


### Explicação da conexão Wi-Fi no Esp-32

Primeiro de tudo, incluímos a biblioteca Wi-Fi para que pudéssemos nos conecntar à internet. Então, configuramos o Wi-fi com um IP e Senha para que conseguíssimos nos conectar à rede. Depois disso, definimos qual port usaremos para criar o web server.

No setup, conectamos ao Wi-Fi. Se a conexão para o Wi-Fi funcionar, a sentença "Connection Sucessful" aparecerá no monitor serial. Se a conexão falhar, o Esp-32 dará um delay de 500 etentará novamente a re-conexão à rede Wi-Fi. 
Este ciclo se repete até que WiFi.status() = WL_CONNECTED

A partir daqui, com o Wi-Fi conectado, o WebServer do Esp-32 será inciado. Ainda aqui, o endereço URL para a conexão será fornecido para o usuário no monitor serial.



### Ônus e Bônus do Projeto
 
 Este projeto visa, antes de tudo, o contato e a experiência com o módulo Wi-fi de certos micro-controladores, como é o caso do Esp8266 ou Esp-32. Aqui pretendemos, antes de tudo, realizar um diagrama simples, porém que fornece resultados que impressionam muito pessoas fora da área.
 
 Portanto, conclui-se que esse projeto permite-nos multiplexionar nossos conhecimentos para pessoas da vida corriqueira, como nossos familiares e amigos. Tal projeto possui o potencial de cativar o interesse e a curiosidade das pessoas quando veêm algo tão impressionante quanto a conexão wifi.

