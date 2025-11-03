#pragma once

#include <memory.h>

#include "../InstructionBase.hpp"

struct WriteInstruction : public RegularInstructionBase
{
    WriteInstruction(size_t targetAddress, size_t size) : TargetAddress(targetAddress), Size(size) {}

    const size_t TargetAddress;
    const size_t Size;

    void OnExecute(RuntimeContext& context) override
    {
        context.StackPointer -= Size;
        memcpy(context.Memory + TargetAddress, context.Memory + context.StackPointer, Size);
    }
};