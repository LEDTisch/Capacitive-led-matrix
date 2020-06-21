#include <Arduino.h>
#include "LedTischKapazitiv.h"
LEDTischKapazitiv::LEDTischKapazitiv(int width, int height){
    this->width=width;
    this->height=height;


}

void LEDTischKapazitiv::setwidthpins(int pins,...){
    va_list pinlist;
    va_start(pinlist, pins);
    
    for (int i = 0; i < pins/2; i++) {
touchwidth[i]=sensor(0,0);
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


for(int i=0;i<width;i++){
    Serial.print("sensor : ");
    Serial.print(i);
    Serial.print("pin : ");
    Serial.println(touchwidth[i].getPin1());
}

}
void LEDTischKapazitiv::init(){



    for(int i=0;i<width;i++){
        touchwidth[i].init();
    }



}
void LEDTischKapazitiv::update(){
        float zeileget[300];

        for(int i=0;i<width;i++){

            float temp=0;
            temp=touchwidth[i].doZyklus();
                    zeileget[i]=temp;

                    if(touchwidth[i].istouched()){
                        Serial.println("touch");
                    }
        }

   /* 
    for(int i=0;i<width;i++){
        zeileget[i]=touchwidth[i].doZyklus();
        Serial.print("pin1: ");
        Serial.print(i);
        Serial.print(" ");
        Serial.println(touchwidth[0].getPin1());

        

    
    }
*/
}