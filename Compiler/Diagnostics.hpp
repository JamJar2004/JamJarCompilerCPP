#pragma once

#include <string>
#include <vector>
#include <memory>
#include <concepts>

#include "Generics/GenericNameSymbol.hpp"
#include "NameSymbol.hpp"
#include "Location.hpp"

struct DiagnosticBase
{
    DiagnosticBase(const LocationInfo& location) : Location(location) {}

    const LocationInfo Location;

    virtual void WriteMessage(std::ostream& output) const = 0;
};

std::ostream& operator<<(std::ostream& target, const DiagnosticBase& diagnostic);


class DiagnosticSet
{
public:
    template<std::derived_from<DiagnosticBase> TDiagnostic, typename... TArgs>
    void Report(TArgs... args) requires std::constructible_from<TDiagnostic, TArgs...>
    {
        _diagnostics.push_back(std::make_unique<TDiagnostic>(args...));
    }

    const std::vector<std::unique_ptr<DiagnosticBase>>& GetDiagnostics() const { return _diagnostics; }
private:
    std::vector<std::unique_ptr<DiagnosticBase>> _diagnostics;
};

struct ScopeNotFoundDiagnostic : public DiagnosticBase
{
    ScopeNotFoundDiagnostic(const NameSymbol& name) : DiagnosticBase(name.Location), Name(name) {}

    const NameSymbol Name;

    void WriteMessage(std::ostream& output) const override
    {
        output << "Scope of name \'" << Name << "\' was not found."; 
    }
};

struct ScopeIsNotTypeDiagnostic : public DiagnosticBase
{
    ScopeIsNotTypeDiagnostic(const NameSymbol& name) : DiagnosticBase(name.Location), Name(name) {}

    const NameSymbol Name;

    void WriteMessage(std::ostream& output) const override
    {
        output << "Scope of name \'" << Name << "\' is not a valid type."; 
    }
};

struct PropertyNameAlreadyExistsDiagnostic : public DiagnosticBase
{
    PropertyNameAlreadyExistsDiagnostic(const LocationInfo& location, const std::string& name) : 
        DiagnosticBase(location), Name(name) {}

    const std::string Name;

    void WriteMessage(std::ostream& output) const override
    {
        output << "Property of name \'" << Name << "\' already exists."; 
    }
};