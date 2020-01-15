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

void Location::SetName(std::string argname)
{
	word = argname;
}
