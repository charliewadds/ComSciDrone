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
    motors[0]= THR;
    motors[1]= THR;
    motors[2]= THR;
    motors[3]= THR;
   // MY = abs(MY);
   // MP= abs(MP);
   // MR= abs(MR);
    if(MP<t){
        motors[2]+=abs(MP*s);
        motors[3]+=abs(MP*s);
        motors[0]-=abs(MP*s);
        motors[1]-=abs(MP*s);
    }
    if(MP>t){  //dont need abs() because it is already positive
        motors[0]+=MP*s;
        motors[1]+=MP*s;
        motors[2]-=MP*s;
        motors[3]-=MP*s;
    }
    if(MR>t){
        motors[0]+=MR*s;
        motors[2]+=MR*s;
       motors[1]-=MP*s;
        motors[3]-=MP*s;
    }
    if(MR<t){
        motors[1]+=abs(MR*s);
        motors[3]+=abs(MR*s);
        motors[0]-=abs(MP*s);
        motors[2]-=abs(MP*s);
    }
    if(motors[0]<0){
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
