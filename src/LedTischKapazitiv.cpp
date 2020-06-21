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
    //Serial.println("groese");
    //Serial.println(sizeof(touchedlines));
    //int tempanzahl=0;

    touchwidth[0].doZyklus();
   // Serial.println(touchwidth[0].doZyklus());
    Serial.println(touchwidth[0].initfinish);
    /*
    for(int i=0;i<width;i++){
        zeileget[i]=touchwidth[i].doZyklus();
        Serial.println(zeileget[0]);
        if(touchwidth[i].initfinish==1){
            Serial.println("initfinisched");
            if(touchwidth[i].istouched()){
                        Serial.println("irgentwas getoucht");
        }
        }else{
                    Serial.println("init");

        }
        */

        /*
        if(touchwidth[i].initfinish==1){
            Serial.println("initfinisch");

        if(touchwidth[i].istouched()){
            touchedlines[tempanzahl]=i;
            Serial.println("touched");
            tempanzahl++;
        }
        */
        
    


}