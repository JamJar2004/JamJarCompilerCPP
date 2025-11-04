#pragma once

#include <memory.h>

#include "../InstructionBase.hpp"

struct WriteInstruction : public RegularInstructionBase
{
    WriteInstruction(size_t size) : Size(size) {}

    const size_t Size;

    void OnExecute(RuntimeContext& context) override
    {
        size_t targetAddress = context.Pop<size_t>();
        context.StackPointer -= Size;
        memcpy(context.Memory + targetAddress, context.Memory + context.StackPointer, Size);
    }
};