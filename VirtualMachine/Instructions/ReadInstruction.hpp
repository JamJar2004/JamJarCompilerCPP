#pragma once

#include <memory.h>

#include "../InstructionBase.hpp"

struct ReadInstruction : public RegularInstructionBase
{
    ReadInstruction(size_t sourceAddress, size_t size) : SourceAddress(sourceAddress), Size(size) {}

    const size_t SourceAddress;
    const size_t Size;

    void OnExecute(RuntimeContext& context) override
    {
        memcpy(context.Memory + context.StackPointer, context.Memory + SourceAddress, Size);
        context.StackPointer += Size;
    }
};