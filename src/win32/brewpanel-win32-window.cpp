#pragma once

#include "brewpanel-win32.hpp"

global BPWin32Window bp_win32_window; 

internal LRESULT CALLBACK
bp_win32_window_callback(
    HWND   window_handle, 
    UINT   message, 
    WPARAM w_param, 
    LPARAM l_param) {

}

internal BPWin32Window*
bp_win32_window_create(
    const BPWin32Args& args) {

    bp_win32_window = {0};

    //create window class
    bp_win32_window.wclass.lpfnWndProc   = (WNDPROC)bp_win32_window_callback;
    bp_win32_window.wclass.hInstance     = args.h_instance;
    bp_win32_window.wclass.lpszClassName = "Brewpanel";
    bp_win32_window.wclass.style         = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;

    return(&bp_win32_window);
}
