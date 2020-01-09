#pragma once

#ifndef __WORLD_H__
#define __WORLD_H__

#include "ModuleFileSystem.h"
#include <list>

class World
{
public:
	World();
	virtual ~World();

	bool Start();
	bool CleanUp();

	void SaveWorld();
	void LoadWorld();

public:
	ModuleFileSystem* filesystem;

private:
	std::list<Module*> listmodules;
};

#endif //WORLD_H_