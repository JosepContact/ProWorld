#include "ModuleConceptManager.h"
#include "App.h"

ModuleConceptManager::ModuleConceptManager(bool start_enabled) : Module(start_enabled)
{
}

ModuleConceptManager::~ModuleConceptManager()
{
}

bool ModuleConceptManager::Start()
{

	//-- Locations ----
	pugi::xml_document	location_file;
	pugi::xml_node		locations;

	locations = app->filesystem->LoadXML(DATA_LOCATION_XML_PATH, LOCATION, location_file);

	if (locations.empty() != false)
	{
		LOG("Locations.xml loaded correctly!\n");

		for (pugi::xml_node location = locations.child("Location"); location; location = location.next_sibling("Location"))
		{
		}
	}

	return true;
}

bool ModuleConceptManager::CleanUp()
{
	return true;
}
