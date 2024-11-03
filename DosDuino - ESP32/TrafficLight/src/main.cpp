#include <Arduino.h>
#include <Keypad.h>

int greenLight = 13;
int yellowLight = 12;
int redLight = 11;

int state = 0; // 0 - Green, 1 - Yellow, 2 - Red, 3 - Yellow (return), 4 - Green (return)


const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {8, 7, 6, 5};
byte colPins[COLS] = {4, 3, 2, 1};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// put function declarations here:
void setupTrafficLight();
void trafficLightMain();
void trafficLightOff();
void trafficLightOn();

void setup() {
  Serial.begin(115200);

  pinMode(greenLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(redLight, OUTPUT);

  setupTrafficLight();

  Serial.println("Semafor pokrenut!");
}

void loop() {
  char key = keypad.getKey();

  Serial.println("Pritisnite 0 u iduću sekundu za gašenje semafora!");
  delay(1000);
  if (key == '0') {
    trafficLightOff(); 
  } else {
    trafficLightMain(); 
  }
  
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
  char key = keypad.getKey();
  
    if (key == '0'){
        trafficLightOff();
      }
    switch(state){
      case 0:
        digitalWrite(yellowLight, LOW); 
        digitalWrite(greenLight, HIGH);
        Serial.println("Zeleno svjetlo 5 sekundi");
        delay(5000);
        state = 1;
        break;
      case 1: 
        digitalWrite(greenLight, LOW);
        digitalWrite(yellowLight, HIGH);
        Serial.println("Žuto svjetlo 3 sekunde (Zeleno na Crveno)");
        delay(3000);
        state = 2;
        break;
      case 2:
        digitalWrite(yellowLight, LOW);
        digitalWrite(redLight, HIGH);
        Serial.println("Crveno svjetlo 5 sekundi");
        delay(5000);
        state = 3;
        break;
      case 3:
        digitalWrite(redLight, LOW);
        digitalWrite(yellowLight, HIGH);
        Serial.println("Žuto svjetlo 3 sekunde (Crveno na Zeleno)");
        delay(3000);
        state = 0;
        break;
      }  
    }

void trafficLightOff(){
  char key;
  Serial.println("Semafor ugašen dok se ne stisne 9!");
  do{
    key = keypad.getKey();
    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight, HIGH);
    digitalWrite(redLight, LOW); 
    delay(500);
    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, LOW); 
    delay(500);
  } while(key != '9');

  trafficLightOn();
}

void trafficLightOn(){
  Serial.println("Semafor ponovno radi!");

  for (int i=0; i<3; i++){
    digitalWrite(greenLight, HIGH);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH);
    delay(500);

    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight, HIGH);
    digitalWrite(redLight, LOW); 
    delay(500);
  }
  delay(2000);
}