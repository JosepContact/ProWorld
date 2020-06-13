#include "EventManager.h"
#include "App.h"
#include "ModuleWorld.h"
#include "HelperFunctions.h"

using namespace std;

EventManager::EventManager()
{
	
}

EventManager::~EventManager()
{
}

Event * EventManager::CreateEvent(std::string name, uint id, pugi::xml_node node)
{
	Event* nevent = new Event();
	nevent->event_name = name;
	nevent->id = id;
	event_vector.push_back(nevent);

	nevent->priority = node.child("Priority").attribute("value").as_int();
	nevent->seek = node.child("Seek").attribute("value").as_int();
	nevent->curr_type = static_cast<Event::JourneyAct>(node.child("Type").attribute("value").as_int());

	// Load Characters ~~~~~~~~~~
	
	pugi::xml_node character_nodes = node.child("Characters");

	for (pugi::xml_node cha = character_nodes.child("Character"); cha; cha = cha.next_sibling("Character"))
	{
		nevent->AddCharacter((Character::MoralAlignment)cha.child("Moral").attribute("value").as_int(), 
			(Character::AttitudeAlignment)cha.child("Attitude").attribute("value").as_int(), 
			(Character::Archetype)cha.child("Archetype").attribute("value").as_int(), 
			(Character::CharacterType)cha.child("CharacterType").attribute("value").as_int(), cha.child("Strength").attribute("value").as_int(), 
			cha.child("Intelligence").attribute("value").as_int(), cha.child("Dexterity").attribute("value").as_int(), 
			cha.child("Charisma").attribute("value").as_int());
	}

	// Load Sentences ~~~~~~~~~~~~~~~

	pugi::xml_node sentence_nodes = node.child("Text");

	for (pugi::xml_node sen = sentence_nodes.child("Sentence"); sen; sen = sen.next_sibling("Sentence"))
	{
		nevent->FillSentence(sen.attribute("N").as_int(),
			sen.attribute("Mandatory").as_bool(),
			sen.attribute("Follows").as_int(),
			sen.attribute("val").as_string());
	}

	return nevent;
}

WordPool * EventManager::CreateWordPool(pugi::xml_node node)
{

	WordPool* word_pool = new WordPool;

	word_pool->name = node.child("Name").attribute("value").as_string();

	// Load Words ~~~~~~~~~~~~
	pugi::xml_node word_nodes = node.child("Pool");

	for (pugi::xml_node wor = word_nodes.child("n"); wor; wor = wor.next_sibling("n"))
	{
		word_pool->outcomes.push_back(wor.attribute("val").as_string());
	}

	word_pools.push_back(word_pool);

	return word_pool;
}

std::vector<Event*> EventManager::GetAllEvents()
{
	return event_vector;
}

std::vector<WordPool*> EventManager::GetWordPools()
{
	return word_pools;
}

std::vector<std::string> EventManager::GetOutcomesFromWord(std::string word)
{
	for (auto it = word_pools.begin(); it != word_pools.end(); ++it)
	{
		if (word.compare((*it)->name) == 0)
			return (*it)->outcomes;
	}

	vector<string> ret;
	int EventId = -1;

	auto it = WorldEventsTable.find(word);
	if (it != WorldEventsTable.end()) {
		EventId = it->second;
	}

	switch (EventId)
	{
	case EventManager::WETs::_heroraceadj:
		return app->world->GetCharacterAdjectives(app->world->GetHero());
		break;
	case EventManager::WETs::_herorace:
		ret.push_back(toLowercase(app->world->GetCharacterRace(app->world->GetHero())));
		break;
	case EventManager::WETs::_heroname:
		ret.push_back(toLowercase(app->world->GetCharacterName(app->world->GetHero())));
		break;
	case EventManager::WETs::_heroorigintype:
		ret.push_back(toLowercase(app->world->GetCharacterOriginType(app->world->GetHero())));
		break;
	case EventManager::WETs::_herooriginname:
		ret.push_back(toLowercase(app->world->GetCharacterOriginName(app->world->GetHero())));
		break;
	case EventManager::WETs::_heropronoun:
		ret.push_back(toLowercase(app->world->GetCharacterPronoun(app->world->GetHero())));
		break;
	case EventManager::WETs::_heroadj:
		break;
	case EventManager::WETs::_fantasyname:
		ret.push_back(toLowercase(app->namegenerator->GenerateClassicName()));
		break;
	case EventManager::WETs::_heroreflectivepronoun:
		ret.push_back(toLowercase(app->world->GetCharacterReflectivePronoun(app->world->GetHero())));
		break;
	case EventManager::WETs::_secondaryreflectivepronoun:
		ret.push_back(toLowercase(app->world->GetCharacterReflectivePronoun(app->world->GetSecondaries()[0])));
		break;
	case EventManager::WETs::_secondaryname:
		ret.push_back(toLowercase(app->world->GetCharacterName(app->world->GetSecondaries()[0])));
		break;
	case EventManager::WETs::_secondaryraceadj:
		return app->world->GetCharacterAdjectives(app->world->GetSecondaries()[0]);
		break;
	case EventManager::WETs::_heroposessivepronoun:
		ret.push_back(app->world->GetCharacterPosessivePronoun(app->world->GetHero()));
		break;
	case EventManager::WETs::_secondarypronoun:
		ret.push_back(app->world->GetCharacterPronoun(app->world->GetSecondaries()[0]));
		break;
	}

	
	return ret;
}
