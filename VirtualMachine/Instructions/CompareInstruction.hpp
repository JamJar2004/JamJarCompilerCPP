#pragma once

#include <memory.h>
#include <concepts>

#include "../InstructionBase.hpp"


template<typename TOperand, std::invocable_r<bool, TOperand, TOperand> TInvokable>
struct BinaryInstruction : public RegularInstructionBase
{
    void OnExecute(RuntimeContext& context) override
    {
        auto right = context.Pop<TOperand>();
        auto left  = context.Pop<TOperand>();

        context.Push<uint8_t>(_operation(left, right) ? 1 : 0);
    }
private:
    const TInvokable _operation;
};

using IntCompareSmallerInstruction        = BinaryInstruction<size_t, std::less<size_t>>;
using IntCompareGreaterInstruction        = BinaryInstruction<size_t, std::greater<size_t>>;
using IntCompareSmallerOrEqualInstruction = BinaryInstruction<size_t, std::less_equal<size_t>>;
using IntCompareGreaterOrEqualInstruction = BinaryInstruction<size_t, std::greater_equal<size_t>>;
using IntCompareEqualInstruction          = BinaryInstruction<size_t, std::equal_to<size_t>>;
using IntCompareNotEqualInstruction       = BinaryInstruction<size_t, std::not_equal_to<size_t>>;