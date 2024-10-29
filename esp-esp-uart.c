//Code for Sender ESP32 (UART2)
#include "HardwareSerial.h"

#define TX2_PIN 17 // TX pin for UART2
#define RX2_PIN 16 // RX pin for UART2 (not used in sender)

void setup() {
  Serial.begin(115200);                           // Initialize USB serial monitor
  Serial2.begin(9600, SERIAL_8N1, RX2_PIN, TX2_PIN); // Initialize UART2 with baud rate 9600
  
  Serial.println("Sender ESP32 ready to transmit data over UART2...");
}

void loop() {
  const char *data = "Hello!\n";
  
  Serial2.print(data); // Send data over UART2 using print()
  Serial.print("Data sent: ");
  Serial.println(data);

  delay(1000); // Send data every second
}


// Code for Receiver ESP32 (UART2)
#include "HardwareSerial.h"

#define TX2_PIN 17 // TX pin for UART2 (not used in receiver)
#define RX2_PIN 16 // RX pin for UART2

void setup() {
  Serial.begin(115200);                           // Initialize USB serial monitor
  Serial2.begin(9600, SERIAL_8N1, RX2_PIN, TX2_PIN); // Initialize UART2 with baud rate 9600

  Serial.println("Receiver ESP32 ready to receive data over UART2...");
}

void loop() {
  if (Serial2.available() > 0) {
    String receivedData = Serial2.readStringUntil('\n'); // Read the string until newline
    Serial.println("Data received: " + receivedData);
  }
  // Delay is removed for continuous processing
}