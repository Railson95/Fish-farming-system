# SistemaPiscicultura

Sistema que possui um ESP32 e a ele integrado estão sensores de ph,  
temperatura e turbidez. Após coletados, esses parâmetros 
são enviados via protocolo MQTT para uma RaspBerry Pi 0 w, que faz a interface 
gráfica com o usuário via API node-red e também serve de servidor dedicado.

Todos os sensores foram validados e calibrados conforme sensores industriais.

Resultado final
---

![tela-final-tcc](https://user-images.githubusercontent.com/43474214/148824888-47212901-dafc-491a-bc55-f5975c9cb330.png)
