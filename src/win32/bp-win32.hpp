#ifndef BREWPANEL_WIN32_HPP
#define BREWPANEL_WIN32_HPP

#include <Windows.h>

#include "brewpanel.hpp"

struct BPWin32Window;

/* WIN32 */

#define bp_win32_main WINAPI wWinMain

struct BPWin32Args { 
    HINSTANCE h_instance;            
    HINSTANCE h_prev_instance;
    PWSTR     p_cmd_line;
    int       n_cmd_show;
};

struct BPWin32 {
    BPWin32Args    args;
    BPWin32Window* window;
};

/* WINDOW */

struct BPWin32Window {
    WNDCLASSA wclass;
    HWND      handle_window;
    HDC       handle_device_context;
};

internal BPWin32Window*
bp_win32_window_create(
    const BPWin32Args& args);

#endif //BREWPANEL_WIN32_HPP



