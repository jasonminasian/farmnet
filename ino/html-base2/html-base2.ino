#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
/* Wifi info */
const char ssid[25] = "Minifiber";
const char password[25] = "Dumb_dancing_DINO!!";
/* Put IP Address details */
IPAddress local_ip(192,168,40,70);
IPAddress gateway(192,168,40,1);
IPAddress subnet(255,255,255,0);
/* Set up webserver*/
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(int led){
  String ptr = "<!DOCTYPE html>\n";
  ptr +="<html>\n";
  ptr +="<head>\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>LED</h1>\n";
  ptr +="<p>Click to switch LED on and off.</p>\n";
  ptr +="<form method=\"get\">\n";
  if(led)
  ptr +="<input type=\"button\" value=\"LED OFF\" onclick=\"window.location.href='/ledoff'\">\n";
  else
  ptr +="<input type=\"button\" value=\"LED ON\" onclick=\"window.location.href='/ledon'\">\n";
  ptr +="</form>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
