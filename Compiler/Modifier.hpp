#pragma once

class LinkedScopeBase;

struct ModifierBase
{
    virtual bool IsVisible(const LinkedScopeBase& source, LinkedScopeBase& current) = 0;
};

struct PrivateModifier : public ModifierBase
{
    bool IsVisible(const LinkedScopeBase& source, LinkedScopeBase& current) { return &current == &source; }
};

struct PublicModifier : public ModifierBase
{
    bool IsVisible(const LinkedScopeBase& source, LinkedScopeBase& current) { return true; }
};