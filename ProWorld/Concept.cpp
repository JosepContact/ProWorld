#include "Concept.h"

using namespace std;


Concept::Concept()
{
	type = UnkownConcept;
}


Concept::~Concept()
{
}

void Concept::SetName(string name, string plural)
{
	this->word = name;
	this->plural = plural;
}

std::string Concept::GetString()
{
	return word;
}

const char * Concept::GetChar()
{
	return word.c_str();
}
