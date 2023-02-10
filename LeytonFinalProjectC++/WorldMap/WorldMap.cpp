#include <fstream>
#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/PlayerCharacter.h"
#include "../Sprites/InteractablesForMaps.h"
#include <list>
#include "../Sprites/TrainerManager.h"
#include "../Battle/InitiateBattle.h"
using namespace std;
// A class to represent the world
// Loads the map from the map text files
class WorldMap {


public:

	// A buffer for the map
	ALLEGRO_BITMAP* mapBuffer;
	// The map images
	ALLEGRO_BITMAP* mapTiles[35];
	// A list of interactables for map
	std::list<Interactable> interactablesForMap;
	// A list of the trainers for map
	std::list<Trainer> trainersForMap;
	// An array for the map
	int textMap[100][100];
	// Counter for x in loading map
	int loadCounterX = 0;
	// Counter for y in loading map
	int loadCounterY = 0;
	// how wide is the map
	int mapSizeX = 0;
	// How long is the map
	int mapSizeY = 0;
	// When to load the map size
	bool once = false;
	// Width of screen
	int screenWidth;
	// height of screen
	int screenHeight;
	// which location number it is
	int locationNumber = 0;
	// what route number is it
	int routeNumber = 0;
	// What map number it is
	int mapNumber;
	// The previous location of the player before loading map
	int previousTileLocation[2];
	// The position of the closest heal
	int closestHealLocation[2];
	// Filename of the previous map
	const char* previousMap;
	// File name of the current map
	const char* currentMap;
	// Class to manage the trainers
	TrainerManager trainerManager;

	// Constructor for world map
	// Creates the map with the width and height and file path
	WorldMap(int _screenWidth, int _screenHeight, const char * mapFP, int _mapNumber) {
		cout << "Creating new world map\n";
		screenWidth = _screenWidth;
		screenHeight = _screenHeight;
		mapBuffer = al_create_bitmap(screenWidth, screenHeight);

		// Unwalkable black square
		mapTiles[0] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// Walkable black square
		mapTiles[1] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// Reserved
		mapTiles[2] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// Green tile
		mapTiles[3] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		// Reserved for other colour tile
		mapTiles[4] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		// Reserved for other colour tile
		mapTiles[5] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		// Pokemon Grass
		mapTiles[6] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PokemonGrass.png");
		// Pokemon Grass reserved for different sprite
		mapTiles[7] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PokemonGrass.png");
		// Pokemon Grass reserved for different sprite
		mapTiles[8] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PokemonGrass.png");
		// Entrance to small building
		mapTiles[9] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// Poke centre draw tile
		mapTiles[10] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PokemonCentre.png");
		// Poke mart draw tile
		mapTiles[11] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PokeMart.png");
		// Tree draw tile
		mapTiles[12] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/Tree.png");
		// Fence draw tile
		mapTiles[13] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/Fence.png");
		// Basic house tile
		mapTiles[14] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BasicHouse.png");
		// Basic house inside tile
		mapTiles[15] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BasicHouse1F.png");
		// Entrance to overworld at last position
		mapTiles[16] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// Entrance to pokecentre
		mapTiles[17] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// Entrance to Pokemart
		mapTiles[18] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// Pokecentre draw inside
		mapTiles[19] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/InsidePokeCentre.png");
		// Pokemart draw inside
		mapTiles[20] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/InsidePokeMart.png");
		// Entrance to pokecentre
		mapTiles[21] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		// Entrance to map one from map two
		mapTiles[22] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");

		// Water top left image
		mapTiles[23] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterTopLeft.png");
		// water top middle image
		mapTiles[24] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterTopMiddle.png");
		// water top middle image
		mapTiles[25] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterTopRight.png");

		// Water middle left image
		mapTiles[26] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterMiddleLeft.png");
		// water middle middle image
		mapTiles[27] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterMiddleMiddle.png");
		// water middle middle image
		mapTiles[28] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterMiddleRight.png");

		// Water bottom left image
		mapTiles[29] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterBottomLeft.png");
		// water bottom middle image
		mapTiles[30] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterBottomMiddle.png");
		// water bottom middle image
		mapTiles[31] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/waterBottomRight.png");

		// gym tile image
		mapTiles[32] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/gym.png");
		// Entrance to gym gym tile image
		mapTiles[33] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		// inside gym one image
		mapTiles[34] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/firstGymInside.png");
		// Sets the map info up
		mapNumber = mapNumber;
		previousTileLocation[0] = 0;
		previousTileLocation[1] = 0;
		closestHealLocation[0] = 15;
		closestHealLocation[1] = 10;
		// Sets up the interactables
		InteractablesForMaps im;
		routeNumber = _mapNumber;
		interactablesForMap = im.getInteractablesForMap(_mapNumber);
		trainersForMap = trainerManager.getTrainersForMap(_mapNumber);
		// Sets up the map names
		previousMap = "";
		currentMap = mapFP;
		loadMap(mapFP);
		changeLocationNumber();
		
	}

