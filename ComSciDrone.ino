

#include "getYPR.h"


#include "Wire.h"
#include "INOsetup.h"




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




    
}
