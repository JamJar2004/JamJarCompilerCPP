#pragma class

#include <string>
#include <vector>
#include <variant>


enum GenericParameterType
{
    Name,
    Integer
};

struct GenericParameter
{
    GenericParameter(const std::string& name, GenericParameterType type) : 
        Name(name), Type(type) {}

    const std::string Name;

    const GenericParameterType Type;
};

class GenericNameSymbol
{
public:
    GenericNameSymbol(const std::string& name, const std::vector<GenericParameter> parameters) :
        Name(name), Parameters(parameters) {}

    const std::string Name;

    const std::vector<GenericParameter> Parameters;
};