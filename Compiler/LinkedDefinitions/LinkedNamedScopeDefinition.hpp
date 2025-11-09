#pragma once

#include <cstddef>

#include "../ScopeBase.hpp"
#include "../LinkedScopeBase.hpp"
#include "LinkedDefinitionBase.hpp"

class LinkedNamedScopeDefinition : public LinkedScopeBase, public LinkedDefinitionBase
{
public:
    LinkedNamedScopeDefinition(std::shared_ptr<LinkedScopeBase> parent, std::shared_ptr<ModifierBase> modifier, const NameSymbol& name) : 
        LinkedDefinitionBase(*parent, modifier), Name(name) {}

    const NameSymbol Name;

    std::shared_ptr<LinkedTypeBase> Type;

    std::shared_ptr<LinkedNamedScopeDefinition> FindNamedScope(const LinkedScopeBase& sourceScope, const NameSymbol& name) override;
};

class LinkedTypeBase : public LinkedScopeBase
{
public:
    LinkedTypeBase(LinkedNamedScopeDefinition& parent) : Parent(parent) {}

    LinkedNamedScopeDefinition& Parent;

    virtual size_t SizeInBytes() const = 0;

    std::shared_ptr<LinkedNamedScopeDefinition> FindNamedScope(const LinkedScopeBase& sourceScope, const NameSymbol& name) override;
};

class LinkedType : public LinkedTypeBase
{
public:
    LinkedType(LinkedNamedScopeDefinition& parent) : LinkedTypeBase(parent) {}

    size_t SizeInBytes() const override
    {
        return GetStride();
    }

};

template<typename TPrimitive>   
class LinkedPrimitiveType : public LinkedTypeBase
{
public:
    LinkedPrimitiveType(LinkedNamedScopeDefinition& parent) : LinkedTypeBase(parent) {}

    size_t SizeInBytes() const override { return sizeof(TPrimitive); }
};