#pragma once

#include <variant>
#include <unordered_map>
#include <concepts>
#include <memory>

#include "InstructionBase.hpp"

class SubRoutine
{
public:
    template<std::derived_from<InstructionBase> TInstruction, typename... TArgs>
    void AddInstruction(TArgs&&... args) requires std::constructible_from<TInstruction, TArgs...>
    {
        _instructions.push_back(std::make_shared<TInstruction>(args...));
    }

    size_t CreateLabel()
    {
        auto result = _labelIndices.size();
        _labelIndices.push_back(_instructions.size());
        return result;
    }

    const std::vector<std::shared_ptr<InstructionBase>>& GetInstructions() const { return _instructions; }

    const std::vector<size_t>& GetLabelIndices() const { return _labelIndices; }
private:
    std::vector<std::shared_ptr<InstructionBase>> _instructions;

    std::vector<size_t> _labelIndices;
};