#pragma once

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "ModuleFileSystem.h"
#include "ModuleConceptManager.h"
#include "ModuleWorld.h"
#include "ModuleNameGenerator.h"

// ----------

#include <list>

// ---------

#define LOG(format, ...) app->mylog(__FILE__, __LINE__, format, __VA_ARGS__);

// ---------

class App
{
public:
	App();
	virtual ~App();

	bool Start();
	update_status Update();
	bool CleanUp();

	void SaveWorld();
	void LoadWorld();
	
	void QuitApp();

public:
	ModuleFileSystem* filesystem;
	ModuleConceptManager* conceptmanager;
	ModuleWorld* world;
	ModuleNameGenerator* namegenerator;
	

private:
	std::list<Module*> listmodules;

public:
	void mylog(const char file[], int line, const char* format, ...);
};

extern App* app;

#endif //WORLD_H_