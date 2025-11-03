#pragma once

#include <vector>
#include <span>
#include <memory.h>

#include "../InstructionBase.hpp"

struct PushInstruction : public RegularInstructionBase
{
public:
    PushInstruction(size_t size) : Size(size) {}

    const size_t Size;

    void OnExecute(RuntimeContext& context) override
    {
        context.StackPointer += Size;
    }
};

struct PushConstantInstruction : public RegularInstructionBase
{
public:
    PushConstantInstruction(const std::span<uint8_t> data)
    {
        Data.resize(data.size());
        memcpy(Data.data(), data.data(), data.size());
    }

    std::vector<uint8_t> Data;

    virtual void OnExecute(RuntimeContext& context) override
    {
        memcpy(context.Memory + context.StackPointer, Data.data(), Data.size());
        context.StackPointer += Data.size();
    }
};