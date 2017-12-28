#include "ESP8266WiFi.h"
#include <Servo.h>

const char* ssid = "LabProtein";
const char* password = "teinpro_bal1602";
const char* host = "www.alimentacan.cl";
const int led = 5;
int pos;
Servo servo;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  
  //GPIO conectado al servomotor
  servo.attach(4);
  
  //Configuracion conexion WIFI
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(5000);
    Serial.print(WiFi.status());
  }
  Serial.println("\nWiFi connected");
  Serial.println(WiFi.localIP());  
  Serial.println();
    
  //inicalizador LED
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  //Inicializador servidor
  
  server.begin();
  Serial.println("Servidor listo");
}

void loop() 
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int val;
  if (req.indexOf("/gpio/0") != -1){
    val = 0;
    pos = 0;
    while (pos < 720){
      servo.write(pos);
      pos++;
    }
  }
  else if (req.indexOf("/gpio/1") != -1){
    val = 1;
    pos = 720;
    while (pos > 0){
      servo.write(pos);
      pos--;
    }
  }
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO2 according to the request
  digitalWrite(led, val);
    
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  s += (val)?"high":"low";
  s += "<form action='http://192.168.1.119/alimentacan/index.html' method='post'> <input type='submit' value='Volver' /> </form>";
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed

}


