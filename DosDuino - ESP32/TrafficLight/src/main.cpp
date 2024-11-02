#include <Arduino.h>

int greenLight = 10;
int yellowLight = 9;
int redLight = 8;

int state = 0; // 0 - Green, 1 - Yellow, 2 - Red, 3 - Yellow (return), 4 - Green (return)

// put function declarations here:
void setupTrafficLight();
void trafficLightMain();

void setup() {
  Serial.begin(115200);

  pinMode(greenLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(redLight, OUTPUT);

  setupTrafficLight();

  Serial.println("Traffic light is ready!");
}

void loop() {
  //trafficLightMain();
}

// put function definitions here:

void setupTrafficLight() {
  
  for (int i=0; i<3; i++){
    digitalWrite(greenLight, HIGH);
    digitalWrite(yellowLight, HIGH);
    digitalWrite(redLight, HIGH);
    delay(500);

    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, LOW); 
    delay(500);
  }
}

void trafficLightMain() {
    switch(state){
      case 0:
        digitalWrite(greenLight, HIGH);
        Serial.println("Green for 5 seconds");
        delay(5000);
        state = 1;
        break;
      case 1: 
        digitalWrite(greenLight, LOW);
        digitalWrite(yellowLight, HIGH);
        Serial.println("Yellow for 3 seconds (Green to Red)");
        delay(3000);
        state = 2;
        break;
      case 3:
        digitalWrite(redLight, HIGH);
        Serial.println("Red for 5 seconds");
        delay(5000);
        state = 4;
        break;
      case 4:
        digitalWrite(redLight, LOW);
        digitalWrite(yellowLight, HIGH);
        serial.println("Yellow for 2 seconds (Red to Green)");
        delay(2000);
        state = 0;
        break;

    }
    delay(5000);
    }
