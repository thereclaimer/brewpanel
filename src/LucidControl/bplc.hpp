#ifndef BP_LC_HPP
#define BP_LC_HPP

#include "brewpanel.hpp"

#include "bp-memory.hpp"

/*************************************************************************/
/* TYPES                                                                 */
/*************************************************************************/

struct BPLC;

enum BPLCErrorCode_ {
     BPLCErrorCode_InternalIOReadError                              = 0x10,
     BPLCErrorCode_InvalidNumberBytesReceived                       = 0x11,
     BPLCErrorCode_InvalidChannelArgument                           = 0x20,
     BPLCErrorCode_InvalidMultipleChannelArgument                   = 0x21,
     BPLCErrorCode_InvalidIOValue                                   = 0x2A,
     BPLCErrorCode_InvalidArgumentBaudRate                          = 0x30,
     BPLCErrorCode_InvalidOrUnknownValueType                        = 0x40,
     BPLCErrorCode_InvalidDeviceArgument                            = 0x31,
     BPLCErrorCode_InvalidConfigurationParameterArgument            = 0x4A,
     BPLCErrorCode_InvalidConfigurationParameterValueArgumentPassed = 0x4B,
     BPLCErrorCode_MoreThanOneCommandArgumentPassed                 = 0x90
};

typedef u8 BPLCErrorCode;

const char* BP_LC_ERROR_CODE_STRING[] = {
    "LucidControl Error [0x10]: Internal I/O read error Accessing the communication interface (eg. COM1 or /dev/ttyACM0) failed because of communication errors (e.g. Timeouts)",
    "LucidControl Error [0x11]: Invalid number of bytes received Indicates that the number of received bytes in the LEN Field does not correspond to the number of received bytes in the Data Field",
    "LucidControl Error [0x20]: Invalid Channel Argument The passed channel Argument is wrong or it is missed",
    "LucidControl Error [0x21]: Invalid Multiple Channel Argument The passed channel argument is wrong or it is missed",
    "LucidControl Error [0x2A]: Invalid IO Value, The value (writing) does not correspond to the expected number of values, or the value (writing) is not valid for the expected Value Type.",
    "LucidControl Error [0x30]: Invalid Argument Baud Rate The port does not support the passed parameters.",
    "LucidControl Error [0x40]: Invalid or unknown Value Type The passed Value Type is incompatible or not supported.",
    "LucidControl Error [0x31]: Invalid Device Argument specified The device (serial port) is not available or busy (e.g. already opened).",
    "LucidControl Error [0x4A]: Invalid Configuration Parameter Argument",
    "LucidControl Error [0x4B]: Invalid Configuration Parameter Value Argument passed",
    "LucidControl Error [0x90]: More than one Command Argument passed"
};

inline const char* bp_lc_error_code_string(
    BPLCErrorCode error_code) {

    const char* error_string = BP_LC_ERROR_CODE_STRING[error_code]; 

    return(error_string);
}

struct BPLCDataField {
    memory data;
};

/*************************************************************************/
/* REQUEST                                                               */
/*************************************************************************/

union BPLCRequestFrameHeader {

    struct {
        u8 opc; // opcode for request command
        u8 p1;  // parameter 1
        u8 p2   // parameter 2
        u8 len; // number of bytes in the data field
    };

    u32 value; //the header as a 4 byte value
};

struct BPLCRequestFrame {
    BPMemoryArenaHandle    arena;
    BPLCRequestFrameHeader header;
    BPLCDataField          data_field;
};

/*************************************************************************/
/* MEMORY                                                                */
/*************************************************************************/

struct BPLCMemory {
    struct {
        BPMemoryPageHandle request;
        BPMemoryPageHandle response;
    } pages;
};

internal BPLCDataField* bplc_memory_reserve_request (u64 data_field_size);
internal BPLCDataField* bplc_memory_reserve_response(u64 data_field_size);

internal void bplc_memory_release_request (BPLCDataField* data_field);
internal void bplc_memory_release_response(BPLCDataField* data_field);

/*************************************************************************/
/* BPLC                                                                  */
/*************************************************************************/

struct BPLC {
    BPLCMemory memory;
};

#endif //BP_LC_HPP