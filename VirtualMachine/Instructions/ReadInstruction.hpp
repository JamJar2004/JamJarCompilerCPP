#pragma once

#include <memory.h>

#include "../InstructionBase.hpp"

struct ReadInstruction : public RegularInstructionBase
{
    ReadInstruction(size_t size) : Size(size) {}

    const size_t Size;

    void OnExecute(RuntimeContext& context) override
    {
        size_t sourceAddress = context.Pop<size_t>();
        memcpy(context.Memory + context.StackPointer, context.Memory + sourceAddress, Size);
        context.StackPointer += Size;
    }
};

struct CopyInstruction : public RegularInstructionBase
{
    CopyInstruction(size_t size) : Size(size) {}

    const size_t Size;

    void OnExecute(RuntimeContext& context) override
    {
        memcpy(context.Memory + context.StackPointer, context.Memory + context.StackPointer - Size, Size);
        context.StackPointer += Size;
    }
};