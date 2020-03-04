#include "Society.h"
#include "ModuleNameGenerator.h"
#include "App.h"

using namespace std;

Society::Society()
{
	name = app->namegenerator->GenerateClassicName();
	is_asian_based = false;
	is_tribal = false;
}

Society::~Society()
{
}

void Society::SetName(std::string n)
{
	name = n;
}

std::string Society::GetName() const
{
	return name;
}

std::vector<Race*> Society::GetRaces() const
{
	return races;
}

void Society::SetScale(Scale s)
{
	scale = s;
}

Society::Scale Society::GetScale() const
{
	return scale;
}

/*
void Society::SetIsCoastal(bool c)
{
	isCoastal = c;
}

bool Society::GetIsCoastal() const
{
	return isCoastal;
}

void Society::SetInSea(bool s)
{
	inSea = s;
}

bool Society::GetInSea() const
{
	return inSea;
}
*/

void Society::AddRace(Race * r)
{
	races.push_back(r);
}


Location * Society::GetLocationPtr() const
{
	return location;
}

bool Society::AssignLocationPtr(Location * l)
{
	bool ret = false;

	if (l != nullptr)
		location = l;

	ret = true;

	return ret;
}
