#pragma once

#include "RuntimeContext.hpp"

namespace std
{
    template <typename TInvokable, typename TReturn, typename... TArgs>
    concept invocable_r = is_invocable_r_v<TReturn, TInvokable, TArgs...>;
}

struct InstructionBase
{
    virtual ~InstructionBase() {}

    virtual void Execute(RuntimeContext& context) = 0;
};

struct RegularInstructionBase : public InstructionBase
{
    void Execute(RuntimeContext& context) final override
    {
        OnExecute(context);
        ++context.InstructionPointer;
    }

    virtual void OnExecute(RuntimeContext& context) = 0;
};