#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"

kmotor _kmotor(true);

int F[100];
int phai,trai;

void setup() {
  pinMode(A4, INPUT);
  pinMode(A7, INPUT);
  pinMode(A6, INPUT);
  pinMode(A5, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(13, OUTPUT);
  _kmotor.cauhinh();

  trai = 255;
  phai = 255;
}
void checkCamBien(){
  for (int i=0;i<=7;i++){
    F[i] = (int)(analogRead('A'+i));
  }
  delay(500);
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  delay(2000);
  
  for (int i=0;i<=7;i++){
    F[i] = (F[i]+analogRead('A'+i))/2;
  }
  delay(500);
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  delay(1000);

}


void loop() {
  if (analogRead(A4) > F[4] && analogRead(A7) > F[7]) {
    _kmotor.tien(0, (1 * trai));
    _kmotor.tien(1, (0.5 * phai));
  }
  if (analogRead(A7) > F[7] && analogRead(A6) > F[6]) {
    _kmotor.tien(0, (1 * trai));
    _kmotor.tien(1, (0.7 * phai));
  }
  if (analogRead(A6) > F[6] && analogRead(A5) > F[5]) {
    _kmotor.tien(0, (1 * trai));
    _kmotor.tien(1, (0.9 * phai));
  }
  if (analogRead(A5) > F[5] && analogRead(A0) > F[0]) {
    _kmotor.tien(0, (1 * trai));
    _kmotor.tien(1, (1 * phai));
  }
  if (analogRead(A0) > F[0] && analogRead(A1) > F[1]) {
    _kmotor.tien(0, (0.9 * trai));
    _kmotor.tien(1, (1 * phai));
  }
  if (analogRead(A1) > F[1] && analogRead(A2) > F[2]) {
    _kmotor.tien(0, (0.7 * trai));
    _kmotor.tien(1, (1 * phai));
  }
  if (analogRead(A2) > F[2] && analogRead(A3) > F[3]) {
    _kmotor.tien(0, (0.7 * trai));
    _kmotor.tien(1, (1 * phai));
  }

}
