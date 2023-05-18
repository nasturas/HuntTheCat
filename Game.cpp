#include "pch.h"
#include "Game.h"
#include "stdlib.h"
#include <time.h>

using namespace System;

Game::Game()
{
	myCatHunter = gcnew catHunter("Jorjel");
}
Game::~Game()
{
}
bool Game::CreateOptionText(Locatie^ camera)
{
	/*Esti in X.Vezi un dulap, o lustra, un pat.Ce faci
		1. Mergi in camera y (pentru fiecare vecin)
		2. CAuti in dulap
		3. Cauti pe lustra
		4. Caut sub pat.
	*/
	int optiuneUtiliz = 1;
	bool myReturn = false;
	if (camera->MobilierCount())
	{
		Console::Write("Esti {1} {0}. Vezi", camera->GetName(), camera->GetPrepozitie());
		for (int i = 0; i < camera->MobilierCount(); i++)
		{
			Console::Write(" {0}", camera->GetMobilierIdx(i)->GetName());
			if (i == camera->MobilierCount() - 1)
			{
				Console::Write(".");
			}
			else
			{
				Console::Write(",");
			}

		}
		Console::Write(" Ce faci:\n");
	}
	else
	{
		Console::WriteLine("Esti in {0}. Ce faci:\n", camera->GetName());
		
	}
	//Tb sa stim cati vecini sunt. Pentru fiecare vecin vom pune o optiune. 
	int numarOpt = 1;
	for (int i = 0; i < camera->NumarVecini(); i++) 
	{
		Console::WriteLine("{0}. Mergi {2} {1}", numarOpt, camera->GetVeciniNameIdx(i), camera->GetPrepozitie());
		numarOpt++;
	}
	//Pentru fiecare mobilier din camera curenta vom pune o optiune de cautare.
	for (int i = 0; i < camera->MobilierCount(); i++)
	{
		Console::WriteLine("{0}. Cauta {2} {1}", numarOpt, camera->GetMobilierIdx(i)->GetName(), camera->GetMobilierIdx(i)->GetPrepozitie());
		numarOpt++;
	}
	//vrem sa avem numarul de optiuni asa ca scoatem ultima incrementare
	numarOpt--;

	bool validOption = false;
	while (!validOption) 
	{
		// citim de la tastatura optiunea utilizatorului. 
		String^ strOptiuneUtiliz = Console::ReadLine();

		try
		{
			// incercam sa convertim
			optiuneUtiliz = Convert::ToInt32(strOptiuneUtiliz);
			if (optiuneUtiliz <= numarOpt && optiuneUtiliz > 0)
			{
				validOption = true;
			}
			else
			{
				Console::WriteLine("Numarul introdus nu e corect. Alege un numar pozitiv mai mic sau egal cu {0}", numarOpt);
			}

		}
		catch (FormatException^)
		{
			Console::WriteLine("Nu ai introdus un numar");

		}
		catch (OverflowException^)
		{
			Console::WriteLine("Numarul introdus e prea mare. Alege un numar mai mic sau egal cu {0}", numarOpt);

		}

	}
	if (optiuneUtiliz <= camera->NumarVecini())
	{ 
		// a ales sa mearga
		myCatHunter->ChangeLocation(optiuneUtiliz-1);
		myReturn = myhouse->isCatFound(camera->GetVecinIdx(optiuneUtiliz-1));
	}
	else
	{
		//a ales sa caute
		int idx = optiuneUtiliz - camera->NumarVecini() - 1;
		myReturn = myhouse->isCatFound( camera->GetMobilierIdx(idx));
		if (!myReturn)
			Console::WriteLine("Nici o urma de pisic {1} {0}.", camera->GetMobilierIdx(idx)->GetName(), camera->GetMobilierIdx(idx)->GetPrepozitie());
	}

	

	return myReturn;
}

void Game::MakeTurn()
{
	bool gameFinish = false;
	while (!gameFinish)
	{
		gameFinish = CreateOptionText(myCatHunter->GetLocation());
	}
	Console::WriteLine("Felix e aici!");
}

