#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xYY};  //Sustituir YY por el numero de KIT de Arduino
byte ip[] = {192, 168, 6, 1ZZ}; //Sustituir ZZ por 30 + el número de KIT
byte DNS[] = {8, 8, 8, 8};
byte gateway[] = {192, 168, 1, 1};
byte subnet[] = {255, 255, 255, 0};

/* Otra forma de definir los parámetros de red:
    IPAddress ip(192, 168, 0, 2);
    IPAddress dnServer(192, 168, 0, 1);
    IPAddress gateway(192, 168, 0, 1);
    IPAddress subnet(255, 255, 255, 0);
*/

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip, DNS, gateway, subnet);
  Serial.println("Inicializando red...");
  Serial.print("IP fija: configurada: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  Serial.print("Para comprobar que funciona haz ping a la IP: ");
  Serial.println(Ethernet.localIP());

  for (;;)
    ;
}
