#include "ModuleNameGenerator.h"

#include <cstdlib>
#include <ctime>

using namespace std;

ModuleNameGenerator::ModuleNameGenerator(bool start_enabled) : Module(start_enabled)
{
}

ModuleNameGenerator::~ModuleNameGenerator()
{
}

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

	GenerateName();

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
	srand((int)time(0));

	// create a random number from 2 to 4
	int twofour = (rand() % 3) + 2;
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
