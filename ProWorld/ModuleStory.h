#ifndef MODULESTORY_H
#define MODULESTORY_H

#include "Module.h"

class EventManager;


class ModuleStory : public Module {

public:
	ModuleStory(bool start_enabled = true);

	virtual ~ModuleStory();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	virtual update_status Update();

private:
	EventManager* e_manager = nullptr;

public:
	EventManager* GetManager() const;
};

#endif //MODUESTORY_H
