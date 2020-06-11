#pragma once

#ifndef RACE_H
#define RACE_H

#include <vector>
#include "Climate.h"

class RaceAdjective;

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
	std::vector<RaceAdjective*> adjectives;

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

	std::vector<RaceAdjective*> GetAdjectives();
	void AddAdjective(RaceAdjective* adj);

	bool CompareClimate(Climate::ClimatesType climate);

	void AddArchetype(int arch);
	std::vector<int> GetArchetypes() const;
};

class RaceAdjective {
public:
	std::string Adjective;
	int id;
};

#endif // !RACE_H

