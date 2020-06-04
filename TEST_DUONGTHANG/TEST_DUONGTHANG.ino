#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

//KHAI BAO DO LINE

int F[20];


kmotor _kmotor(true);
void setup() {
  Serial.begin(9600);
  _kmotor.cauhinh();

  //doline 1
  pinMode(A7, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);

  //doline2
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  init1();
}
void init1() {
  //F[0] = 860; F[1] = 795; F[2] = 680; F[3] = 705; F[4] = 830; F[5] = 745; F[6] = 738; F[7] = 663;
    F[0] = 944; F[1] = 852; F[2] = 788; F[3] = 802; F[4] = 825; F[5] = 866; F[6] = 784; F[7] = 731;
}






int dolech = 16;

void loop() {

   tangtoc(0,0);
}




void tangtoc(int tocDoGiamBanhM1, int tocDoGiamBanhM2) {
   if(analogRead(A4) > F[4] && analogRead(A3) < F[3]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 255-dolech+10);
  } 
  
    
  if(analogRead(A4) < F[4] && analogRead(A3) > F[3]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 255 -dolech-10);
  } 


  

  
  if(analogRead(A4) > F[4] && analogRead(A3) > F[3]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 255-dolech);

  } 
  
  if(analogRead(A4) > F[4] && analogRead(A7) > F[7]){
    _kmotor.tien(0, 140);
    _kmotor.tien(1, 255-dolech+dolech);
  }
  
  if(analogRead(A3) > F[3] && analogRead(A2) > F[2]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 124);
  }
  

  if(analogRead(A1) > F[1] && analogRead(A2) > F[2]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 230);
  }

    if(analogRead(A6) > F[6] && analogRead(A7) > F[7]){
    _kmotor.tien(0, 230);
    _kmotor.tien(1, 255-dolech+dolech);
  }
  
    if(analogRead(A6) > F[6] && analogRead(A5) > F[5]){
    _kmotor.tien(0, 50);
    _kmotor.tien(1, 255-dolech+dolech);
  }

    
    if(analogRead(A1) > F[1] && analogRead(A0) > F[0]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 50);
  
  }
}
