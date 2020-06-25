#pragma once

#include "pugixml-1.10\src\pugixml.hpp"


#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Event.h"
#include "Globals.h"

#include<vector>
#include<iostream>
#include <unordered_map>

class WordPool;


class EventManager {

public:

	EventManager();
	virtual ~EventManager();

	Event* CreateEvent(std::string name, uint id, pugi::xml_node node);
	WordPool* CreateWordPool(pugi::xml_node);

	//void FillEvent(pugi::xml_nod);
	enum WETs //World Event Types
	{
		_heroraceadj,
		_herorace,
		_heroname,
		_heroorigintype,
		_herooriginname,
		_heropronoun,
		_heroadj,
		_fantasyname,
		_heroreflectivepronoun,
		_secondaryreflectivepronoun,
		_secondaryname,
		_secondaryraceadj,
		_heroposessivepronoun,
		_secondaryposessivepronoun,
		_secondarypronoun,
		_weapon,
		_herooriginrace,
		_magicalcreature,
		_magicalitem,
		_randomsociety
	};

private:
	std::vector<Event*> event_vector;
	std::vector<WordPool*> word_pools;

public:
	std::vector<Event*> GetAllEvents();
	std::vector<WordPool*> GetWordPools();
	std::vector<std::string> GetOutcomesFromWord(std::string word);
};

struct WordPool {
	std::string name;
	std::vector<std::string> outcomes;

};

static std::unordered_map<std::string, EventManager::WETs> const WorldEventsTable = {
{ "_heroraceadj", EventManager::WETs::_heroraceadj },
{ "_herorace",EventManager::WETs::_herorace} ,
{ "_heroname",EventManager::WETs::_heroname },
{ "_heroorigintype",EventManager::WETs::_heroorigintype },
{ "_herooriginname",EventManager::WETs::_herooriginname },
{ "_heropronoun",EventManager::WETs::_heropronoun },
{ "_heroadj",EventManager::WETs::_heroadj },
{ "_fantasyname",EventManager::WETs::_fantasyname },
{ "_heroreflectivepronoun",EventManager::WETs::_heroreflectivepronoun},
{ "_heroreflectivepronoun",EventManager::WETs::_heroreflectivepronoun},
{ "_secondaryreflectivepronoun",EventManager::WETs::_secondaryreflectivepronoun},
{ "_secondaryname",EventManager::WETs::_secondaryname},
{ "_secondaryraceadj",EventManager::WETs::_secondaryraceadj},
{ "_heroposessivepronoun",EventManager::WETs::_heroposessivepronoun},
{ "_secondarypronoun",EventManager::WETs::_secondarypronoun},
{ "_weapon",EventManager::WETs::_weapon},
{ "_herooriginrace",EventManager::WETs::_herooriginrace},
{ "_magicalcreature",EventManager::WETs::_magicalcreature},
{ "_magicalitem",EventManager::WETs::_magicalitem},
{ "_randomsociety",EventManager::WETs::_randomsociety},
};

#endif //EVENTMANAGER_H

