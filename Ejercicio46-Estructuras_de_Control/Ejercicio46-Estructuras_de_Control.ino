/*
  Estructuras de Control
  Menu interactivo
*/

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  String titulo = "Menu Interactivo con Arduino";
  for (int i = 0; i < titulo.length(); i++) {
    Serial.print("-");
  }
  Serial.print("\n" + titulo + "\n");
  for (int i = 0; i < titulo.length(); i++) {
    Serial.print("-");
  }
  Serial.println();
}

void loop() {
  int respuesta;
  do {
    respuesta = menu();
    switch (respuesta) {
      case 1:
        Serial.println("-------> Led encendido");
        digitalWrite(13, HIGH);
        break;
      case 2:
        Serial.println("-------> Led apagado");
        digitalWrite(13, LOW);
        break;
      case 3:
        segundos();
        break;
      case 4:
        Serial.println("-------> Adios...");
        while (true) {
          //se queda aqui el programa
        }
        break;
      default:
        Serial.println("Opcion de menu incorrecta!!!!!");
        break;
    }
    //limpia_terminal();
  } while ((respuesta < 1) || (respuesta > 4));
}

int menu() {
  String leido = "";

  Serial.println("Elige opcion a ejecutar:");
  Serial.println("1 - Encender Led pin 13");
  Serial.println("2 - Apagar Led pin 13");
  Serial.println("3 - Contar segundos hasta pulsar tecla y mostrar por pantalla");
  Serial.println("4 - Fin");

  while (Serial.available() == 0) {
    //Ho hago nada
  }

  do {
    char caracter_leido;
    caracter_leido = Serial.read();
    leido += caracter_leido;
    delay(5);
  }  while (Serial.available() > 0);

  if (leido.toInt() != 0)
    return leido.toInt();
  else return 0;

}

void segundos() {
  int segundo = 0;

  while (Serial.available() == 0) {
    Serial.println("-------> Han pasado " + (String)segundo + " segundos");
    delay(1000);
    segundo++;
  }

  //Vacio buffer de lo enviado
  do {
    Serial.read();
    delay(5);
  }  while (Serial.available() > 0);
}

void limpia_terminal() {		//Solo v�lido para usar con putty
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
}
