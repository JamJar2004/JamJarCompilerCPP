#pragma once

#include "GenericNameSymbol.hpp"
#include "../Definitions/AliasDefinition.hpp"
#include "../Definitions/NamedScopeDefinition.hpp"

struct GenericArgumentAliasVisitor 
{
public:
    GenericArgumentAliasVisitor(ScopeBase& target, const GenericParameter& parameter) :
        _target(target), _parameter(parameter) {}

    void operator()(const GenericNameArgument& nameArgument) 
    { 
        _target.Define(std::make_shared<AliasDefinition>(_parameter.Name, nameArgument.Name));
    }

    void operator()(const GenericValueArgument& valueArgument) 
    { 
        //std::cout << valueArgument.Value << std::endl; 
    }

private:
    ScopeBase& _target;

    const GenericParameter _parameter;
};

class GenericScopeDefinition : public NamedScopeDefinitionBase
{
    GenericScopeDefinition(const LocationInfo& location, std::vector<DeferredDefinition>& deferredDefintions, const std::shared_ptr<ModifierBase>& modifier, const std::string& name, const std::vector<GenericParameter>& parameters, std::shared_ptr<TypeBase> typeDefinition) : 
        NamedScopeDefinitionBase(location, deferredDefintions, modifier, name, typeDefinition),
        Parameters(parameters)
    {
    }

    const std::vector<GenericParameter> Parameters;

    std::shared_ptr<NamedScopeDefinition> TryCreate(const std::vector<GenericArgument>& arguments, DiagnosticSet* diagnostics)
    {   
        auto symbol = NameSymbol(Location, Name, arguments);

        if (arguments.size() == Parameters.size())
        {
            auto result = std::make_shared<NamedScopeDefinition>(GetDeferredDefinitions(), symbol, TypeDefinition);

            for (size_t i = 0; i < Parameters.size(); i++)
            {
                std::visit(GenericArgumentAliasVisitor(*result, Parameters[i]), arguments[i]);
            }

            for (auto definition : GetDefinitions())
            {
                result->Define(definition);
            }

            return result;
        }
        
        if (diagnostics)
        {
            diagnostics->Report<ScopeNotFoundDiagnostic>(symbol);
        }

        return nullptr;
    }
};