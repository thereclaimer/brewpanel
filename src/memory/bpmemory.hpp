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

internal BPMemoryManager* bpmemory_manager_create              ();
internal void             bpmemory_manager_destroy             ();
internal u64              bpmemory_manager_pages_count_total   ();
internal u64              bpmemory_manager_pages_count_free    ();
internal u64              bpmemory_manager_pages_count_reserved();

/***************************************************************************************/
/* MEMORY PAGE                                                                         */
/***************************************************************************************/

struct BPMemoryPage {
    u64           arena_size;
    BPMemoryPage* next;
    BPMemoryPage* previous;
};

internal BPMemoryPageHandle bpmemory_page_reserve(u64 arena_size);

internal void               bpmemory_page_release             (BPMemoryPageHandle page);
internal u64                bpmemory_page_arena_size          (BPMemoryPageHandle page);
internal u64                bpmemory_page_arena_count_total   (BPMemoryPageHandle page);
internal u64                bpmemory_page_arena_count_free    (BPMemoryPageHandle page);
internal u64                bpmemory_page_arena_count_reserved(BPMemoryPageHandle page);

/***************************************************************************************/
/* MEMORY ARENA                                                                        */
/***************************************************************************************/

struct BPMemoryArena {
    BPMemoryPage*  page;
    memory         stack_ptr;
    BPMemoryArena* next; 
    BPMemoryArena* previous; 
};

internal BPMemoryArenaHandle bpmemory_arena_reserve(BPMemoryPageHandle page);

internal void   bpmemory_arena_release      (BPMemoryArenaHandle arena);
internal memory bpmemory_arena_base         (BPMemoryArenaHandle arena);
internal memory bpmemory_arena_clear        (BPMemoryArenaHandle arena);
internal u64    bpmemory_arena_size_total   (BPMemoryArenaHandle arena);
internal u64    bpmemory_arena_size_free    (BPMemoryArenaHandle arena);
internal u64    bpmemory_arena_size_reserved(BPMemoryArenaHandle arena);

internal memory bpmemory_arena_push(BPMemoryArenaHandle arena, u64 memory_size);
internal memory bpmemory_arena_pop (BPMemoryArenaHandle arena, u64 memory_size);

#endif //BP_MEMORY_HPP