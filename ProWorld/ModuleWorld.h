#pragma once


#ifndef __MODULEWORLD_H__
#define __MODULEWORLD_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"


class ModuleWorld : public Module
{
public:

	ModuleWorld(bool start_enabled = true);

	// Destructor
	virtual ~ModuleWorld();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

private:

};

#endif // __FILESYSTEM_H__