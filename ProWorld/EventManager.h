#pragma once

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Event.h"

#include<vector>


class EventManager {

public:

	EventManager();
	virtual ~EventManager();

private:
	std::vector<Event*> queue;
};

#endif //EVENTMANAGER_H

