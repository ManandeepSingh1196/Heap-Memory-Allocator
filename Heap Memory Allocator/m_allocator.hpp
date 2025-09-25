/*
Heap memory allocator using kernel-level memory management (mmap/munmap) for allocation and deallocation.

This allocator leverages the operating system's native memory management functions:
  - mmap:   Maps memory pages from the kernel into the process's address space.
  - munmap: Unmaps (releases) previously mapped memory pages.

--- mmap ---
mmap is a system call that allocates memory by mapping files or devices into memory.
In the context of a heap allocator, mmap is typically used to request anonymous memory from the OS.

Prototype:
  void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);

Parameters:
  - addr:   Suggested starting address for the mapping (usually nullptr for automatic selection).
  - length: Number of bytes to map (must be a multiple of the system's page size).
  - prot:   Memory protection flags (e.g., PROT_READ | PROT_WRITE).
  - flags:  Mapping flags (e.g., MAP_PRIVATE | MAP_ANONYMOUS).
  - fd:     File descriptor (set to -1 when using MAP_ANONYMOUS).
  - offset: Offset in the file (set to 0 for anonymous mapping).

Return Value:
  - On success: Returns a pointer to the mapped memory region.
  - On failure: Returns MAP_FAILED ((void*)-1).

Usage Example:
  void* mem = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

--- munmap ---
munmap is used to unmap a region of memory previously mapped by mmap, releasing it back to the OS.

Prototype:
  int munmap(void* addr, size_t length);

Parameters:
  - addr:   Starting address of the memory region to unmap.
  - length: Length of the region to unmap (must match the length used in mmap).

Return Value:
  - On success: Returns 0.
  - On failure: Returns -1.

Usage Example:
  munmap(mem, size);

--- Notes ---
- These functions are available on POSIX-compliant systems (Linux, macOS, etc.).
- On Windows, similar functionality is provided by VirtualAlloc/VirtualFree.
- Proper alignment and size (multiple of page size) are required for portability and correctness.
- Always check the return values for errors when using these system calls.

This allocator uses mmap to obtain large memory blocks from the kernel and munmap to release them when no longer needed.
*/


#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <sys/types.h>



/*
 A simple heap memory allocator using a doubly linked list to manage free and allocated memory chunks.
 Each chunk has a header containing its size, allocation status, and pointers to the next and previous chunks.
 The allocator supports initialization, allocation, and deallocation of memory blocks.
 */

struct HeapChunk {
	size_t size;          // Size of the chunk (including header)
	bool is_free;        // Is this chunk free?
	HeapChunk* next;     // Pointer to the next chunk
	HeapChunk* prev;     // Pointer to the previous chunk
};




/*
 Each chunk has a header containing its size, allocation status, and pointers to the next and previous chunks.
 The allocator supports initialization, allocation, and deallocation of memory blocks.
*/

struct Heap {
	void* start;         // Start of the heap memory
	size_t total_size;   // Total size of the heap
	HeapChunk* head;     // Pointer to the first chunk in the heap
};





// Initialize the heap with a given memory block and size creating the initial free chunk
void* heap_init(void* memory, size_t size)
{
	void* heap_start = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}




// Allocate a block of memory of the given size from the heap upon request and return a pointer to it
void* heap_alloc(Heap* heap, size_t size)
{
	//mmap
}




// Free a previously allocated block of memory, merging adjacent free chunks if possible
void heap_free(Heap* heap, void* ptr)
{
	//munmap
}


