
#include <Arduino.h>
#include "sensor.h"
class LEDTischKapazitiv{
    private:
        int width=0;
        int height=0;
    
    public:
    LEDTischKapazitiv(int width,int height);
    sensor touchwidth[];
    int touchedlines[300];
    void setwidthpins(int pins,...);
    void init();
    void update();
    
};
