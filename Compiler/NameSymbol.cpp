#include "NameSymbol.hpp"

std::ostream& operator<<(std::ostream& target, const GenericArgument& genericArgument)
{
    std::visit(GenericArgumentLoggerVisitor(target), genericArgument);
    return target;
}

std::ostream& operator<<(std::ostream& target, const NameSymbol& name)
{
    target << name.Name;
    if (name.GenericArguments.size() > 0)
    {
        target << '<';

        for (size_t i = 0; i < name.GenericArguments.size() - 1; i++)
        {
            target << name.GenericArguments[i] << ", ";
        }

        target << name.GenericArguments[name.GenericArguments.size() - 1] << '>';
    }

    return target;
}