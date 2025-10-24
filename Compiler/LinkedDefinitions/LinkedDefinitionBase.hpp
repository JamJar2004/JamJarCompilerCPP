#pragma once

#include <memory>
#include "../Modifier.hpp"

class LinkedScopeBase;

class LinkedDefinitionBase
{
public:
    LinkedDefinitionBase(LinkedScopeBase& parent, std::shared_ptr<ModifierBase> modifier);

    LinkedScopeBase& Parent;

    bool IsVisible(const LinkedScopeBase& sourceScope)
    {
        return _modifier->IsVisible(sourceScope, Parent);
    }
private:
    const std::shared_ptr<ModifierBase> _modifier;
};