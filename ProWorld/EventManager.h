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

};

#endif //EVENTMANAGER_H

