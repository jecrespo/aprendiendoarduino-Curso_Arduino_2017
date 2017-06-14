/* Knight Rider 4
   --------------

   Based on Knight Rider 2 but change timer received by serial port
   @modified by: aprendiendoarduino

*/
#define DEBUG 0

int pinArray[] = {2, 3, 4, 5, 6};
int count = 0;
int timer = 100;

void setup() {

  Serial.begin(9600);
  Serial.println("Introduce el valor del timer (10 a 500 ms)");

  for (count = 0; count < 6; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  for (count = 0; count < 6; count++) {
    if (Serial.available()) timer = lee_timer();
#if DEBUG
    Serial.println("Valor de timer = " + String(timer));
#endif
    digitalWrite(pinArray[count], HIGH);
#if DEBUG
    Serial.println("Led " + String(count) + " ENCENDIDO");
#endif
    delay(timer);
    digitalWrite(pinArray[count], LOW);
#if DEBUG
    Serial.println("Led " + String(count) + " APAGADO");
#endif
    delay(timer);
  }
  for (count = 5; count >= 0; count--) {
    if (Serial.available()) timer = lee_timer();
#if DEBUG
    Serial.println("Valor de timer = " + String(timer));
#endif
    digitalWrite(pinArray[count], HIGH);
#if DEBUG
    Serial.println("Led " + String(count) + " ENCENDIDO");
#endif
    delay(timer);
    digitalWrite(pinArray[count], LOW);
#if DEBUG
    Serial.println("Led " + String(count) + " APAGADO");
#endif
    delay(timer);
  }
}

int lee_timer() {
  String cadena_Leida = "";
  do {
    char caracter_leido = Serial.read();
    cadena_Leida += caracter_leido;
    delay(5);
  }  while (Serial.available() > 0);

  int nuevo_timer = cadena_Leida.toInt();

  if (nuevo_timer >= 10 && nuevo_timer <= 500) {
    Serial.println("Nuevo timer establecido a " + (String)nuevo_timer + " segundos");
    return nuevo_timer;
  }
  else {
    Serial.println("El valor del timer debe estar entre 10 y 500 ms, introduce un valor correcto");
    return timer;
  }
  Serial.println("Introduce un nuevo valor del timer (10 a 500 ms)");
}

