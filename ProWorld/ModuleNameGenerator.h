#ifndef __MODULENAMEGENERATOR_H__
#define __MODULENAMEGENERATOR_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Adjective.h"
#include "Geography.h"

#include <string>
#include <vector>

#define MAX_ADJECTIVES 5

class ModuleNameGenerator : public Module
{
public:

	enum PlaceNameType
	{
		OwnPlaceName = 0,
		TheName,
		ColorName
	};

	ModuleNameGenerator(bool start_enabled = true);

	// Destructor
	virtual ~ModuleNameGenerator();

	// Starts The FileSystem Module
	bool Start();

	// Called before quitting
	bool CleanUp();

	//virtual update_status Update();

	std::string GenerateName();
	std::string GenerateClassicName();

	std::string GeneratePlaceName(Geography::Place*, std::vector<Adjective*>);

	std::string GenRegularMaleCharName();
	std::string GenRegularFemaleCharName();

	std::string GenChineseMName();
	std::string GenChineseFName();
	std::string GenJapaneseMName();
	std::string GenJapaneseFName();
	std::string GenMTribalName();
	std::string GenFTribalName();

private:
	std::string GetJapaneseSurname();
	std::vector<std::string> vector_syllabes;

	std::vector<std::string> vector_end_syllabes;
};

#endif // __MODULENAMEGENERATOR_H__