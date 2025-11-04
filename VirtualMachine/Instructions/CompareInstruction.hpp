#pragma once

#include <memory.h>
#include <concepts>

#include "../InstructionBase.hpp"

template<typename TOperand, std::invocable_r<bool, TOperand, TOperand> TInvokable>
struct CompareInstruction : public RegularInstructionBase
{
public:
    CompareInstruction() : _operation() {}

    void OnExecute(RuntimeContext& context) override
    {
        auto right = context.Pop<TOperand>();
        auto left  = context.Pop<TOperand>();

        context.Push<uint8_t>(_operation(left, right) ? 1 : 0);
    }
private:
    const TInvokable _operation;
};

using UIntCompareSmallerInstruction        = CompareInstruction<size_t, std::less<size_t>>;
using UIntCompareGreaterInstruction        = CompareInstruction<size_t, std::greater<size_t>>;
using UIntCompareSmallerOrEqualInstruction = CompareInstruction<size_t, std::less_equal<size_t>>;
using UIntCompareGreaterOrEqualInstruction = CompareInstruction<size_t, std::greater_equal<size_t>>;
using UIntCompareEqualInstruction          = CompareInstruction<size_t, std::equal_to<size_t>>;
using UIntCompareNotEqualInstruction       = CompareInstruction<size_t, std::not_equal_to<size_t>>;

using SIntCompareSmallerInstruction        = CompareInstruction<int64_t, std::less<int64_t>>;
using SIntCompareGreaterInstruction        = CompareInstruction<int64_t, std::greater<int64_t>>;
using SIntCompareSmallerOrEqualInstruction = CompareInstruction<int64_t, std::less_equal<int64_t>>;
using SIntCompareGreaterOrEqualInstruction = CompareInstruction<int64_t, std::greater_equal<int64_t>>;
using SIntCompareEqualInstruction          = CompareInstruction<int64_t, std::equal_to<int64_t>>;
using SIntCompareNotEqualInstruction       = CompareInstruction<int64_t, std::not_equal_to<int64_t>>;