#pragma once

#ifndef MODULENARRATION_H
#define MODULENARRATION_H

#include "Module.h"

using namespace std;

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

	//
	virtual update_status Update();
private:
	string nWorld;
	string nClimate;

	bool StartsWithVowel(string word);
	string GetAorAn(string word);
	
};

#endif // !MODULENARRATION_H
