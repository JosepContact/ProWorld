#ifndef MODULESTORY_H
#define MODULEGSTORY_H

#include "Module.h"
#include "EventManager.h"


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

};

#endif //MODUESTORY_H
