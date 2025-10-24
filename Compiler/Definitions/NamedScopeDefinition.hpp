#pragma once

#include "../ScopeBase.hpp"

class TypeDefinitionBase;

struct NamedScopeDefinitionBase : public ScopeBase, public DefinitionBase
{
    NamedScopeDefinitionBase(std::vector<DeferredDefinition>& deferredDefinitions, std::shared_ptr<ModifierBase> modifier, const std::string& name, std::shared_ptr<TypeDefinitionBase> typeDefinition) :
        ScopeBase(deferredDefinitions), DefinitionBase(modifier), Name(name), TypeDefinition(typeDefinition) {}

    const std::string Name;

    std::shared_ptr<TypeDefinitionBase> TypeDefinition;
};

struct NamedScopeDefinition : public NamedScopeDefinitionBase
{
    NamedScopeDefinition(std::vector<DeferredDefinition>& deferredDefinitions, std::shared_ptr<ModifierBase> modifier, const NameSymbol& name, std::shared_ptr<TypeDefinitionBase> typeDefinition) :
        NamedScopeDefinitionBase(deferredDefinitions, modifier, name.Name, typeDefinition), Symbol(name) {}

    const NameSymbol Symbol;

    virtual bool TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics) override;
};

class TypeBase : public ScopeBase
{
    
};

class Type : public TypeBase
{
    bool TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics) override;
};