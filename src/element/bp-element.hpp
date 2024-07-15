#ifndef BP_ELEMENT_HPP
#define BP_ELEMENT_HPP

#include "brewpanel.hpp"

#include "bp-pid.hpp"

struct BPElement {
    f32         set_value;
    f32         read_value;
    BPPidHandle pid;
};

struct BPElementManager {
    BPElement hlt_element;    
    BPElement blk_element;    
};

#endif //BP_ELEMENT_HPP