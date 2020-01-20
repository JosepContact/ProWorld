#pragma once


#ifndef __MODULEWORLD_H__
#define __MODULEWORLD_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Climate.h"
#include "Geography.h"
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
	void SetClimate();
	void SetSky();
	void SetGeography();

private:
	// WORLD
	std::string wname;
	WorldType wtype;

	// WORLD ATTRIBUTES
	std::array<std::array<Concept*, 2>, 3> woverview;
	Climate* wclimate = nullptr;
	Sky* wsky = nullptr;
	Geography* wgeography = nullptr;

private:
	//OTHER TOOLS
	//bool set_climate = false;
};

#endif // __MODULEWORLD_H__