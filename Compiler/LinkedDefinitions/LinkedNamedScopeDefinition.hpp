#pragma once

#include <cstddef>

#include "../ScopeBase.hpp"
#include "../LinkedScopeBase.hpp"
#include "LinkedDefinitionBase.hpp"

class LinkedTypeDefinitionBase;

class LinkedNamedScopeDefinition : public LinkedScopeBase, public LinkedDefinitionBase
{
public:
    LinkedNamedScopeDefinition(std::vector<DeferredDefinition>& deferredDefinitions, std::shared_ptr<LinkedScopeBase> parent, std::shared_ptr<ModifierBase> modifier, const NameSymbol& name) : 
        LinkedScopeBase(deferredDefinitions), LinkedDefinitionBase(*parent, modifier), Name(name) {}

    const NameSymbol Name;

    std::shared_ptr<LinkedTypeDefinitionBase> Type;
};

class LinkedTypeDefinitionBase : public LinkedScopeBase
{
public:
    virtual size_t SizeInBytes() const = 0;
};

class LinkedTypeDefinition : public LinkedScopeBase
{
public:
    virtual size_t SizeInBytes() const
    {
        return 0;
    }

};

class LinkedUInt32TypeDefinition : public LinkedTypeDefinitionBase
{
public:
    size_t SizeInBytes() const { return sizeof(uint32_t); }
};