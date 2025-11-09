#include "LinkedPropertyDefinition.hpp"

#include "LinkedNamedScopeDefinition.hpp"

LinkedPropertyDefinition::LinkedPropertyDefinition(LinkedScopeBase &parent, std::shared_ptr<ModifierBase> modifier, size_t offset, std::shared_ptr<LinkedTypeBase> type, const std::string &name) : 
    LinkedDefinitionBase(parent, modifier), Offset(offset), Name(name), Type(type) {}