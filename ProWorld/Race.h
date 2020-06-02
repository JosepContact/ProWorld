#pragma once

#ifndef RACE_H
#define RACE_H

#include <vector>
#include "Climate.h"

class Race  : public Concept
{
public:

	enum SizeType
	{
		VerySmall,
		Small,
		Normal,
		Large,
		VeryLarge
	};

	Race();
	Race(std::string argword, std::string argplural, ConceptType argtype);
	~Race();

	

private:
	std::vector<Climate::ClimatesType> climates;

	bool isCoastal;
	bool inSea;
	SizeType size;
	std::string str_size;
	std::vector<int> vector_archetypes;

public:

	bool GetIsCoastal() const;
	void SetIsCoastal(bool);

	bool GetInSea() const;
	void SetInSea(bool);

	void SetSize(SizeType);
	SizeType GetSizeType() const;

	std::string GetStrSize() const;

	std::vector<Climate::ClimatesType> GetClimates();
	void AddClimate(Climate::ClimatesType climate);

	bool CompareClimate(Climate::ClimatesType climate);

	void AddArchetype(int arch);
	std::vector<int> GetArchetypes() const;
};

#endif // !RACE_H

