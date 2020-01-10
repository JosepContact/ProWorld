#include <stdio.h>
#include <iostream>
#include "Location.h"
#include "App.h"
#include "Globals.h"

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

App* app = nullptr;

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
			app = new App();
			state = START_STATE;

			break;
		
		case START_STATE:
		// ( --------- World Starts -------------- )
			if (app->Start() == false)
			{
				state == EXIT_STATE;
			}
			else
			{
				state = UPDATE_STATE;
			}
		case UPDATE_STATE:
		// ( --------- World Updates -------------- )
			//int update_return = world->Update();
			state = CLEAN_UP_STATE;

		case CLEAN_UP_STATE:
			// ( --------- World Finishes -------------- )
			if (app->CleanUp() == false)
			{
				state == EXIT_STATE;
			}
			else
			{
				state = UPDATE_STATE;
			}
			state = EXIT_STATE;
			ret = EXIT_SUCCESS;

		}
	}
	
	delete app;
	return ret;
}