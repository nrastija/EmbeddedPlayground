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
  pinMode(greenLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(redLight, OUTPUT);

  setupTrafficLight();


  int result = myFunction(2, 3);
}

void loop() {

}

// put function definitions here:
int setupTrafficLight() {


}