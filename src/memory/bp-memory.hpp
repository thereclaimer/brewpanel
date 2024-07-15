#ifndef BP_MEMORY_HPP
#define BP_MEMORY_HPP

#include "brewpanel.hpp"

/***************************************************************************************/
/* TYPES                                                                               */
/***************************************************************************************/

struct BPMemoryManager;
struct BPMemoryPage;
struct BPMemoryArena;

typedef handle BPMemoryPageHandle;
typedef handle BPMemoryArenaHandle; 

/***************************************************************************************/
/* MEMORY MANAGER                                                                      */
/***************************************************************************************/

struct BPMemoryManager {
    u64            page_size;
    u64            count_pages;
    struct {
        BPMemoryPage* free;
        BPMemoryPage* reserved;
    } pages;
};

internal BPMemoryManager* bp_memory_manager_create(u64 page_size);

internal void             bp_memory_manager_destroy             ();
internal u64              bp_memory_manager_pages_count_total   ();
internal u64              bp_memory_manager_pages_count_free    ();
internal u64              bp_memory_manager_pages_count_reserved();

/***************************************************************************************/
/* MEMORY PAGE                                                                         */
/***************************************************************************************/

struct BPMemoryPage {
    u64           arena_size;
    BPMemoryPage* next;
    BPMemoryPage* previous;
};

internal BPMemoryPageHandle bp_memory_page_reserve(u64 arena_size);

internal void               bp_memory_page_release             (BPMemoryPageHandle page);
internal u64                bp_memory_page_arena_size          (BPMemoryPageHandle page);
internal u64                bp_memory_page_arena_count_total   (BPMemoryPageHandle page);
internal u64                bp_memory_page_arena_count_free    (BPMemoryPageHandle page);
internal u64                bp_memory_page_arena_count_reserved(BPMemoryPageHandle page);

/***************************************************************************************/
/* MEMORY ARENA                                                                        */
/***************************************************************************************/

struct BPMemoryArena {
    BPMemoryPage*  page;
    memory         stack_ptr;
    BPMemoryArena* next; 
    BPMemoryArena* previous; 
};

internal BPMemoryArenaHandle bp_memory_arena_reserve(BPMemoryPageHandle page);

internal void   bp_memory_arena_release      (BPMemoryArenaHandle arena);
internal memory bp_memory_arena_base         (BPMemoryArenaHandle arena);
internal memory bp_memory_arena_clear        (BPMemoryArenaHandle arena);
internal u64    bp_memory_arena_size_total   (BPMemoryArenaHandle arena);
internal u64    bp_memory_arena_size_free    (BPMemoryArenaHandle arena);
internal u64    bp_memory_arena_size_reserved(BPMemoryArenaHandle arena);

internal memory bp_memory_arena_push(BPMemoryArenaHandle arena, u64 memory_size);
internal memory bp_memory_arena_pop (BPMemoryArenaHandle arena, u64 memory_size);

#endif //BP_MEMORY_HPP