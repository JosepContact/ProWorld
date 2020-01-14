#pragma once

#ifndef __ADJECTIVE_H__
#define __ADJECTIVE_H__

#include "Concept.h"

class Adjective : public Concept {

public:
	Adjective();
	~Adjective();

private:

	int assigned_nouns;
	int to_plural;

public:

};


#endif //ADJECTIVE_H