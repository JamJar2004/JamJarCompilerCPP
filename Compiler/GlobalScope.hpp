#pragma once

#include "ScopeBase.hpp"

struct GlobalScope : public ScopeBase 
{
    GlobalScope(std::vector<DeferredDefinition>& deferredDefinitions) : ScopeBase(deferredDefinitions) {}
};