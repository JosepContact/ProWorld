#pragma once

#ifndef __MODULEFILESYSTEM_H__
#define __MODULEFILESYSTEM_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"


class ModuleFileSystem : public Module
{
public:

	ModuleFileSystem(bool start_enabled = true);

	// Destructor
	virtual ~ModuleFileSystem();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	unsigned int Load(const char* path, char** bufer);

	std::string CreateFolder(const char* path, const char* folder_name);

private:
	
};

#endif // __FILESYSTEM_H__
