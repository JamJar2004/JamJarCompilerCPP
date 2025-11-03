#pragma once

#include "../InstructionBase.hpp"

struct PopInstruction : public RegularInstructionBase
{
    PopInstruction(size_t size) : Size(size) {}

    const size_t Size;

    void OnExecute(RuntimeContext& context) override
    {
        context.StackPointer -= Size;
    }
};