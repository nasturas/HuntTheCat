#include "pch.h"

Actor::Actor(String^ nameArg)
{
	name = nameArg;
}

Actor::~Actor()
{
	delete name;
}

String^ Actor::GetName()
{
	return name;
}
