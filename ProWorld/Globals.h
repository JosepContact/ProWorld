#pragma once

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

#define NULL 0
typedef unsigned int uint;

// Deletes a buffer
#define RELEASE( x ) \
    {                        \
    if( x != NULL )        \
	    {                      \
      delete x;            \
	  x = NULL;              \
	    }                      \
    }

#define VERY_HIGH_CHANCE 95
#define HIGH_CHANCE 80
#define MEDIUM_HIGH_CHANCE 60
#define MEDIUM_CHANCE 50
#define MEDIUM_LOW_CHANCE 40
#define LOW_CHANCE 20
#define VERY_LOW_CHANCE 5

#define ORGANIZATION_NAME "Managicality"
#define APP_NAME "ProWorld 0.1"

#define DATA_LOCATION_XML_PATH "Data/Locations.xml"
#define DATA_ADJECTIVE_XML_PATH "Data/Adjectives.xml"
#define DATA_CLIMATES_XML_PATH "Data/Climates.xml"
#define DATA_RACES_XML_PATH "Data/Races.xml"
#define DATA_EVENTS_XML_PATH "Data/Events.xml"
#define DATA_WORDS_XML_PATH "Data/WordPool.xml"

#endif //GLOBALS_H

