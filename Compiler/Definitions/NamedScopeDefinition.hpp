#pragma once

#include "../ScopeBase.hpp"

class TypeBase;
class LinkedTypeBase;
class LinkedNamedScopeDefinition;

struct NamedScopeDefinitionBase : public ScopeBase, public DefinitionBase
{
    NamedScopeDefinitionBase(const LocationInfo& location, std::vector<DeferredDefinition>& deferredDefinitions, std::shared_ptr<ModifierBase> modifier, const std::string& name, std::shared_ptr<TypeBase> typeDefinition) :
        ScopeBase(deferredDefinitions), DefinitionBase(modifier, location), Name(name), TypeDefinition(typeDefinition) {}

    const std::string Name;

    std::shared_ptr<TypeBase> TypeDefinition;
};

struct NamedScopeDefinition : public NamedScopeDefinitionBase
{
    NamedScopeDefinition(std::vector<DeferredDefinition>& deferredDefinitions, std::shared_ptr<ModifierBase> modifier, const NameSymbol& name, std::shared_ptr<TypeBase> typeDefinition) :
        NamedScopeDefinitionBase(name.Location, deferredDefinitions, modifier, name.Name, typeDefinition), Symbol(name) {}

    const NameSymbol Symbol;

    bool TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics) override;
};

class TypeBase : public ScopeBase
{
public:
    TypeBase(std::vector<DeferredDefinition>& deferredDefinitions) : ScopeBase(deferredDefinitions) {}

    virtual std::shared_ptr<LinkedTypeBase> CreateLinkedType(LinkedNamedScopeDefinition& parent) = 0;
};

class Type : public TypeBase
{
public:
    Type(std::vector<DeferredDefinition>& deferredDefinitions) : TypeBase(deferredDefinitions) {}

    std::shared_ptr<LinkedTypeBase> CreateLinkedType(LinkedNamedScopeDefinition& parent) override;
};

template<typename TPrimitive>
class PrimitiveType : public TypeBase
{
public:
    PrimitiveType(std::vector<DeferredDefinition>& deferredDefinitions) : TypeBase(deferredDefinitions) {}

    std::shared_ptr<LinkedTypeBase> CreateLinkedType(LinkedNamedScopeDefinition& parent) override;
};

#include "../LinkedDefinitions/LinkedNamedScopeDefinition.hpp"

template<typename TPrimitive>
inline std::shared_ptr<LinkedTypeBase> PrimitiveType<TPrimitive>::CreateLinkedType(LinkedNamedScopeDefinition& parent)
{
    return std::make_shared<LinkedPrimitiveType<TPrimitive>>(parent);
}
