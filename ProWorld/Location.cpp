#include "Location.h"
#include "Concept.h"

#include <string>

using namespace std;

Location::Location() : Concept()
{
	type = Concept::Location;
}

Location::Location(std::string argword, std::string argplural, ConceptType argtype) : Concept(word, plural, type)
{
	word = argword;
	plural = argplural;
	type = argtype;
}

Location::~Location()
{

}

void Location::AddAdjective(int n)
{
	adjectives.push_back(n);
}

vector<int> Location::GetAdjectives() const
{
	return adjectives;
}

void Location::SetIsCoastal(bool set)
{
	isCoastal = set;
}

bool Location::GetIsCoastal() const
{
	return isCoastal;
}

void Location::SetInSea(bool set)
{
	inSea = set;
}

bool Location::GetInSea() const
{
	return inSea;
}

void Location::SetSituation(Geography::CardinalPoints sit)
{
	situation = sit;
}

Geography::CardinalPoints Location::GetSituation() const
{
	return situation;
}

void Location::SetName(std::string argname)
{
	word = argname;
}

std::string Location::GetName() const
{
	return name;
}

vector<Climate::ClimatesType> Location::GetClimates()
{
	return climates;
}

void Location::AddClimate(Climate::ClimatesType climate)
{
	climates.push_back(climate);
}

bool Location::CompareClimate(Climate::ClimatesType climate)
{
	for (vector<Climate::ClimatesType>::iterator it = climates.begin(); it != climates.end(); it++)
		if (climate == (*it)) return true;

	return false;
}

bool Location::SpawnInSea(Geography::LandType spawnable)
{
	switch (spawnable)
	{
		case Geography::LandType::Land:
			return (inSea == false);
			break;
		case Geography::LandType::Water:
			return (inSea == true);
			break;
		default:
			break;
	}
	return false;
}
