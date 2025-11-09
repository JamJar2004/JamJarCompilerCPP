#pragma once

#include <memory>

#include "LinkedDefinitionBase.hpp"

class LinkedTypeBase;

class LinkedPropertyDefinition : public LinkedDefinitionBase
{
public:
    LinkedPropertyDefinition(LinkedScopeBase& parent, std::shared_ptr<ModifierBase> modifier, size_t offset, std::shared_ptr<LinkedTypeBase> type, const std::string& name);
        
    const size_t Offset;

    const std::shared_ptr<LinkedTypeBase> Type;
    const std::string                     Name;
};