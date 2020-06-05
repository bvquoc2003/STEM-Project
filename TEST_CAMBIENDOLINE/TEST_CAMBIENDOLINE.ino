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
#define PIN_DO2 10


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



  
  pinMode(PIN_DO1, INPUT);
  pinMode(PIN_DO2, INPUT);

  pulses1 = 0;
  timeOld2 = 0;

}

void init1() {
  //F[0] = 860; F[1] = 795; F[2] = 680; F[3] = 705; F[4] = 830; F[5] = 745; F[6] = 738; F[7] = 663;
    F[0] = 944; F[1] = 852; F[2] = 788; F[3] = 802; F[4] = 825; F[5] = 866; F[6] = 784; F[7] = 731;
}

//734
//611
//498
//502
//r580
//590
//511
//382
//

//958
//945
//934
//945
//965
//968
//954
//935
//


//827
//683
//567
//582
//629
//691
//584
//504
//

//991
//975
//952
//963
//971
//976
//955
//943

//666
//551
//463
//475
//530
//588
//502
//403
//
//961
//955
//925
//931
//945
//935
//919
//895



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
int dolech = 16;

void loop() {
   check();
   Serial.println(analogRead(A0));
   Serial.println(analogRead(A1));
   Serial.println(analogRead(A2));
   Serial.println(analogRead(A3));
   Serial.println(analogRead(A4));
   Serial.println(analogRead(A5));
   Serial.println(analogRead(A6));
   Serial.println(analogRead(A7));
   Serial.println("--------");
   delay(1000);
}
