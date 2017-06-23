#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xYY  //Sustituir YY por el numero de MAC correcto
};

char server[] = "www.aprendiendoarduino.com";

EthernetClient client;
String Num_Arduino = "";
String Mensaje = "";

void setup()
{
  Serial.begin(9600);
  // start the Ethernet connection

  Serial.println("inicializando red...");
  //Ethernet.begin(mac, ip, DNS, gateway, subnet);

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    for (;;)
      ;
  }
  else {
    Serial.print("IP asignada por DHCP: ");
    Serial.println(Ethernet.localIP());
  }

  pideDatos();
  mandaDatosGET();
}

void loop()
{
  pideDatos();
  mandaDatosGET();
}

void pideDatos () { //Función bloqueante
  Num_Arduino = "";
  Mensaje = "";

  Serial.println("----------------------\r\nIntroduce el numero de Arduino");
  while (Serial.available() == 0) {
    //espero a introducir el número de Arduino
  }
  do {
    char caracter_leido = Serial.read();
    if ((caracter_leido > '0') && (caracter_leido <  'z'))  //solo admito caracteres ascii entre 0 y z
      Num_Arduino += caracter_leido;
    delay(5);
  }  while (Serial.available() > 0);

  Serial.println("Introduce el mensaje que quieres mandar por GET");
  while (Serial.available() == 0) {
    //espero a introducir el número de Arduino
  }
  do {
    char caracter_leido = Serial.read();
    if ((caracter_leido > '0') && (caracter_leido <  'z'))  //solo admito caracteres ascii entre 0 y z
      Mensaje += caracter_leido;
    delay(5);
  }  while (Serial.available() > 0);

  Serial.println("Arduino: " + Num_Arduino + "\r\nMensaje: " + Mensaje);
}

void mandaDatosGET() {  //Función bloqueante
  String webString = "";

  Serial.println("enviando mensaje... ");
  Serial.println("connecting to server...");
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET /servicios/aprendiendoarduino/GET_Request.php?arduino=");
    client.print(Num_Arduino);
    client.print("&mensaje=");
    client.print(Mensaje);
    client.println(" HTTP/1.1");
    client.println("Host: www.aprendiendoarduino.com");
    client.println("Connection: close");
    client.println();
    Serial.print("Peticion enviada: ");
    Serial.print("GET /servicios/aprendiendoarduino/GET_Request.php?arduino=");
    Serial.print(Num_Arduino);
    Serial.print("&mensaje=");
    Serial.println(Mensaje);
  }
  else {
    Serial.println("connection failed");
  }

  while (client.available() == 0) {
    //Espero respuesta del servidor
  }

  if (client.available()) {
    Serial.println("Respuesta del Servidor---->");
    while (client.available()) {
      char c = client.read();
      webString += c;
    }
    Serial.println(webString);

    if (webString.lastIndexOf("OK") > 0)
      Serial.println("Datos enviados correctamente");
    else
      Serial.println("Error al enviar los datos");

    client.stop();
  }
}
