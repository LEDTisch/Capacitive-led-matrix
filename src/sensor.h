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
    
};
#endif