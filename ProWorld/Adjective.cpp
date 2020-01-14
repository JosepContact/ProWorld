#include "Adjective.h"

Adjective::Adjective()
{
}

Adjective::Adjective(std::string argname, ConceptType argtype)
{
	word = argname;
	type = argtype;
}

Adjective::~Adjective()
{
}

void Adjective::SetAssignedNouns(int n)
{
	assigned_nouns = n;
}

void Adjective::SetToPlural(bool toplural)
{
	to_plural = toplural;
}
