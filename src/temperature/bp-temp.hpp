#ifndef BP_TEMP_HPP
#define BP_TEMP_HPP

#include "brewpanel.hpp"

/*********/
/* TYPES */
/*********/

struct      BPTemp;
struct      BPTempManager;
struct      BPTempCalibration;
typedef u32 BPTempMode;
typedef u32 BPTempId;

#define BP_TEMP_FREEZING_F 032.0f
#define BP_TEMP_FREEZING_C 000.0f
#define BP_TEMP_BOILING_F  212.0f
#define BP_TEMP_BOILING_C  100.0f 

/********/
/* TEMP */
/********/

enum BPTempId_ {
     BPTempId_HLT   = 0,
     BPTempId_MLT   = 1,
     BPTempId_BLK   = 2,
     BPTempId_Count = 3
};

enum BPTempMode_ {
    BPTempMode_Farenheit = 0,
    BPTempMode_Celcius   = 1
};

struct BPTemp {
    f32 value;
};

union BPTempReading {

    struct {
        f32 hlt;
        f32 mlt;
        f32 blk;
    };

    f32 array[BPTempId_Count];    
};

struct BPTempCalibration {
    BPTempId id;
    f32      measured_freezing;
    f32      measured_boiling;
};

internal void
bp_temp_read(
    BPTempReading& temp_reading);

internal void
bp_temp_calibration(
    const BPTempCalibration& calibration);

/****************/
/* TEMP MANAGER */
/****************/

struct BPTempManager {
    BPTempMode mode;
    f32        measured_values[BPTempId_Count];
    f32        calibration_slope[BPTempId_Count];
    f32        calibration_offset[BPTempId_Count];
};

internal BPTempManager*
bp_temp_manager_create();

#endif //BP_TEMP_HPP