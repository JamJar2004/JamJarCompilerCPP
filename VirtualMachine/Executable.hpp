#pragma once

#include "RuntimeContext.hpp"

class Executable
{
public:
    RuntimeContext Run(size_t memorySize, size_t stackSize)
    {
        return RuntimeContext(memorySize, stackSize);
    }
};