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

float* stabilize(float MY,float MP,float MR,float t, float s){//definetly going to have problems with float* vs float** etc
    
    
    if(MP<t){
        motors[2]+MP*s;
        motors[3]+MP*s;
    }
    if(MP>t){
        motors[0]+MP*s;
        motors[1]+MP*s;
    }
    if(MR<t){
        motors[0]+MR*s;
        motors[2]+MR*s;
    }
    if(MR>t){
        motors[1]+MR*s;
        motors[3]+MR*s;
    }
    Serial.println(motors[0]);
    return motors;
}
