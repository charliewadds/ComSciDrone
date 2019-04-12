//
//  INOsetup.h
//  
//
//  Created by Charlie Wadds on 2019-04-12.
//

#ifndef INOsetup_h
#define INOsetup_h

#include <Arduino.h>
#endif /* INOsetup_h */
const int M1PIN = 3;
const int M2PIN = 5;
const int M3PIN = 6;
const int M4PIN = 9;
float motors[4];
void INOsetup(){
    // join I2C bus (I2Cdev library doesn't do this automatically)
    
    Wire.begin();
    TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
    
    
    
    Serial.begin(115200);//make this 115200 to use teapot (no clue what teapot is)
    //some weird serial thing can go here for arduino leonardo done even know what that is
    
    
    Serial.println(F("starting"));//use F to reduce the sram usage
    mpu.initialize();
    
    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));
    
    // wait for ready
    //this is super dumb
    /*
     Serial.println(F("\nSend any character to begin DMP programming and demo: "));
     while (Serial.available() && Serial.read()); // empty buffer
     while (!Serial.available());                 // wait for data
     while (Serial.available() && Serial.read()); // empty buffer again
     */
    // load and configure the DMP (I think DMP is digital motion processor)
    Serial.println(F("starting accel"));
    DevStat = mpu.dmpInitialize();
    
    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788); // 1688 factory default for my test chip
    //not totally sure what these do but without them the output is all over the place
    
    // make sure it worked (returns 0 if so)
    if (DevStat == 0) {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);
        
        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, GotData, RISING);
        AccelIntStat = mpu.getIntStatus();
        
        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        AccelRdy = true;
        
        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(DevStat);
        Serial.println(F(")"));
    }
    
    // configure LED for output
    pinMode
    pinMode(LED_PIN, OUTPUT);
}
