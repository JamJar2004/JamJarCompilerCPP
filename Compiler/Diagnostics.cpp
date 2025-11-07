#include "Diagnostics.hpp"

std::ostream& operator<<(std::ostream& target, const DiagnosticBase& diagnostic)
{
    diagnostic.WriteMessage(target);
    target << " { File: " << diagnostic.Location.FileName << ", Line: " << diagnostic.Location.Line << ", Column: " << diagnostic.Location.Column << " }";
    return target;
}