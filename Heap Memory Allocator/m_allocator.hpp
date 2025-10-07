/*
Heap memory allocator using Windows kernel-level memory management (VirtualAlloc/VirtualFree) for allocation and deallocation.

This allocator leverages the Windows operating system's native memory management functions:
  - VirtualAlloc:   Reserves or commits memory pages in the process's address space.
  - VirtualFree:    Releases or decommits previously allocated memory pages.

--- VirtualAlloc ---
VirtualAlloc is a Windows API function that allocates memory by reserving or committing pages in the virtual address space of the calling process.

Prototype:
  LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);

Parameters:
  - lpAddress:         Suggested starting address for the allocation (usually nullptr for automatic selection).
  - dwSize:            Number of bytes to allocate (should be a multiple of the system's page size).
  - flAllocationType:  Type of allocation (e.g., MEM_RESERVE, MEM_COMMIT).
  - flProtect:         Memory protection flags (e.g., PAGE_READWRITE).

Return Value:
  - On success: Returns a pointer to the allocated memory region.
  - On failure: Returns nullptr.

Usage Example:
  void* mem = VirtualAlloc(nullptr, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

--- VirtualFree ---
VirtualFree is used to release or decommit a region of memory previously allocated by VirtualAlloc.

Prototype:
  BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);

Parameters:
  - lpAddress:   Starting address of the memory region to free.
  - dwSize:      Size of the region to free (0 to release the entire region).
  - dwFreeType:  Type of free operation (e.g., MEM_RELEASE, MEM_DECOMMIT).

Return Value:
  - On success: Returns nonzero.
  - On failure: Returns zero.

Usage Example:
  VirtualFree(mem, 0, MEM_RELEASE);

--- Notes ---
- These functions are available on Windows systems.
- On POSIX systems (Linux, macOS, etc.), similar functionality is provided by mmap/munmap.
- Proper alignment and size (multiple of page size) are required for portability and correctness.
- Always check the return values for errors when using these system calls.

This allocator uses VirtualAlloc to obtain large memory blocks from the Windows kernel and VirtualFree to release them when no longer needed.
*/


#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <windows.h>




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
	void* heap_start = VirtualAlloc;
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


