#pragma once
#include "Locatie.h"
#include "Actor.h"
using namespace System;

ref class Cat:Actor
{

public:
    Cat(String^ catName);
    ~Cat();
    ClasaDeBaza^ Ascund(List<Locatie^>^ Camere) override;
};

