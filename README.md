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

Assim como o NodeMCU foi desenvolvido tendo como base um ESP8266, o ESP32 possui também uma plataforma de prototipagem correspondente, no caso, o NodeMCU-32S:

![img02_conhecendo_o_nodemcu-32s_esp32_esp-32_wifi_bluetooth_esp8266_arduino_iot_esp-wroom-32](https://user-images.githubusercontent.com/53986050/65087917-e0676780-d98d-11e9-9953-7c91b9585b44.jpg)

O NodeMCU-32S é uma plataforma de prototipagem baseada no ESP32 e que é comumente utilizada no desenvolvimento de projetos ioT. A placa já conta com conversor USB serial integrado e porta micro USB para alimentação e programação.

O controlador do NodeMCU-32S em questão é o módulo ESP-WROOM-32. Além do ESP32, o ESP-WROOM-32 possui também um cristal de 40MHz, memória flash integrada de 4MB, antena embutida e blindagem EMI.

OBS: há no mercado outros modelos de NodeMCU-32S que são baseados em outros controladores, contudo, todos eles possuem variantes do ESP32.

Abaixo temos as principais características do NodeMCU-32S:

<ol> Baseado no SoC (System on Chip) ESP32-D0WDQ6 (Datasheet ESP-32)
– Módulo controlador ESP-WROOM-32 (Datasheet ESP-WROOM-32)
– Microprocessador dual core Tensilica Xtensa 32-bit LX6
– Clock ajustável de 80MHz até 240MHz
– Desempenho de até 600 DMIPS
– Possui ROM de 448KB
– Possui SRAM de 520KB
– Possui RTC Slow SRAM de 8KB
– Possui RTC Fast SRAM de 8KB
– Possui memória flash externa de 32Mb (4 megabytes)
– Opera na faixa de 2.2V – 3.6VDC
– Pode ser alimentado com 5VDC através do conector micro USB
– Opera em nível lógico 3.3V (não tolerante a 5V)
– Opera com corrente típica de 80mA
– Corrente máxima por pino é de 12mA (recomenda-se usar 6mA)
– Possui Interfaces de GPIO / Sensores capacitivos / ADC / DAC / LNA pré amplificado / CAN
– Possui 36 GPIOs
– GPIOs com função PWM / I2C e SPI
– Possui ADC (conversor analógico digital) de 18 canais com resolução de 12 bits
– Possui 2 DAC (conversor digital analógico) com resolução de 8 bits
– Possui suporte a redes WiFi padrão 802.11 b/g/n
– O WiFi opera na faixa de 2.4 a 2.5GHz
– WiFi possui opções de segurança WPA / WPA2 / WPA2-Enterprise / WPS
– WiFi possui opções de criptografia AES / RSA / ECC / SHA
– Opera nos modos Station / SoftAP / SoftAP + Station/ P2P
– Possui Antena integrada
– Possui Bluetooth v4.2 BR / EDR e BLE (Bluetooth Low Energy)
– Opera em temperaturas na faixa de -40º a 85ºC
– Programável via USB, host ou WiFi (OTA / Over The Air)
– Compatível com a IDE do Arduino
– Compatível com módulos e sensores utilizados no Arduino

As informações completas sobre as especificações da placa, podem ser vistas no Datasheet ESP-WROOM-32 e no Datasheet ESP-32.

Na imagem abaixo temos a pinagem do NodeMCU-32S:

![img04_conhecendo_o_nodemcu-32s_esp32_esp-32_wifi_bluetooth_esp8266_arduino_iot_esp-wroom-32-768x729](https://user-images.githubusercontent.com/53986050/65087967-0bea5200-d98e-11e9-82f7-a17071abc0f7.png)



### Explicação da conexão Wi-Fi no Esp-32

Primeiro de tudo, incluímos a biblioteca Wi-Fi para que pudéssemos nos conecntar à internet. Então, configuramos o Wi-fi com um IP e Senha para que conseguíssimos nos conectar à rede. Depois disso, definimos qual port usaremos para criar o web server.

No setup, conectamos ao Wi-Fi. Se a conexão para o Wi-Fi funcionar, a sentença "Connection Sucessful" aparecerá no monitor serial. Se a conexão falhar, o Esp-32 dará um delay de 500 etentará novamente a re-conexão à rede Wi-Fi. 
Este ciclo se repete até que WiFi.status() = WL_CONNECTED

A partir daqui, com o Wi-Fi conectado, o WebServer do Esp-32 será inciado. Ainda aqui, o endereço URL para a conexão será fornecido para o usuário no monitor serial.



### Ônus e Bônus do Projeto
 
 Este projeto visa, antes de tudo, o contato e a experiência com o módulo Wi-fi de certos micro-controladores, como é o caso do Esp8266 ou Esp-32. Aqui pretendemos, antes de tudo, realizar um diagrama simples, porém que fornece resultados que impressionam muito pessoas fora da área.
 
 Portanto, conclui-se que esse projeto permite-nos multiplexionar nossos conhecimentos para pessoas da vida corriqueira, como nossos familiares e amigos. Tal projeto possui o potencial de cativar o interesse e a curiosidade das pessoas quando veêm algo tão impressionante quanto a conexão wifi.

