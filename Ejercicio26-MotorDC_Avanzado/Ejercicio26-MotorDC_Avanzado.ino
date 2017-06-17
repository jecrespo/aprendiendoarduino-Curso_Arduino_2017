//Pines
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

//Estados botones
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

//Estados Motor
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  Serial.begin(9600);

  //Botones
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);

  //Motor
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  //Motor apagado
  digitalWrite(enablePin, LOW);
}

void loop() {
  // leo estado de los botones y el potenciometro
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4;

  //Detecto flancos ascendentes para cambiar velocidad y encendido motor
  if (onOffSwitchState != previousOnOffSwitchState) {
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  if (directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  //Control dirección de giro
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  //Control encendido/apagado y velocidad con el pin enable del L293D
  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }

  //Actualizar estados
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;

  //Imprimo por el Serial Plotter
  Serial.print(motorEnabled*100);
  Serial.print(" ");
  Serial.print(motorSpeed);
  Serial.print(" ");
  Serial.println(motorDirection*100);
}
