#include "ModuleStory.h"
#include "EventManager.h"
#include "Globals.h"
#include "App.h"
#include "Event.h"
#include "HelperFunctions.h"

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
	Event* curr_event = nullptr;
	int seek_event = 0;

	vector<Event*> all_events = e_manager->GetAllEvents();
	vector<Event*> events_seeked;
	vector<Event*> events_prio;
	vector<Event*> events_nextlayer;

	//ACT 1

	curr_act++;

	for (std::vector<Event*>::iterator it = all_events.begin(); it != all_events.end(); ++it)
	{		
		if ((*it)->id == seek_event && (*it)->ValidEvent(app->world->wcharacters) == true && (*it)->curr_type == Event::JourneyAct::OrdinaryWorld)
		{
			events_seeked.push_back((*it));
		}
	} // Starts

	//Choose One Of The Events
	curr_event = ChooseEvent(events_seeked);
	SeekEvent(curr_event);
	int a = 3;
}




Event * ModuleStory::SeekEvent(Event * ev)
{
	Event* ret = nullptr;
	vector<Event*> all_events = e_manager->GetAllEvents();
	vector<Event*> events_seeked;
	vector<Event*> events_prio;
	vector<Event*> events_nextlayer;

	for (auto it = all_events.begin(); it != all_events.end(); ++it)
	{
		if (ev->seek == (*it)->id && (*it)->ValidEvent(app->world->wcharacters) == true && (*it)->curr_type == ev->curr_type)
			events_seeked.push_back((*it));
	}

	if (!events_seeked.empty())
	{
		ret = ChooseEvent(events_seeked);
		ret = SeekEvent(ret);
		return ret;
	}

	for (auto it = all_events.begin(); it != all_events.end(); ++it)
	{
		if (ev->priority == (*it)->id && (*it)->ValidEvent(app->world->wcharacters) == true && (*it)->curr_type == ev->curr_type)
			events_prio.push_back((*it));
	}

	if (!events_prio.empty())
	{
		ret = ChooseEvent(events_prio);
		ret = SeekEvent(ret);
		return ret;
	}

	int curr_layer = ev->curr_type;
	curr_layer++;

	for (auto it = all_events.begin(); it != all_events.end(); ++it)
	{
		if (curr_layer == (*it)->curr_type && (*it)->ValidEvent(app->world->wcharacters) == true && (*it)->id == 0)
		{
			events_nextlayer.push_back((*it));
		}
	}

	if (!events_nextlayer.empty())
	{
		ret = ChooseEvent(events_nextlayer);
		ret = SeekEvent(ret);
		return ret;
	}

	return ret;
}

Event* ModuleStory::ChooseEvent(std::vector<Event*> vect_ev)
{
	Event* ret = vect_ev[GetRandomNumber(0, vect_ev.size() - 1)];
	story_queue.push_back(ret);

	if (ret->arc != 0 && type == 0)
		type = static_cast<ModuleStory::StoryType>(ret->arc);

	return ret;
}

EventManager * ModuleStory::GetManager() const
{
	return e_manager;
}

std::vector<Event*> ModuleStory::GetStory()
{
	return story_queue;
}
