#pragma once


#ifndef __MODULEWORLD_H__
#define __MODULEWORLD_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Concept.h"
#include "Sky.h"
#include <array>

class ModuleWorld : public Module
{
public:
	enum WorldType {
		European,
		Xinese,
		Japanese,
		African
	};

	enum Climates
	{
		Tropical, //HOT 0
		Arid, //HOT 1
		Continental,  //REGULAR 2
		Polar  //COLD 3
	};

	ModuleWorld(bool start_enabled = true);

	// Destructor
	virtual ~ModuleWorld();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	virtual update_status Update();

private:
	void StartWorld();
	WorldType GenerateWorldType();
	void SetWorldOverview();
	void SetSky();

private:
	bool isUnderground = false;
	std::string world_name;
	WorldType world_type;
	std::array<std::array<Concept*, 2>, 3> world_overview;

	Sky* sky;
	Climates world_climate;
};

#endif // __MODULEWORLD_H__