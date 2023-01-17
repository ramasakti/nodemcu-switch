#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define RelayD5 D5

const char *ssid = "Prolink_DL7303_47DA";
const char *password = "rvd25Fz6wQ";

ESP8266WebServer server(80);
String webpage;

void setup() {
  Serial.begin(115200);
  pinMode(RelayD5, OUTPUT);
  delay(10);
  Serial.print("Koneksi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("...");
  }

  Serial.print("\n");
  Serial.print("IP: ");
  Serial.print(WiFi.localIP());
  Serial.print("\n");
  Serial.print("Terhubung ke: ");
  Serial.print(ssid);
  Serial.print("\n");

  webpage += "<!DOCTYPE html>";
  webpage += "<html lang=\"en\">";
  webpage += "<head>";
  webpage += "<meta charset='UTF-8'>";
  webpage += "<meta http-equiv='X-UA-Compatible' content='IE=edge'>";
  webpage += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  webpage += "<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD' crossorigin='anonymous'>";
  webpage += "<link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/uikit@3.15.19/dist/css/uikit.min.css'/>";
  webpage += "<script src='https://cdn.jsdelivr.net/npm/uikit@3.15.20/dist/js/uikit.min.js'></script>";
  webpage += "<script src='https://cdn.jsdelivr.net/npm/uikit@3.15.20/dist/js/uikit-icons.min.js'></script>";
  webpage += "<title>Smart School</title>";
  webpage += "</head>";
  webpage += "<body>";
  webpage += "<div class='container mt-5'>";
  webpage += "<div class='uk-child-width-1-1@m uk-grid-small uk-grid-match' uk-grid>";
  webpage += "<div>";
  webpage += "<div class='uk-card uk-card-default uk-card-body'>";
  webpage += "<h3 class='uk-card-title'>Switch Pintu Staff</h3>";
  webpage += "<div class='form-check form-switch'>";
  webpage += "<input class='form-check-input' type='checkbox' id='switchPintu' onchange='switchingPintu()'>";
  webpage += "<label class='form-check-label' for='switchPintu' id='labelPintu'></label>";
  webpage += "</div>";
  webpage += "</div>";
  webpage += "</div>";
  webpage += "</div>";
  webpage += "</div>";
  webpage += "</div>";
  webpage += "<script src='https://smaispa.sch.id/switchPintu.js'></script>";
  webpage += "<script src='https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js' integrity='sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN' crossorigin='anonymous'></script>";
  webpage += "</body>";
  webpage += "</html>";

  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });   
  
  server.on("/on", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(RelayD5, HIGH);
  });   
  
  server.on("/off", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(RelayD5, LOW);
  });

  server.begin();
  Serial.println("Server Murup");
}

void loop() {
  server.handleClient();
}