#include "LinkedDefinitionBase.hpp"

LinkedDefinitionBase::LinkedDefinitionBase(LinkedScopeBase& parent, std::shared_ptr<ModifierBase> modifier) :
    _modifier(modifier), Parent(parent) {}