#include "ModuleStory.h"
#include "EventManager.h"

ModuleStory::ModuleStory(bool start_enabled) : Module(start_enabled)
{
	e_manager = new EventManager();
}

ModuleStory::~ModuleStory()
{
	RELEASE(e_manager);
}

bool ModuleStory::Start()
{
	return false;
}

bool ModuleStory::CleanUp()
{
	return false;
}

update_status ModuleStory::Update()
{
	return update_status();
}
