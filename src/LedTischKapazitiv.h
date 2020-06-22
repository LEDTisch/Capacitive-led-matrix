
#include <Arduino.h>
#include "sensor.h"
class LEDTischKapazitiv{
    private:
        int width=0;
        int height=0;

    
    public:
    LEDTischKapazitiv(int width,int height);

    //width
    int touchedlines[20];
    sensor touchwidth[20];
    float zeileget[20];
    void setwidthpins(int pins,...);
    //height
    int touchedcolumns[20];
    sensor touchheight[20];
    float spalteget[20];
    void setheightpins(int pins,...);

    void init();
    void update();
    
};
