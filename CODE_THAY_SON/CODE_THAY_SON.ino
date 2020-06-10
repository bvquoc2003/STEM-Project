#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"

kmotor _kmotor(true);

int F[100];


int z;
int i2;
//int a;
//int b;
//int c;
//int d;
//int e;
//int f;
//int g;
//int h;
//int i;
//int j;
//int k;
//int m;
//int n;
//int o;
//int p;
//int q;
//int r;
//int s;
//int t;
//int u;
//int v;
//int w;
//int x;
//int y;

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



  z = 255;
  i2 = 255;
//  for (int count = 0; count < 5; count++) {
//    a = (int)(analogRead(A4));
//    b = (int)(analogRead(A7));
//    c = (int)(analogRead(A6));
//    d = (int)(analogRead(A5));
//    e = (int)(analogRead(A0));
//    f = (int)(analogRead(A1));
//    g = (int)(analogRead(A2));
//    h = (int)(analogRead(A3));
//    delay(500);
//  }
//  digitalWrite(13, HIGH);
//  delay(2000);
//  digitalWrite(13, LOW);
//  delay(2000);
//  for (int count2 = 0; count2 < 5; count2++) {
//    i = (int)(analogRead(A4));
//    j = (int)(analogRead(A7));
//    k = (int)(analogRead(A6));
//    m = (int)(analogRead(A5));
//    n = (int)(analogRead(A0));
//    o = (int)(analogRead(A1));
//    p = (int)(analogRead(A2));
//    q = (int)(analogRead(A3));
//  }
//  r = (int)((a + i) / 2);
//  s = (int)((b + j) / 2);
//  t = (int)((c + k) / 2);
//  u = (int)((d + m) / 2);
//  v = (int)((e + n) / 2);
//  w = (int)((f + o) / 2);
//  x = (int)((g + p) / 2);
//  y = (int)((h + q) / 2);
//  delay(500);
//  digitalWrite(13, HIGH);
//  delay(2000);
//  digitalWrite(13, LOW);
//  delay(1000);
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
    _kmotor.tien(0, (1 * z));
    _kmotor.tien(1, (0.5 * i2));
  }
  if (analogRead(A7) > F[7] && analogRead(A6) > F[6]) {
    _kmotor.tien(0, (1 * z));
    _kmotor.tien(1, (0.7 * i2));
  }
  if (analogRead(A6) > F[6] && analogRead(A5) > F[5]) {
    _kmotor.tien(0, (1 * z));
    _kmotor.tien(1, (0.9 * i2));
  }
  if (analogRead(A5) > F[5] && analogRead(A0) > F[0]) {
    _kmotor.tien(0, (1 * z));
    _kmotor.tien(1, (1 * i2));
  }
  if (analogRead(A0) > F[0] && analogRead(A1) > F[1]) {
    _kmotor.tien(0, (0.9 * z));
    _kmotor.tien(1, (1 * i2));
  }
  if (analogRead(A1) > F[1] && analogRead(A2) > F[2]) {
    _kmotor.tien(0, (0.7 * z));
    _kmotor.tien(1, (1 * i2));
  }
  if (analogRead(A2) > F[2] && analogRead(A3) > F[3]) {
    _kmotor.tien(0, (0.7 * z));
    _kmotor.tien(1, (1 * i2));
  }

}
