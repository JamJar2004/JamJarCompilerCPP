#include "PropertyDefinition.hpp"

#include "NamedScopeDefinition.hpp"
#include "../LinkedDefinitions/LinkedNamedScopeDefinition.hpp"

bool PropertyDefinition::TryLink(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics)
{
    auto scope = targetScope->FindNamedScope(*targetScope, Type);

    if (!scope)
    {
        if (diagnostics)
        {
            diagnostics->Report<ScopeNotFoundDiagnostic>(Type);
        }
        return false;
    }

    auto type = scope->Type;

    if (!type)
    {
        if (diagnostics)
        {
            diagnostics->Report<ScopeIsNotTypeDiagnostic>(Type);
        }
        return false;
    }

    if (!targetScope->TryDefineProperty(Modifier, Name, type))
    {
        if (diagnostics)
        {
            diagnostics->Report<PropertyNameAlreadyExistsDiagnostic>(Type.Location, Name);
        }
        return false;
    }
    return true;
}