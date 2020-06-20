
#include <Arduino.h>
#include "sensor.h"
class LEDTischKapazitiv{
    private:
        int width=0;
        int height=0;
    
    public:
    LEDTischKapazitiv(int width,int height);
    sensor touchwidth[];
    float zeileget[];
    int touchedlines[];
    void setwidthpins(int pins,...);
    void init();
    void update();
    
};
