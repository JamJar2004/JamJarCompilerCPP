#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "Modifier.hpp"
#include "NameSymbol.hpp"

class LinkedNamedScopeDefinition;
class LinkedPropertyDefinition;
class LinkedTypeDefinitionBase;

class DeferredDefinition;

class LinkedScopeBase
{
public:
    LinkedScopeBase(std::vector<DeferredDefinition>& deferredDefinitions);

    bool TryDefineProperty(std::shared_ptr<ModifierBase> modifier, const std::string& name, std::shared_ptr<LinkedTypeDefinitionBase> type);

    bool TryDefineNamedScope(const std::string& name, std::shared_ptr<LinkedNamedScopeDefinition> namedScope);

    bool TryDefineNamedScope(std::shared_ptr<LinkedNamedScopeDefinition> namedScope);

    std::optional<LinkedPropertyDefinition> FindProperty(const std::string& name);

    std::shared_ptr<LinkedNamedScopeDefinition> FindNamedScope(const LinkedScopeBase& sourceScope, const NameSymbol& name);
protected:
    size_t GetStride() const { return _stride; }
private:
    std::unordered_map<std::string, std::shared_ptr<LinkedNamedScopeDefinition>> _scopes;

    std::unordered_map<std::string, size_t> _variableIndices;

    std::vector<LinkedPropertyDefinition> _variables;

    size_t _stride;
};