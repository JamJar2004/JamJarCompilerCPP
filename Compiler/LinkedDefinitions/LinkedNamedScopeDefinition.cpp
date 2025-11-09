#include "LinkedNamedScopeDefinition.hpp"

std::shared_ptr<LinkedNamedScopeDefinition> LinkedNamedScopeDefinition::FindNamedScope(const LinkedScopeBase& sourceScope, const NameSymbol& name)
{
    auto found = LinkedScopeBase::FindNamedScope(sourceScope, name);
    if (found)
    {
        return found;
    }
    return Parent.FindNamedScope(sourceScope, name);
}

std::shared_ptr<LinkedNamedScopeDefinition> LinkedTypeBase::FindNamedScope(const LinkedScopeBase& sourceScope, const NameSymbol& name)
{
    auto found = LinkedScopeBase::FindNamedScope(sourceScope, name);
    if (found)
    {
        return found;
    }
    return Parent.FindNamedScope(sourceScope, name);
}


