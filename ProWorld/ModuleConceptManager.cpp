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

	if (locations.empty() == false)
	{
		LOG("Locations.xml loaded correctly!\n");

		for (pugi::xml_node location = locations.child("Location"); location; location = location.next_sibling("Location"))
		{
			location = location.child("Info");
			Location* concept = (Location*)CreateConcept(location.child("Name").attribute("value").as_string(), location.child("Plural").attribute("value").as_string(), 
				Concept::ConceptType::Location);		

			pugi::xml_node adj_nodes = location.child("Adjectives");

			for (pugi::xml_node loc = adj_nodes.child("Adj"); loc; loc = loc.next_sibling("Adj"))
			{
				concept->AddAdjective(loc.attribute("val").as_int());
			}

			location = location.parent();
		}
	}

	//-- Adjectives ----
	pugi::xml_document	adjective_file;
	pugi::xml_node		adjectives;

	return true;
}

bool ModuleConceptManager::CleanUp()
{
	for (list<Concept*>::iterator it = concept_list.begin(); it != concept_list.end(); it++)
		RELEASE((*it));

	return true;
}

Concept* ModuleConceptManager::CreateConcept(std::string word, std::string plural, Concept::ConceptType type)
{
	
	Concept* ret = nullptr;

	switch (type)
	{
	case Concept::ConceptType::Location:
	{
		Location* location = new Location(word, plural, type);
		concept_list.push_back(location);
		location->SetID(curr_id);
		location_vector.push_back(location);
		ret = location;
		break;
	}
	case Concept::ConceptType::UnkownConcept:
		LOG("ModuleConceptManager::CreateConcept() Received unknown type!\n");
		break;
	default:
		LOG("ModuleConceptManager::CreateConcept() Received unknown type!\n");
		break;
	}
	
	curr_id++;

	return ret;

}