void Game::GameInit()
{
	//initializam random 
	srand(time(0));
	myhouse = gcnew BigHouse("house");


	Locatie^ dormitor = gcnew Locatie("dormitor", "in");
	Locatie^ baie = gcnew Locatie("baie", "in");
	Locatie^ balcon = gcnew Locatie("balcon", "in");
	Locatie^ hol = gcnew Locatie("hol", "in");
	Locatie^ sufragerie = gcnew Locatie("sufragerie", "in");
	Locatie^ terasa = gcnew Locatie("terasa", "in");
	Locatie^ bucatarie = gcnew Locatie("bucatarie", "in");

	myhouse->AdaugaCamera(dormitor);
	myhouse->AdaugaCamera(baie);
	myhouse->AdaugaCamera(balcon);
	myhouse->AdaugaCamera(hol);
	myhouse->AdaugaCamera(sufragerie);
	myhouse->AdaugaCamera(terasa);
	myhouse->AdaugaCamera(bucatarie);
	

	myhouse->AdaugaLegatura(dormitor, baie);
	myhouse->AdaugaLegatura(dormitor, balcon);
	myhouse->AdaugaLegatura(dormitor, hol);
	myhouse->AdaugaLegatura(hol, sufragerie);
	myhouse->AdaugaLegatura(hol, bucatarie);
	myhouse->AdaugaLegatura(bucatarie, sufragerie);
	myhouse->AdaugaLegatura(terasa, sufragerie);


	//obiecte din baie
	ClasaDeBaza^ cadaB = gcnew ClasaDeBaza("cada", "in");
	baie->AddMobilier(cadaB);
	ClasaDeBaza^ usaB = gcnew ClasaDeBaza("usa", "dupa");
	baie->AddMobilier(usaB);

	//obiecte din dormitor
	ClasaDeBaza^ patD = gcnew ClasaDeBaza("pat", "sub");
	dormitor->AddMobilier(patD);
	ClasaDeBaza^ lustraD = gcnew ClasaDeBaza("lustra", "pe");
	dormitor->AddMobilier(lustraD);

	//obiecte din balcon
	ClasaDeBaza^ ghiveciFlori = gcnew ClasaDeBaza("ghiveci flori", "dupa");
	balcon->AddMobilier(ghiveciFlori);

	//obiecte din hol
	ClasaDeBaza^ cuierH = gcnew ClasaDeBaza("cuier", "pe");
	hol->AddMobilier(cuierH);

	//obiecte din sufragerie
	ClasaDeBaza^ canapeaS = gcnew ClasaDeBaza("canapea", "pe");
	sufragerie->AddMobilier(canapeaS);
	ClasaDeBaza^ lustraS = gcnew ClasaDeBaza("lustra", "pe");
	sufragerie->AddMobilier(lustraS);
	ClasaDeBaza^ biblosS = gcnew ClasaDeBaza("biblioteca", "printre cartile din ");
	sufragerie->AddMobilier(biblosS);

	//obiecte din bucatarie
	ClasaDeBaza^ frigider = gcnew ClasaDeBaza("frigider", "pe");
	bucatarie->AddMobilier(frigider);

	//obiecte din terasa
	ClasaDeBaza^ masaT = gcnew ClasaDeBaza("masa", "sub");
	terasa->AddMobilier(masaT);


	//acum pisica se poate ascunde
	myhouse->AscundePisica();
	//nu avem nevoie de valoare de return
	//acum alegem aleator o pozitie de inceput
	(void)myCatHunter->Ascund(myhouse->GetListRooms());

	//Prezentare joc
	Console::Write("Intr-o zi insorita de primavara, {0}, un barbat cu o inima plina de compasiune pentru animale, a primit o cerere neasteptata. Vecina lui, doamna Johannis, a avut o urgenta familiala si a fost nevoita sa plece din oras pentru câteva zile. Ea l-a rugat pe {0} sa aiba grija de pisica ei, {1}, in absenta ei.\n	{0} a acceptat cu bucurie responsabilitatea de a avea grija de {1}. Cu toate acestea, in curând a realizat ca pisioiul e neastâmparat.De fiecare data când incerca sa il gaseasca, {1} reusea sa se ascunda in cele mai ingenioase locuri.\nCu un zâmbet pe buze, {0} a inceput cautarea.\n", myCatHunter->GetName(), myhouse->GetHouseCatName());
}
