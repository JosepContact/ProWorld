#include "World.h"


World::World()
{
	// ----- Create Modules ----
	ModuleFileSystem* filesystem = new ModuleFileSystem;

	// ----- Add Modules to World ---
	listmodules.push_back(filesystem);

}


World::~World()
{
	for (std::list<Module*>::reverse_iterator rit = listmodules.rbegin(); rit != listmodules.rend(); ++rit)
	{
		if ((*rit) != nullptr)
			RELEASE(*rit);
	}

	listmodules.clear();
}

bool World::Start()
{
	return false;
}

bool World::CleanUp()
{
	return false;
}


void World::SaveWorld()
{
}

void World::LoadWorld()
{
}
