#pragma once

#include <ostream>

#include "../InstructionBase.hpp"

template<typename TValue>
class OutputInstruction : public RegularInstructionBase
{
public:
    OutputInstruction(std::ostream& outputStream) : _outputStream(outputStream) {}

    void OnExecute(RuntimeContext& context) override
    {   
        auto value = context.Pop<TValue>();
        _outputStream << "[Out]: {" << value << "}" << std::endl;
    }
private:
    std::ostream& _outputStream;
}; 