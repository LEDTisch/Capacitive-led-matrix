#include <Arduino.h>

int zykluscounter = 0;
int zyklussumme = 0;
int initruns = 0;
float schwellwert = 0;
int initfinish = 0;
int ispressed = 0;
void setup()
{

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT); //Status led
  delay(500);          //default 500
}

void isjustpressed()
{
  //Serial.println("Just pressed");
}

void zyklus()
{
  pinMode(4, INPUT);
  digitalWrite(2, HIGH);  //DIrekte Verbindung auf Input die andere auf 5V um zu laden
  delayMicroseconds(100); //Default 250 bester Wert 200
  digitalWrite(2, LOW);
  zykluscounter++;
  pinMode(4, OUTPUT); //
  digitalWrite(4, LOW);
  pinMode(2, INPUT);
  delayMicroseconds(100); //Default 250 bester wert 200
}

void mangepress()
{
  if (schwellwert > zykluscounter)
  {

    digitalWrite(13, HIGH);

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
  }
}

void reset()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  delay(100); //Zeit zum Entladen default 500 bester wert 100
}

void findschwelle()
{
  schwellwert = (zyklussumme / initruns) * 0.982f; //Entscheidender Wert       Default: 0.98 besster wert 0.982
  Serial.println(schwellwert);
  initfinish = 1;
}

void inputhandler()
{
  
  if (initfinish == 1)
  {
    Serial.println(zykluscounter);
    mangepress();
  }

  zyklussumme += zykluscounter;
  initruns++;
  zykluscounter = 0;

  if (initruns > 10 && initfinish == 0)
  { //default 10

    findschwelle();
  }

  reset();
}

void loop()
{

  zyklus(); 

  if (digitalRead(2) == HIGH)
  {

    inputhandler();
  }



}