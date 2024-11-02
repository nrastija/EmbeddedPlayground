#include <Arduino.h>
#include <string>

int greenLight = 10;
int yellowLight = 9;
int redLight = 8;

int polje[3] = {1, 0, 0}; // 1 - zelena, 2 - zuta, 3 - crvena

string high = "HIGH";
string low = "LOW";

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);

  pinMode(greenLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(redLight, OUTPUT);

  setupTrafficLight();

  Serial.println("Traffic light is ready!");
}

void loop() {
  trafficLightMain();
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

void trafficLightMain() {
    if (polje[0] == 1){
      digitalWrite(greenLight, HIGH);
      digitalWrite(yellowLight, LOW);
      digitalWrite(redLight, LOW);
      polje[0] = 0, polje[1] = 1, polje[2] = 0;
      Serial.println("Green for 5 seconds!");
    }
    else if (polje[1] == 1){
      digitalWrite(greenLight, LOW);
      digitalWrite(yellowLight, HIGH);
      digitalWrite(redLight, LOW);
      polje[0] = 0, polje[1] = 0, polje[2] = 1;
      Serial.println("Yellow for 5 seconds!");
    }
    else{
      digitalWrite(greenLight, LOW);
      digitalWrite(yellowLight, LOW);
      digitalWrite(redLight, HIGH);
      polje[0] = 1, polje[1] = 0, polje[2] = 0;
      Serial.println("Red for 5 seconds!");
    }
    delay(5000);
    }

}