#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xYY  //Sustituir YY por el numero de KIT de Arduino
};

void setup() {
  Serial.begin(9600);
  // start the Ethernet connection:
  Serial.println("Inicializando red...");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    for (;;)
      ;
  }
  else {
    Serial.print("IP asignada por DHCP: ");
    Serial.println(Ethernet.localIP());
  }
}

void loop() {
  Serial.print("Para comprobar que funciona haz ping a la IP: " + Ethernet.localIP());

  for (;;)
    ;
}
