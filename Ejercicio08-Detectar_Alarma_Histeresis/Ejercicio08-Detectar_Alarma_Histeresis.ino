const int analogPin = A0;   // pin that the sensor is attached to
const int ledPin = 13;      // pin that the LED is attached to
const int threshold_base = 400;
int threshold;
const int histeresis = 50;  //Valor de la histeresis
boolean alarma;				//1 = ALARMA, 0 = NO ALARMA

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
  int analogValue = analogRead(analogPin);	//Inicializo el valor de la alarma
  if (analogValue > threshold_base) {
    alarma = 1;
    threshold = threshold_base - histeresis;
  }
  else {
    alarma = 0;
    threshold = threshold_base + histeresis;
  }
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);	//En cada loop compruebo el valor de la entrada analógica

  // if the analog value is high enough, turn on the LED:
  if (analogValue > threshold) {
    if (alarma == 0) {
      digitalWrite(ledPin, HIGH);
      Serial.println("ALARMA!!!!!!!!!!!!!!");
      alarma = 1;
      threshold = threshold_base - histeresis;
    }
  } else {
    if (alarma == 1) {
      digitalWrite(ledPin, LOW);
      Serial.println("ALARMA RECUPERADA");
      alarma = 0;
      threshold = threshold_base + histeresis;
    }
  }

  // print values
  Serial.print(analogValue);
  Serial.print(" ");
  Serial.print(threshold);
  Serial.print(" ");
  Serial.println(alarma * 1024);
  delay(50);
  delay(50);
}
