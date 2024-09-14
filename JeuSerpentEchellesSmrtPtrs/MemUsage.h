#ifndef MEMUSAGE_H
#define MEMUSAGE_H

#include <cstdlib>

struct MemoryUsage
{
    size_t totalAllocated = 0;
    size_t totalFreed = 0;
    size_t currentUsage() {return totalAllocated - totalFreed;}

    void PrintMemoryUsage();
};

#endif /* MEMUSAGE_H */

