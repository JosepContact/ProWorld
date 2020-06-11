#pragma once

#include "pugixml-1.10\src\pugixml.hpp"


#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Event.h"
#include "Globals.h"

#include<vector>

class WordPool;

class EventManager {

public:

	EventManager();
	virtual ~EventManager();

	Event* CreateEvent(std::string name, uint id, pugi::xml_node node);
	WordPool* CreateWordPool(pugi::xml_node);

	//void FillEvent(pugi::xml_nod);


private:
	std::vector<Event*> story_queue;
	std::vector<Event*> event_vector;
	std::vector<WordPool*> word_pools;
};

struct WordPool {
	std::string name;
	std::vector<std::string> outcomes;
};

#endif //EVENTMANAGER_H

