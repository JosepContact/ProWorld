#pragma once
#include <stdio.h>
#include <iostream>
#include <sstream>

#ifndef __CONCEPT_H__
#define __CONCEPT_H__

class Location;

class Concept
{
public:
	enum ConceptType {
		Location,
		Adjective,
		Climate,
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
		void SetWord(std::string name, std::string plural);
		std::string GetWord();
		std::string GetPlural();
		const char* GetChar();
		void SetID(unsigned int argid);
};

#endif