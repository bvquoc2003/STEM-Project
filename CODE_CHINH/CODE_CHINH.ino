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


const int trig = 2;    
const int echo = 12;  



void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);  
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A7, INPUT);
  pinMode(A6, INPUT);
  pinMode(A5, INPUT);

  pinMode(13,OUTPUT);
  
  _kmotor.cauhinh();
  attachInterrupt (0,encoder,RISING);
  Serial.begin(9600);

    pinMode(trig,OUTPUT);   
    pinMode(echo,INPUT); 

  
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
int socambien = 0;
void kiemtravach(){
  if(analogRead(A0) > cb0)
    socambien++;
  if(analogRead(A1) > cb1)
    socambien++;
  if(analogRead(A2) > cb2)
    socambien++;
  if(analogRead(A3) > cb3)
    socambien++;
  if(analogRead(A4) > cb4)
    socambien++;
  if(analogRead(A5) > cb5)
    socambien++;
  if(analogRead(A6) > cb6)
    socambien++;
  if(analogRead(A7) > cb7)
    socambien++;
    
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

float sieuam(int trig,int echo){
          float dem=0;
            pinMode(trig,OUTPUT);
            digitalWrite(trig,LOW);
            delayMicroseconds(2);
            digitalWrite(trig,HIGH);
            delayMicroseconds(10);
            digitalWrite(trig,LOW);
            pinMode(echo, INPUT);
            dem = pulseIn(echo,HIGH,30000)/58.0;
            if(dem==0) dem=30;
            return dem;
}

int giatricua = 5;
int lancua = 0;
void chayham(){
   if(sieuam(2,12) <= 8){
    _kmotor.tien(0,200);
    _kmotor.tien(1,75);

   } else {
      _kmotor.tien(0,255);
      _kmotor.tien(1,255);
   }
}

    
int time_now = 0;
int OK_ChayThang = 1;
int OK_GapVach = 1;
int ok_chayham = 0;
void loop() {
    kiemtravach();
   Serial.println (demencoder);
   Serial.println("----");
   if(OK_ChayThang==1){
       chaythang();
       OK_ChayThang = 0;
   }


   
   if(ok_chayham == 0)
    dolinecong();  


    
   if(socambien >=6 && OK_GapVach == 1 && ok_chayham == 0){
    digitalWrite(13,HIGH);
    OK_GapVach = 2;
    time_now = millis();
    ok_chayham = 1;
   } 
     if(ok_chayham == 1 && OK_GapVach == 2){
        chayham();
      } 

   if(OK_GapVach == 2 && socambien >=6 && millis() > time_now+2000 && ok_chayham == 1){
        digitalWrite(13,LOW);
        ok_chayham = 0;
  
   }
   

//   Serial.println (demencoder);
//   Serial.println("----");
//   if(OK_ChayThang==1){
//       chaythang ();
//       OK_ChayThang = 0;
//   }
//   
//    dolinecong();
//

    
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
//        if (demencoder >= 950){
//     dung();
//   }
   socambien = 0;
}
