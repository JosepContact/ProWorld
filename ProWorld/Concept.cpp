#include "Concept.h"

Concept::Concept()
{
	type = UnkownConcept;
}


Concept::~Concept()
{
}

void Concept::SetName(std::string name, std::string plural)
{
	this->word = name;
	this->plural = plural;
}
