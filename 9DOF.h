//
//  9DOF.h
//  
//
//  Created by Charlie Wadds on 2019-04-25.
//

#ifndef _DOF_h
#include <Arduino.h>
#include "MPU6050_6Axis_MotionApps20.h"
#include "I2Cdev.h"
#include <Wire.h>
#include <SPI.h>
#include <SparkFunLSM9DS1.h>
#define _DOF_h


#endif /* _DOF_h */

LSM9DS1 imu;

#define LSM9DS1_M    0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG    0x6B // Would be 0x6A if SDO_AG is LOW

#define PRINT_CALCULATED
//#define PRINT_RAW
#define PRINT_SPEED 250 // 250 ms between prints
static unsigned long lastPrint = 0; // Keep track of print time

#define DECLINATION -8.58 // Declination (degrees) in Boulder, CO.


void getGyroAccel(){
    if ( imu.gyroAvailable() )
    {
        // To read from the gyroscope,  first call the
        // readGyro() function. When it exits, it'll update the
        // gx, gy, and gz variables with the most current data.
        imu.readGyro();
        y= imu.gz;
        p= imu.gy;
        r=imu.gx;
    }
    if ( imu.accelAvailable() )
    {
        // To read from the accelerometer, first call the
        // readAccel() function. When it exits, it'll update the
        // ax, ay, and az variables with the most current data.
        imu.readAccel();
    }
    if ( imu.magAvailable() )
    {
        // To read from the magnetometer, first call the
        // readMag() function. When it exits, it'll update the
        // mx, my, and mz variables with the most current data.
        imu.readMag();
    }
    
}
