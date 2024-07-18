#include <DHT.h>
#include <DHT_U.h>

// Define pin for soil moisture sensor
const int soilMoisturePin = A0;
// Define pin for methane sensor's digital output
const int methaneSensorPin = 2;
// Define pin for relay control
const int relayPin = 8;
// Define pin for buzzer
const int buzzerPin = 11;

void setup() {
  Serial.begin(9600);
  // Initialize pins
  pinMode(soilMoisturePin, INPUT);
  pinMode(methaneSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize the relay (pump is off)
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read soil moisture level
  int soilMoisture = analogRead(soilMoisturePin);

  // Read methane level
  int methaneLevel = digitalRead(methaneSensorPin);

  // Check soil moisture and control water pump
  if (soilMoisture < 500) {
    digitalWrite(relayPin, HIGH); // Turn pump on
  } else {
    digitalWrite(relayPin, LOW);  // Turn pump off
  }
  
  // Control buzzer based on methane level
  if (methaneLevel == HIGH) {
    digitalWrite(buzzerPin, HIGH); // Buzzer on
  } else {
    digitalWrite(buzzerPin, LOW);  // Buzzer off
  }

  Serial.print("Methane Level: ");
  Serial.print(methaneLevel == HIGH ? "Detected" : "Not Detected");
  Serial.print("\t Soil Moisture Level: ");
  Serial.println(soilMoisture);

  delay(1000); // Delay for stability (adjust as needed)
}
