#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------


// TODO 1: Create a struct needed to hold the information to Map node

enum map_orientantion {
	right_down,
	right_up,
	left_down,
	left_up,
	error

};


// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:


	bool LoadMap(const char* path);

public:
	struct MapNode;
	struct TileSet;

	pugi::xml_document Map;

	// TODO 1: Add your struct for map info as public for now

	struct MapNode {


		uint width = 0;
		uint height = 0;

		map_orientantion orientation = map_orientantion::error;
	};

	struct TileSet {

		int FirstGID = 0;
		uint TilleWidth = 0;
		uint TilleHeight = 0;
		uint spacing = 0;
		uint magine = 0;

	};

private:

	pugi::xml_document	map_file;

	

	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__