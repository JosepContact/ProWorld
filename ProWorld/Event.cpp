#include "Event.h"
#include "App.h"

using namespace std;

Event::Event()
{
}

Event::~Event()
{
	for (vector<Character*>::iterator it = characters.begin(); it != characters.end(); ++it)
		RELEASE(*it);

	for (vector<Sentence*>::iterator it = sentences.begin(); it != sentences.end(); ++it)
		RELEASE(*it);
}

void Event::AddCharacter(Character::MoralAlignment moral, Character::AttitudeAlignment attitude, Character::Archetype archetype, Character::CharacterType type, 
	 int str, int intel, int dex, int charisma)
{
	Character* cha = new Character(moral, attitude, archetype, type, str, intel, dex, charisma);

	characters.push_back(cha);
}

void Event::FillSentence(uint id, bool mandatory, int goes_after, std::string sentence)
{
	Sentence* nsentence = new Sentence;

	nsentence->id = id;
	nsentence->mandatory = mandatory;
	nsentence->goes_after = goes_after;
	nsentence->text = sentence;

	sentences.push_back(nsentence);

}

bool Event::ValidEvent(std::vector<Character*> chars)
{

	if (app->story->type > 0 && storytype > 0 && app->story->type != storytype)
		return false;

	int n_req = characters.size();

	for (vector<Character*>::iterator it = chars.begin(); it != chars.end(); ++it)
	{
		for (vector<Character*>::iterator it2 = characters.begin(); it2 != characters.end(); ++it2)
		{
			if ((*it2)->GetMorality() == (Character::MoralAlignment::MUnknown) || (*it)->GetMorality() == (*it2)->GetMorality())
			{
				if ((*it2)->GetAttitude() == (Character::AttitudeAlignment::AUnknown) || (*it)->GetAttitude() == (*it2)->GetAttitude())
				{
					if ((*it)->character_type == (*it2)->character_type || (*it2)->character_type == Character::CharacterType::CTNeutral)
						n_req--;
				}
			}
		}

	}

	return (n_req <= 0);
}
