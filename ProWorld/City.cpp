#include "City.h"
#include "ModuleNameGenerator.h"
#include "App.h"

using namespace std;

City::City()
{
	name = app->namegenerator->GenerateClassicName();
}

City::~City()
{
}

void City::SetName(std::string n)
{
	name = n;
}

std::string City::GetName() const
{
	return name;
}

std::vector<Race*> City::GetRaces() const
{
	return races;
}

void City::SetScale(Scale s)
{
	scale = s;
}

City::Scale City::GetScale() const
{
	return scale;
}

void City::SetIsCoastal(bool c)
{
	isCoastal = c;
}

bool City::GetIsCoastal() const
{
	return isCoastal;
}

void City::SetInSea(bool s)
{
	inSea = s;
}

bool City::GetInSea() const
{
	return inSea;
}

void City::AddRace(Race * r)
{
	races.push_back(r);
}


Location * City::GetLocationPtr() const
{
	return location;
}

bool City::AssignLocationPtr(Location * l)
{
	bool ret = false;

	if (l != nullptr)
		location = l;

	ret = true;

	return ret;
}