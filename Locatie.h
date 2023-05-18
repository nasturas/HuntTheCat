#pragma once
#include "ClasaDeBaza.h"
using namespace System::Collections::Generic;
using namespace System;


ref class Locatie: ClasaDeBaza
{
public: 
	Locatie(String^ Name, String^Lprepozitie);
	~Locatie();
	void AdaugaVecin(Locatie^ vecin);
	int MobilierCount();
	ClasaDeBaza^ GetMobilierIdx(int x);
	void AddMobilier(ClasaDeBaza^ mobil);
	int NumarVecini();
	String^ GetVeciniNameIdx(int x);
	Locatie^ GetVecinIdx(int x);
private:
	List<Locatie^>^ Vecini;
	List<ClasaDeBaza^>^ mobilier;
};
