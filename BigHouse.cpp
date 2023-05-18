#include "pch.h"
#include "BigHouse.h"

BigHouse::BigHouse(String^ camName) : Name(camName), isCatHere(false)
{
	locatii = gcnew List<Locatie^>();
	houseCat = gcnew Cat("Felix");
}

BigHouse::~BigHouse()
{
	delete locatii;
}

String^ BigHouse::GetBigHouseName()
{
	return Name;
}

void BigHouse::AdaugaCamera(Locatie^ camera)
{
	locatii->Add(camera);
}

void BigHouse::AdaugaLegatura(Locatie^ sursa, Locatie^ destinatie)
{
	sursa->AdaugaVecin(destinatie);
	destinatie->AdaugaVecin(sursa);
}

void BigHouse::AscundePisica()
{
	theCatIsHere = houseCat->Ascund(locatii);
}

bool BigHouse::isCatFound(ClasaDeBaza^ locArg)
{
	return locArg == theCatIsHere;
}

List<Locatie^>^ BigHouse::GetListRooms()
{
	return locatii;
}

String^ BigHouse::GetHouseCatName()
{
	return houseCat->GetName();
}




