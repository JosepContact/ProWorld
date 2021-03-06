#pragma once


#ifndef __MODULEWORLD_H__
#define __MODULEWORLD_H__

#define N_LOCATIONS 25
#define MAX_LOCATIONS_PER_CELL 7

#define MAX_CHARACTERS 5
#define MIN_CHARACTERS 3

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Climate.h"
#include "Geography.h"
#include "Sky.h"
#include "Society.h"
#include "Character.h"
#include <array>
#include <string>
#include <vector>

class ModuleWorld : public Module
{
public:
	enum WorldType {
		European,
		Xinese,
		Japanese,
		African
	};

	ModuleWorld(bool start_enabled = true);

	// Destructor
	virtual ~ModuleWorld();


	bool Start();

	// Called before quitting
	bool CleanUp();

	virtual update_status Update();

public:
	void StartWorld();
	void DeleteWorld();
private:
	WorldType GenerateWorldType();
	void SetClimate();
	void SetSky();
	void SetGeography();
	void CreateMap();
	void CreateCharacters();
	void SetSociety(Society* soc, Geography::CellLand &cell);
public:
	// WORLD
	std::string wname;
	WorldType wtype;

	// WORLD ATTRIBUTES
	std::array<std::array<Concept*, 2>, 3> woverview;
	
	Sky* wsky = nullptr;
	Geography* wgeography = nullptr;

	std::vector<Geography::CellLand> geoVector;

	std::vector<Society*> wsocieties;
	std::vector<Character*> wcharacters;

public:
	Climate* GetClimate() const;

private:
	Climate* wclimate = nullptr; // this pointer points at climate, it's not created and must not be destroyed

public:
	Character* GetHero() const;
	Character* GetVillain() const;
	std::vector<Character*> GetSecondaries() const;
	std::vector<Character*> GetSecondaryVillains() const;
	std::vector<Character*> GetThirdVillains() const;
	std::vector<std::string> GetCharacterAdjectives(Character*);
	std::string GetCharacterRace(Character*) const;
	std::string GetCharacterName(Character*) const;
	std::string GetCharacterOriginType(Character*) const;
	std::string GetCharacterOriginName(Character*) const;
	std::string GetCharacterPronoun(Character*) const;
	std::string GetCharacterReflectivePronoun(Character*) const;
	std::string GetCharacterPosessivePronoun(Character*) const;
	std::string GetRandomLocation(Character*) const; //Char's origin is excluded

};

#endif // __MODULEWORLD_H__