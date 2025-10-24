#pragma once

#include <cstddef>

class Label
{
public:
    Label()
    {
        _id = _nextId++;
    }

    size_t GetId() const { return _id; }
private:
    inline static size_t _nextId = 0;

    size_t _id;
};