	// chnages the locaiton number based on the map
	void changeLocationNumber()
	{
		if (strcmp(currentMap, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt") == 0) {
			locationNumber =  5;
		}
		else if (strcmp(currentMap, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapTwo.txt") == 0) {
			locationNumber = 7;
		}
	}

	// Destroys all sprites on map
	void destroyAllSprites() {

		
	}

	// Resets the array of maps to 0's
	void resetMapToZeros() {
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				textMap[i][j] = 0;
			}
		}
	}


	// Loops through all the interactbales to see if anything is interacting
	int interact(PlayerCharacter& player, ALLEGRO_EVENT_QUEUE* queue, const char* keyPressed, int directionX, int directionY, int xTile, int yTile, int screenWidth, int screenHeight) {

		for (Interactable& inter : interactablesForMap)
		{
			if (inter.isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
				inter.interact(player, queue,  screenWidth,  screenHeight);
				return 1;
			}
		}
		for (Trainer& trainer : trainersForMap)
		{
			if (trainer.isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
				trainer.interact(player, queue, screenWidth, screenHeight);
				return 1;
			}
		}

		return 0;
	}

	// Checks to see if the map needs to be changed
	void checkToChangeMaps(PlayerCharacter& player) {
		int tile = getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
		// Entrance to basic house
		if (tile == 9) {

			if (strcmp(currentMap, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt") == 0) {
				if (player.xTilePosition == 9 && player.yTilePosition == 9) {
					mapNumber = 20;
				}
				else if (player.xTilePosition == 19 && player.yTilePosition == 9) {
					mapNumber = 21;
				}
				else if (player.xTilePosition == 9 && player.yTilePosition == 16) {
					mapNumber = 22;
				}
				else if (player.xTilePosition == 19 && player.yTilePosition == 16) {
					mapNumber = 23;
				}
			}
			else if (strcmp(currentMap, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapTwo.txt") == 0) {
				if (player.xTilePosition == 14 && player.yTilePosition == 56) {
					mapNumber = 24;
				}
				else if (player.xTilePosition == 21 && player.yTilePosition == 52) {
					mapNumber = 25;
				}
				
			}
			else {
				mapNumber = 99;
			}

			// Reloads rthe map
			// Sets the previous positions
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			cout << "Tile  L : " << player.xTilePosition << " " << player.yTilePosition << " \n";
			previousTileLocation[0] = player.xTilePosition;
			previousTileLocation[1] = (player.yTilePosition) +1;
			player.resetPlayer(7, 10);
			previousMap = currentMap;
			currentMap = "../LeytonFinalProjectC++/WorldMap/TextMaps/BasicHouseMap.txt";
			loadMap(currentMap);

			InteractablesForMaps im;
			interactablesForMap = im.getInteractablesForMap(mapNumber);
			trainersForMap = trainerManager.getTrainersForMap(mapNumber);

		}
		// Entrance to poke centre
		else if (tile == 17) {
			// Reloads rthe map
			// Sets the previous positions
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			previousTileLocation[0] = player.xTilePosition;
			previousTileLocation[1] = (player.yTilePosition) + 1;
			player.setAllPositions(6, 8);
			player.resetPlayer(6, 8); 
			resetMapToZeros();
			previousMap = currentMap;
			currentMap = "../LeytonFinalProjectC++/WorldMap/TextMaps/PokeCentreMap.txt";
			loadMap(currentMap);
			mapNumber = 11;
			InteractablesForMaps im;
			interactablesForMap = im.getInteractablesForMap(mapNumber);
			trainersForMap = trainerManager.getTrainersForMap(mapNumber);
		}
		// Entrance to poke mart
		else if (tile == 18) {
			// Reloads rthe map
			// Sets the previous positions
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			previousTileLocation[0] = player.xTilePosition;
			previousTileLocation[1] = (player.yTilePosition) + 1;
			player.setAllPositions(2, 6);
			player.resetPlayer(2, 6);
			resetMapToZeros();
			previousMap = currentMap;
			currentMap = "../LeytonFinalProjectC++/WorldMap/TextMaps/PokeMartMap.txt";
			loadMap(currentMap);
			mapNumber = 12;
			InteractablesForMaps im;
			interactablesForMap = im.getInteractablesForMap(mapNumber);
			trainersForMap = trainerManager.getTrainersForMap(mapNumber);
		}
		// entrance to map from buildings 
		else if (tile == 16) {
			// Reloads rthe map
			// Sets the previous positions
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			player.resetPlayer(previousTileLocation[0], previousTileLocation[1]);

			if (strcmp(previousMap, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt") == 0) {
				mapNumber = 1;
				routeNumber = 1;
			}else if (strcmp(previousMap, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapTwo.txt") == 0) {
				mapNumber = 2;
				routeNumber = 2;
			}
			loadMap(previousMap);
			currentMap = previousMap;
			previousMap = "";
			InteractablesForMaps im;
			interactablesForMap = im.getInteractablesForMap(mapNumber);
			trainersForMap = trainerManager.getTrainersForMap(mapNumber);
			changeLocationNumber();
		}
		// entrance to map two
		else if (tile == 21) {
			// Reloads rthe map
			// Sets the previous positions
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			previousTileLocation[0] = player.xTilePosition;
			previousTileLocation[1] = (player.yTilePosition) + 1;
			player.resetPlayer(15, 7);
			resetMapToZeros();
			previousMap = currentMap;
			currentMap = "../LeytonFinalProjectC++/WorldMap/TextMaps/MapTwo.txt";
			routeNumber = 2;
			loadMap(currentMap);
			mapNumber = 2;
			InteractablesForMaps im;
			interactablesForMap = im.getInteractablesForMap(mapNumber);
			trainersForMap = trainerManager.getTrainersForMap(mapNumber);
			changeLocationNumber();
		}
		// entrance to map one from map 2
		else if (tile == 22) {
			// Reloads rthe map
			// Sets the previous positions
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			previousTileLocation[0] = player.xTilePosition;
			previousTileLocation[1] = (player.yTilePosition) + 1;
			// player.setAllPositions(75, 40);
			resetMapToZeros();
			previousMap = currentMap;
			currentMap = "../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt";
			loadMap(currentMap);
			routeNumber = 1;
			player.resetPlayer(28, 72);
			mapNumber = 1;
			InteractablesForMaps im;
			interactablesForMap = im.getInteractablesForMap(mapNumber);
			trainersForMap = trainerManager.getTrainersForMap(mapNumber);
			changeLocationNumber();

		}

		// Entrance to gym
		else if (tile == 33) {
			// Reloads rthe map
			// Sets the previous positions
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			previousTileLocation[0] = player.xTilePosition;
			previousTileLocation[1] = (player.yTilePosition) + 1;
			player.resetPlayer(8, 20);
			resetMapToZeros();
			previousMap = currentMap;
			currentMap = "../LeytonFinalProjectC++/WorldMap/TextMaps/Gym.txt";
			loadMap(currentMap);
			mapNumber = 13;
			InteractablesForMaps im;
			interactablesForMap = im.getInteractablesForMap(mapNumber);
			trainersForMap = trainerManager.getTrainersForMap(mapNumber);
		}
	}



	// Checks to see if the player can move
	// Different tiles will be movable
	int canPlayerMove(const char* keyPressed, int directionX, int directionY, int xTile, int yTile) {
		int tempYTile = yTile + 1;
		cout << "X : " <<xTile << " Y : " << yTile << " Tile N : " << getWhatPlayerIsStandingOn(xTile, yTile) << "\n";
		if (strcmp(keyPressed, "w") == 0) {
			if (directionY == 1) {

				if (tempYTile - 1 >= 0) {
					if (textMap[xTile][tempYTile-1] == 0) {
						return 0;
					}else if (textMap[xTile][tempYTile-1] == 1) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 10) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 11) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 12) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 13) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 14) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 23) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 24) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 25) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 26) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 27) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 28) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 29) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 30) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 31) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 32) {
						return 0;
					}
					// checks the interactbles too
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}

					std::list<Trainer>::reverse_iterator revItTrainer;
					for (revItTrainer = trainersForMap.rbegin(); revItTrainer != trainersForMap.rend(); revItTrainer++)
					{
						if (revItTrainer->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}

				}
				else {
					return 0;
				}

			}
			return 1;
		}

		else if (strcmp(keyPressed, "s") == 0) {
			if (directionY == -1) 
			{
				if (tempYTile + 1 < mapSizeY) {
					if (textMap[xTile][tempYTile + 1] == 0 ) {
						return 0;
					}
					else if (textMap[xTile][tempYTile+1] == 1) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 10) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 11) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 12) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 13) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 14) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 23) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 24) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 25) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 26) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 27) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 28) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 29) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 30) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 31) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 32) {
						return 0;
					}
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}

					std::list<Trainer>::reverse_iterator revItTrainer;
					for (revItTrainer = trainersForMap.rbegin(); revItTrainer != trainersForMap.rend(); revItTrainer++)
					{
						if (revItTrainer->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}
				}
				else {
					return 0;
				}
			}
			return 1;
		}

		else if (strcmp(keyPressed, "a") == 0) {
			if (directionX == -1) {
				if (xTile - 1 >= 0) {
					if (textMap[xTile-1][tempYTile] == 0) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 1) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 10) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 11) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 12) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 13) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 14) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 23) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 24) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 25) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 26) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 27) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 28) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 29) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 30) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 31) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 32) {
						return 0;
					}
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}

					std::list<Trainer>::reverse_iterator revItTrainer;
					for (revItTrainer = trainersForMap.rbegin(); revItTrainer != trainersForMap.rend(); revItTrainer++)
					{
						if (revItTrainer->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}
				}
				else {
					return 0;
				}
			}
			return 1;
		}

		else if (strcmp(keyPressed, "d") == 0) {

			if (directionX == 1) {
				if (xTile +1 < mapSizeX) {
					if (textMap[xTile + 1][tempYTile] == 0 ) {
						return 0;
					}else if (textMap[xTile + 1][tempYTile] == 1 ) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 10) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 11) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 12) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 13) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 14) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 23) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 24) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 25) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 26) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 27) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 28) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 29) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 30) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 31) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 31) {
						return 0;
					}
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}

					std::list<Trainer>::reverse_iterator revItTrainer;
					for (revItTrainer = trainersForMap.rbegin(); revItTrainer != trainersForMap.rend(); revItTrainer++)
					{
						if (revItTrainer->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
							return 0;
						}

					}
				}
				else {
					return 0;
				}
			}
			return 1;

		}
		return 0;
	}

	// Lopads the map from the file name
	void loadMap(const char * filename) {
		ifstream openfile(filename);
		// Opens the file
		if (openfile.is_open()) {
			while (!openfile.eof()) {
				if (once == false) {
					// Sets the sizes
					openfile >> mapSizeX >> mapSizeY;
					once = true;
				}
				// puts the value into text map
				openfile >> textMap[loadCounterX][loadCounterY];
				loadCounterX++;
				if (loadCounterX >= mapSizeX) {
					loadCounterX = 0;
					loadCounterY++;
				}
			}
		}
		else {
			cout << "\nfile not open\n";
		}

	}

	// returns the player back to the closest heal when dead
	void returnPlayerToClosestHeal(PlayerCharacter &player) {
		for (int i = 0; i < player.numberOfPokemonInParty; i++)
		{
			player.trainersParty[i].healPokemonToFull();
		}
		player.setAllPositions(closestHealLocation[0], closestHealLocation[1]);
	}

	// Checks through the trainers to see if the player is within their line of sight
	// Initiates battle if true
	bool checkForTrainerBattle(PlayerCharacter& player, ALLEGRO_EVENT_QUEUE* queue){

		for (Trainer& trainer : trainersForMap)
		{
			if (trainer.isInLineOfSight(player.xTilePosition, player.yTilePosition)) {
				
				trainer.displayTextBox(player.xPosition - (screenWidth / 4), player.yPosition + 170, screenWidth, screenHeight, queue);
				if (trainer.isBattlingTrainer) {
					InitiateBattle initiateBattle = InitiateBattle(trainer, screenWidth, screenHeight, queue, player, trainer.locationNumber);
				}

				if (!player.isAllPokemonInPartyDead() && trainer.isAllPokemonInPartyDead()) {
					trainer.hasBeenFought = true;
				}
				else if(player.isAllPokemonInPartyDead())
				{
					returnPlayerToClosestHeal(player);
				}
				
				return true;

			}
		}
		return false;
	}

	// returns what tile the player is standing on
	int getWhatPlayerIsStandingOn(int xTile, int yTile) {

		int tempYTile = yTile + 1;
		int tile = 0;
		if (xTile >= 0 && xTile <= screenWidth && tempYTile >= 0 && tempYTile <= screenHeight) {
			tile = textMap[xTile][tempYTile];
		}
		else {
			tile = 0;
		}
		// cout << "Player on : " << tile << "at : " << xTile << "," << yTile << " .\n";
		return tile;
	}



	// Draws the different parts of the map
	// AS well as interactbales and trainers
	void drawMap() {

		for (int i = 0; i < mapSizeX; i++)
		{
			for (int j = 0; j < mapSizeY; j++)
			{
				if (textMap[i][j] == 0 || textMap[i][j] == 1 || textMap[i][j] == 2 || textMap[i][j] == 0 || textMap[i][j] == 9 || textMap[i][j] == 17 || textMap[i][j] == 18 || textMap[i][j] == 33) {

				}else if (textMap[i][j] == 10){
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 85, 82, (i*32), (j *32), (32 * 5), (32 * 4), 0);
				}
				else if (textMap[i][j] == 11) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 86, 65, (i * 32), (j * 32), ( 32 * 5), ( 32 * 4), 0);
				}
				else if (textMap[i][j] == 12) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 65, 104, (i * 32), (j * 32), (32 * 2), (32 * 3), 0);
				}
				else if (textMap[i][j] == 14) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 73, 80, (i * 32), (j * 32), (32 * 5), (32 * 4), 0);
				}
				else if (textMap[i][j] == 15) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 176, 135, (0), (0), (32 * 16), (32 * 12), 0);
				}
				else if (textMap[i][j] == 19) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 254, 189, (0), (0), (32 * 13), (32 * 10), 0);
				}
				else if (textMap[i][j] == 20) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 159, 145, (0), (0), (32 * 12), (32 * 8), 0);
				}
				else if (textMap[i][j] == 32) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 100, 93, (i * 32), (j * 32), (32 * 5), (32 * 4), 0);
				}
				else if (textMap[i][j] == 34) {
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 278, 368, (i * 32), (j * 32), (32 * 17), (32 * 21), 0);
				}
				else {
					al_draw_bitmap(mapTiles[textMap[i][j]], i * 32, j * 32, 0);
				}
				
			}
		}

		std::list<Interactable>::reverse_iterator revIt;
		for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
		{
			revIt->drawSprite();

		}

		std::list<Trainer>::reverse_iterator revItTrainer;
		for (revItTrainer = trainersForMap.rbegin(); revItTrainer != trainersForMap.rend(); revItTrainer++)
		{
			revItTrainer->drawSprite();

		}

		
		
		
	}


	
};