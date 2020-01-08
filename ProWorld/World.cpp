#include "World.h"
#include "FileSystem.h"



World::World()
{
	FileSystem* file = new FileSystem;
	file->Start();

	delete file;
}


World::~World()
{
}

void World::SaveWorld()
{
}

void World::LoadWorld()
{
}
