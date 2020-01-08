#include <stdio.h>
#include <iostream>
#include "Location.h"
#include "World.h"

using namespace std;

#define EXIT_SUCCESS 1
#define EXIT_FAILURE 0

enum MainState {
	CREATE_STATE,
	START_STATE,
	UPDATE_STATE,
	CLEAN_UP_STATE,
	EXIT_STATE,
};

World* world = nullptr;

int main(int argc, char ** argv)
{
	int ret = EXIT_FAILURE;

	MainState state = CREATE_STATE;

	while (state != EXIT_STATE)
	{
		switch (state)
		{

		case CREATE_STATE:
		// ( ---------- World Creation -------------)
			world = new World();
			state = START_STATE;

			break;
		
		case START_STATE:
		// ( --------- World Starts -------------- )

			state = UPDATE_STATE;
		
		
		case UPDATE_STATE:
		// ( --------- World Updates -------------- )

			state = CLEAN_UP_STATE;

		case CLEAN_UP_STATE:
			// ( --------- World Finishes -------------- )

			state = EXIT_STATE;
			ret = EXIT_SUCCESS;

		}
	}
	
	delete world;
	return ret;
}