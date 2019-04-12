

#include "getYPR.h"


#include "Wire.h"
#include "INOsetup.h"
#include "MotorControl.h"




// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    INOsetup();
}



// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    updateYPR();
Serial.print("yaw ");
Serial.print(y);
Serial.print("      pitch ");
Serial.print(p);
Serial.print("      roll ");
Serial.print(r);
Serial.println();
    Serial.print("      M1 ");
Serial.print(motors[0]);
    Serial.print("      M2 ");
Serial.print(motors[1]);
    Serial.print("      M3 ");
Serial.print(motors[2]);
    Serial.print("      M4 ");
Serial.print(motors[3]);
Serial.println();



    
}
