#include <Arduino.h>
#include <map>
#include <tuple>
#include <cstdlib>

int bluePin = 15;
int redPin = 13;
int greenPin = 14;

void setColor(int red, int blue, int green){
  digitalWrite(redPin, red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
}

void greeting(){
  Serial.println("Hello");
  
  for (int i=0; i<3; i++){
    setColor(HIGH, HIGH, HIGH);
    delay(100);
    setColor(LOW, LOW, LOW);
    delay(100);
  }
}

// Red - 1, 0, 0
// Blue - 0, 1, 0
// Green - 0, 0, 1

std::map<String, std::tuple<int, int, int>> rgbCmnds = {
  {"O", std::make_tuple(0, 0, 0)},
  {"R", std::make_tuple(1, 0, 0)},
  {"B", std::make_tuple(0, 0, 1)},
  {"G", std::make_tuple(0, 1, 0)},
  {"W", std::make_tuple(1, 1, 1)}
};

void processCommand(String color){
  Serial.println("You entered: " + color);

  /*if(rgbCmnds.find(color) != rgbCmnds.end()){
    auto matchingColor = rgbCmnds[color];

    int r = std::get<0>(matchingColor);
    int g = std::get<1>(matchingColor);
    int b = std::get<2>(matchingColor);

    setColor(r, g, b);
  }
  else
    Serial.println("Color not found...");*/

    srand(time(0));

    int r = rand() % 2;
    int g = rand() % 2;
    int b = rand() % 2;

    Serial.println(r + g + b);
    setColor(r, g, b);
}

void readSerialInput()
{
  String input = "";

  while (Serial.available() > 0){
    byte incoming = Serial.read();
    input.concat((char) incoming);
  }

  if (input != ""){
    input.trim();
    Serial.println("You entered " + input);
    processCommand(input);
    input = "";
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(redPin, OUTPUT);   
  pinMode(bluePin, OUTPUT);   
  pinMode(greenPin, OUTPUT);   

  greeting();

  Serial.println("Please enter something");

}

void loop() {
  processCommand("temp");
  delay(100);
}
