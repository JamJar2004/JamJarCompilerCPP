#include "NamedScopeDefinition.hpp"

#include "../LinkedDefinitions/LinkedNamedScopeDefinition.hpp"

bool NamedScopeDefinition::TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics)
{
    auto scope = std::make_shared<LinkedNamedScopeDefinition>(targetScope, Modifier, Symbol);
    auto result = targetScope->TryDefineNamedScope(scope) && TryLinkDefinitions(scope, diagnostics);

    if (result && TypeDefinition)
    {
        auto type = TypeDefinition->CreateLinkedType(*scope);
        scope->Type = type;
        return TypeDefinition->TryLinkDefinitions(type, diagnostics);
    }
    return result;
}

std::shared_ptr<LinkedTypeBase> Type::CreateLinkedType(LinkedNamedScopeDefinition& parent)
{
    return std::make_shared<LinkedType>(parent);
}
