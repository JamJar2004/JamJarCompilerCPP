#pragma once

#include <vector>
#include <memory>
#include <chrono>

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

    std::chrono::milliseconds Run(size_t memorySize, size_t stackSize)
    {
       

        auto memory = new uint8_t[memorySize];
        RuntimeContext runtimeContext(memory, memorySize, stackSize, _labelIndices);

        auto startTime = std::chrono::high_resolution_clock::now();

        while (runtimeContext.InstructionPointer < _instructions.size())
        {
            _instructions[runtimeContext.InstructionPointer]->Execute(runtimeContext);
        }

        auto endTime = std::chrono::high_resolution_clock::now();

        delete[] memory;

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    }

    template<size_t MemorySize>
    std::chrono::milliseconds Run(size_t stackSize)
    {
        uint8_t memory[MemorySize];
        
        RuntimeContext runtimeContext(memory, MemorySize, stackSize, _labelIndices);

        auto startTime = std::chrono::high_resolution_clock::now();

        while (runtimeContext.InstructionPointer < _instructions.size())
        {
            _instructions[runtimeContext.InstructionPointer]->Execute(runtimeContext);
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    }
private:
    std::vector<std::shared_ptr<InstructionBase>> _instructions;

    std::vector<size_t> _labelIndices;
};