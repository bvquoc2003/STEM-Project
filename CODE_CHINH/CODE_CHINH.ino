#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"

kmotor _kmotor(true);

int cb1 = 819;
int cb2 = 792;
int cb3 = 783;
int cb4 = 866;
int cb5 = 814;
int cb6 = 800;
int cb7 = 757;
int cb0 = 852;


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

//ENCODER INIT
float rpm1;


#define PIN_DO1 10
volatile unsigned int pulses1;


unsigned long timeOld1;



#define HOLES_DISC 20



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
   pinMode(PIN_DO1, INPUT);
  pulses1 = 0;
  
  attachInterrupt(digitalPinToInterrupt(PIN_DO1), counter1, FALLING);


  Serial.begin(9600);

    pinMode(trig,OUTPUT);   
    pinMode(echo,INPUT); 

  
}

void counter1()
{
  pulses1++;
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


int demSoLo1 = 0;
int item1 = 0;
int oldItem1 = 0;





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

 void chaythang (){
  for (int i = 0;i<=250;i+=10){
    _kmotor.tien(0, i);
    _kmotor.tien(1, (i - i * 0.05));
  delay(40);
  Serial.println (i);
  }

 }
void dung (){
   for (int i = 250; i >= 0; i-=10){
   _kmotor.tien(0,i);
    _kmotor.tien(1,i-15); 
     delay(12);
  }

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
  int x = sieuam(2,12);
   if(x <= 10){
    _kmotor.tien(0,200);
    _kmotor.tien(1,75);
   } else {
      _kmotor.tien(0,200);
      _kmotor.tien(1,200);
   }
}

    
int time_now = 0;
int OK_ChayThang = 1;
int OK_GapVach = 1;
int ok_chayham = 0;
void loop() {
    kiemtravach();
   if(OK_ChayThang==1){
       chaythang();
       OK_ChayThang = 0;
   }
   
   
   XuLySoLo1();
   if(ok_chayham == 0){
   dolinecong();
   }
      
   

    
   if(OK_GapVach == 1 && socambien >= 7 && ok_chayham == 0){
    digitalWrite(13,HIGH);
    OK_GapVach = 2;
    time_now = millis();
    ok_chayham = 1;
   } 
     if(ok_chayham == 1 && OK_GapVach == 2){
        chayham();
        Serial.println(sieuam(2,12));
      } 

   if(OK_GapVach == 2 && socambien >=6 && millis() > time_now+1000 && ok_chayham == 1){
        digitalWrite(13,LOW);
        ok_chayham = 0; 
        OK_GapVach = 3;
        time_now = millis();
        demSoLo1 = 0;
   }
   if(OK_GapVach == 3){
    if (demSoLo1/2 >= 200){
       M1_1 = 150;
       M2_1 = 150;
    } 
   }
////



//
   if(OK_GapVach == 3 && demSoLo1>=200){
    if(analogRead(A0) > 852+50 && analogRead(A1) > 819+50  && analogRead(A2) > 792+50  && analogRead(A3) > 783+50 ){
     _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1,0);
    delay(150);




    
     _kmotor.tien(0, (1 * M1_1));
    _kmotor.tien(1,150);
    delay(155);
     _kmotor.tien(0, 0);
    _kmotor.tien(1,0);
    delay(30);
     _kmotor.tien(0, -50);
    _kmotor.tien(1,-50);
    delay(30);
         _kmotor.tien(0, 0);
    _kmotor.tien(1,0);
    delay(10000);
    }

   }
    


   socambien = 0;
}
