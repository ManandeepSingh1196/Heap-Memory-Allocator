# Memory Allocator in C++

This project is my attempt to write a **custom memory heap** in C/C++ from scratch.  
The goal is to understand how memory management works at a low level and to get hands-on with system calls that usually stay hidden behind `malloc` and `new`.

---

## Why?
Every program depends on dynamic memory allocation, but most developers never see how it actually works.  
By building my own heap, I’ll learn:
- How operating systems provide memory to processes.
- How allocators track free and used blocks.

---

## System Calls Used
The kernel is the only thing that can truly give memory to a process. My allocator will interact with it directly using:

### `mmap`
- Requests a chunk of virtual memory from the kernel (page-aligned).
- Flexible and commonly used in modern allocators.

### `munmap`
- Releases previously mapped memory back to the kernel.
- Important for large allocations that shouldn’t stay around forever.

### `mprotect` (Might use this)
- Changes access permissions on memory pages.
- Useful for debugging (e.g., guard pages to catch buffer overflows).

### `sbrk` (legacy) (Not using this btw)
- Grows or shrinks the program’s heap.
- Included for learning, but less useful in multithreaded environments today.

