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

void Race::SetSize(int s)
{
	size = s;
}

void Race::SetSize(std::string)
{
	// por hacer xD
}
