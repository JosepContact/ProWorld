#pragma once


#ifndef __MODULECONCEPTMANAGER_H__
#define __MODULECONCEPTMANAGER_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Concept.h"

//------------------

#include<vector>
#include<list>

//------------------

#define LOCATION "Locations"

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

	Concept* CreateConcept(std::string word, std::string plural, Concept::ConceptType type);


private:

	std::list<Concept*> concept_list;

	std::vector<Concept*> location_vector;
	
	unsigned int curr_id = 0;

};

#endif // __MODULECONCEPTMANAGER_H__