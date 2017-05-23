/*
Serial Plotter Example
*/

int x = -20;

void setup() {
   Serial.begin(9600); 
}

void loop() {
    Serial.print(5*x+1);
    Serial.print(",");
    Serial.print(x*x);
    Serial.print(",");
    Serial.println(analogRead(A0));
    x++;
    delay(5);
    if (x == 20) x = -20;
}
