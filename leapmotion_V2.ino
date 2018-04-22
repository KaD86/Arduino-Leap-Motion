#include <NewPing.h>
int trig1=9;
int echo1=6;
int trig2=7;
int echo2=5;
int R;
int L;
NewPing right(9,6,50);
NewPing left(7,5,50);
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
 
}

void loop() {
  
  //Serial.println("hi,am arduino");
  R=right.ping_cm();
  L=left.ping_cm();
  //Serial.println(R);
  //Serial.println(L);
  
 if (R==0 && L==0){
 
    Serial.println('0');
  }
  
  else if(R<L){
    
    Serial.println('2');
  }
  else if(R>L){
    
    Serial.println('1');
    

  
  }
  
}
