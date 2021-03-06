#pragma once

#ifndef MODULENARRATION_H
#define MODULENARRATION_H

#include "Module.h"
#include "Character.h"
#include "Event.h"
using namespace std;

//class Event;
//struct Event::Sentence;

class ModuleNarration : public Module
{
public:
	ModuleNarration(bool start_enabled = true);

	virtual ~ModuleNarration();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();
	//

	string WorldName();
	string WorldSky();
	string WorldClimate();
	string WorldGeography();
	string WorldCharacters(Character*);
	string WorldCharactersArchetype(Character*);
	string WorldCharactersGoal(Character*);
	string WorldCharactersFlaw(Character*);
	string WorldCharactersOrigin(Character*);
	string WorldCharactersRace(Character*);	
	//
	virtual update_status Update();
private:
	string nWorld;
	string nClimate;

	bool StartsWithVowel(string word);
public:
	string GetAorAn(string word);
	string NarrateEvent(Event* ev);
	string DoSentence(Event::Sentence* s);
	string GetLowBarWord(int lowbarpos, string str);
	string SubstituteWords(string str);
	string ReplaceAorAn(string str);
	string Capitalize(string str);
	string AddJumplines(string str);
};

#endif // !MODULENARRATION_H
