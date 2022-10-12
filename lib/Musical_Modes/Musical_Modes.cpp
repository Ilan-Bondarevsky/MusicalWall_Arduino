#include <Arduino.h>
#include "Musical_Modes.h"

#include "Musical_StandAlone/Musical_StandAlone.h"
#include "Musical_Song_StandAlone/Musical_Song_StandAlone.h"

#include "Musical_Led.h"
#include "Musical_MP3.h"
#include "Musical_MPR_Sensor.h"

#include "Songs_Data.h"
#include "Songs_Function.h"
#include "Data_File.h"

#include "Musical_hc10_BLE_Blutooth.h"

void musical_Program(){
    while(1){
        writeData("My Misrable Life");
    delay(1000);
    }

    bool changeModeToDefault = false;
    switch (curMode)
    {
    case StandAlone:
        changeModeToDefault = sa_PlayMode();
        break;
    case StandAlone_Song:
        changeModeToDefault = saS_playMode();
        break;
    
    default:
        changeModeToDefault = true;
        break;
    }
    
    if(changeModeToDefault){
        changeMode(defaultMode);
    }
}

bool changeMode(enum Available_Modes newMode){
    if(curMode == newMode){
        Serial.println("Already in the mode!");
        return false;
    }
    Serial.print("Changing mode from ");
    Serial.print(ModeName[curMode]);
    Serial.print(" to mode ");
    curMode = newMode;
    Serial.println(ModeName[curMode]);
    Serial.println("");
    return true;
}