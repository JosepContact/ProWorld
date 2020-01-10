#pragma once
#include <stdio.h>
#include <iostream>
#include <sstream>


class Concept
{
public:
	enum ConceptType {
		Location,
		UnkownConcept
	};


		Concept();
		Concept(std::string argword, std::string argplural, ConceptType argtype);

		virtual ~Concept();

	protected:
		std::string word;
		std::string plural;
		ConceptType type;
		unsigned int id;
	
	public:
		void SetName(std::string name, std::string plural);
		std::string GetString();
		const char* GetChar();
		void SetID(unsigned int argid);
};
