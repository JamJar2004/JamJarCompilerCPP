#pragma once

#include <stdint.h>
#include <cstddef>
#include <unordered_map>

class RuntimeContext
{
public:
    RuntimeContext(size_t memorySize, size_t stackSize) : Memory(new uint8_t[memorySize]) 
    {
        _freeSpaces[stackSize] = memorySize - stackSize;
    }

    RuntimeContext(const RuntimeContext&) = delete;

    ~RuntimeContext()
    {
        delete[] Memory;
    }

    RuntimeContext& operator=(const RuntimeContext&) = delete;

    uint8_t* const Memory;

    size_t InstructionPointer;
    size_t StackBasePointer;
    size_t StackPointer;

    template<typename TValue>
    void Push(const TValue& value)
    {
        memcpy(Memory + StackPointer, &value, sizeof(TValue));
        StackPointer += sizeof(TValue);
    }

    template<typename TValue>
    TValue Pop()
    {
        StackPointer -= sizeof(TValue);
        return *(TValue*)(Memory + StackPointer)
    }

    template<typename TValue>
    TValue& Read(size_t address)
    {
        return *(TValue*)(Memory + address)
    }

    size_t Allocate(size_t sizeInBytes)
    {
        for(auto it = _freeSpaces.begin(); it != _freeSpaces.end(); ++it)
        {
            size_t freeSpaceStartAddress = it->first;
            size_t freeSpaceSize = it->second;
            if(freeSpaceSize >= sizeInBytes)
            {
                _freeSpaces.erase(it);
                if(freeSpaceSize != sizeInBytes)
                {
                    _freeSpaces[freeSpaceStartAddress + sizeInBytes] = freeSpaceSize - sizeInBytes;
                }
                return freeSpaceStartAddress;
            }
        }
        return 0;
    }

    void Free(size_t address, size_t sizeInBytes)
    {
        auto it = _freeSpaces.find(address + sizeInBytes);
        size_t freeSpaceSize = sizeInBytes;
        if(it != _freeSpaces.end())
        {
            freeSpaceSize += it->second;
            _freeSpaces.erase(it);
        }

        _freeSpaces[address] = freeSpaceSize;
    }
private:
    std::unordered_map<size_t, size_t> _freeSpaces;
};