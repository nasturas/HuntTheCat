#pragma once
#include "Locatie.h"
#include "Cat.h"

using namespace System;
using namespace System::Collections::Generic;

ref class BigHouse
{
public:
	BigHouse(String^ camName);
	~BigHouse();
	String ^GetBigHouseName();
	void AdaugaCamera(Locatie^);
	void AdaugaLegatura(Locatie^ sursa, Locatie^ destinatie);
	void AscundePisica();
	bool isCatFound(ClasaDeBaza^ locArg);
	List<Locatie^>^ GetListRooms();
	String^ GetHouseCatName();
private:
	String^ Name;
	bool isCatHere;
	List<Locatie^>^ locatii;
	ClasaDeBaza^ theCatIsHere;
	Cat^ houseCat;
	Locatie^ theHunterIsHere;
};




