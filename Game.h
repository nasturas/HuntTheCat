#pragma once
#include "Locatie.h"

ref class Game {

public:
	Game();
	~Game();
	bool CreateOptionText(Locatie^ camera);
	void MakeTurn();
	void GameInit();
private:
	BigHouse^ myhouse;
	catHunter^ myCatHunter;
};
