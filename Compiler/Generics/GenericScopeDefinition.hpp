#pragma once

#include "GenericNameSymbol.hpp"
#include "../Definitions/AliasDefinition.hpp"

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
    GenericScopeDefinition(std::vector<DeferredDefinition>& deferredDefintions, const std::string& name, const std::vector<GenericParameter>& parameters, std::shared_ptr<TypeDefinitionBase> typeDefinition) : 
        NamedScopeDefinitionBase(deferredDefintions, name, typeDefinition),
        Parameters(parameters)
    {
    }

    const std::vector<GenericParameter> Parameters;

    std::shared_ptr<NamedScopeDefinition> TryCreate(const std::vector<GenericArgument>& arguments, DiagnosticSet* diagnostics)
    {   
        if (arguments.size() == Parameters.size())
        {
            auto result = std::make_shared<NamedScopeDefinition>(GetDeferredDefinitions(), NameSymbol(Name, arguments), TypeDefinition);

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
            diagnostics->Report<ScopeNotFoundDiagnostic>(NameSymbol(Name, arguments));
        }

        return nullptr;
    }
};