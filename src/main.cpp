#include "Arduino.h"
#include "sensor.h"
#include "LedTischKapazitiv.h"

LEDTischKapazitiv touch = LEDTischKapazitiv(4,15);



sensor zeile1 = sensor(2,3);
sensor zeile2 = sensor(4,5);
sensor zeile3 = sensor(6,7);
sensor zeile4 = sensor(8,9);

sensor spalte1 = sensor(10,11);
sensor spalte2 = sensor(12,13);

int zykluscounter = 0;
int zyklussumme = 0;
int initruns = 0;
float schwellwert = 0;
int initfinish = 0;
int ispressed = 0;
int giveout=0;
void setup()
{

  Serial.begin(9600);

    touch.setwidthpins(8,2,3,4,5,6,7,8,9);
    touch.init();

  
  pinMode(13, OUTPUT); //Status led
  zeile1.init();
  zeile2.init();
  zeile3.init();
  zeile4.init();

  spalte1.init();
  spalte2.init();


}

float zeileget1=-1;
float zeileget2=-1;
float zeileget3=-1;
float zeileget4=-1;

float spalteget1=-1;
float spalteget2=-1;

float biggest=-5;
float spaltenbiggest=-5;

void loop()
{


zeileget1=zeile1.doZyklus();
zeileget2=zeile2.doZyklus();
zeileget3=zeile3.doZyklus();
zeileget4=zeile4.doZyklus();

spalteget1=spalte1.doZyklus();
spalteget2=spalte2.doZyklus();

if(zeile1.initfinish==1&&zeile2.initfinish==1&&zeile3.initfinish==1&&zeile4.initfinish==1&&spalte1.initfinish==1&&spalte2.initfinish==1) {

if(giveout==0) {
  giveout=1;
  Serial.println("Init finish");
}

  biggest=0;
  spaltenbiggest=0;

if(zeile1.istouched()){
  if(zeileget1<biggest)
  {
    biggest=zeileget1;
  }
}
if(zeile2.istouched()){
  if(zeileget2<biggest)
  {
    biggest=zeileget2;
  }
}
if(zeile3.istouched()){
  if(zeileget3<biggest)
  {
    biggest=zeileget3;
  }
}
if(zeile4.istouched()){
  if(zeileget4<biggest)
  {
    biggest=zeileget4;
  }
}

if(zeileget1==biggest){
Serial.println("zeile1");
}
if(zeileget2==biggest){
Serial.println("zeile2");
}
if(zeileget3==biggest){
Serial.println("zeile3");
} 
if(zeileget4==biggest){
Serial.println("zeile4");
}

if(spalte1.istouched()){
  if(spalteget1<spaltenbiggest){
    spaltenbiggest=spalteget1;
  }
}
if(spalte2.istouched()){
  if(spalteget2<spaltenbiggest){
    spaltenbiggest=spalteget2;
  }
}
if(spalteget1==spaltenbiggest){
  Serial.println("spalte1");

}
if(spalteget2==spaltenbiggest){
  Serial.println("spalte2");

}

}


}