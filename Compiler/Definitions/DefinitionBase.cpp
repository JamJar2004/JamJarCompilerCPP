#include "DefinitionBase.hpp"

DeferredDefinition::DeferredDefinition(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, std::shared_ptr<DefinitionBase> definition) :
        _parent(parent), _targetScope(targetScope), _definition(definition) {}

bool DeferredDefinition::TryLink(DiagnosticSet& diagnostics)
{
    return _definition->TryLink(_parent, _targetScope, &diagnostics);
}