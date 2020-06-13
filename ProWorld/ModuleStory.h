#ifndef MODULESTORY_H
#define MODULESTORY_H

#define MAXEVENTSPERACT 3

#include "Module.h"
#include <vector>

class EventManager;
class Event;

class ModuleStory : public Module {

public:
	ModuleStory(bool start_enabled = true);

	virtual ~ModuleStory();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	virtual update_status Update();

	void CreateStory();
	Event* SeekEvent(Event* ev);
	Event* ChooseEvent(std::vector<Event*> vect_ev);

private:
	EventManager* e_manager = nullptr;
	std::vector<Event*> story_queue;
public:
	EventManager* GetManager() const;
	std::vector<Event*> GetStory();
};

#endif //MODUESTORY_H
