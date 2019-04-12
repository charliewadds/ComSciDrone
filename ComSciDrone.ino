

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
    updateYPR(); //F() is supposed to save sram
Serial.print(F("yaw "));
Serial.print(F(y));
Serial.print(F("      pitch "));
Serial.print(F(p));
Serial.print(F("      roll "));
Serial.print(r);
Serial.println();
    Serial.print(F("      M1 "));
Serial.print(F(motors[0]));
    Serial.print(F("      M2 "));
Serial.print(F(motors[1]));
    Serial.print(F("      M3 "));
Serial.print(F(motors[2]));
    Serial.print(F("      M4 "));
Serial.print(F(motors[3]));
Serial.println();
    delay(100);//only for debugging



    
}
