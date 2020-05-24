#include "SR04.h"
#define TRIG_SF 5
#define ECHO_SF 4
#define H4 9
#define H3 8
#define H2 7
#define H1 6
#define InterrupcionB 3
#define InterrupcionL 2
long F = 0;
SR04 SFrente = SR04(ECHO_SF, TRIG_SF);
void setup() {
  pinMode(H1, OUTPUT);
  pinMode(H2, OUTPUT);
  pinMode(H3, OUTPUT);
  pinMode(H4, OUTPUT);
  pinMode(InterrupcionL, INPUT);
  attachInterrupt(0, Del, CHANGE);
  pinMode(InterrupcionB, INPUT);
  attachInterrupt(1, Detras, CHANGE);
}
void loop() {     
    Sonicos();
}
void Revisar() {
  Izquierda();
}
void Delante() {
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);
  digitalWrite(H3, LOW);
  digitalWrite(H4, HIGH);
}

void Atras() {
  digitalWrite(H1, HIGH);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);
  digitalWrite(H4, LOW);
}

void Izquierda() {
  digitalWrite(H1, HIGH);
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(H4, HIGH);
}

void Derecha() {
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);
  digitalWrite(H3, HIGH);
  digitalWrite(H4, LOW);
}
void Detras() { 
    int DecAtras = analogRead(A1);
    if (DecAtras < 50) {
    Delante();
    }  
}
void Del() { 
  int DecDela = analogRead(A0);  
  if (DecDela < 600 ) {
    Atras();
    delay(1000);
  } 
}
void Sonicos() {
  F = SFrente.Distance();
  int d = 30;
  if (F < d && F > 0) {    
    Delante();
  }else if (F < 5 && F > 0) {   
    Delante();
  }else{
    delay(1000);
    Revisar();
  }
}

