#pragma once

#include "../ScopeBase.hpp"

struct PropertyDefinition : public DefinitionBase
{
    PropertyDefinition(std::shared_ptr<ModifierBase> modifier, const LocationInfo& location, const NameSymbol& type, const std::string& name) : 
        DefinitionBase(modifier, location), Type(type), Name(name) {}

    const NameSymbol  Type;
    const std::string Name;

    bool TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics) override;
};