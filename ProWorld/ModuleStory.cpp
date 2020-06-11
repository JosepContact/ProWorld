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
	return true;
}

bool ModuleStory::CleanUp()
{
	return true;
}

update_status ModuleStory::Update()
{
	return UPDATE_CONTINUE;
}

EventManager * ModuleStory::GetManager() const
{
	return e_manager;
}
