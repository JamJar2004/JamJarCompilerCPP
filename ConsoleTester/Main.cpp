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
    auto privateModifier = std::make_shared<PrivateModifier>();
    auto publicModifier = std::make_shared<PublicModifier>();

    GlobalScope rootScope(deferredDefinitions);

    rootScope.Define<NamedScopeDefinition>(deferredDefinitions, publicModifier, NameSymbol(LocationInfo(1, 1, 1, "Float32.jam"), "Float32"), std::make_shared<PrimitiveType<float>>(deferredDefinitions));

    auto type = std::make_shared<Type>(deferredDefinitions);
    auto vector3Scope = std::make_shared<NamedScopeDefinition>(deferredDefinitions, publicModifier, NameSymbol(LocationInfo(10, 1, 4, "Vector3.jam"), "Vector3"), type);
    type->Define<PropertyDefinition>(privateModifier, LocationInfo(10, 1, 0, "DUMMY"), NameSymbol(LocationInfo(10, 1, 4, "DUMMY"), "Float32"), "X");
    type->Define<PropertyDefinition>(privateModifier, LocationInfo(10, 2, 0, "DUMMY"), NameSymbol(LocationInfo(10, 2, 4, "DUMMY"), "Float32"), "Y");
    type->Define<PropertyDefinition>(privateModifier, LocationInfo(10, 3, 0, "DUMMY"), NameSymbol(LocationInfo(10, 3, 4, "DUMMY"), "Float32"), "Z");
    
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
        std::cout << *diagnostic << std::endl;
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