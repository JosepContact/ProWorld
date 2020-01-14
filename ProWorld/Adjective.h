#pragma once

#ifndef __ADJECTIVE_H__
#define __ADJECTIVE_H__

#include "Concept.h"

class Adjective : public Concept {

public:
	Adjective();
	Adjective(std::string argname, ConceptType argtype );
	~Adjective();

private:

	int assigned_nouns;
	bool to_plural;

public:
	int GetNounsKey() const;
	bool GetToPlural() const;
	void SetAssignedNouns(int n);
	void SetToPlural(bool toplural);

};


#endif //ADJECTIVE_H