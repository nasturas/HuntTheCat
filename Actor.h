#pragma once

#include "ClasaDeBaza.h"
#include "Locatie.h"
using namespace System;
using namespace System::Collections::Generic;

ref class Actor abstract
{
public:
	Actor(String^nameArg);
	~Actor();
	virtual ClasaDeBaza^ Ascund(List<Locatie^>^ Camere)=0;
	String^ GetName();
private:
	String^ name;
};
