#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
 
int i;
int j;
int k;
int m;
int l;
int n;
int o;
int p;
int q;
int v;
int w;
int x;
int y;
int z;
int a;
int b;
int c;
int d;
int s;
int t;
int u;
int f;
int e;
int g;
 
void setup() {
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
 
  for (int count = 0; count < 5; count++) {
    i = (int)(analogRead(A5));
    j = (int)(analogRead(A6));
    k = (int)(analogRead(A7));
    m = (int)(analogRead(A4));
    l = (int)(analogRead(A3));
    n = (int)(analogRead(A2));
    o = (int)(analogRead(A1));
    p = (int)(analogRead(A0));
    delay(500);
  }
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  delay(3000);
  for (int count2 = 0; count2 < 5; count2++) {
    q = (int)(analogRead(A5));
    v = (int)(analogRead(A6));
    w = (int)(analogRead(A7));
    x = (int)(analogRead(A4));
    y = (int)(analogRead(A3));
    z = (int)(analogRead(A2));
    a = (int)(analogRead(A1));
    b = (int)(analogRead(A0));
  }
  c = (int)((p + b) / 2);
  d = (int)((o + a) / 2);
  s = (int)((n + z) / 2);
  t = (int)((l + y) / 2);
  u = (int)((m + x) / 2);
  f = (int)((k + w) / 2);
  e = (int)((j + v) / 2);
  g = (int)((i + q) / 2);
  delay(000);
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  delay(1000);
 
}
 
void loop() {
  Serial.print("int cb1 = ");
  Serial.print(d);
  Serial.println(";");
  Serial.print("int cb2 = ");
  Serial.print(s);
  Serial.println(";");
  Serial.print("int cb3 = ");
  Serial.print(t);
  Serial.println(";");
  Serial.print("int cb4 = ");
  Serial.print(u);
  Serial.println(";");
  Serial.print("int cb5 = ");
  Serial.print(g);
  Serial.println(";");
  Serial.print("int cb6 = ");
  Serial.print(e);
  Serial.println(";");
  Serial.print("int cb7 = ");
  Serial.print(f);
  Serial.println(";");
  Serial.print("int cb0 = ");
  Serial.print(c);
  Serial.println(";");
  delay(3000);
 
}
