// Librerias a usar
#include <ESP8266WiFi.h>

//Variables a usar
const char* ssid = "LabProtein";
const char* password = "teinpro_bal1602";
const int relay = 5;


void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password);

  Serial.print("Conectando a ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado! Su direccion IP es: ");
  Serial.println(WiFi.localIP());

  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.println("Configuracion OK");

}

void loop() {
  
  while (relay<100){
    digitalWrite(relay, HIGH);
    delay(2000);
    Serial.println("OFF");
    digitalWrite(relay, LOW);
    delay(2000);
    Serial.println("ON"); 
  }

}
