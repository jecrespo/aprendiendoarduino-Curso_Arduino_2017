// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 10;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT_PULLUP); //Resistencia de pullup interna
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); //Inicialmente apagado
  // initialize serial communication:
  Serial.begin(9600);
  lastButtonState = digitalRead(buttonPin); //inicializo el estado del pulsador
}

void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      buttonPushCounter++;
      Serial.println("Flanco Descendente");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
      // Comprobar pulsaciones para activar LED
      if (buttonPushCounter % 4 == 0) {
        int estadoLed = digitalRead(ledPin);
        digitalWrite(ledPin, !estadoLed);
        !estadoLed ? Serial.println("LED ENCENDIDO") : Serial.println("LED APAGADO"); //Operador ternario
      }
    }
    else {
      Serial.println("Flanco Ascendente");
    }
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;
}
