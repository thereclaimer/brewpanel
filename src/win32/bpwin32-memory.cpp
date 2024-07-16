#pragma once

#include "bpwin32.hpp"

internal u64 
bpwin32_memory_page_size() {

    SYSTEM_INFO system_info;
    GetSystemInfo(system_info);

    return(system_info.dwPageSize);
}

internal memory 
bpwin32_memory_page_reserve(
    u32 page_count) {

    SYSTEM_INFO system_info;
    GetSystemInfo(system_info);

    u64 allocation_size = system_info.dwPageSize * page_count; 

    memory reserved_memory =
        VirtualAlloc(
            0,
            allocation_size,
            MEM_RESERVE,
            PAGE_NOACCESS);

    brewpanel_assert(reserved_memory);

    return(reserved_memory);
}

internal memory
bpwin32_memory_page_commit(
    memory page_address) {

    SYSTEM_INFO system_info;
    GetSystemInfo(system_info);

    memory committed_memory = 
        VirtualAlloc(
            page_address,
            system_info.dwPageSize,
            MEM_COMMIT,
            PAGE_READWRITE);

    brewpanel_assert(committed_memory);

    return(committed_memory);
}

internal void
bpwin32_memory_page_release(
    memory page_address) {

    SYSTEM_INFO system_info;
    GetSystemInfo(system_info);

    b32 free_result =
        VirtualFree(
            page_address,
            system_info.dwPageSize,
            MEM_DECOMMIT);

    brewpanel_assert(free_result);
}


internal void
bpwin32_memory_page_decommit(
    memory page_address,
    u64    page_count) {

    SYSTEM_INFO system_info;
    GetSystemInfo(system_info);
    
    u64 allocation_size = system_info.dwPageSize * page_count; 

    b32 free_result =
        VirtualFree(
            page_address,
            allocation_size,
            MEM_RELEASE);

    brewpanel_assert(free_result);
}