#pragma once

#include "defines.h"

//used to store the internal platform state pointer.
typedef struct platform_state {
    void* internal_state;
}platform_state;

//stores the platform's state wrapped with some platform specfic information
b8 platform_startup(
    platform_state* plat_state,
    const char* application_name,
    i32 x,
    i32 y,
    i32 width,
    i32 height
);

//Shuts down the platform at the address pointed to by the plat_state pointer
 void platform_shutdown(platform_state* plat_state);

//Pumps the next message and return the address from the state
b8 platform_pump_messages(platform_state* plat_state);

//Allocates a block of memory of the given size and aligment. returns pointer to block
void* platform_allocate(u64 size, b8 aligned);

//frees the block at the block void* pointer.
void platform_free(void* block, b8 aligned);

//zeros out the memory at the block for the given size
void* platform_zero_memory(void* block, u64 size);

//copys memory into the dest block from the const source void* pointer, for the given size.
void* platform_copy_memory(void* dest, const void* source, u64 size);

//Sets the memory at the given dest block pointer to the 32bit value for the u64 size
void* platform_set_memory(void* dest, i32 value, u64 size);

//Allows for platform specific colored console printing 
void platform_console_write(const char* message, u8 color);

//Allows for platform specific colored console error printing 
void platform_console_write_error(const char* message, u8 color);

//retrieves the absolute platform specfic type
f64 platform_get_absolute_time();

//Sleep on threed for the provided ms. This blocks main thread.
void platform_sleep(u64 ms);