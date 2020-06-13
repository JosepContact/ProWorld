#pragma once

#ifndef EVENT_H
#define EVENT_H

#include "Character.h"
#include "Globals.h"

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

	struct Sentence
	{
		int id = 0;
		bool mandatory = true;
		int goes_after = -1;
		std::string text;
	};

	Event();
	virtual ~Event();

	std::string event_name;
	uint id;

	std::vector<Character*> characters;
	int act = -1;
	int priority = -1;
	Event* prev = nullptr;
	int seek = -1;
	JourneyAct curr_type = OrdinaryWorld;

	//Requirements
	Character* reqs[3];
	int min_characters = 0;

	std::vector<Sentence*> sentences;

	//When verb(location()) the location(), Hero() verb(sound) ; some; Adjective(sound); place() sound() place(); that verb(feeling()) feeling() in Hero->Pronoun().
	public:
	void AddCharacter(Character::MoralAlignment moral, Character::AttitudeAlignment attitude, Character::Archetype archetype, 
		Character::CharacterType type, int str, int intel, int dex, int cha);
	void FillSentence(uint id, bool mandatory, int goes_after, std::string sentence);

	bool ValidEvent(std::vector<Character*> chars);
};

#endif