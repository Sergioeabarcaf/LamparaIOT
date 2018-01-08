// Librerias a usar
#include <ESP8266WiFi.h>

//Variables a usar
const char* ssid = "LabProtein";
const char* password = "teinpro_bal1602";
const int relay = 5;

uint8_t ownMAC[6];

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password);

  Serial.print("Conectando a ");
  //Se debe parsear el contenido obtenido desde WiFi. con c_str()
  Serial.printf("SSID: %s\n", WiFi.SSID().c_str());
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado! Su direccion IP es: ");
  Serial.println(WiFi.localIP());
  WiFi.macAddress(ownMAC);
  Serial.printf("MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",ownMAC[0],ownMAC[1],ownMAC[2],ownMAC[3],ownMAC[4],ownMAC[5]);

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
