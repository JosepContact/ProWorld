#pragma once
#include <stdio.h>
#include <iostream>
#include <sstream>


class Concept
{
	public:
		Concept();
		virtual ~Concept();
	enum ConceptType {
		Location,
		UnkownConcept
	};
	
	protected:
		std::string word;
		std::string plural;
		ConceptType type;
	
	public:
		void SetName(std::string name, std::string plural);
		std::string GetString();
		const char* GetChar();
};
