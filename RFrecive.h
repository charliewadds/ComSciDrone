//
//  Header.h
//
//  the format of the input is $/yy.yy/pp.pp/rr.rr/tt.tt/$ y.yy is yaw p.pp is pitch r.rr is roll tt.tt is throttle
//  need some way of adding a sign on the Y P and R
//  Created by Charlie Wadds on 2019-04-15.
//  23 charactes for each string

#ifndef Header_h
#define Header_h
#include <RCSwitch.h>
#include <Arduino.h>
#endif /* Header_h */
RCSwitch mySwitch = RCSwitch();//this should go in the setup file


int BufSizeMax = 27;//add one to be safe
char Buf[BufSizeMax];
char getLetter(){ //need to turn it from whatever the input is to char
    if(mySwitch.available()){
    char let = mySwitch.geRecivedValue();
        return let;
        else{
            return '$$';
        }
    }
}
char Buffer(){//store all the chars in an array
    float yJoy = 0;
    float pJoy = 0;
    float rJoy = 0;
    float tJoy = 0;
    int yprt = 0;//0 for yaw 1 for pitch etc
    bool dec = false; // if it is before or after the decimal
    int decInt = 0; //0 for 10s and ones 1 for 0.1 2 for 0.01 etc
    char letCurr = getLetter();
    char BufOut[17];
    int timesAround = 0;
     if (mySwitch.available()) {
    if(letCurr=='$'){
        letCurr = getLetter();
        if(mySwitch.available()){
            while(letCurr!='$'){//while a packet is being read
                
                letCurr = getLetter();//this is only called before or after a / is read
                
                if(letCurr=='/'){
                    dec = false;
                    
                    while(letCurr!=/){
                    
                        letCurr = getLetter();
                        letCurrAsInt//MAKE THIS WORK
                        if(letCurr!='.'){
                        if(dec== false){//before the decimal place
                            //convert char to int
                            yJoy+=letCurr;
                            
                        }
                        else{//for after the decimal place
                            //convert char to int again
                            yJoy+=letCurr/(10*decInt);//10 for 0.1 100 for 0.01 etc
                            decInt++;
                            }
                    }else if(letCurr=='.'){//this is called if there is a decimal read in the input
                        dec = true;
                        decInt++;
                    }
                    }
                    
                    decInt=0;//set the int displaying the decimal place to
                    dec=false;
                    yprt++;
                }
                timesAround++;//this only is called after a /
                }
            yprt=0;
            decInt= 0;
            dec= false;
        
              }
        
    }
    
    
}
void GetJoy(){
    float Yjoy;
    float Pjoy;
    float Rjoy;
    float Tjoy;
    if(L == '$'){
        
    }
    
    
    
    
}




