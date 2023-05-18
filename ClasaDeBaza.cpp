#include "pch.h"
#include "ClasaDeBaza.h"

ClasaDeBaza::ClasaDeBaza(String^ CName, String^prepozitieArg)
{
	name = CName;
	prepozitie = prepozitieArg;
}


ClasaDeBaza::~ClasaDeBaza()
{

}

String^ ClasaDeBaza::GetName()
{
	return name;
}

String^ ClasaDeBaza::GetPrepozitie()
{
	return prepozitie;
}
