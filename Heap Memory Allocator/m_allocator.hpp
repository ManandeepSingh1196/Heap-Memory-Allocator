#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>

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


