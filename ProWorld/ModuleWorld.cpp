#include "ModuleWorld.h"
#include "App.h"

ModuleWorld::ModuleWorld(bool start_enabled) : Module(start_enabled)
{
}

ModuleWorld::~ModuleWorld()
{
}

bool ModuleWorld::Start()
{
	return true;
}

bool ModuleWorld::CleanUp()
{
	return true;
}
