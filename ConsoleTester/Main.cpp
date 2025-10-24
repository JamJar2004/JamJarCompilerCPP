#include <iostream>
#include <vector>
#include <memory>

#include "../Compiler/GlobalScope.hpp"
#include "../Compiler/LinkedGlobalScope.hpp"
#include "../Compiler/Definitions/PropertyDefinition.hpp"
#include "../Compiler/Definitions/NamedScopeDefinition.hpp"

#include "../VirtualMachine/SubRoutineBuilder.hpp"

int main()
{
    std::vector<DeferredDefinition> deferredDefinitions;
    GlobalScope rootScope(deferredDefinitions);

    auto privateModifier = std::make_shared<PrivateModifier>();
    auto publicModifier = std::make_shared<PublicModifier>();

    auto type = std::make_shared<TypeDefinition>();

    auto vector3Scope = std::make_shared<NamedScopeDefinition>(deferredDefinitions, publicModifier, NameSymbol("Vector3"), type);
    type->Define<PropertyDefinition>(privateModifier, NameSymbol("Float32"), std::string("X"));
    type->Define<PropertyDefinition>(privateModifier, NameSymbol("Float32"), std::string("Y"));
    type->Define<PropertyDefinition>(privateModifier, NameSymbol("Float32"), std::string("Z"));
    
    rootScope.Define(vector3Scope);

    DiagnosticSet diagnostics;
    auto linkedGlobalScope = std::make_shared<LinkedGlobalScope>();
    if (!rootScope.TryLinkDefinitions(linkedGlobalScope, nullptr))
    {
        size_t successCount = 0;
        for (auto deferredDefinition : deferredDefinitions)
        {
            if (deferredDefinition.TryLink(diagnostics))
            {
                ++successCount;
            }
        }
    }

    //SubRoutineBuilder mainSubRoutine;
    //mainSubRoutine.AddInstruction(PushInstructionData { sizeof(size_t) });
    //mainSubRoutine.AddInstruction(WriteInstructionData { sizeof(size_t), });
}