# Projeto: Acesso remoto à lâmpadas usando wifi

O projeto consiste no uso de um micro-controlador ESP-32 para o acionamento de relés que, por meio do uso Wi-fi, se comunicam com o celular ou computador de alguém.

### Pré-requisitos

  Primeiramente, faz-se necessário:
  - ESP32 e sua IDE (em conjunto com a biblioteca <ESP8266WiFi.h>)
  - Módulo de relé 5v
  - Cabos Jumper
  
 ### Instalação
 
 Em primeiro lugar, deve-se conectar o relé de forma paralela ao interruptor da lâmpada.
  Devemos então conectar o relé ao micro-controlador e dar upload no programa,



### Explicação da conexão Wi-Fi no Esp-32

Primeiro de tudo, incluímos a biblioteca Wi-Fi para que pudéssemos nos conecntar à internet. Então, configuramos o Wi-fi com um IP e Senha para que conseguíssimos nos conectar à rede. Depois disso, definimos qual port usaremos para criar o web server.

No setup, conectamos ao Wi-Fi. Se a conexão para o Wi-Fi funcionar, a sentença "Connection Sucessful" aparecerá no monitor serial. Se a conexão falhar, o Esp-32 dará um delay de 500 etentará novamente a re-conexão à rede Wi-Fi. 
Este ciclo se repete até que WiFi.status() = WL_CONNECTED

A partir daqui, com o Wi-Fi conectado, o WebServer do Esp-32 será inciado. Ainda aqui, o endereço URL para a conexão será fornecido para o usuário no monitor serial.



## Ônus e Bônus do Projeto
 
 Este projeto visa, antes de tudo, o contato e a experiência com o módulo Wi-fi de certos micro-controladores, como é o caso do Esp8266 ou Esp-32. Aqui pretendemos, antes de tudo, realizar um diagrama simples, porém que fornece resultados que impressionam muito pessoas fora da área.
 
 Portanto, conclui-se que esse projeto permite-nos multiplexionar nossos conhecimentos para pessoas da vida corriqueira, como nossos familiares e amigos. Tal projeto possui o potencial de cativar o interesse e a curiosidade das pessoas quando veêm algo tão impressionante quanto a conexão wifi.

