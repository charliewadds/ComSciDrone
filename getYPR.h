#include <Arduino.h>
#include "MPU6050_6Axis_MotionApps20.h"
#include "I2Cdev.h"
MPU6050 mpu;

//#define OUTPUT_READABLE_YAWPITCHROLL


bool ypr == true;//this is probably wrong


#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)


float y;
float p;
float r;
bool blinkState = false;

// MPU control/status vars
bool AccelRdy = false;  //true it the sensor has started
char AccelIntStat;   // interrupt status byte (what is this and what does it do)
char DevStat;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
char fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo




// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high this has to be a volatile bool because the arduino uses multi-threading for the interrupt pins
void GotData?() {//might need to take out the question mark
    mpuInterrupt = true;
}
void updateYPR() {
    // if programming failed, don't try to do anything
    if (!AccelRdy) return;
    
    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
        // other program behavior stuff here
        // .
        // .
        // .
        // if you are really paranoid you can frequently test in between other
        // stuff to see if mpuInterrupt is true, and if so, "break;" from the
        // while() loop to immediately process the MPU data
        // .
        // .
        // .
    }
    
    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    AccelIntStat = mpu.getIntStatus();
    
    // get current FIFO count
    fifoCount = mpu.getFIFOCount();
    
    // check for overflow (this should never happen unless our code is too inefficient)
    if ((AccelIntStat & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow! (make sure the baud rate is 115200 or higher)"));
        
        // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (AccelIntStat & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
        
        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;
        

        

        
//#ifdef OUTPUT_READABLE_YAWPITCHROLL Again probably wrong
        if(ypr){
        // display Euler angles in degrees
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        
        y= ypr[0] * 180/M_PI;
        p=ypr[1] * 180/M_PI;
        r=ypr[2] * 180/M_PI;
        /*
        Serial.print("ypr\t");
        Serial.print(y);
        Serial.print("\t");
        Serial.print(p);
        Serial.print("\t");
         Serial.println(r);*/}
//#endif
        
#ifdef OUTPUT_READABLE_REALACCEL
        // display real acceleration, adjusted to remove gravity
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetAccel(&aa, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
        Serial.print("areal\t");
        Serial.print(aaReal.x);
        Serial.print("\t");
        Serial.print(aaReal.y);
        Serial.print("\t");
        Serial.println(aaReal.z);
#endif
        

        
   //mpu.resetFIFO(); 
}
