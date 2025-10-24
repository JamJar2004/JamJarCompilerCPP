#pragma once

#include <queue>

#include "../Diagnostics.hpp"
#include "../Modifier.hpp"

class ScopeBase;
class LinkedScopeBase;

struct DefinitionBase
{
public:
    DefinitionBase(std::shared_ptr<ModifierBase> modifier) : Modifier(modifier) {}

    const std::shared_ptr<ModifierBase> Modifier; 

    virtual bool TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics) = 0;
};

struct DeferredDefinition
{
public:
    DeferredDefinition(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, std::shared_ptr<DefinitionBase> definition);
    
    bool TryLink(DiagnosticSet& diagnostics);
private:
    ScopeBase& _parent;

    std::shared_ptr<LinkedScopeBase> _targetScope;

    const std::shared_ptr<DefinitionBase> _definition;
};
