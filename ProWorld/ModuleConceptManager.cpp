#include "App.h"
#include "ModuleConceptManager.h"
#include "Concept.h"
#include "Location.h"
#include "Adjective.h"


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

			pugi::xml_node adj_n_nodes = location.child("Adjectives");

			for (pugi::xml_node loc = adj_n_nodes.child("Adj"); loc; loc = loc.next_sibling("Adj"))
			{
				concept->AddAdjective(loc.attribute("val").as_int());
			}

			location = location.parent();
		}
	}

	//-- Adjectives ----
	pugi::xml_document	adjective_file;
	pugi::xml_node		adjectives;

	adjectives = app->filesystem->LoadXML(DATA_ADJECTIVE_XML_PATH, ADJECTIVE, adjective_file);

	if (adjectives.empty() == false)
	{
		LOG("Adjectives.xml loaded correctly!\n");

		for (pugi::xml_node adject = adjectives.child("Adjective"); adject; adject = adject.next_sibling("Adjective"))
		{
			adject = adject.child("Info");
			Adjective* adjective = (Adjective*)CreateConcept(adject.child("Name").attribute("value").as_string(), string(""),
				Concept::ConceptType::Adjective);

			adjective->SetAssignedNouns(adject.child("Nouns").attribute("value").as_int());
			adjective->SetToPlural(adject.child("toPlural").attribute("value").as_bool());

			adject = adject.parent();
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
	case Concept::ConceptType::Adjective:
	{
		Adjective* adjective = new Adjective(word, type);
		concept_list.push_back(adjective);
		adjective->SetID(curr_id);
		adjective_vector.push_back(adjective);
		ret = adjective;
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

std::vector<Location*> ModuleConceptManager::GetLocationVector() const
{
	return location_vector;
}

std::vector<Adjective*> ModuleConceptManager::GetAdjectiveVector() const
{
	return adjective_vector;
}

std::vector<Adjective*> ModuleConceptManager::GetAdjectivesByKey(int key)
{
	vector<Adjective*> ret;

	for (vector<Adjective*>::iterator it = adjective_vector.begin(); it != adjective_vector.end(); ++it)
	{
		if ((*it)->GetNounsKey() == key)
			ret.push_back((*it));
	}
	return ret;
}
