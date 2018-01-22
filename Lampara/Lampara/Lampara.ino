// Librerias a usar
#include <ESP8266WiFi.h>

//Variables a usar
const char* ssid = "LabProtein";
const char* password = "teinpro_bal1602";
const int relay = 5;

const char* host = "192.168.1.166";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Conectando a ");
  //Se debe parsear el contenido obtenido desde WiFi. con c_str()
  Serial.printf("SSID: %s\n", WiFi.SSID().c_str());
  
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Conectado! ");

  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  
  Serial.println("Configuracion OK");

}

void loop() {

  WiFiClient client;

  digitalWrite(relay, HIGH);

  Serial.printf("\n Conectando con %s ... ", host);
    
    if (client.connect(host, 80))
    {
      Serial.println("Conectado con host");
      while (client.connected())
      {
        if (client.available())
        {
          Serial.println("contenido disponible");
          String line = client.readStringUntil('\n');
          Serial.println(line);
        }
        else{
          Serial.println("no hay contenido disponible");
        }
      }
      client.stop();
      Serial.println("\n[Disconnected]");
     }
     else
     {
        Serial.println("connection failed!]");
        client.stop();
     }
     delay(30000);
}
