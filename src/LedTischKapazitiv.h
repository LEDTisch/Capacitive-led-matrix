
#include <Arduino.h>
#include "sensor.h"
class LEDTischKapazitiv{
    private:
        int width=0;
        int height=0;

    
    public:
    LEDTischKapazitiv(int width,int height);
    int touchedlines[50];
    sensor touchwidth[50];
    float zeileget[50];

    void setwidthpins(int pins,...);
    void init();
    void update();
    
};
