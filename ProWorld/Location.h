#pragma once
#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "Concept.h"
#include "Geography.h"
#include "City.h"

#include<vector>

class Adjective;

class Location : public Concept {

public:
	Location();
	Location(std::string argword, std::string argplural, ConceptType argtype);
	~Location();

public:
	enum LocationType {
		tCity,
		tTown,
		tVillage,
		tPort,
		tTemple,
		tSanctuary,
		tManument,
		tMountain,
		tVolcano,
		tValley,
		tCave,
		tForest,
		tJungle,
		tPlain,
		tSwamp,
		tRiver,
		tLake,
		tBay,
		TIsland,
		tArchipielago,
		tIceberg,
		tPeninsula,
		tDesert,
		tOasis,
		tOcean,
		tReef
	};

	std::vector<Climate::ClimatesType> climates;


private:

	std::string name;
	std::vector<int> adjectives;
	bool isCoastal;
	bool inSea;
	Geography::CardinalPoints situation;
	City* city = nullptr;

public:

	void AddAdjective(int n);
	std::vector<int> GetAdjectives() const;

	void SetIsCoastal(bool set);
	bool GetIsCoastal() const;

	void SetInSea(bool set);
	bool GetInSea() const;

	void SetSituation(Geography::CardinalPoints sit);
	Geography::CardinalPoints GetSituation() const;

	void SetName(std::string);
	std::string GetName() const;

	std::vector<Climate::ClimatesType> GetClimates();
	void AddClimate(Climate::ClimatesType climate);

	bool CompareClimate(Climate::ClimatesType climate);
	bool SpawnInSea(Geography::LandType);

	
};

#endif