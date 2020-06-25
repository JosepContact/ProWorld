#ifndef MODULESTORY_H
#define MODULESTORY_H

#define MAXEVENTSPERACT 3

#include "Module.h"
#include <vector>

class EventManager;
class Event;

class ModuleStory : public Module {

public:
	ModuleStory(bool start_enabled = true);

	virtual ~ModuleStory();

	enum StoryType
	{
		Regain_Kingdom = 1, 
		Meet_Magical_Master, 
		Vengeance, 
		Magic_Item, 
		Break_From_Curse,
	};

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	virtual update_status Update();

	void CreateStory();
	Event* SeekEvent(Event* ev);
	Event* ChooseEvent(std::vector<Event*> vect_ev);

private:
	EventManager* e_manager = nullptr;
	std::vector<Event*> story_queue;

public:
	EventManager* GetManager() const;
	std::vector<Event*> GetStory();

	//Hero
	std::string weapon;

	StoryType type;
	//-- Regain Kingdom
	//-- MagicalMaster
	std::string magicalcreature;
	std::string magicalmasterrace;
	std::string mentorname;

	//-- Vengeance
	std::string act;
	//-- Magical Item
	std::string magicalitem;
	std::string magicalitemorigin;

};

#endif //MODUESTORY_H


