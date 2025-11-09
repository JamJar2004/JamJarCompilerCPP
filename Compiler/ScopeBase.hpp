#pragma once

#include <variant>
#include <memory>
#include <unordered_map>
#include <optional>
#include <concepts>

#include "NameSymbol.hpp"
#include "Definitions/DefinitionBase.hpp"

class ScopeBase
{
public:
    ScopeBase(std::vector<DeferredDefinition>& deferredDefinitions);

    virtual ~ScopeBase() {}

    const std::vector<std::shared_ptr<DefinitionBase>> GetDefinitions() const { return _definitions; }

    void Define(std::shared_ptr<DefinitionBase> definition)
    {
        _definitions.push_back(definition);
    }

    template<std::derived_from<DefinitionBase> TDefinition, typename... TArgs>
    void Define(TArgs&&... args) requires std::constructible_from<TDefinition, TArgs...>
    {
        _definitions.push_back(std::make_shared<TDefinition>(args...));
    }

    void AddDeferredDefinition(ScopeBase& parent, std::shared_ptr<LinkedScopeBase> targetScope, std::shared_ptr<DefinitionBase> definition)
    {
        _deferredDefinitions.emplace_back(parent, targetScope, definition);
    }

    bool TryLinkDefinitions(std::shared_ptr<LinkedScopeBase> targetScope, DiagnosticSet* diagnostics);

    std::vector<DeferredDefinition>& GetDeferredDefinitions() { return _deferredDefinitions; }
private:
    std::vector<std::shared_ptr<DefinitionBase>> _definitions;

    std::vector<DeferredDefinition>& _deferredDefinitions;
};



