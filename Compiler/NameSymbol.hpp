#pragma once

#include <string>
#include <vector>
#include <any>
#include <variant>

#include "Location.hpp"

struct GenericNameArgument;
struct GenericValueArgument;

using GenericArgument = std::variant<GenericNameArgument, GenericValueArgument>;

struct NameSymbol
{
    NameSymbol(const LocationInfo& location, const std::string& name) : NameSymbol(location, name, {}) {}
    
    NameSymbol(const LocationInfo& location, const std::string& name, const std::vector<GenericArgument>& genericArguments) :
        Name(name), GenericArguments(genericArguments), Location(location) {}

    const LocationInfo Location;
    const std::string Name;

    const std::vector<GenericArgument> GenericArguments;
};

std::ostream& operator<<(std::ostream& target, const GenericArgument& genericArgument);

std::ostream& operator<<(std::ostream& target, const NameSymbol& name);

struct GenericNameArgument
{
    NameSymbol Name;
};

struct GenericValueArgument
{
    std::any Value;
};

struct GenericArgumentLoggerVisitor 
{
public:
    GenericArgumentLoggerVisitor(std::ostream& target) : _target(target) {}

    void operator()(const GenericNameArgument& nameArgument) 
    { 
        _target << nameArgument.Name; 
    }

    void operator()(const GenericValueArgument& valueArgument) 
    { 
        //std::cout << valueArgument.Value << std::endl; 
    }

private:
    std::ostream& _target;
};

