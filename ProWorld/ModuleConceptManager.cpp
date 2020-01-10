#include "ModuleConceptManager.h"
#include "Concept.h"
#include "Location.h"
#include "App.h"

using namespace std;

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
			CreateConcept(location.child("Name").attribute("value").as_string(), location.child("Plural").attribute("value").as_string(), 
				Concept::ConceptType::Location);
		}
	}

	return true;
}

bool ModuleConceptManager::CleanUp()
{
	for (list<Concept*>::iterator it = concept_list.begin(); it != concept_list.end(); it++)
		RELEASE((*it));

	return true;
}

void ModuleConceptManager::CreateConcept(std::string word, std::string plural, Concept::ConceptType type)
{
	Concept* concept = new Concept(word, plural, type);
	concept_list.push_back(concept);

	switch (type)
	{
	case Concept::ConceptType::Location:
		location_vector.push_back(concept);
		break;
	case Concept::ConceptType::UnkownConcept:
		LOG("ModuleConceptManager::CreateConcept() Received unknown type!\n");
		break;
	default:
		LOG("ModuleConceptManager::CreateConcept() Received unknown type!\n");
		break;
	}
}
