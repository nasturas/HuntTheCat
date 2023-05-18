#pragma once

using namespace System;

ref class catHunter: Actor
{
public:
    catHunter(String^ name);
    ~catHunter();

    void ChangeLocation(int NewVecinIdxArg);
    Locatie^ GetLocation();
    ClasaDeBaza^ Ascund(List<Locatie^>^ Camere) override;
private:
    Locatie^ undeMaAflu;
};


