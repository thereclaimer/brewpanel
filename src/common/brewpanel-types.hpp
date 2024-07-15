#ifndef BREWPANEL_TYPES_HPP
#define BREWPANEL_TYPES_HPP

#include <cstdint>

#define internal static
#define local    static
#define global   static
#define external extern "C" __declspec(dllexport)
#define api      extern "C" __declspec(dllimport)
#define null     0

#define possum_assert(condition) if(!(condition)) *((int*)(NULL)) = 1
#define possum_nop()             possum_assert(true)
#define possum_panic()           possum_assert(false)

typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef s8       b8;
typedef s16      b16;
typedef s32      b32;
typedef s64      b64;

typedef float    f32;
typedef double   f64;

typedef void*    handle;

typedef u8       byte;
typedef byte*    memory;

#endif //BREWPANEL_TYPES_HPP