#pragma once

#include <string>

#include "../Scope.hpp"
#include "DefinitionBase.hpp"

struct AliasDefinition : public DefinitionBase
{
    AliasDefinition(std::shared_ptr<ModifierBase> modifier, std::string& name, const NameSymbol& sourceName) :
        DefinitionBase(modifier), Name(name), SourceName(sourceName) {}

    const std::string Name;

    const NameSymbol SourceName;

    bool TryLink(ScopeBase& parent, LinkedScopeBase& targetScope, DiagnosticSet* diagnostics)
    {
        auto scope = targetScope.FindNamedScope(SourceName);
        if (!scope)
        {
            if (diagnostics)
            {
                diagnostics->Report<ScopeNotFoundDiagnostic>(SourceName);
            }
            return false;
        }

        targetScope.TryDefineNamedScope(scope);
        return true;
    }
};