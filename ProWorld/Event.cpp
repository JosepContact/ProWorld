#include "Event.h"

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

void Event::AddCharacter(Character::MoralAlignment moral, Character::AttitudeAlignment attitude, Character::Archetype archetype, Character::CharacterType type)
{
	Character* cha = new Character(moral, attitude, archetype, type);

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
