#include <Arduino.h>
#include "LedTischKapazitiv.h"
LEDTischKapazitiv::LEDTischKapazitiv(int width, int height){
    this->width=width;
    this->height=height;


}

void LEDTischKapazitiv::setwidthpins(int pins,...){
    va_list pinlist;
    va_start(pinlist, pins);
    
    for (int i = 0; i < pins; i++) {
        for(int j=0;j<2;j++){
        if(j==0){
            touchwidth[i].setPin1(va_arg(pinlist, int));

        }
        if(j==1){
            touchwidth[i].setPin2(va_arg(pinlist, int));

        }
   }
    }
	
   va_end(pinlist);


}
void LEDTischKapazitiv::init(){

    for(int i=0;i<width;i++){
        touchwidth[i].init();
        Serial.println("blub");
    }
}
void LEDTischKapazitiv::update(){
    for(int i=0;i<width;i++){
        zeileget[i]=touchwidth[i].doZyklus();
    }
}