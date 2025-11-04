#pragma once

#include <memory.h>
#include <concepts>

#include "../InstructionBase.hpp"

namespace std
{
    template<typename _Tp>
    struct bit_left_shift : public binary_function<_Tp, _Tp, _Tp>
    {
        _GLIBCXX14_CONSTEXPR
        _Tp
        operator()(const _Tp& __x, const _Tp& __y) const { return __x << __y; }
    };

     template<typename _Tp>
    struct bit_right_shift : public binary_function<_Tp, _Tp, _Tp>
    {
        _GLIBCXX14_CONSTEXPR
        _Tp
        operator()(const _Tp& __x, const _Tp& __y) const { return __x >> __y; }
    };
}


template<typename TOperand, std::invocable_r<TOperand, TOperand, TOperand> TInvokable>
struct BinaryInstruction : public RegularInstructionBase
{
public:
    BinaryInstruction() : _operation() {}

    void OnExecute(RuntimeContext& context) override
    {
        auto right = context.Pop<TOperand>();
        auto left  = context.Pop<TOperand>();

        context.Push(_operation(left, right));
    }
private:
    const TInvokable _operation;
};

using UIntAddInstruction = BinaryInstruction<size_t, std::plus<size_t>>;
using UIntSubInstruction = BinaryInstruction<size_t, std::minus<size_t>>;
using UIntMulInstruction = BinaryInstruction<size_t, std::multiplies<size_t>>;
using UIntDivInstruction = BinaryInstruction<size_t, std::divides<size_t>>;
using UIntModInstruction = BinaryInstruction<size_t, std::modulus<size_t>>;

using UIntBitwiseAndInstruction = BinaryInstruction<size_t, std::bit_and<size_t>>;
using UIntBitwiseOrInstruction  = BinaryInstruction<size_t, std::bit_or<size_t>>;
using UIntBitwiseXorInstruction = BinaryInstruction<size_t, std::bit_xor<size_t>>;

using  UIntLeftShiftInstruction = BinaryInstruction<size_t, std::bit_left_shift<size_t>>;
using UIntRightShiftInstruction = BinaryInstruction<size_t, std::bit_right_shift<size_t>>;

using SIntAddInstruction = BinaryInstruction<int64_t, std::plus<int64_t>>;
using SIntSubInstruction = BinaryInstruction<int64_t, std::minus<int64_t>>;
using SIntMulInstruction = BinaryInstruction<int64_t, std::multiplies<int64_t>>;
using SIntDivInstruction = BinaryInstruction<int64_t, std::divides<int64_t>>;
using SIntModInstruction = BinaryInstruction<int64_t, std::modulus<int64_t>>;

using SIntBitwiseAndInstruction = BinaryInstruction<size_t, std::bit_and<size_t>>;
using SIntBitwiseOrInstruction  = BinaryInstruction<size_t, std::bit_or<size_t>>;
using SIntBitwiseXorInstruction = BinaryInstruction<size_t, std::bit_xor<size_t>>;

using  SIntLeftShiftInstruction = BinaryInstruction<size_t, std::bit_left_shift<size_t>>;
using SIntRightShiftInstruction = BinaryInstruction<size_t, std::bit_right_shift<size_t>>;

using Float32AddInstruction = BinaryInstruction<float, std::plus<float>>;
using Float32SubInstruction = BinaryInstruction<float, std::minus<float>>;
using Float32MulInstruction = BinaryInstruction<float, std::multiplies<float>>;
using Float32DivInstruction = BinaryInstruction<float, std::divides<float>>;
using Float32ModInstruction = BinaryInstruction<float, std::modulus<float>>;

using Float64AddInstruction = BinaryInstruction<double, std::plus<double>>;
using Float64SubInstruction = BinaryInstruction<double, std::minus<double>>;
using Float64MulInstruction = BinaryInstruction<double, std::multiplies<double>>;
using Float64DivInstruction = BinaryInstruction<double, std::divides<double>>;
using Float64ModInstruction = BinaryInstruction<double, std::modulus<double>>;