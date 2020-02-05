#pragma once
#ifndef __LOCATION_H__
#define __LOCATION_H__

#include "Concept.h"
#include "Climate.h"
#include<vector>

class Location : public Concept {
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

public:
	Location();
	Location(std::string argword, std::string argplural, ConceptType argtype, LocationType arglocation);
	~Location();

public:

	std::vector<Climate::ClimatesType> climates;


private:
	std::vector<int> adjectives;
	bool isCoastal;
	bool inSea;
	//Geography::CardinalPoints situation;
	LocationType locationType;

public:

	void AddAdjective(int n);
	std::vector<int> GetAdjectives() const;

	void SetIsCoastal(bool set);
	bool GetIsCoastal() const;

	void SetInSea(bool set);
	bool GetInSea() const;

	//void SetSituation(Geography::CardinalPoints sit);
	//Geography::CardinalPoints GetSituation() const;

	std::vector<Climate::ClimatesType> GetClimates();
	void AddClimate(Climate::ClimatesType climate);

	bool CompareClimate(Climate::ClimatesType climate);
	bool SpawnInSea(int);

	void SetLocationType(LocationType loctype);
	LocationType GetLocationType() const;
};

#endif