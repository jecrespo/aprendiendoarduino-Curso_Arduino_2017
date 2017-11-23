// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop() {
  
Serial.println(F("UTF-8 test:"));
Serial.println(F(" Micro µ µ µ µ µ µ µ µ µ µ"));
Serial.println(F(" Euro € € € € € € € € € €"));
Serial.println(F(" (c) © © © © © © © © © ©"));
Serial.println("Atención");

Serial.println(F("-----------"));

}
