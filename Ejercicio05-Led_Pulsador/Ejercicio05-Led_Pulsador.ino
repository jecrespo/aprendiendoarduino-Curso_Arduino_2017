int pushButton = 3;
int led = 4;


void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  delay(1);

  if (buttonState == LOW) {
    digitalWrite(led, LOW);
    Serial.println("Apago Led");
  }
  else {
    digitalWrite(led, HIGH);
    Serial.println("Enciendo Led");
  }
}
