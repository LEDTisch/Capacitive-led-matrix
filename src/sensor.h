#include<Arduino.h>
#ifndef SENSOR_H
#define SENSOR_H

class sensor{
private:
    int pin1;
    int pin2;
public:
    int zykluscounter=0;
    int schwellwert=0;
    int ispressed=0;
    int zyklussumme=0;
    int initruns=0;
    int initfinish=0;
    boolean touched=false;

    sensor(int pin1, int pin2);
    void init();
    void zyklus();
    void managepress();
    void isjustpressed();
    void reset();
    void findschwelle();
    float inputhandler();
    float getZykluscount();
    float getSchwelle();
    boolean istouched();
    float doZyklus();
    void setPins(int pin1,int pin2);
    void setPin1(int pin1);
    void setPin2(int pin2);
    int getPin1();
    int getPin2();
    
};
#endif