#pragma once

#include <vector>
#include <memory>

#include "RuntimeContext.hpp"
#include "InstructionBase.hpp"
#include "SubRoutine.hpp"

class Executable
{
public:
    void AddSubRoutine(const SubRoutine& subRoutine)
    {
        for (auto labelIndex : subRoutine.GetLabelIndices())
        {
            _labelIndices.push_back(labelIndex + _instructions.size());
        }

        for (const auto& instruction : subRoutine.GetInstructions())
        {
            _instructions.push_back(instruction);
        }
    }

    void Run(size_t memorySize, size_t stackSize)
    {
        RuntimeContext runtimeContext(memorySize, stackSize, _labelIndices);

        while (runtimeContext.InstructionPointer < _instructions.size())
        {
            _instructions[runtimeContext.InstructionPointer]->Execute(runtimeContext);
        }
    }
private:
    std::vector<std::shared_ptr<InstructionBase>> _instructions;

    std::vector<size_t> _labelIndices;
};