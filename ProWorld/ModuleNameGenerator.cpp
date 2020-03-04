#include "ModuleNameGenerator.h"
#include "HelperFunctions.h"
#include "App.h"
#include "CharacterName.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <ctype.h>

using namespace std;

ModuleNameGenerator::ModuleNameGenerator(bool start_enabled) : Module(start_enabled)
{
	srand((int)time(0));
}

ModuleNameGenerator::~ModuleNameGenerator()
{
	vector_syllabes.clear();
	vector_end_syllabes.clear();
}

char NamePrefix[][7] =
{
	"River",
	"Mage",
	"Gloom",
	"Fear",
	"Ebon",
	"Sleet",
	"Grey",
	"Spirit",
	"Lime",
	"Ghost",
	"Fair",
	"Last",
	"Clay",
	"Shroud",
	"Crow",
	"Little",
	"Rose",
	"Rogue",
	"Amber",
	"Winter",
	"Spring",
	"Dry",
	"Basin",
	"Brine",
	"Night",
	"Shadow",
	"Sun",
	"Shade",
	"Wind",
	"Dark",
	"High",
	"Edge",
	"Gold"
};

char NameSuffix[][7] =
{
	"reach",
	"well",
	"storm",
	"haven",
	"hallow",
	"wrath",
	"shell",
	"gulf",
	"wall",
	"bourne",
	"pass",
	"wallow",
	"wick",
	"horn",
	"brook",
	"burn",
	"winter",
	"point",
	"bell",
	"drift",
	"view",
	"spear",
	"grave",
	"chill",
	"dale",
	"shear",
	"hill",
	"meadow",
	"yard",
	"light",
	"grasp"
};

bool ModuleNameGenerator::Start()
{
	
	string syllabe = "da";
	vector_syllabes.push_back(syllabe);
	syllabe = "ye";
	vector_syllabes.push_back(syllabe);
	syllabe = "ma";
	vector_syllabes.push_back(syllabe);
	syllabe = "qio";
	vector_syllabes.push_back(syllabe);
	syllabe = "do";
	vector_syllabes.push_back(syllabe);
	syllabe = "clo";
	vector_syllabes.push_back(syllabe);
	syllabe = "breo";
	vector_syllabes.push_back(syllabe);
	syllabe = "ce";
	vector_syllabes.push_back(syllabe);
	syllabe = "sos";
	vector_syllabes.push_back(syllabe);
	syllabe = "kal";
	vector_syllabes.push_back(syllabe);
	syllabe = "drias";
	vector_syllabes.push_back(syllabe);
	syllabe = "pea";
	vector_syllabes.push_back(syllabe);
	syllabe = "blo";
	vector_syllabes.push_back(syllabe);
	syllabe = "ti";
	vector_syllabes.push_back(syllabe);
	syllabe = "kas";
	vector_syllabes.push_back(syllabe);
	syllabe = "gar";
	vector_syllabes.push_back(syllabe);
	syllabe = "ki";
	vector_syllabes.push_back(syllabe);
	syllabe = "le";
	vector_syllabes.push_back(syllabe);
	syllabe = "mi";
	vector_syllabes.push_back(syllabe);
	syllabe = "me";
	vector_syllabes.push_back(syllabe);
	syllabe = "kuthas";
	vector_syllabes.push_back(syllabe);
	syllabe = "zo";
	vector_syllabes.push_back(syllabe);
	syllabe = "garth";
	vector_syllabes.push_back(syllabe);
	syllabe = "pas";
	vector_syllabes.push_back(syllabe);
	syllabe = "se";
	vector_syllabes.push_back(syllabe);
	syllabe = "cir";
	vector_syllabes.push_back(syllabe);
	syllabe = "reo";
	vector_syllabes.push_back(syllabe);
	syllabe = "reo";
	vector_syllabes.push_back(syllabe);
	syllabe = "kla";
	vector_syllabes.push_back(syllabe);
	syllabe = "le";
	vector_syllabes.push_back(syllabe);
	syllabe = "xor";
	vector_syllabes.push_back(syllabe);
	syllabe = "ye";
	vector_syllabes.push_back(syllabe);
	syllabe = "rak";
	vector_syllabes.push_back(syllabe);
	syllabe = "si";
	vector_syllabes.push_back(syllabe);
	syllabe = "de";
	vector_syllabes.push_back(syllabe);
	syllabe = "neme";
	vector_syllabes.push_back(syllabe);
	syllabe = "nox";
	vector_syllabes.push_back(syllabe);
	syllabe = "cy";
	vector_syllabes.push_back(syllabe);

	//Ending Syllabes
	syllabe = "tika";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "rea";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "cion";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "on";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "topia";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "rion";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "cire";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "cius";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "dos";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "ceus";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "mir";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "guul";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "gari";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "mic";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "xis";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "sis";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "ris";
	vector_end_syllabes.push_back(syllabe);
	syllabe = "siris";
	vector_end_syllabes.push_back(syllabe);

	return true;
}

bool ModuleNameGenerator::CleanUp()
{
	vector_syllabes.clear();
	vector_end_syllabes.clear();

	return true;
}

