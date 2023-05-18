#pragma once

using namespace System;

ref class ClasaDeBaza
{
public:
    ClasaDeBaza(String^ name, String^prepozitieArg);
    ~ClasaDeBaza();
    String^ GetName();
    String^ GetPrepozitie();

private:
    String^ name;
    String^ prepozitie;

};
