#pragma once

#ifndef RACE_H
#define RACE_H

#include "Concept.h"
#include <vector>
#include "Geography.h"

class Race  : public Concept
{
public:

	Race();
	Race(std::string argword, std::string argplural, ConceptType argtype);
	~Race();

	std::vector<Climate::ClimatesType> climates;

private:
	bool isCoastal;
	bool inSea;
	int size;
	std::string str_size;

public:

	bool GetIsCoastal() const;
	void SetIsCoastal(bool);

	bool GetInSea() const;
	void SetInSea(bool);

	void SetSize(int);
	void SetSize(std::string);

	std::string GetStrSize() const;
};

#endif // !RACE_H

