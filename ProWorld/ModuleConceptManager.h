#pragma once


#ifndef __MODULECONCEPTMANAGER_H__
#define __MODULECONCEPTMANAGER_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Concept.h"
#include "Location.h"
#include "Adjective.h"
#include "Race.h"
#include "Climate.h"

//------------------

#include<vector>
#include<list>

//------------------

#define LOCATION "Locations"
#define ADJECTIVE "Adjectives"
#define CLIMATE "Climates"
#define RACE "Races"
#define EVENT "Events"
#define WORDPOOL "Words"

class ModuleConceptManager : public Module
{
public:

	ModuleConceptManager(bool start_enabled = true);

	// Destructor
	virtual ~ModuleConceptManager();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

private:

	Concept* CreateConcept(std::string word, std::string plural, Concept::ConceptType type, int id);


private:

	std::list<Concept*> concept_list;

	std::vector<Location*> location_vector;
	std::vector<Adjective*> adjective_vector;
	std::vector<Climate*> climate_vector;
	std::vector<Race*> race_vector;
	
	unsigned int curr_id = 0;
public:

	std::vector<Location*> GetLocationVector()const;
	std::vector<Adjective*> GetAdjectiveVector()const;
	std::vector<Climate*> GetClimateVector()const;
	std::vector<Race*> GetRaceVector()const;

	std::vector<Adjective*> GetAdjectivesByKey(int key);
	Location* GetLocationByName(std::string);

	std::vector<Race*> GetRacesVectorByClimate();
	std::vector<Adjective*> GetAdjectivesByPriority(std::vector<Adjective*>);

private:
	std::vector<Adjective*> GetAdjectivesToIterateByPriority(std::vector<Adjective*>, int key);
};

#endif // __MODULECONCEPTMANAGER_H__