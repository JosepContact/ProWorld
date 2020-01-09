#include "World.h"

using namespace std;

World::World()
{
	// ----- Create Modules ----
	ModuleFileSystem* filesystem = new ModuleFileSystem;

	// ----- Add Modules to World ---
	listmodules.push_back(filesystem);

}


World::~World()
{
	for (list<Module*>::reverse_iterator rit = listmodules.rbegin(); rit != listmodules.rend(); ++rit)
	{
		if ((*rit) != nullptr)
			RELEASE(*rit);
	}

	listmodules.clear();
}

bool World::Start()
{
	bool ret = true;
	for (list<Module*>::iterator it = listmodules.begin(); it != listmodules.end(); ++it) {
		if ((*it) != nullptr && ret == true) {
			ret = (*it)->Start();
		}
	}
	return ret;
}

bool World::CleanUp()
{
	bool ret = true;
	for (list<Module*>::iterator it = listmodules.begin(); it != listmodules.end(); ++it) {
		if ((*it) != nullptr && ret == true) {
			ret = (*it)->CleanUp();
		}
	}
	return ret;
}


void World::SaveWorld()
{
}

void World::LoadWorld()
{
}
