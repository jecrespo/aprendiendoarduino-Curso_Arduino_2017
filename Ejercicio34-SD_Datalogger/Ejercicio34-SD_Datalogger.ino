//Data Acquisition (DAQ) a tarjeta SD
//Ejemplo para leer y guardar en una tarjeta SD datos de una sonda de temperatura TMP36
//Los datos son guardados en un fichero llamado temp_log.csv

#include <SPI.h>
#include <SD.h>
#include <MsTimer2.h>

const int chipSelect = 4;
const int temperatura_pin = A0;

String dataString;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  MsTimer2::set(5000, saveData); // 5 sec period
  MsTimer2::start();

  Serial.println("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  if (!SD.exists("temp_log.csv")) {
    File dataFile = SD.open("temp_log.csv", FILE_WRITE);
    dataFile.println("Time(sec),Temperature");
    Serial.println("Creo nuevo fichero");
    dataFile.close();
  }
  else Serial.println("Fichero existente");

  Serial.println("MENU");
  Serial.println("1 - Muestra ultima linea guardada en la tarjeta SD");
  Serial.println("2 - Volcar datos guardados en la SD");
  Serial.println("3 - Borrar datos SD");

}

void loop() {
  if (Serial.available() > 0) {
    char caracterLeido = Serial.read();
    Serial.println("Opcion leida: " + (String)caracterLeido);
    if (caracterLeido == '1') {
      Serial.println("Ultima linea guardada: \"" + dataString + "\"");
    }
    else if (caracterLeido == '2') {
      muestraDatos();
    }
    else if (caracterLeido == '3') {
      borrarDatos();
    }
    else Serial.println("Caracter incorrecto... opciones validas 1, 2 o 3");
    //Muestra menú
    Serial.println("------------------------");
    Serial.println("MENU");
    Serial.println("1 - Muestra ultima linea guardada en la tarjeta SD");
    Serial.println("2 - Volcar datos guardados en la SD");
    Serial.println("3 - Borrad datos SD");
    Serial.println("------------------------");
  }
  while (Serial.available() > 0) {
    Serial.read();  //Vacio el buffer
    delay(5);
  }
}

void saveData()
{
  //read temperature
  int sensorVal = analogRead(temperatura_pin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;

  // make a string for assembling the data to log:
  dataString = String(millis() / 1000) + ",";

  dataString = dataString + (String)temperature ;

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("temp_log.csv", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    //Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening temp_log.csv");
  }
}

void muestraDatos() {
  File dataFile = SD.open("temp_log.csv");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening temp_log.csv");
  }
}

void borrarDatos() {
  if (SD.remove("temp_log.csv")) {
    File dataFile = SD.open("temp_log.csv", FILE_WRITE);
    dataFile.println("Time(sec),Temperature");
    Serial.println("FICHERO BORRADO");
    dataFile.close();
  }
  else Serial.println("No se ha podido borrar el fichero");
}

