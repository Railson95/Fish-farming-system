#include <driver/adc.h>
#include <esp_adc_cal.h>

#include <WiFi.h>
#include <PubSubClient.h>

#define V_REF 1100

//Variaveis do protocolo MQTT
const char* ssid = "Virus1";
const char* password =  "Test(123)";
const char* mqttServer = "192.168.0.107";//endereço ip da raspberry, pode mudar se o roteador não estiver configurado como estático
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

//Variáveis da temperatura
float temperatura = 0.0;
float somaTemperatura = 0.0;
float mediaTemperatura = 0.0;
float bufTemperatura[100];

//Variáveis da turbidez
float turbidez = 0.0;
float voltage2 = 0.0;
float bufTurbidez[100];
float somaTurbidez = 0.0;
float mediaTurbidez = 0.0;

//Variáveis do pH
unsigned long int avgValue;
int temp;

//Strings para enviar os dados via protocolo
char turbidezString[30];
char temperaturaString[30];
char phString[30];

void setup()
{

  //Configurações das entradas
  adc1_config_width(ADC_WIDTH_12Bit);
  adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11); //seta a porta 32 para leitura da turbidez
  adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_DB_11); //seta a porta 35 para leitura do ph
  adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11); //seta a porta 34 para leitura da temperatura


  //Configurações do protocolo MQTT, para conexão a rede wifi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Iniciando conexao com a rede WiFi..");
  }

  Serial.println("Conectado na rede WiFi!");
  Serial.begin(9600);
}

//Função que lê a temperatura
float leituraTemperatura() {
  esp_adc_cal_characteristics_t characteristics;
  esp_adc_cal_get_characteristics(V_REF, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, &characteristics);

  for (int i = 0; i < 10; i++) {
    uint32_t voltage = adc1_to_voltage(ADC1_CHANNEL_6, &characteristics);
    temperatura = float(voltage) / 10;
    bufTemperatura[i] = temperatura;
    delay(30);
  }


  for (int i = 0; i < 10; i++)
  {
    somaTemperatura = bufTemperatura[i] + somaTemperatura;
    delay(30);
  }

  mediaTemperatura = somaTemperatura / 10;



  Serial.print("Temperatura: ");
  Serial.println(mediaTemperatura);

  somaTemperatura = 0.0;

  return mediaTemperatura;

  //delay(2000);
}


float leituraTurbidez() {
  esp_adc_cal_characteristics_t characteristics;
  esp_adc_cal_get_characteristics(V_REF, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, &characteristics);

  for (int i = 0; i < 99; i++)
  {
    uint32_t voltage = adc1_to_voltage(ADC1_CHANNEL_4, &characteristics); //realiza a leitura da tensão retornada pelo esp32
    voltage2 = float(voltage) / 1000;
    turbidez = -1055.1 * voltage2 + 2461.2;
    bufTurbidez[i] = turbidez;
    delay(30);
  }



  //printf("%.3f V\n", voltage2);

  for (int i = 0; i < 99; i++)
  {
    somaTurbidez = bufTurbidez[i] + somaTurbidez;
    delay(30);
  }

  mediaTurbidez = somaTurbidez / 100;

  Serial.print("Turbidez: ");
  printf("%.1f NTU\n", mediaTurbidez);

  somaTurbidez = 0.0;

  return mediaTurbidez;

  //delay(2000);
}

//Função que calcula a média dos valores do ph
unsigned long int media(int buf[10]) {

  avgValue = 0;
  for (int i = 0; i < 10; i++)
    avgValue += buf[i];

  return avgValue;
}

float leituraPh() {
  int buf[10];
  esp_adc_cal_characteristics_t characteristics;
  esp_adc_cal_get_characteristics(V_REF, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, &characteristics);

  uint32_t voltage = adc1_to_voltage(ADC1_CHANNEL_7, &characteristics);// realiza a leitura da tensão retornada pelo esp32


  for (int i = 0; i < 10; i++)
  {
    buf[i] = voltage;
    delay(30);
  }

  int mediaPH = media(buf) / 10;

  float pHVol = (float)mediaPH / 1000;
  float phValue = -9.22 * pHVol + 22.45;
  Serial.print("pH = ");
  Serial.println(phValue);
  return phValue;
  delay(2000);
}

void loop()
{
  //leituraTurbidez();
  //leituraTemperatura();
  //leituraPh();
  reconectabroker();
//
  //dtostrf é uma função que pega um float e converte ele para guardar em uma string
  dtostrf(leituraTurbidez(), 1, 2, turbidezString);//chama a função que faz a leitura da turbidez e retorna um float
  dtostrf(leituraTemperatura(), 1, 2, temperaturaString);//chama a função que faz a leitura da temperatura e retorna um float
  dtostrf(leituraPh(), 1, 2, phString);//chama a função que faz a leitura do ph e retorna um float

  //Envia a mensagem ao broker
    client.publish("turbidez", turbidezString);
    Serial.println("Mensagem1 enviada com sucesso...");
    delay(3000);
 
    client.publish("ph", phString);
    Serial.println("Mensagem2 enviada com sucesso...");
    delay(3000);
  
    client.publish("temperatura", temperaturaString);
    Serial.println("Mensagem3 enviada com sucesso...");
    delay(3000);
  
  //  //Aguarda 30 segundos para enviar uma nova mensagem
    delay(5000);
}

void reconectabroker()
{
  //Conexao ao broker MQTT
  client.setServer(mqttServer, mqttPort);
  while (!client.connected())
  {
    Serial.println("Conectando ao broker MQTT...");
    if (client.connect("ESP32Client"))
    {
      Serial.println("Conectado ao broker!");
    }
    else
    {
      Serial.print("Falha na conexao ao broker - Estado: ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
