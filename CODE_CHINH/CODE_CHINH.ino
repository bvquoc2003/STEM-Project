#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"

kmotor _kmotor(true);

int cb1 = 824;
int cb2 = 801;
int cb3 = 784;
int cb4 = 869;
int cb5 = 832;
int cb6 = 809;
int cb7 = 780;
int cb0 = 843;

int M1_1 = 250;
int M2_1 = 250;
int M1_2 = 255;
int M2_2 = 250;
int a = 0;
int b = 0;
int c = 0;
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
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (0.3 * M2_2));
  }
  if (analogRead(A0) > cb0 && analogRead(A1) > cb1) {
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (0.4 * M2_2));
  }
  if (analogRead(A1) > cb1 && analogRead(A2) < cb2) {
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (0.5 * M2_2));
  }
  if (analogRead(A1) > cb1 && analogRead(A2) > cb2) {
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (0.6 * M2_2));
  }
  if (analogRead(A2) > cb2 && analogRead(A3) < cb3) {
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (0.7 * M2_2));
  }
  if (analogRead(A2) > cb2 && analogRead(A3) > cb3) {
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (0.8 * M2_2));
  }
  if (analogRead(A3) > cb3 && analogRead(A4) < cb4) {
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (0.9 * M2_2));
  }
  if (analogRead(A3) > cb3 && analogRead(A4) > cb4) {
    _kmotor.tien(0, (1 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
 if (analogRead(A4) > cb4 && analogRead(A6) < cb6) {
    _kmotor.tien(0, (0.9 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
  if (analogRead(A4) > cb4 && analogRead(A6) > cb6) {
    _kmotor.tien(0, (0.8 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
  if (analogRead(A6) > cb6 && analogRead(A4) < cb4) {
    _kmotor.tien(0, (0.7 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
  if (analogRead(A7) > cb7 && analogRead(A6) > cb6) {
    _kmotor.tien(0, (0.6 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
  if (analogRead(A7) > cb7 && analogRead(A6) < cb6) {
    _kmotor.tien(0, (0.5 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
    if (analogRead(A5) > cb5 && analogRead(A7) > cb7) {
    _kmotor.tien(0, (0.4 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
      if (analogRead(A5) > cb5 && analogRead(A7) < cb7) {
    _kmotor.tien(0, (0.3 * M1_2));
    _kmotor.tien(1, (1 * M2_2));
  }
 }


 
 void dolinecong (){
  if (analogRead(A0) > cb0 && analogRead(A1) < cb1) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0 * M2_1));
  }
  if (analogRead(A0) > cb0 && analogRead(A1) > cb1) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.1 * M2_1));
  }
  if (analogRead(A1) > cb1 && analogRead(A2) < cb2) {
    _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1, (0.3 * M2_1));
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
if (analogRead(A4) > cb4 && analogRead(A6) < cb6) {
    _kmotor.tien(0, (0.9 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A4) > cb4 && analogRead(A6) > cb6) {
    _kmotor.tien(0, (0.8 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A6) > cb6 && analogRead(A4) < cb4) {
    _kmotor.tien(0, (0.7 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A7) > cb7 && analogRead(A6) > cb6) {
    _kmotor.tien(0, (0.6 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
  if (analogRead(A7) > cb7 && analogRead(A6) < cb6) {
    _kmotor.tien(0, (0.3 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
    if (analogRead(A5) > cb5 && analogRead(A7) > cb7) {
    _kmotor.tien(0, (0.1 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
      if (analogRead(A5) > cb5 && analogRead(A7) < cb7) {
    _kmotor.tien(0, (0 * M1_1));
    _kmotor.tien(1, (1 * M2_1));
  }
 }
 
 void chaythang (){
  for (int i = 0;i<=250;i+=10){
    _kmotor.tien(0, i);
    _kmotor.tien(1, (i - i * 0.05));
  delay(10);
  Serial.println (i);
  }
 }
  void dung (){
   _kmotor.tien(0,0);
    _kmotor.tien(1,0);  
  }

  
   

int OK_ChayThang = 1;
void loop() {

   Serial.println (demencoder);
   Serial.println("----");
   if(OK_ChayThang==1){
       chaythang ();
       OK_ChayThang = 0;
   }
    dolinecong();
//   if ((a == 0)&&(demencoder <=390)){
//     dolinethang();
//     b = 1;
//   }
//    if ((b == 1)&&(demencoder > 390)){
//     dolinecong();
//     c = 1;
//   }
//     if ((c == 1)&&(demencoder >= 650)){
//     dolinethang();
//   }
//        if ((demencoder >= 950)){
//     dung();
//   }

}
