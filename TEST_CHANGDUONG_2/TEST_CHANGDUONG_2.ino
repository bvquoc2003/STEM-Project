#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

//KHAI BAO DO LINE

int F[20];




//ENCODER INIT
float rpm1;
float rpm2;

#define PIN_DO1 2
//#define PIN_DO2 6
//

volatile unsigned int pulses1;
volatile unsigned int pulses2;

unsigned long timeOld1;
unsigned long timeOld2;

#define HOLES_DISC 20



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

    pinMode(13, OUTPUT);

  
  pinMode(PIN_DO1, INPUT);
//  pinMode(PIN_DO2, INPUT);

  pulses1 = 0;
  timeOld2 = 0;
  attachInterrupt(digitalPinToInterrupt(PIN_DO1), counter1, FALLING);
//  attachInterrupt(digitalPinToInterrupt(PIN_DO2), counter2, FALLING);

  
  khoidong();
}


// ENCODE COUNTER for not miss some disc
void counter1()
{
  pulses1++;
}

//void counter2() {
//  pulses2++;
//}
//



void init1() {
  //F[0] = 860; F[1] = 795; F[2] = 680; F[3] = 705; F[4] = 830; F[5] = 745; F[6] = 738; F[7] = 663;
    F[0] = 832; F[1] = 767; F[2] = 702; F[3] = 724; F[4] = 747; F[5] = 764; F[6] = 703; F[7] = 624;
}

int soCamBien = 0;
void check() {

  
  if (analogRead(A0) > F[0])
    soCamBien++;
  if (analogRead(A1) > F[1])
    soCamBien++;
  if (analogRead(A2) > F[2])
    soCamBien++;
  if (analogRead(A3) > F[3])
    soCamBien++;
  if (analogRead(A4) > F[4])
    soCamBien++;
  if (analogRead(A5) > F[5])
    soCamBien++;
  if (analogRead(A6) > F[6])
    soCamBien++;
  if (analogRead(A7) > F[7])
    soCamBien++;

}




int changDuong = 0;

int time_now = 0;

int demSoLo1 = 0;
int demSoLo2 = 0;


int item1 = 0;
int item2 = 0;

int oldItem1 = 0;
int oldItem2 = 0;

void XuLySoLo1() {
  if (millis() - timeOld1 >= 0)
  {
    detachInterrupt(digitalPinToInterrupt(PIN_DO1));
    rpm1 = (pulses1 * 60) / (HOLES_DISC);

    item1 = digitalRead(PIN_DO1);

    if (item1 != oldItem1  ) {
      demSoLo1 ++;
      oldItem1 = item1;
    }



    timeOld1 = millis();

    attachInterrupt(digitalPinToInterrupt(PIN_DO1), counter1, FALLING);
  }
}
//void XuLySoLo2() {
//  if (millis() - timeOld2 >= 0)
//  {
//    detachInterrupt(digitalPinToInterrupt(PIN_DO2));
//    rpm2 = (pulses2 * 60) / (HOLES_DISC);
//
//    item2 = digitalRead(PIN_DO2);
//
//    if (item2 != oldItem2) {
//      demSoLo2 ++;
//      item2 = oldItem2;
//    }
//    //Serial.println(demSoLo2/2);
//
//
//    timeOld2 = millis();
//
//    attachInterrupt(digitalPinToInterrupt(PIN_DO2), counter2, FALLING);
//  }
//}
//



int dolech = 2;

void loop() {

  XuLySoLo1();
  //XuLySoLo2();
  
   check();
//   if(soCamBien >=6){
//    _kmotor.tien(0, 0);
//    _kmotor.tien(1, 0);
//    digitalWrite(13, HIGH);
//    delay(5000);
//    digitalWrite(13, LOW);
//   }

  if(demSoLo1 == 230){
    changDuong++;
    demSoLo1 = 0;
    _kmotor.tien(0,0);
    _kmotor.tien(1,0);
    
  }

  Serial.println(changDuong);
  
  Serial.println(demSoLo1);
  switch(changDuong){
    case 0:tangtoc(0,0);
        digitalWrite(13, LOW);
    break;
    case 1:
    tangtoc(50,50);
          digitalWrite(13, HIGH);
    break;
    case 2:
    tangtoc(50,50);
        digitalWrite(13, LOW);
        break;
    
    
  }
   
}




void tangtoc(int tocDoGiamBanhM1, int tocDoGiamBanhM2) {
  if(analogRead(A4) > F[4] && analogRead(A3) > F[3]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 255-dolech);
  } 
   if(analogRead(A4) > F[4] && analogRead(A3) < F[3]){
    _kmotor.tien(0, 248);
    _kmotor.tien(1, 255-dolech);
    
  } 
  
    
  if(analogRead(A4) < F[4] && analogRead(A3) > F[3]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 248-dolech);
    
  } 


  
  if(analogRead(A4) > F[4] && analogRead(A7) > F[7]){
    _kmotor.tien(0, 225);
    _kmotor.tien(1, 255-dolech);
  }


    if(analogRead(A3) > F[3] && analogRead(A2) > F[2]){
    _kmotor.tien(0, 255);
    _kmotor.tien(1, 225-dolech);
  }

  

  if(analogRead(A1) > F[1] && analogRead(A2) > F[2]){
    _kmotor.tien(0, 255-tocDoGiamBanhM1);
    _kmotor.tien(1, 160-dolech-tocDoGiamBanhM2);
  }

    if(analogRead(A6) > F[6] && analogRead(A7) > F[7]){
    _kmotor.tien(0, 160-tocDoGiamBanhM1);
    _kmotor.tien(1, 255-dolech-tocDoGiamBanhM2);
  }
  
    if(analogRead(A6) > F[6] && analogRead(A5) > F[5]){
    _kmotor.tien(0, 60-tocDoGiamBanhM1);
    _kmotor.tien(1, 255-dolech-tocDoGiamBanhM2);
  }

    
    if(analogRead(A1) > F[1] && analogRead(A0) > F[0]){
    _kmotor.tien(0, 255-tocDoGiamBanhM1);
    _kmotor.tien(1, 60-dolech-tocDoGiamBanhM2);
  
  }
  
}


void   khoidong(){
  for (int i=0;i<=250;i+=50){
    _kmotor.tien(0,i);
    _kmotor.tien(1,i-dolech);
    delay(50);
  }
}
