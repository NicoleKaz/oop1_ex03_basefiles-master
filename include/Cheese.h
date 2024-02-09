#pragma once

#include "GameObject.h"

class Cheese : public GameObject
{
public:
    Cheese();
    virtual void init() override;
};