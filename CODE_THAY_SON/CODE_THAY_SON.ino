#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "kmotor.h"
#define PIN_DO1 4
kmotor _kmotor(true);

int F[100];
int phai,trai,dolech;

void setup() {
  pinMode(A4, INPUT);
  pinMode(A7, INPUT);
  pinMode(A6, INPUT);
  pinMode(A5, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(PIN_DO1, INPUT);
  
  pinMode(13, OUTPUT);
  _kmotor.cauhinh();

  trai = 255;
  phai = 255;
  dolech=0;

  checkCamBien();
   attachInterrupt(digitalPinToInterrupt(PIN_DO1), counter1, FALLING);
}
int pulses1 = 0;
 void counter1()
{
  pulses1++;
}



int item1;
int oldItem1 = 0;
int demSoLo1 = 0;
void XuLySoLo1() {
    item1 = digitalRead(PIN_DO1);
    if (item1 != oldItem1  ) {
      demSoLo1 ++;
      oldItem1 = item1;
    }
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
int a=0,b;

void loop() {
//
  XuLySoLo1();
  if(demSoLo1/2 == 270){
    _kmotor.tien(0,0);
    _kmotor.tien(1,0);
    delay(1000);
    demSoLo1==0;
    a++;
  }
  if(a==0){
    Doline();
  }
  if(a==1){
    //Xuly cua T1 va T2
  }
  if(a==2){
   // xuly di thg tro lai va tien toi ham
  }
  if(a==3){
    //xuly qua ham`
  }
  if(a==4){
    //ve dich ( CO 1 KHUC CUA )
  }
}





void Doline(){
   
  //9 truong hop dau tien
 if (analogRead(A0) > F[0] && analogRead(A5) > F[5]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,255-dolech);
  }
  if (analogRead(A0) > F[0] && analogRead(A5) < F[5]) {
    _kmotor.tien(0,200);
    _kmotor.tien(1,255-dolech);
  }
  if (analogRead(A0) < F[0] && analogRead(A5) > F[5]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,200-dolech);
  }
   if (analogRead(A4) > F[4] && analogRead(A6) > F[6] && analogRead(A5) > F[5] && analogRead(A7) > F[7]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,60-dolech);
   }
  if (analogRead(A5) > F[5] && analogRead(A7) > F[7]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,60-dolech);
  }
  if (analogRead(A0) > F[0] && analogRead(A1) > F[1]) {
    _kmotor.tien(0,180);
    _kmotor.tien(1,255-dolech);
  }
 if (analogRead(A6) > F[6] && analogRead(A7) > F[7]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,60-dolech);
  }
   if (analogRead(A1) > F[1] && analogRead(A2) > F[2]) {
    _kmotor.tien(0,160);
    _kmotor.tien(1,255-dolech);
  }
   if (analogRead(A4) > F[4] && analogRead(A6) > F[6]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,60-dolech);
  }
  if (analogRead(A2) > F[2] && analogRead(A3) > F[3]) {
    _kmotor.tien(0,150);
    _kmotor.tien(1,255-dolech);
  }
  //8 truong hop sau
  if (analogRead(A3) > F[3] && analogRead(A2) < F[2]) {
    _kmotor.tien(0,10);
    _kmotor.tien(1,255-dolech);
  }
   if (analogRead(A4) > F[4] && analogRead(A6) < F[6]) {
    _kmotor.tien(0,255);
    _kmotor.tien(1,10-dolech);
  }
}
