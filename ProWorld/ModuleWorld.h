#pragma once


#ifndef __MODULEWORLD_H__
#define __MODULEWORLD_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Concept.h"
#include "Climate.h"
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
};

#endif // __MODULEWORLD_H__