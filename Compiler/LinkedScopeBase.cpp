#include "LinkedScopeBase.hpp"
#include "LinkedDefinitions/LinkedNamedScopeDefinition.hpp"
#include "LinkedDefinitions/LinkedPropertyDefinition.hpp"

LinkedScopeBase::LinkedScopeBase(std::vector<DeferredDefinition>& deferredDefinitions) : LinkedScopeBase(deferredDefinitions) {}

bool LinkedScopeBase::TryDefineProperty(std::shared_ptr<ModifierBase> modifier, const std::string& name, std::shared_ptr<LinkedTypeDefinitionBase> type)
{
    auto it = _variableIndices.find(name);
    if (it == _variableIndices.end())
    {
        _variableIndices[name] = _variables.size();
        _variables.emplace_back(*this, modifier, _stride, type, name);
        _stride += type->SizeInBytes();
        return true;
    }

    return false;
}

bool LinkedScopeBase::TryDefineNamedScope(const std::string& name, std::shared_ptr<LinkedNamedScopeDefinition> namedScope)
{
    auto it = _scopes.find(name);
    if (it == _scopes.end())
    {
        _scopes[name] = namedScope;
        return true;
    }
    return false;
}

bool LinkedScopeBase::TryDefineNamedScope(std::shared_ptr<LinkedNamedScopeDefinition> namedScope)
{
    auto it = _scopes.find(namedScope->Name.Name);
    if (it == _scopes.end())
    {
        _scopes[namedScope->Name.Name] = namedScope;
        return true;
    }
    return false;
}

std::optional<LinkedPropertyDefinition> LinkedScopeBase::FindProperty(const std::string& name)
{
    auto it = _variableIndices.find(name);
    if (it == _variableIndices.end())
    {
        return {};
    }

    auto result = _variables[it->second];
}

std::shared_ptr<LinkedNamedScopeDefinition> LinkedScopeBase::FindNamedScope(const LinkedScopeBase& sourceScope, const NameSymbol& name)
{
    auto it = _scopes.find(name.Name);
    if (it == _scopes.end())
    {
        return nullptr;
    }

    auto result = it->second;
    if (!result->IsVisible(sourceScope))
    {
        return nullptr;
    }

    return it->second;
}