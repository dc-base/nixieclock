#include <Wire.h>
#include "RTClib.h"

//Hours (Tens)
#define A0 2
#define B0 3
#define C0 4
#define D0 5

//Hours (Ones)
#define A1 6
#define B1 7
#define C1 8
#define D1 9

//Minutes (Tens)
#define A2 10
#define B2 11
#define C2 12
#define D2 13

//Minutes (Ones)
//A0, A1, A2, A3
#define A3 14
#define B3 15
#define C3 16
#define D3 17

#define Button0 20 //A6
#define Button1 21 //A7
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(B0, OUTPUT);
  pinMode(C0, OUTPUT);
  pinMode(D0, OUTPUT);

  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);

  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(D2, OUTPUT);

  pinMode(A3, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(D3, OUTPUT);

  pinMode(Button0, INPUT); //A6
  pinMode(Button1, INPUT); //A7

  if (! rtc.begin()) {
   Serial.println("RTC not Initialized");
   while (1);
 }

 delay(1000);
}
int HT[4] = {A0,B0,C0,D0};
int HO[4] = {A1,B1,C1,D1};
int MT[4] = {A2,B2,C2,D2};
int MO[4] = {A3,B3,C3,D3};

// the loop function runs over and over again forever
int i = 0;
int h_offset = 0;
int m_offset = 0;

void loop() {

  //Serial.print(analogRead(Button0));
  if(digitalRead(Button0)){
    h_offset++;
  }
  DateTime now = rtc.now();
  //print_rtc();
  int h_tens = (now.hour() + h_offset) / 10;
  int h_ones = (now.hour() + h_offset) % 10;
  int m_tens = (now.minute() + m_offset) / 10;
  int m_ones = (now.minute() + m_offset) % 10;
  Serial.print(h_tens);
  Serial.print(h_ones);
  Serial.print(":");
  Serial.print(m_tens);
  Serial.print(m_ones);
  Serial.println();

//  int val = 9;
//  decode3(val, HT);
//  decode3(val, HO);
//  decode3(val, MT);
//  decode3(val, MO);

  decode3(h_tens, HT);
  decode3(h_ones, HO);
  decode3(m_tens, MT);
  decode3(m_ones, MO);
  delay(100);
//  if(i==9){
//    i=0;
//  }
//  decode(h_tens, i);
//  decode(h_ones, i);
//  decode(m_tens, i);
//  decode(m_ones, i);
//  delay(1000); 
//  i++;
}
void print_rtc(){
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}
void decode(int num, int set[]) {
  switch (num){
    case 0:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 1:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 2:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 3:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 4:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 5:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 6:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 7:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 8:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], HIGH);
      break;
    case 9:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], HIGH);
      break;
    default:
      //Clear
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], HIGH);
      break;
  }
}
void decode2(int num, int set[]) {
  switch (num){
    case 0:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], HIGH);
      break;
    case 1:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], HIGH);
      break;
    case 2:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 3:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 4:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 5:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 6:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 7:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 8:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 9:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    default:
      //Clear
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], HIGH);
      break;
  }
}
void decode3(int num, int set[]) {
  switch (num){
    case 0:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 1:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 2:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], HIGH);
      break;
    case 3:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], HIGH);
      break;
    case 4:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 5:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 6:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 7:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], LOW);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], LOW);
      break;
    case 8:
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    case 9:
      digitalWrite(set[0], LOW);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], LOW);
      digitalWrite(set[3], LOW);
      break;
    default:
      //Clear
      digitalWrite(set[0], HIGH);
      digitalWrite(set[1], HIGH);
      digitalWrite(set[2], HIGH);
      digitalWrite(set[3], HIGH);
      break;
  }
}
