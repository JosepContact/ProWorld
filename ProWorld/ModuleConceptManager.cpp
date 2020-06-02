#include "App.h"
#include "ModuleConceptManager.h"
#include "Concept.h"
#include "Location.h"
#include "Adjective.h"
#include "Climate.h"
#include "Race.h"

#include <algorithm>

using namespace std;

ModuleConceptManager::ModuleConceptManager(bool start_enabled) : Module(start_enabled)
{
}

ModuleConceptManager::~ModuleConceptManager()
{
	concept_list.clear();
	location_vector.clear();
	adjective_vector.clear();
	climate_vector.clear();
	race_vector.clear();
}

bool ModuleConceptManager::Start()
{

	//-- Locations ----
	pugi::xml_document	location_file;
	pugi::xml_node		locations;

	locations = app->filesystem->LoadXML(DATA_LOCATION_XML_PATH, LOCATION, location_file);

	if (!locations.empty())
	{
		LOG("Locations.xml loaded correctly!\n");

		for (pugi::xml_node location = locations.child("Location"); location; location = location.next_sibling("Location"))
		{
			location = location.child("Info");
			Location* concept = (Location*)CreateConcept(location.child("Name").attribute("value").as_string(), location.child("Plural").attribute("value").as_string(), 
				Concept::ConceptType::Location, location.child("id").attribute("value").as_int());		

			concept->SetIsCoastal(location.child("Coastal").attribute("value").as_bool());
			concept->SetInSea(location.child("inSea").attribute("value").as_bool());

			pugi::xml_node adj_n_nodes = location.child("Adjectives");

			for (pugi::xml_node loc = adj_n_nodes.child("Adj"); loc; loc = loc.next_sibling("Adj"))
			{
				concept->AddAdjective(loc.attribute("val").as_int());
			}

			pugi::xml_node cli_n_nodes = location.child("Climates");

			for (pugi::xml_node loc = cli_n_nodes.child("Adj"); loc; loc = loc.next_sibling("Adj"))
			{
				concept->AddClimate((Climate::ClimatesType)loc.attribute("val").as_int());
			}

			location = location.parent();
		}
	}

	//-- Adjectives ----
	pugi::xml_document	adjective_file;
	pugi::xml_node		adjectives;

	adjectives = app->filesystem->LoadXML(DATA_ADJECTIVE_XML_PATH, ADJECTIVE, adjective_file);

	if (!adjectives.empty())
	{
		LOG("Adjectives.xml loaded correctly!\n");

		for (pugi::xml_node adject = adjectives.child("Adjective"); adject; adject = adject.next_sibling("Adjective"))
		{
			adject = adject.child("Info");
			Adjective* adjective = (Adjective*)CreateConcept(adject.child("Name").attribute("value").as_string(), string(""),
				Concept::ConceptType::Adjective, adject.child("id").attribute("value").as_int());

			adjective->SetAssignedNouns(adject.child("Nouns").attribute("value").as_int());
			adjective->SetToPlural(adject.child("toPlural").attribute("value").as_bool());
			adjective->SetPriority(adject.child("prio").attribute("val").as_int());
			adjective->SetDesc(adject.child("desc").attribute("val").as_bool());

			adject = adject.parent();
		}
	}

	//-- Climates ----
	pugi::xml_document	climate_file;
	pugi::xml_node		climates;

	climates = app->filesystem->LoadXML(DATA_CLIMATES_XML_PATH, CLIMATE, climate_file);

	if (!climates.empty())
	{
		LOG("Climates.xml loaded correctly!\n");

		for (pugi::xml_node node_cl = climates.child("Climate"); node_cl; node_cl = node_cl.next_sibling("Climate"))
		{
			node_cl = node_cl.child("Info");
			Climate* climate = (Climate*)CreateConcept(node_cl.child("Name").attribute("value").as_string(), string(""),
				Concept::ConceptType::Climate, node_cl.child("id").attribute("value").as_int());

			climate->SetClimateType((Climate::ClimatesType)node_cl.child("Key").attribute("value").as_int());
			climate->SetTemperature(node_cl.child("Temperature").attribute("value").as_string());

			node_cl = node_cl.parent();

		}
	}

	//-- Races ----
	pugi::xml_document	race_file;
	pugi::xml_node		races;
	races = app->filesystem->LoadXML(DATA_RACES_XML_PATH, RACE, climate_file);

	if (!races.empty())
	{
		LOG("Races.xml loaded correctly\n");

		for (pugi::xml_node node_ra = races.child("Race"); node_ra; node_ra = node_ra.next_sibling("Race"))
		{
			node_ra = node_ra.child("Info");
			Race* race = (Race*)CreateConcept(node_ra.child("Name").attribute("value").as_string(), node_ra.child("Plural").attribute("value").as_string(),
				Concept::ConceptType::Race, node_ra.child("id").attribute("value").as_int());

			race->SetIsCoastal(node_ra.child("Coastal").attribute("value").as_bool());
			race->SetInSea(node_ra.child("inSea").attribute("value").as_bool());
			race->SetSize((Race::SizeType)node_ra.child("Size").attribute("value").as_int());

			pugi::xml_node cli_n_nodes = node_ra.child("Climates");

			for (pugi::xml_node rac = cli_n_nodes.child("Adj"); rac; rac = rac.next_sibling("Adj"))
			{
				race->AddClimate((Climate::ClimatesType)rac.attribute("val").as_int());
			}

			pugi::xml_node arch_n_nodes = node_ra.child("Archetypes");
			
			for (auto arch = arch_n_nodes.child("Adj"); arch; arch = arch.next_sibling("Adj"))
			{
				race->AddArchetype(arch.attribute("val").as_int());
			}

			node_ra = node_ra.parent();
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

Concept* ModuleConceptManager::CreateConcept(std::string word, std::string plural, Concept::ConceptType type, int id)
{
	
	Concept* ret = nullptr;

	switch (type)
	{
	case Concept::ConceptType::Location:
	{
		Location* location = new Location(word, plural, type, Location::LocationType(id));
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
	case Concept::ConceptType::Climate:
	{
		Climate* climate = new Climate(word, type);
		concept_list.push_back(climate);
		climate->SetID(curr_id);
		climate_vector.push_back(climate);
		ret = climate;
		break;
	}
	case Concept::ConceptType::Race:
	{
		Race* race = new Race(word, plural, type);
		concept_list.push_back(race);
		race->SetID(curr_id);
		race_vector.push_back(race);
		ret = race;
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

std::vector<Climate*> ModuleConceptManager::GetClimateVector() const
{
	return climate_vector;
}

std::vector<Race*> ModuleConceptManager::GetRaceVector() const
{
	return race_vector;
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

Location * ModuleConceptManager::GetLocationByName(string arg)
{
	for (vector<Location*>::iterator it = location_vector.begin(); it != location_vector.end(); ++it)
	{
		if ((*it)->GetWord() == arg)
		{
			return (*it);
		}
	}

	LOG("Couldn't find Location in location_vector at ModuleConceptManager: %s\n", arg);

	return nullptr;
}

vector<Race*> ModuleConceptManager::GetRacesVectorByClimate()
{
	vector<Race*> ret;

	for (vector<Race*>::iterator it = race_vector.begin(); it != race_vector.end(); it++)
	{
		if ((*it)->CompareClimate(app->world->GetClimate()->GetClimateType()))
			ret.push_back((*it));
	}
	return ret;
}

std::vector<Adjective*> ModuleConceptManager::GetAdjectivesByPriority(std::vector<Adjective*> argadj)
{
	vector<Adjective*> ret;

	if (argadj.empty())
	{
		LOG("argument vector<Adjective*> was empty at ModuleConceptManager::GetAdjectivesByPriority(vector<Adjective*>)");
		return ret;
	}

	int prio = 0, adj_size = argadj.size();

	vector<Adjective*>::iterator it = argadj.begin();

	do
	{
		while (it != argadj.end())
		{

			vector<Adjective*> to_emplace = GetAdjectivesToIterateByPriority(argadj, prio);
			
			if (to_emplace.empty())
			{
				prio++;
				it++;
				adj_size--;
				continue;
			}
			else {
				for (int i = 0; i < to_emplace.size(); i++)
					ret.push_back(to_emplace[i]);	
				prio++;
				adj_size--;
			}
			it++;
		}

		it = argadj.begin();

	} while (adj_size > 0);

	return ret;
}

std::vector<Adjective*> ModuleConceptManager::GetAdjectivesToIterateByPriority(std::vector<Adjective*> argadj, int key)
{
	vector<Adjective*> ret;

	for (vector<Adjective*>::iterator it = argadj.begin(); it != argadj.end(); it++)
	{
		if ((*it)->GetPriority() == key)
			ret.push_back((*it));
	}
	return ret;
}
