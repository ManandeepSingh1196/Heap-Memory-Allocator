#include <iostream>
#include "m_allocator.hpp"

int main()
{
	//Try to allocate memory using the custom allocator here
	void* test = heap_init(nullptr, 1024 * 1024); // Initialize a heap with 1MB


	std::cin.get();
	return 0;
}