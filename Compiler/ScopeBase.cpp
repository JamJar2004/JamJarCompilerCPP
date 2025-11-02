#include "ScopeBase.hpp"
#include "LinkedScopeBase.hpp"

ScopeBase::ScopeBase(std::vector<DeferredDefinition>& deferredDefinitions) :
    _deferredDefinitions(deferredDefinitions) {}

bool ScopeBase::TryLinkDefinitions(std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics)
{
    auto result = true;
    for (auto definition : _definitions)
    {
        if (!definition->TryLink(*this, targetScope, diagnostics))
        {
            AddDeferredDefinition(*this, targetScope, definition);
            result = false;
        }
    }

    return result;
}

