#ifndef BP_PUMP_HPP
#define BP_PUMP_HPP

#include "brewpanel.hpp"

/*********/
/* TYPES */
/*********/

struct  BPPump;
struct  BPPumpManager;
typedef u32 BPPumpId;
typedef u32 BPPumpControl;

/********/
/* PUMP */
/********/

enum BPPumpId_ {
     BPPumpId_Water = 0,
     BPPumpId_Wort  = 1,
     BPPumpId_Count = 2
};

enum BPPumpControl_ {
     BPPumpControl_Off = 0,
     BPPumpControl_On  = 1,
};

struct BPPump {
     BPPumpControl control;
};

struct BPPumpControlStatus {

     union {

          struct {
               BPPumpControl water;
               BPPumpControl wort;
          };
     
          BPPumpControl array[BPPumpId_Count];
     };
};

internal void
bp_pump_control(
     BPPumpId      pump_id,
     BPPumpControl pump_control);

internal void
bp_pump_control_status(
     BPPumpControlStatus& pump_control_status);

internal void
bp_pump_control_all_stop();

/*****************/
/* PUMP MANAGER  */
/*****************/

struct BPPumpManager {

     union {

          struct {
               BPPump water;
               BPPump wort;
          };

          BPPump array[BPPumpId_Count];

     } pumps;
};

internal BPPumpManager*
bp_pump_manager_create();

#endif  //BP_PUMP_HPP