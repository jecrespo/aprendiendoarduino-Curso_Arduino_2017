int AnalogpinArray[] = {A0, A1, A2, A3, A4, A5};
int pinArray[] = {2, 3, 4, 5, 6, 7};
int AnalogData[6];
int DigitalData[6];

unsigned long tiempo = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(pinArray[i], INPUT);
  }
  tiempo = millis();
}

void loop() {
  for (int i = 0; i < 6; i++) {
    AnalogData[i] = analogRead(AnalogpinArray[i]);
    DigitalData[i] = digitalRead(pinArray[i]);
  }
  if ((millis() -  tiempo) > 5000) {
    tiempo = millis();  //inicio contador
    Serial.println("Entradas Analógicas:");
    for (int i = 0; i < 6; i++) {
      Serial.println ("Pin " + String(AnalogpinArray[i]) + " ---> " + String(AnalogData[i]));
    }
    Serial.println("Entradas Digitales:");
    for (int i = 0; i < 6; i++) {
      Serial.println ("Pin " + String(pinArray[i]) + " ---> " + String(DigitalData[i]));
    }
  }
}
