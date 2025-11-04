#include <iostream>
#include <vector>
#include <memory>

#include "../Compiler/GlobalScope.hpp"
#include "../Compiler/LinkedGlobalScope.hpp"
#include "../Compiler/Definitions/PropertyDefinition.hpp"
#include "../Compiler/Definitions/NamedScopeDefinition.hpp"

#include "../VirtualMachine/Executable.hpp"
#include "../VirtualMachine/Instructions/OutputInstruction.hpp"
#include "../VirtualMachine/Instructions/PushInstruction.hpp"
#include "../VirtualMachine/Instructions/BinaryInstruction.hpp"

int main()
{
    // std::vector<DeferredDefinition> deferredDefinitions;
    // GlobalScope rootScope(deferredDefinitions);
    // auto privateModifier = std::make_shared<PrivateModifier>();
    // auto publicModifier = std::make_shared<PublicModifier>();
    // auto type = std::make_shared<Type>(deferredDefinitions);
    // auto vector3Scope = std::make_shared<NamedScopeDefinition>(deferredDefinitions, publicModifier, NameSymbol("Vector3"), type);
    // type->Define<PropertyDefinition>(privateModifier, NameSymbol("Float32"), std::string("X"));
    // type->Define<PropertyDefinition>(privateModifier, NameSymbol("Float32"), std::string("Y"));
    // type->Define<PropertyDefinition>(privateModifier, NameSymbol("Float32"), std::string("Z"));
    //
    // rootScope.Define(vector3Scope);
    // DiagnosticSet diagnostics;
    // auto linkedGlobalScope = std::make_shared<LinkedGlobalScope>();
    // if (!rootScope.TryLinkDefinitions(linkedGlobalScope, nullptr))
    // {
    //     size_t successCount = 0;
    //     for (auto deferredDefinition : deferredDefinitions)
    //     {
    //         if (deferredDefinition.TryLink(diagnostics))
    //         {
    //             ++successCount;
    //         }
    //     }
    // }
    // 
    // for (auto& diagnostic : diagnostics.GetDiagnostics())
    // {
    //     diagnostic->WriteMessage(std::cout);
    //     std::cout << std::endl;
    // }

    Executable executable;
    SubRoutine mainSubRoutine;
    mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(16777216);
    mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(8);
    mainSubRoutine.AddInstruction<UIntRightShiftInstruction>();
    mainSubRoutine.AddInstruction<OutputInstruction<size_t>>(std::cout);

    executable.AddSubRoutine(mainSubRoutine);

    executable.Run(1024, 512);

    return 0;
}