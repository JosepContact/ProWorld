#pragma once

#ifndef MODULENARRATION_H
#define MODULENARRATION_H

#include "Module.h"

class ModuleNarration : public Module
{
public:
	ModuleNarration(bool start_enabled = true);

	virtual ~ModuleNarration();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	virtual update_status Update();
};

#endif // !MODULENARRATION_H
