#include "pch.h"
#include "catHunter.h"
#include "stdlib.h"

catHunter::catHunter(String^ HName): Actor(HName)
{
	
}

catHunter::~catHunter()
{

}

void catHunter::ChangeLocation(int NewVecinIdxArg)
{
	undeMaAflu = undeMaAflu->GetVecinIdx(NewVecinIdxArg);
	
}

Locatie^ catHunter::GetLocation()
{
	return undeMaAflu;
}

ClasaDeBaza^ catHunter::Ascund(List<Locatie^>^ Camere)
{
	ClasaDeBaza^ myReturn;
	//reinitializam pe rand cu un alt seed. Dorim astfel ca pozitia catHunter sa fie random si fata de pisica
	srand(rand());
	int indexCamera = rand() % Camere->Count;
	undeMaAflu = Camere[indexCamera];
	myReturn = Camere[indexCamera];
	return myReturn;
}

