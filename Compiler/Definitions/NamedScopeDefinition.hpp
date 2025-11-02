#pragma once

#include "../ScopeBase.hpp"

class TypeBase;

struct NamedScopeDefinitionBase : public ScopeBase, public DefinitionBase
{
    NamedScopeDefinitionBase(std::vector<DeferredDefinition>& deferredDefinitions, std::shared_ptr<ModifierBase> modifier, const std::string& name, std::shared_ptr<TypeBase> typeDefinition) :
        ScopeBase(deferredDefinitions), DefinitionBase(modifier), Name(name), TypeDefinition(typeDefinition) {}

    const std::string Name;

    std::shared_ptr<TypeBase> TypeDefinition;
};

struct NamedScopeDefinition : public NamedScopeDefinitionBase
{
    NamedScopeDefinition(std::vector<DeferredDefinition>& deferredDefinitions, std::shared_ptr<ModifierBase> modifier, const NameSymbol& name, std::shared_ptr<TypeBase> typeDefinition) :
        NamedScopeDefinitionBase(deferredDefinitions, modifier, name.Name, typeDefinition), Symbol(name) {}

    const NameSymbol Symbol;

    bool TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics) override;
};

class TypeBase : public ScopeBase
{
public:
    TypeBase(std::vector<DeferredDefinition>& deferredDefinitions) : ScopeBase(deferredDefinitions) {}
};

class Type : public TypeBase
{
public:
    Type(std::vector<DeferredDefinition>& deferredDefinitions) : TypeBase(deferredDefinitions) {}
};