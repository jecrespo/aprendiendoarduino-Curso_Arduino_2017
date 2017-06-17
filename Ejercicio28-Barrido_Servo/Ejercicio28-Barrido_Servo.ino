#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int controlPin = 2;

int velocidad = 0;
int pulsacion = 0;
int estado_boton;
int estado_boton_anterior;

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(20);

  pinMode(controlPin, INPUT_PULLUP);
  estado_boton_anterior = digitalRead(controlPin);
}

void loop() {
  detecta_pulsacion();

  if (pulsacion > 0) {
    for (pos = 20; pos <= 160; pos += 5) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(velocidad);
      detecta_pulsacion();
    }

    for (pos = 160; pos >= 20; pos -= 5) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(velocidad);
      detecta_pulsacion();
    }
  }
}

void detecta_pulsacion() {
  // leo estado boton
  estado_boton = digitalRead(controlPin);

  //Detección pulsación boton
  if (estado_boton != estado_boton_anterior) {
    if (estado_boton == HIGH) {
      Serial.println("Nueva pulsacion");
      pulsacion++;
      switch (pulsacion) {
        case 1:
          velocidad = 30;
          break;
        case 2:
          velocidad = 20;
          break;
        case 3:
          velocidad = 10;
          break;
        case 4:
          pulsacion = 0;
          break;
      }
    }
  }
  estado_boton_anterior = estado_boton;
}

