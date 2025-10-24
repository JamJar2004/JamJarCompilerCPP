#pragma once

#include "PropertyDefinition.hpp"

struct FunctionDefinition : public DefinitionBase
{
    FunctionDefinition(const NameSymbol& name, const NameSymbol& returnType) :
        Name(name), ReturnType(returnType) {}

    NameSymbol Name;
    NameSymbol ReturnType;

    std::vector<PropertyDefinition> Parameters;
};