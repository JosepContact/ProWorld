#pragma once

#ifndef __APP_H__
#define __APP_H__

#include "ModuleFileSystem.h"
#include "ModuleConceptManager.h"
#include "ModuleWorld.h"
#include "ModuleNameGenerator.h"
#include "ModuleNarration.h"
#include "ModuleGraphics.h"
#include "ModuleStory.h"

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
	ModuleNameGenerator* namegenerator;
	ModuleWorld* world;
	ModuleNarration* narration;
	ModuleGraphics* graphics;
	ModuleStory* story;

	bool quit;
private:
	std::list<Module*> listmodules;

public:
	void mylog(const char file[], int line, const char* format, ...);
};

extern App* app;

#endif //WORLD_H_