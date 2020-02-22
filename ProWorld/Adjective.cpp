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

int Adjective::GetNounsKey() const
{
	return assigned_nouns;
}

bool Adjective::GetToPlural() const
{
	return to_plural;
}

void Adjective::SetAssignedNouns(int n)
{
	assigned_nouns = n;
}

void Adjective::SetToPlural(bool toplural)
{
	to_plural = toplural;
}

void Adjective::SetPriority(int a)
{
	priority = a;
}

int Adjective::GetPriority() const
{
	return priority;
}
