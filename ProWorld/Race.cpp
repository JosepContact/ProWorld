#include "Race.h"

using namespace std;

Race::Race()
{
}

Race::Race(std::string argword, std::string argplural, ConceptType argtype)
{
	word = argword;
	plural = argplural;
	type = argtype;
}

Race::~Race()
{
}

bool Race::GetIsCoastal() const
{
	return isCoastal;
}

void Race::SetIsCoastal(bool coast)
{
	isCoastal = coast;
}

bool Race::GetInSea() const
{
	return inSea;
}

void Race::SetInSea(bool sea)
{
	inSea = sea;
}

void Race::SetSize(SizeType s)
{
	size = s;
}

Race::SizeType Race::GetSizeType() const
{
	return size;
}

std::string Race::GetStrSize() const
{
	string ret;

	switch (size)
	{
	case VerySmall:
		ret = "very small";
		break;
	case Small:
		ret = "small";
		break;
	case Normal:
		ret = "normal";
		break;
	case Large:
		ret = "large";
		break;
	case VeryLarge:
		ret = "very large";
		break;
	}
	return ret;
}


vector<Climate::ClimatesType> Race::GetClimates()
{
	return climates;
}

void Race::AddClimate(Climate::ClimatesType climate)
{
	climates.push_back(climate);
}


bool Race::CompareClimate(Climate::ClimatesType climate)
{
	for (vector<Climate::ClimatesType>::iterator it = climates.begin(); it != climates.end(); it++)
		if (climate == (*it)) return true;

	return false;
}

void Race::AddArchetype(int arch)
{
	vector_archetypes.push_back(arch);
}

std::vector<int> Race::GetArchetypes() const
{
	return vector_archetypes;
}
