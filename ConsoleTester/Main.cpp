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
#include "../VirtualMachine/Instructions/CompareInstruction.hpp"
#include "../VirtualMachine/Instructions/ReadInstruction.hpp"
#include "../VirtualMachine/Instructions/WriteInstruction.hpp"
#include "../VirtualMachine/Instructions/JumpInstruction.hpp"
#include "../VirtualMachine/Instructions/AllocateInstruction.hpp"
#include "../VirtualMachine/Instructions/FreeInstruction.hpp"

int main()
{
    std::vector<DeferredDefinition> deferredDefinitions;
    GlobalScope rootScope(deferredDefinitions);
    auto privateModifier = std::make_shared<PrivateModifier>();
    auto publicModifier = std::make_shared<PublicModifier>();
    auto type = std::make_shared<Type>(deferredDefinitions);
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
     
    for (auto& diagnostic : diagnostics.GetDiagnostics())
    {
         diagnostic->WriteMessage(std::cout);
         std::cout << std::endl;
    }

    //Executable executable;
    //SubRoutine mainSubRoutine;
//
    //auto conditionLabel = mainSubRoutine.CreateLabel();
    //auto endLabel = mainSubRoutine.CreateLabel();
//
    //auto counterAddress = sizeof(size_t);
    //auto arrayPointerAddress = counterAddress + sizeof(size_t);
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(0);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(0);
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(0);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(2);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(4);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(6);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(8);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(10);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(12);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(14);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(16);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(18);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(20);
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(11 * sizeof(size_t));
    //mainSubRoutine.AddInstruction<AllocateInstruction>();
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(arrayPointerAddress);
    //mainSubRoutine.AddInstruction<WriteInstruction>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(arrayPointerAddress);
    //mainSubRoutine.AddInstruction<ReadInstruction>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<WriteInstruction>(11 * sizeof(size_t));
//
    //mainSubRoutine.SetLabelLocation(conditionLabel); 
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(counterAddress);
    //mainSubRoutine.AddInstruction<ReadInstruction>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(11);
//
    //mainSubRoutine.AddInstruction<UIntCompareSmallerInstruction>();
//
    //mainSubRoutine.AddInstruction<JumpIfFalseInstruction>(endLabel);
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(counterAddress);
    //mainSubRoutine.AddInstruction<ReadInstruction>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<UIntMulInstruction>();
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(arrayPointerAddress);
    //mainSubRoutine.AddInstruction<ReadInstruction>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<UIntAddInstruction>();
    //mainSubRoutine.AddInstruction<ReadInstruction>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<OutputInstruction<size_t>>(std::cout);
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(1);
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(counterAddress);
    //mainSubRoutine.AddInstruction<ReadInstruction>(sizeof(size_t));
//
    //mainSubRoutine.AddInstruction<UIntAddInstruction>();
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(counterAddress);
    //mainSubRoutine.AddInstruction<WriteInstruction>(sizeof(size_t));
    //
    //mainSubRoutine.AddInstruction<GotoInstruction>(conditionLabel);
//
    //mainSubRoutine.SetLabelLocation(endLabel);
//
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(arrayPointerAddress);
    //mainSubRoutine.AddInstruction<ReadInstruction>(sizeof(size_t));
    //mainSubRoutine.AddInstruction<PushConstantValueInstruction<size_t>>(11 * sizeof(size_t));
    //mainSubRoutine.AddInstruction<FreeInstruction>();
//
    //executable.AddSubRoutine(mainSubRoutine);
//
    ////auto duration1 = executable.Run(1024, 512);
    //auto duration2 = executable.Run<2048>(1024);
//
    ////std::cout << "Execution Time: " << duration1.count() << "ms" << std::endl;
    //std::cout << "Execution Time: " << duration2.count() << "ms" << std::endl;
//
    return 0;
}