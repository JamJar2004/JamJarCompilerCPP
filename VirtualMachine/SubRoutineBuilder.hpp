#pragma once

#include <variant>
#include <unordered_map>

#include "Instructions/PushInstruction.hpp"
#include "Instructions/PopInstruction.hpp"
#include "Instructions/ReadInstruction.hpp"
#include "Instructions/WriteInstruction.hpp"
#include "Label.hpp"

using InstructionData = std::variant<PushInstructionData, PopInstructionData, ReadInstructionData, WriteInstructionData>;

class SubRoutineBuilder
{
public:
    void AddInstruction(InstructionData instruction)
    {
        _instructions.push_back(instruction);
    }

    void AddLabel(Label label)
    {
        _labelIndices[label.GetId()] = _instructions.size();
    }
private:
    std::vector<InstructionData> _instructions;

    std::unordered_map<size_t, size_t> _labelIndices;
};

class SubRoutine
{
    
};