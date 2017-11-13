#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 13;      // pin that the LED is attached to
const float threshold_base = 26;  // an arbitrary threshold level that's in the range of the analog input
float threshold = 26;
boolean alarma;        //1 = ALARMA, 0 = NO ALARMA
const float histeresis = 0.5;  //Valor de la histeresis

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  dht.begin();
  // initialize serial communications:
  Serial.begin(9600);
  float analogValue = dht.readTemperature();  //Inicializo el valor de la alarma
  if (analogValue > threshold) {
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
  float analogValue = dht.readTemperature();  //En cada loop compruebo el valor de la entrada analógica

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
  Serial.println(alarma * 50);
  delay(50);
}
