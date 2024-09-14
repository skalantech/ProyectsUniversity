#include "MemUsage.h"
#include <iostream>
#include <vector>

static MemoryUsage s_MemoryUsage;
static size_t s_allocNum = 0;
static size_t s_dallocNum = 0;

void* operator new(size_t size)
{
    // std::cout << "Allocating " << size << "bytes\n";
    s_MemoryUsage.totalAllocated += size;
    s_allocNum++;
    void* ptr = malloc(size);
    return ptr;
}

void operator delete(void* memory)
{
    // std::cout << "Freeing memory";
    s_dallocNum++;
    free(memory);
}

void operator delete(void* memory, size_t size)
{
    // std::cout << "Freeing " << size << "bytes\n";
    s_MemoryUsage.totalFreed += size;
    s_dallocNum++;
    free(memory);
}

void* operator new[](size_t size)
{
    // std::cout << "Allocating array " << size << " bytes\n";
    s_MemoryUsage.totalAllocated += size;
    s_allocNum++;
    void* ptr = malloc(size);
    return ptr;
}

void operator delete[](void* memory)
{

    // std::cout << "Freeing array " << myMemoryMap.back() << " bytes\n";
    s_dallocNum++;
    free(memory);
}

void operator delete[](void* memory, size_t size)
{
    // std::cout << "Freeing array " << size << " bytes\n";
    s_MemoryUsage.totalFreed += size;
    s_dallocNum++;
    free(memory);
}

void MemoryUsage::PrintMemoryUsage()
{
    std::cout << "Total Allocated: " << s_MemoryUsage.totalAllocated << " bytes\n";
    std::cout << "Total Freed: " << s_MemoryUsage.totalFreed << " bytes\n";
    std::cout << "Memory Usage: " << s_MemoryUsage.currentUsage()/1024/1024 << " Mbytes\n";
    std::cout << "Allocs: " << s_allocNum << '\n';
    std::cout << "Dallocs: " << s_dallocNum << '\n';
}