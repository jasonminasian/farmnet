#include "ESPAsyncWebServer.h"
#include <ESP8266WiFi.h>

// Replace with your network credentials
char ssid[25] = "Minifiber";
char password[25] = "Dumb_dancing_DINO!!";
/* Set up webserver*/
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem;}
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin:0px auto; padding-bottom: 25px;}
    .switch {position: relative; display: inline-block; width: 120px; height: 68px} 
    .switch input {display: none}
    .slider {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; border-radius: 6px}
    .slider:before {position: absolute; content: ""; height: 52px; width: 52px; left: 8px; bottom: 8px; background-color: #fff; -webkit-transition: .4s; transition: .4s; border-radius: 3px}
    input:checked+.slider {background-color: #b30000}
    input:checked+.slider:before {-webkit-transform: translateX(52px); -ms-transform: translateX(52px); transform: translateX(52px)}
  </style>
</head>
<body>
  <h2>ESP Web Server</h2>
</body>
</html>
)rawliteral";

void wifiConnect(void) {
  WiFi.begin(ssid, password);
  Serial.println("connecting");
  delay(1000);
  while(WiFi.status() !=WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }
  if(WiFi.status() == WL_CONNECTED) {
    Serial.println(WiFi.localIP());
    }
}

void setup(){
Serial.begin(115200);
  wifiConnect();
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html);
});

server.begin();
}

void loop() {
}
