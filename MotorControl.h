//
//  MotorControl.h
//  
//
//  Created by Charlie Wadds on 2019-04-12.
//

#ifndef MotorControl_h
#define MotorControl_h
#include <Arduino.h>
//#include "getYPR.h"

#endif /* MotorControl_h */
//float motors[4];
/*
float y;
float p;
float r;
/*
 *this method takes t which is the tolorance to change the motors at
 * it also takes s whigh is the sensitivity
 *
 */

float* stabilize(float MY,float MP,float MR,float t, int s, float THR){//definetly going to have problems with float* vs float** etc
    //Serial.println(MY);
    motors[0]= THR;//clockwise
    motors[1]= THR;//counterclockwise
    motors[2]= THR;//counterclockwise
    motors[3]= THR;//clockwise
    int Ys = 10;//this most likely needs to be changed
    float Ydiff=0;//variable to store the difference in yaw position over YnumTimes loops of the function
   // MY = abs(MY);
   // MP= abs(MP);
   // MR= abs(MR);
    if(MP<t){
        motors[2]+=abs(MP*s);
        motors[3]+=abs(MP*s);
        motors[0]-=abs(MP*(s/2));
        motors[1]-=abs(MP*(s/2));
    }
    if(MP>t){  //dont need abs() because it is already positive
        motors[0]+=MP*s;
        motors[1]+=MP*s;
        motors[2]-=MP*(s/2);//divide by 2 might make things worse but it seems like a good idea
        motors[3]-=MP*(s/2);
    }
    if(MR>t){//dont need abs() because it is already positive
        motors[0]+=MR*s;
        motors[2]+=MR*s;
        motors[1]-=MP*(s/2);
        motors[3]-=MP*(s/2);
    }
    if(MR<t){
        motors[1]+=abs(MR*s);
        motors[3]+=abs(MR*s);
        motors[0]-=abs(MP*(s/2));
        motors[2]-=abs(MP*(s/2));
    }
    if(Ycounter==0){                  _
        Ycurr=MY;                      |
        Ycounter++;                    |
    }else if(Ycounter==YnumTimes){     |
                                       |
            Ydiff = Ycurr-MY;          | // this gets the change in yaw over YnumTimes loops of the program global variabes can be found in INOsetup.h
        Ycounter=0;                    |// the problem with this is it is going to bounce between clockwise and counterclockwise it needs a way of choosing the optimal balance
                                       |
    }else if(Ycounter<YnumTimes){      |
        Ycounter++;                    |
    }                                  |
                                      -
    if(Ydiff>0.02){//if the difference in y is greater than 0.02(to reduce noise) this means it is rotating clockwise
        Ys=Ydiff
        motors[0]-=Ys;
        motors[3]-=Ys;
        motors[1]+=Ys;
        motors[2]+=Ys;
    }else if(Ydiff<(-0.02)){//this means it is rotating counter clockwise
        motors[0]+=Ys;
        motors[3]+=Ys;
        motors[1]-=Ys;
        motors[2]-=Ys;
    }
    if(motors[0]<0){  //this makes sure no negative numbers are sent to PWM pins they don't like that
        motors[0]=0;
    }
    if(motors[1]<0){
        motors[1]=0;
    }
    if(motors[2]<0){
        motors[2]=0;
    }
    if(motors[3]<0){
        motors[3]=0;
    }
   // Serial.println(motors[0]);
    return motors;
}

void PWMout(){
    analogWrite(M1PIN,motors[0]);
    analogWrite(M2PIN,motors[1]);
    analogWrite(M3PIN,motors[2]);
    analogWrite(M4PIN,motors[3]);
    
    
}
