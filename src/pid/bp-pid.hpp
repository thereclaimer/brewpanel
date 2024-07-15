#ifndef BP_PID_HPP
#define BP_PID_HPP

#include "brewpanel.hpp"

struct BPPid;
 
struct BPPidProportional {
    f32 term;
    f32 constant;
}; 
 
struct BPPidIntegral {
    f32 term;
    f32 constant;
}; 

struct BPPidDerivative {
    f32 term;
    f32 constant;
}; 

struct BPPid {
    f32               set_value;
    f32               measured_value;
    f32               output_value;
    u64               time;
    u64               delta_time;
    BPPidProportional proportional;
    BPPidIntegral     integral;
    BPPidDerivative   derivative;
};

typedef void* BPPidHandle;

internal BPPidHandle
bp_pid_create(
    f32 p,
    f32 i,
    f32 d);

#endif //BP_PID_HPP