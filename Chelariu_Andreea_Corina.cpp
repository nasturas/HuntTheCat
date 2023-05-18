#include "pch.h"


using namespace System;

int main(array<System::String ^> ^args)
{
    Game^ fg = gcnew Game();

    fg->GameInit();
    fg->MakeTurn();

    Console::WriteLine("Bravo! Pa!");
    return 0;
}
