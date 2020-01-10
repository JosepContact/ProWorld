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

#define LOCATION "Location"

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

	void CreateConcept(std::string word, std::string plural, Concept::ConceptType type);


private:

	std::list<Concept*> concept_list;

	std::vector<Concept*> location_vector;
	


};

#endif // __MODULECONCEPTMANAGER_H__