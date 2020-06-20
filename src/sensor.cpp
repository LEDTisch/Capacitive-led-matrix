#include <Arduino.h>
#include "sensor.h"
sensor::sensor(int pin1, int pin2){ //pin1 ist der Pin ohne das Kabel pin 2 mit
this->pin1=pin1;
this->pin2=pin2;
}
void sensor::init() {
    pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}
void sensor::zyklus(){
  pinMode(pin2, INPUT);
  digitalWrite(pin1, HIGH);  //DIrekte Verbindung auf Input die andere auf 5V um zu laden
  delayMicroseconds(100); //Default 250 bester Wert 200
  digitalWrite(pin1, LOW);
  zykluscounter++;
  pinMode(pin2, OUTPUT); //
  digitalWrite(pin2, LOW);
  pinMode(pin1, INPUT);
  delayMicroseconds(100); //Default 250 bester wert 200
}
void sensor::managepress(){
      if (schwellwert > zykluscounter)
  {

    digitalWrite(13, HIGH);
    touched=true;

    if (ispressed != 1)
    {
      ispressed = 1;
      isjustpressed();

    }
  }
  else
  {
    ispressed = 0;
    digitalWrite(13, LOW);
    touched=false;
  }
}

void sensor::reset()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  delay(50); //Zeit zum Entladen default 500 bester wert 100
}

void sensor::findschwelle()
{
  schwellwert = (zyklussumme / initruns) * 0.97f; //Entscheidender Wert       Default: 0.98 besster wert 0.982
  //Serial.println(schwellwert);
  initfinish = 1;
}

float sensor::inputhandler()
{
  
  if (initfinish == 1)
  {
    //Serial.println(zykluscounter);
    managepress();
  }

  zyklussumme += zykluscounter;
  initruns++;
  

  if (initruns > 10 && initfinish == 0)
  { //default 10

    findschwelle();
  }

  reset();
  float returnvalue = zykluscounter;
  zykluscounter=0;
  return returnvalue;
}

float sensor::getZykluscount() {
     zyklus(); 

  if (digitalRead(pin1) == HIGH)
  {

   return inputhandler();
    
  }else{
      
      return -1;
      
  }

}

float sensor::getSchwelle() {
    return schwellwert;
}
void sensor::isjustpressed() {

}

boolean sensor::istouched(){
    return touched;
}

float sensor::doZyklus()
{
    while(digitalRead(pin1) != HIGH){
        zyklus();
    }
    return inputhandler()-getSchwelle();

}
