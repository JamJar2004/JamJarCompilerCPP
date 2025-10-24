#pragma once

#include <memory>

#include "LinkedNamedScopeDefinition.hpp"
#include "LinkedDefinitionBase.hpp"

class LinkedPropertyDefinition : public LinkedDefinitionBase
{
public:
    LinkedPropertyDefinition(LinkedScopeBase& parent, std::shared_ptr<ModifierBase> modifier, size_t offset, std::shared_ptr<LinkedTypeDefinitionBase> type, const std::string& name) :
        LinkedDefinitionBase(parent, modifier), Offset(offset), Name(name), Type(type) {}

    const size_t Offset;

    const std::shared_ptr<LinkedTypeDefinitionBase> Type;
    const std::string                               Name;
};