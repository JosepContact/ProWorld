#pragma once

#ifndef EVENT_H
#define EVENT_H

#include "Character.h"

#include <vector>

class Event {
public:
	enum EventType {
		Description,
		StartConflict,
		EndConflict,
		CharactersMeet,
		CharacterArc,
		StartAct,
		EndAct
	};

	enum JourneyAct {
		OrdinaryWorld,
		CallToAdventure,
		RefusalOfTheCall,
		MeetingMentor,
		CrossingFirstTheshold,
		TestsAlliesEnemies,
		Approach,
		Ordeal,
		Reward,
		TheRoadBack,
		Resurrection,
		Return
	};

	Event();
	virtual ~Event();

	std::vector<Character*> characters;
	int act = -1;
	int priority = -1;
	Event* prev = nullptr;

	//Requirements
	Character* reqs[3];
	int min_characters = 0;

	//When verb(location()) the location(), Hero() verb(sound) ; some; Adjective(sound); place() sound() place(); that verb(feeling()) feeling() in Hero->Pronoun().

};

#endif