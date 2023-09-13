#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";  // Reemplaza con el nombre de tu red Wi-Fi
const char* password = ""; // Reemplaza con la contraseña de tu red Wi-Fi
const char* serverUrl = ""; // Reemplaza con la URL de tu servidor PHP

int pinpir = 35;

void setup() {
  Serial.begin(115200);
  pinMode(pinpir, INPUT);
  
  Serial.println("Iniciando...");
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wi-Fi...");
  }
  
  Serial.println("Conectado a la red Wi-Fi.");
}

void loop() {
  int valor = digitalRead(pinpir);
  Serial.print("Valor del sensor PIR: ");
  Serial.println(valor);
  delay(500);
  
  if (WiFi.status() == WL_CONNECTED) {
    String mac = WiFi.macAddress();
    HTTPClient http;
    
    String postData = "mac=" + mac + "&valor=" + String(valor);
    
    Serial.println("Enviando datos al servidor...");
    Serial.println("Datos a enviar: " + postData);
    
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    int httpResponseCode = http.POST(postData);
    
    if (httpResponseCode > 0) {
      Serial.println("Datos enviados exitosamente al servidor.");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error en la solicitud HTTP. Código de respuesta: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  } else {
    Serial.println("Desconectado de la red Wi-Fi.");
  }
  
  delay(2500);
}