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
float motors[4];
/*
float y;
float p;
float r;
/*
 *this method takes t which is the tolorance to change the motors at
 * it also takes s whigh is the sensitivity
 *
 */
float* stabilize(float t, float s){//definetly going to have problems with float* vs float** etc
    
    
    if(p<0-t){
        motors[2]+p*s;
        motors[3]+p*s;
    }
    if(p>0+t){
        motors[0]+p*s;
        motors[1]+p*s;
    }
    if(r<0-t){
        motors[0]+r*s;
        motors[2]+r*s;
    }
    if(r>0+t){
        motors[1]+r*s;
        motors[3]+r*s;
    }
    return motors;
}
