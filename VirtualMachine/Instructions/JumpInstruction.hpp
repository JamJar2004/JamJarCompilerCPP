#pragma once

#include "../InstructionBase.hpp"

struct GotoInstruction : public InstructionBase
{
    GotoInstruction(size_t targetInstructionIndex) : TargetInstructionIndex(targetInstructionIndex) {}

    const size_t TargetInstructionIndex;

    void Execute(RuntimeContext& context) final override
    {
        context.InstructionPointer = context.LabelIndices[TargetInstructionIndex];
    }
};

struct JumpIfTrueInstruction : public InstructionBase
{
    JumpIfTrueInstruction(size_t targetInstructionIndex) : TargetInstructionIndex(targetInstructionIndex) {}

    const size_t TargetInstructionIndex;

    void Execute(RuntimeContext& context) final override
    {
        auto condition = context.Pop<uint8_t>();
        if (condition)
        {
            context.InstructionPointer = context.LabelIndices[TargetInstructionIndex];
        }
        else
        {
            ++context.InstructionPointer;
        }
    }
};

struct JumpIfFalseInstruction : public InstructionBase
{
    JumpIfFalseInstruction(size_t targetInstructionIndex) : TargetInstructionIndex(targetInstructionIndex) {}

    const size_t TargetInstructionIndex;

    void Execute(RuntimeContext& context) final override
    {
        auto condition = context.Pop<uint8_t>();
        if (condition)
        {
            ++context.InstructionPointer;
        }
        else
        {
            context.InstructionPointer = context.LabelIndices[TargetInstructionIndex];
        }
    }
};