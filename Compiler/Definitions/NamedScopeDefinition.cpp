#include "NamedScopeDefinition.hpp"

#include "../LinkedDefinitions/LinkedNamedScopeDefinition.hpp"

bool NamedScopeDefinition::TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics)
{
    auto scope = std::make_shared<LinkedNamedScopeDefinition>(targetScope, Modifier, Symbol);
    return targetScope->TryDefineNamedScope(scope) && TryLinkDefinitions(scope, diagnostics);
}