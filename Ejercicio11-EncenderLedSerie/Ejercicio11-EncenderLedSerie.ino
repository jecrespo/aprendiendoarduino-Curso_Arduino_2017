/*
  Interactivo
*/
#define DEBUG 0

String leido = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Introduce una cadena de texto: ");
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    leido = ""; //vacio lo leido
    do {
      char caracter_leido;
      delay(5);
      caracter_leido = Serial.read();
      leido += caracter_leido;
    }  while (Serial.available() > 0);

    Serial.println("He leido la cadena: \"" + leido + "\"");

    if (leido.startsWith("enciende"))
    //if (leido == "enciende")
      digitalWrite(LED_BUILTIN, HIGH);

    if (leido.startsWith("apaga"))
    //if (leido == "apaga")
      digitalWrite(LED_BUILTIN, LOW);

    Serial.println("Introduce una cadena de texto: ");
  }
}

