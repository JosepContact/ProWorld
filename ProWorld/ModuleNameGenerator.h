#pragma once

#ifndef __MODULENAMEGENERATOR_H__
#define __MODULENAMEGENERATOR_H__

#include "pugixml-1.10\src\pugixml.hpp"
#include "Module.h"
#include "Adjective.h"
#include "Geography.h"

#include <string>
#include <vector>

class ModuleNameGenerator : public Module
{
public:

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
private:
	std::vector<std::string> vector_syllabes;

	std::vector<std::string> vector_end_syllabes;
};

#endif // __MODULENAMEGENERATOR_H__