#include "App.h"

#include <windows.h>

using namespace std;

App::App()
{
	// ----- Create Modules ----
	filesystem = new ModuleFileSystem;
	conceptmanager = new ModuleConceptManager;
	namegenerator = new ModuleNameGenerator;
	world = new ModuleWorld;
	narration = new ModuleNarration;
	graphics = new ModuleGraphics;

	// ----- Add Modules to World ---
	listmodules.push_back(filesystem);
	listmodules.push_back(conceptmanager);
	listmodules.push_back(namegenerator);
	listmodules.push_back(world);
	listmodules.push_back(narration);
	listmodules.push_back(graphics);
}


App::~App()
{
	for (list<Module*>::reverse_iterator rit = listmodules.rbegin(); rit != listmodules.rend(); ++rit)
	{
		if ((*rit) != nullptr)
			RELEASE(*rit);
	}

	listmodules.clear();
}

bool App::Start()
{
	bool ret = true;
	for (list<Module*>::iterator it = listmodules.begin(); it != listmodules.end(); ++it) {
		if ((*it) != nullptr && ret == true) {
			ret = (*it)->Start();
		}
	}
	return ret;
}

update_status App::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (list<Module*>::iterator it = listmodules.begin(); it != listmodules.end(); ++it) {
		if ((*it) != nullptr && ret == true) {
			ret = (*it)->Update();
		}
	}

	return ret;
}

bool App::CleanUp()
{
	bool ret = true;
	for (list<Module*>::iterator it = listmodules.begin(); it != listmodules.end(); ++it) {
		if ((*it) != nullptr && ret == true) {
			ret = (*it)->CleanUp();
		}
	}
	return ret;
}


void App::SaveWorld()
{
}

void App::LoadWorld()
{
}

void App::QuitApp()
{

}

void App::mylog(const char file[], int line, const char * format, ...)
{
	static char tmp_string[4096];
	static va_list  ap;

	// Construct the string from variable arguments
	va_start(ap, format);
	vsprintf_s(tmp_string, 4096, format, ap);
	va_end(ap);
	OutputDebugString(tmp_string);
}
