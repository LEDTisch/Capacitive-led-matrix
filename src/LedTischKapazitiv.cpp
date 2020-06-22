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
    Serial.print("widthsensor : ");
    Serial.print(i);
    Serial.print(" pin : ");
    Serial.println(touchwidth[i].getPin1());
}
Serial.println();

}
void LEDTischKapazitiv::setheightpins(int pins,...){
    va_list pinlist;
    va_start(pinlist, pins);
    
    for (int i = 0; i < pins/2; i++) {
touchheight[i]=sensor(0,0);
        for(int j=0;j<2;j++){

        if(j==0){
            touchheight[i].setPin1(va_arg(pinlist, int));

        }
        if(j==1){
            touchheight[i].setPin2(va_arg(pinlist, int));

        }
   }
    }
	
   va_end(pinlist);


for(int i=0;i<width;i++){
    Serial.print("heightsensor : ");
    Serial.print(i);
    Serial.print(" pin : ");
    Serial.println(touchheight[i].getPin1());
}
Serial.println();
}
void LEDTischKapazitiv::init(){



    for(int i=0;i<width;i++){
        touchwidth[i].init();
    }
        for(int i=0;i<height;i++){
        touchwidth[i].init();
    }



}
void LEDTischKapazitiv::update(){
        

        int zaeler=0;


                for(int i=0;i<height;i++){

            float temp=0;
            temp=touchheight[i].doZyklus();
                    spalteget[i]=temp;
                    if(touchheight[i].getinitfinish()==1){
    
                    if(touchheight[i].istouched()){
                        Serial.print("spalte: ");
                        Serial.println(i);
                        touchedcolumns[zaeler]=4321;
                        //zaeler++;
                    }
                    }else{
                        Serial.println("init");
                    }
        }
        for(int i=0;i<width;i++){

            float temp=0;
            temp=touchwidth[i].doZyklus();
                    zeileget[i]=temp;
                    if(touchwidth[i].getinitfinish()==1){
    
                    if(touchwidth[i].istouched()){
                        Serial.print("zeile: ");
                        Serial.println(i);
                        touchedlines[zaeler]=4321;
                        //zaeler++;
                    }
                    }else{
                        Serial.println("init");
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

    for(int i=0;i<width;i++){
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(touchwidth[i].getPin1());
}
*/


}