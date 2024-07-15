#ifndef BP_CORE_HPP
#define BP_CORE_HPP

#include "brewpanel.hpp"

#include "bp-comm.hpp"
#include "bp-element.hpp"
#include "bp-pump.hpp"
#include "bp-temp.hpp"

struct BPCore;

struct BPCore{
    BPElementManager* element_manager;
    BPPumpManager*    pump_manager;
    BPTempManager*    temp_manager;
};


#endif //BP_CORE_HPP