#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"
 
kmotor _kmotor(true);
 
int cb1 = 825;
int cb2 = 812;
int cb3 = 796;
int cb4 = 871;
int cb5 = 853;
int cb6 = 825;
int cb7 = 794;
int cb0 = 864;
 
int M1_1 = 255;
int M2_1 = 250;
int a = 1;
int demencoder = 0;
 
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);  
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A7, INPUT);
  pinMode(A6, INPUT);
  pinMode(A5, INPUT);
  _kmotor.cauhinh();
  attachInterrupt (0,encoder,RISING);
  Serial.begin(9600);
}
 
void encoder(){
  if (digitalRead(4) == 1)
    demencoder++; 
}
 
void dolinethang (){
  if (analogRead(A0) > cb0 && analogRead(A1) < cb1) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.3 * M2_1));
  }
  if (analogRead(A0) > cb0 && analogRead(A1) > cb1) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.4 * M2_1));
  }
  if (analogRead(A1) > cb1 && analogRead(A2) < cb2) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.5 * M2_1));
  }
  if (analogRead(A1) > cb1 && analogRead(A2) > cb2) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.6 * M2_1));
  }
  if (analogRead(A2) > cb2 && analogRead(A3) < cb3) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.7 * M2_1));
  }
  if (analogRead(A2) > cb2 && analogRead(A3) > cb3) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.8 * M2_1));
  }
  if (analogRead(A3) > cb3 && analogRead(A4) < cb4) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.9 * M2_1));
  }
  if (analogRead(A3) > cb3 && analogRead(A4) > cb4) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A4) > cb4 && analogRead(A7) < cb7) {
    _kmotor.tien(0, (0.9 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A4) > cb4 && analogRead(A7) > cb7) {
    _kmotor.tien(0, (0.8 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A7) > cb7 && analogRead(A6) < cb6) {
    _kmotor.tien(0, (0.7 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A7) > cb7 && analogRead(A6) > cb6) {
    _kmotor.tien(0, (0.6 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A6) > cb6 && analogRead(A5) < cb5) {
    _kmotor.tien(0, (0.5 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
    if (analogRead(A5) > cb5 && analogRead(A6) > cb6) {
    _kmotor.tien(0, (0.4 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
      if (analogRead(A5) < cb5 && analogRead(A6) > cb6) {
    _kmotor.tien(0, (0.3 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
 }
 void dolinecong (){
 
 }
 void chaythang (){
    for (int i = 1; i <= 200; i += 10) {
      _kmotor.tien(0, i);
      _kmotor.tien(1, (i - i * 0.05));
      delay(20);
    }
}
int b; 
void loop() {
      Serial.println (demencoder);
//      if (demencoder == 200){
//        demencoder = 0;
//      }
//
//    if (a == 1) {
//      chaythang ();
//      a = 2;
//    }
    if ((a == 1)&&(demencoder < 200)){
      dolinethang ();
      b = 3;
    }
        if ((b == 3)&&(demencoder == 200)){
        _kmotor.tien(0, 0);
      _kmotor.tien(1, 0);
      a = 4;
    }
}
