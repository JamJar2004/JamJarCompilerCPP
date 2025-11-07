#pragma once

#include "../InstructionBase.hpp"

struct FreeInstruction : public RegularInstructionBase
{
public:
    FreeInstruction() {}

    void OnExecute(RuntimeContext& context) override
    {
        auto sizeInBytes = context.Pop<size_t>();
        auto address = context.Pop<size_t>();
        context.Free(address, sizeInBytes);
    }
};