#pragma once

#include <string>
#include "Globals.h"

#ifndef __MODULE_H__
#define __MODULE_H__

class World;

class Module
{
private:
	bool enabled;
protected:

public:
	std::string name = "Module";

	Module(bool start_enabled = true) {}

	virtual ~Module() {}

	virtual bool Start()
	{
		return true;
	}

	virtual bool CleanUp() 
	{
		return true;
	}

	virtual update_status Update() 
	{
		return UPDATE_CONTINUE;
	}

};

#endif //_MODULE_H_