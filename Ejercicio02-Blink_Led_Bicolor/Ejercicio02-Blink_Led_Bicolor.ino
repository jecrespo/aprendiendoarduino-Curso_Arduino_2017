// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  Serial.println("Encendido VERDE");
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);
  digitalWrite(8, HIGH);
  Serial.println("Encendido ROJO");
  delay(1000);              // wait for a second
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  Serial.println("Encendido NARANJA");
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    
  digitalWrite(8, LOW);
  Serial.println("Apagado");
  delay(1000);              // wait for a second
}
