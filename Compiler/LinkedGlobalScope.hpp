#pragma once

#include "LinkedScopeBase.hpp"

struct LinkedGlobalScope : public LinkedScopeBase 
{
    LinkedGlobalScope(std::vector<DeferredDefinition> deferredDefinitions) : LinkedScopeBase(deferredDefinitions) {}
};