#include "pch.h"
#include "Locatie.h"

Locatie::Locatie(String^ LName, String^ Lprepozitie): ClasaDeBaza(LName,Lprepozitie)
{
	Vecini = gcnew List<Locatie^>();
	mobilier = gcnew List<ClasaDeBaza^>();
}

Locatie::~Locatie()
{
	delete Vecini;
	delete mobilier;
}

void Locatie::AdaugaVecin(Locatie^ vecin)
{
	Vecini->Add(vecin);
}

int Locatie::MobilierCount()
{
	return mobilier->Count;
}

ClasaDeBaza^ Locatie::GetMobilierIdx(int x)
{
	return mobilier[x];
}

void Locatie::AddMobilier(ClasaDeBaza^ mobil)
{
	mobilier->Add(mobil);
}

int Locatie::NumarVecini()
{
	return Vecini->Count;
}

String^ Locatie::GetVeciniNameIdx(int x)
{
	if (x < Vecini->Count)
	{
		return Vecini[x]->GetName();
	}
	else
	{
		throw gcnew IndexOutOfRangeException("Index is too great!");
	}
}

Locatie^ Locatie::GetVecinIdx(int x)
{
	if (x < Vecini->Count)
	{
		return Vecini[x];
	}
	else
	{
		throw gcnew IndexOutOfRangeException("Index is too great!");
	}
}
