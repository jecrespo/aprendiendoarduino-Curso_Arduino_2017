#define MUESTRA_TIEMPO 0

#define PIN_LED 13
#define PIN_PULSADOR 2

unsigned long tiempo_loop;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_PULSADOR, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  tiempo_loop = millis();
}

void loop() {
#if MUESTRA_TIEMPO
  Serial.print("Tiempo Loop = ");
  Serial.print(millis() - tiempo_loop);
  Serial.println(" ms");
#endif
  tiempo_loop = millis();
  int sensorVal = digitalRead(PIN_PULSADOR);
  Serial.println(sensorVal);
  if (sensorVal == HIGH) {
    digitalWrite(PIN_LED, LOW);
  }
  else {
    digitalWrite(PIN_LED, HIGH);
    Serial.println("Pulsado...");
  }
}
