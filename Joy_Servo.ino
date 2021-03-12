#include <Servo.h>

Servo Servomoteur;

int VRx = A2;
int VRy = A3;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;
const int pin_servo = 5;

void setup() {
  Serial.begin(115200);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 

  Servomoteur.attach(pin_servo);
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, 0, 180);
  mapY = map(yPosition, 0, 1023, 0, 180);


  //if 
  Servomoteur.write(mapX);
  
 
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  //delay(100);
}
 