std::string ModuleNameGenerator::GenerateName()
{
	//srand((int)time(0));

	// create a random number from 2 to 4
	//int twofour = (rand() % 3) + 2;

	int twofour = GetRandomNumber(2, 4);

	string name;

	for (uint i = 0; i < twofour; ++i)
	{
		if (i == twofour - 1) //25% chance of getting a final syllabe
		{ 
			int random_syll = (rand() % vector_end_syllabes.size());
			name += vector_end_syllabes[random_syll];
		}
		else
		{
			int random_syll = (rand() % vector_syllabes.size());
			name += vector_syllabes[random_syll];
		}
	}

	return name;
}

std::string ModuleNameGenerator::GenerateClassicName()
{

	string ret(NamePrefix[GetRandomNumber(0, 32)]);
	string ret2(NameSuffix[GetRandomNumber(0, 30)]);

	return (ret + ret2);
}

std::string ModuleNameGenerator::GeneratePlaceName(Geography::Place* place, std::vector<Adjective*> adjectives)
{
	string ret;

	if (adjectives.empty())
	{
		LOG("argument vector<Adjective*> was empty at ModuleNameGenerator::GeneratePlaceName(vector<Adjective*>)");
		return ret;
	}
	
	vector<Adjective*> adj = app->conceptmanager->GetAdjectivesByPriority(adjectives);
	vector<Adjective*> desc_adj;

	int maxtypes = 1;
	for (int i = 0; i < adj.size(); i++)
	{
		if (adj[i]->GetPriority() == 5)
			maxtypes++;
	}

	switch(GetRandomNumber(0, maxtypes))
	{
	case OwnPlaceName:
		ret += GenerateClassicName();
		place->has_name = true;
		place->nametype = (int)OwnPlaceName;

		break;
	case ColorName:
	{
		vector<Adjective*> color_adj;
		for (int i = 0; i < adj.size(); i++)
		{
			if (adj[i]->GetPriority() == 5)
				color_adj.push_back(adj[i]);
		}

		ret += color_adj[GetRandomNumber(0, color_adj.size() - 1)]->GetWord() + " " + place->location->GetWord();
		place->has_name = true;
		place->nametype = (int)ColorName;

		break;
	}
	case TheName:
		ret += "The";

		bool is_plural = false;
		int prev_prio = -1;
		int adj_count = 0;

		for (int i = 0; i < adj.size(); i++)
		{
			Adjective* temp = adj[i];
			if (temp->GetPriority() != prev_prio && GetBoolByRandom(LOW_CHANCE))
			{
				if (temp->GetWord() == "Many") is_plural = true;
				ret += " " + temp->GetWord();

				prev_prio = temp->GetPriority();
				adj_count++;
			}
		}

		if (adj_count == 0)
		{
			ret = toLowercase(place->location->GetWord());
			place->has_name = false;
			return ret;
		}

		if (is_plural == true)
			ret += " " + place->location->GetPlural();
		else ret += " " + place->location->GetWord();

		place->nametype = (int)TheName;
		place->has_name = true;

		break;
	}

	// WRITE DESCRIPTION

	int n_adj = GetRandomNumber(1, adj.size());

	do
	{
		Adjective* temp = adj[GetRandomNumber(0, adj.size() - 1)];

		if (temp->GetWord() == "Many" || temp->GetDesc() == false)
		{
			n_adj--;
			continue;
		}

		if (find(desc_adj.begin(), desc_adj.end(), temp) != desc_adj.end())
			continue;

		if (GetBoolByRandom(MEDIUM_CHANCE))
		{
			desc_adj.push_back(temp);
			n_adj--;
		}

	} while (n_adj > 0);
	string desc;

	desc += "This place is based on " + app->narration->GetAorAn(place->location->GetWord()) + " " + toLowercase(place->location->GetWord()) + ".\n";
	
	if (!desc_adj.empty())
	{
		desc += "It's ";
		for (int i = 0; i < desc_adj.size(); i++)
		{
			desc += toLowercase(desc_adj[i]->GetWord());

			if (i < desc_adj.size() - 2 && desc_adj.size() > 1)
				desc += ", ";
			else if (i == (desc_adj.size() - 2)) // el bug es que comta primer els que tenen descripcio abans de ficar el and, llavors posa el and y en el if entra y no posa res (crec). Haig de crear un nou vector vaya
				desc += " and ";
		}
		desc += ".\n";
	}
	place->desc = desc;
	return ret;

	
}

std::string ModuleNameGenerator::GenRegularMaleCharName()
{
	string ret(MaleNamePrefix[GetRandomNumber(0, 26)]);
	string ret2(MaleNameSuffix[GetRandomNumber(0, 17)]);

	return (ret + ret2);
}

std::string ModuleNameGenerator::GenRegularFemaleCharName()
{
	string ret(FemaleNamePrefix[GetRandomNumber(0, 17)]);
	string ret2(FemaleNameSuffix[GetRandomNumber(0, 19)]);

	return (ret + ret2);
}
