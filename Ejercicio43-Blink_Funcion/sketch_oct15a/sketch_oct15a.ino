void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  enciendo();
  delay(1000);  
  apago();
  delay(1000);  
}

void enciendo() {
  Serial.println("Enciendo...");
  digitalWrite(13, HIGH);
}

void apago(){
  Serial.println("Apago...");
  digitalWrite(13, LOW);  
}
