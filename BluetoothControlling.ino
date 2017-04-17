#include <SoftwareSerial.h>
SoftwareSerial BT(11, 10);
String perintah;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  while (BT.available()) {
    delay(10);
    char c = BT.read();
    perintah += c;
  }
  if (perintah.length() > 0) {
    Serial.println(perintah);

    if (perintah == "bedroom on") {
      digitalWrite(2, HIGH);
    } else if (perintah == "bedroom off") {
      digitalWrite(2, LOW);
    } else if (perintah == "bathroom on") {
      digitalWrite(3, HIGH);
    } else if (perintah == "bathroom off") {
      digitalWrite(3, LOW);
    } else if (perintah == "living room on") {
      digitalWrite(4, HIGH);
    } else if (perintah == "living room off") {
      digitalWrite(4, LOW);
    } else if (perintah == "television on") {
      digitalWrite(5, HIGH);
    } else if (perintah == "television off") {
      digitalWrite(5, LOW);
    } else if (perintah == "all on") {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
    } else if (perintah == "all off" | perintah == "all of") {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
    perintah = "";
  }
}
