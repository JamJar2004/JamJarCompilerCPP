#pragma once

#include <stdint.h>
#include <stddef.h>
#include <string>

struct LocationInfo
{
    LocationInfo(size_t index, size_t line, size_t column, const std::string& fileName) :
        Index(index), Line(line), Column(column), FileName(fileName) {} 

    size_t Index;
    size_t Line;
    size_t Column;
    
    std::string FileName;
};