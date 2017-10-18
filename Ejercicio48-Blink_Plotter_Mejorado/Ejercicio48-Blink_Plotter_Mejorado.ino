// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  int segundos = millis() / 1000;
  if (segundos % 2 == 0) {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.println("1");
  }
  else {
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("0");
  }
}
