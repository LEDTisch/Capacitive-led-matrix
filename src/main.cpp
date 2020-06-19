#include <Arduino.h>
#include "sensor.h"
sensor zeile1 = sensor(2,3);
sensor zeile2 = sensor(4,5);
sensor zeile3 = sensor(6,7);
sensor zeile4 = sensor(8,9);


int zykluscounter = 0;
int zyklussumme = 0;
int initruns = 0;
float schwellwert = 0;
int initfinish = 0;
int ispressed = 0;
void setup()
{

  Serial.begin(9600);
  
  pinMode(13, OUTPUT); //Status led
  zeile1.init();
  zeile2.init();
  zeile3.init();
  zeile4.init();


}

float zeileget1=-1;
float zeileget2=-1;
float zeileget3=-1;
float zeileget4=-1;


float biggest=-5;

void loop()
{


zeileget1=zeile1.doZyklus();
zeileget2=zeile2.doZyklus();
zeileget3=zeile3.doZyklus();
zeileget4=zeile4.doZyklus();



  biggest=0;

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

}