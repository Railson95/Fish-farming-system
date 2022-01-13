# Sistema de Piscicultura, usando IoT
Sobre
=================
Sistema que possui um ESP32 e a ele integrado estão sensores de ph, temperatura e turbidez. Após coletados, esses parâmetros são enviados via protocolo 
MQTT para uma RaspBerry Pi 0 w, que faz a interface gráfica com o usuário via API node-red e também serve de servidor dedicado.Todos os sensores foram 
validados e calibrados conforme sensores industriais.

<img src="https://img.shields.io/badge/c++-esp32-blue"/> <img src="https://img.shields.io/badge/raspberryPi0W-NodeRed-orange"/>

Tabela de conteúdos
=================
<!--ts-->
   * [Sobre](#Sobre)
   * [Tabela de Conteudo](#tabela-de-conteudo)
   * [Como usar](#como-usar)
      * [Pre Requisitos](#pre-requisitos)
      * [Funcionamento](#funcionamento)
   * [Tests](#testes)
      * [Resultado final do sistema com os dados mostrados na API Node-Red](#resultado-final-do-sistema-com-os-dados-mostrados-na-API-Node-Red)
   * [Status do projeto](#status-do-projeto)
   * [Tecnologias](#tecnologias)
<!--te-->

Como usar
=================

Pre Requisitos
----
```bash
Para rodar o sistema será necessário a instalação
*IDE Arduino, configurada com a biblioteca do ESP32
*Configuração dos ips e senhas da rede wifi
*Raspberry Pi, instalação do mosquito 
*Instalação da API Node-Red na Raspberry Pi
```

Funcionamento
----
```bash
Os dados dos sensores serão coletados e enviados de forma automática para a Raspberry Pi
```

Tests
=================
Resultado final do sistema com os dados mostrados na API Node-Red
----
<div align="center">
<img src="https://user-images.githubusercontent.com/43474214/148824888-47212901-dafc-491a-bc55-f5975c9cb330.png" width="700px" />
</div>


Status do projeto
=================

<h4 align="center"> 
	🚧  Sistema de piscicultura de baixo custo 🚀 Terminado...  🚧
</h4>

Tecnologias
=================

<img src="https://img.shields.io/badge/c++-esp32-blue"/> <img src="https://img.shields.io/badge/raspberryPi0W-NodeRed-orange"/> <img src="https://img.shields.io/badge/Mosquito-Broker-MQTT"/> <img src="https://img.shields.io/badge/IDE-Arduino-orange"/> <img src="https://img.shields.io/badge/Instrumentação-Sensores-orange"/>

Autor
---

Feito por Railson Maritns 👋🏽 Entre em contato!







		

