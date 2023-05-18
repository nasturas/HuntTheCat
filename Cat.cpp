#include "pch.h"
#include "Cat.h"
#include "ClasaDeBaza.h"
#include "stdlib.h"


Cat::Cat(String^ catName): Actor(catName)
{
	
}

Cat::~Cat()
{
	
}

ClasaDeBaza^ Cat::Ascund(List<Locatie^>^ Camere)
{
	ClasaDeBaza^ myReturn;
	/*aici fac algoritm de alegere random*/
	int indexCamera = rand() % Camere->Count;

	//decide daca se ascunde in camera sau intr-un obiect din camera
	//daca rand() % 2 da 0 pisica se ascunde in camera, altfel cauta sa se ascunda in obiect.
	if(rand() % 2) 
	{ 
		int indexObiect = rand() % Camere[indexCamera]->MobilierCount();
		myReturn = Camere[indexCamera]->GetMobilierIdx(indexObiect);
	}
	else
	{
		myReturn = Camere[indexCamera];
	}

	return myReturn;
}

