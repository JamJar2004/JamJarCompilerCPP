#pragma once

#include "../InstructionBase.hpp"

struct AllocateInstruction : public RegularInstructionBase
{
public:
    AllocateInstruction() {}

    void OnExecute(RuntimeContext& context) override
    {
        auto sizeInBytes = context.Pop<size_t>();
        auto address = context.Allocate(sizeInBytes);
        context.Push<size_t>(address);
    }
};