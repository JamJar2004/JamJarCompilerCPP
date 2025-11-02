#pragma once

#include <cstddef>

#include "../ScopeBase.hpp"
#include "../LinkedScopeBase.hpp"
#include "LinkedDefinitionBase.hpp"

class LinkedTypeBase;

class LinkedNamedScopeDefinition : public LinkedScopeBase, public LinkedDefinitionBase
{
public:
    LinkedNamedScopeDefinition(std::shared_ptr<LinkedScopeBase> parent, std::shared_ptr<ModifierBase> modifier, const NameSymbol& name) : 
        LinkedDefinitionBase(*parent, modifier), Name(name) {}

    const NameSymbol Name;

    std::shared_ptr<LinkedTypeBase> Type;
};

class LinkedTypeBase : public LinkedScopeBase
{
public:
    virtual size_t SizeInBytes() const = 0;
};

class LinkedType : public LinkedScopeBase
{
public:
    virtual size_t SizeInBytes() const
    {
        return GetStride();
    }

};

class LinkedUInt32Type : public LinkedTypeBase
{
public:
    size_t SizeInBytes() const { return sizeof(uint32_t); }
};