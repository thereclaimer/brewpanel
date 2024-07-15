#ifndef BP_COMM_HPP
#define BP_COMM_HPP

#include "brewpanel.hpp"

struct BPComm;

/**************/
/* COMM INPUT */
/**************/

union BPCommInputTemp{

    struct {
        f32 hlt;
        f32 mlt;
        f32 blk;
    };

    f32 array[3];
};

union BPCommInputPumpStatus{

    struct {
        b16 water;
        b16 wort;
    };
    
    b32 packed;
};

struct BPCommInput {
    BPCommInputTemp       temp;
    BPCommInputPumpStatus pump_status;
};

/***************/
/* COMM OUTPUT */
/***************/

union BPCommOutputPumpRelays {

    struct {
        b8 water;
        b8 wort;
    };

    b16 packed;
};

union BPCommOutputElementContactors {

    struct {
        b8 hlt;
        b8 blk;
    };

    b16 packed;
};


union BPCommOutputElementSSRs {
    
    struct {
        f32 hlt;
        f32 blk;
    };

    f32 array[2];
};

struct BPCommOutput {
    BPCommOutputPumpRelays        pump_relays;
    BPCommOutputElementContactors element_contactors;
    BPCommOutputElementSSRs       element_ssrs;
    b32                           alarm;
};

struct BPComm {
    BPCommInput  input;
    BPCommOutput output;
};


#endif //BP_COMM_HPP