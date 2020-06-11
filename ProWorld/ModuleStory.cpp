#include "ModuleStory.h"
#include "EventManager.h"
#include "Globals.h"
#include "App.h"
#include "Event.h"

using namespace std;

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

void ModuleStory::CreateStory()
{
	int curr_act = 0;
	//ACT 1

	curr_act++;

	vector<Event*> all_events = e_manager->GetAllEvents();

	for (std::vector<Event*>::iterator it = all_events.begin(); it != all_events.end(); ++it)
	{
		if ((*it)->ValidEvent(app->world->wcharacters) == true)
		{
			story_queue.push_back(*it);
		}
	}


	//ACT 2

	//ACT3



}

EventManager * ModuleStory::GetManager() const
{
	return e_manager;
}

std::vector<Event*> ModuleStory::GetStory()
{
	return story_queue;
}
