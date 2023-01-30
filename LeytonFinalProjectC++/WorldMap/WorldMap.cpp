#include <fstream>
#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/PokemonGrass.cpp"
#include "../Sprites/PlayerCharacter.h"
#include "../Sprites/InteractablesForMaps.h"
#include <list>
using namespace std;
class WorldMap {


public:

	ALLEGRO_BITMAP* mapBuffer;
	ALLEGRO_BITMAP* mapTiles[25];

	std::list<Interactable> interactablesForMap;

	int textMap[100][100];
	int loadCounterX = 0;
	int loadCounterY = 0;
	int mapSizeX = 0;
	int mapSizeY = 0;
	bool once = false;
	int screenWidth;
	int screenHeight;
	int locationNumber = 0;
	int mapNumber;
	int previousTileLocation[2];
	int closestHealLocation[2];


	WorldMap(int _screenWidth, int _screenHeight, const char * mapFP, int _mapNumber) {
		cout << "Creating new world map\n";
		screenWidth = _screenWidth;
		screenHeight = _screenHeight;
		mapBuffer = al_create_bitmap(screenWidth, screenHeight);
		PokemonGrass grass = PokemonGrass();
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
		mapTiles[6] = grass.spriteImage;
		// Pokemon Grass reserved for different sprite
		mapTiles[7] = grass.spriteImage;
		// Pokemon Grass reserved for different sprite
		mapTiles[8] = grass.spriteImage;
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
		mapNumber = mapNumber;
		previousTileLocation[0] = 0;
		previousTileLocation[1] = 0;
		InteractablesForMaps im;
		interactablesForMap = im.getInteractablesForMap(_mapNumber);
		loadMap(mapFP);
		
	}

	void destroyAllSprites() {

		
	}



	int interact(PlayerCharacter& player, ALLEGRO_EVENT_QUEUE* queue, const char* keyPressed, int directionX, int directionY, int xTile, int yTile, int screenWidth, int screenHeight) {

		for (Interactable& inter : interactablesForMap)
		{
			if (inter.idOfInteractable == 1) {

				if (inter.isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
					inter.interact(player, queue,  screenWidth,  screenHeight);
					return 1;
				}

			}

		}

		return 0;
	}

	void checkToChangeMaps(PlayerCharacter& player) {
		int tile = getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
		if (tile == 9) {
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			previousTileLocation[0] = player.xTilePosition;
			previousTileLocation[1] = (player.yTilePosition) +1;
			player.resetPlayer(7, 10);
			loadMap("../LeytonFinalProjectC++/WorldMap/TextMaps/BasicHouseMap.txt");
			mapNumber = 10;
		}
		else if (tile == 16) {
			once = false;
			loadCounterX = 0;
			loadCounterY = 0;
			player.resetPlayer(previousTileLocation[0], previousTileLocation[1]);
			loadMap("../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt");
			mapNumber = 1;
		}
	}




	int canPlayerMove(const char* keyPressed, int directionX, int directionY, int xTile, int yTile) {
		int tempYTile = yTile + 1;
		
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
					else if (textMap[xTile][tempYTile - 1] == 12) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 13) {
						return 0;
					}
					else if (textMap[xTile][tempYTile - 1] == 14) {
						return 0;
					}
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
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
					else if (textMap[xTile][tempYTile + 1] == 12) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 13) {
						return 0;
					}
					else if (textMap[xTile][tempYTile + 1] == 14) {
						return 0;
					}
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
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
					else if (textMap[xTile - 1][tempYTile] == 12) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 13) {
						return 0;
					}
					else if (textMap[xTile - 1][tempYTile] == 14) {
						return 0;
					}
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
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
					else if (textMap[xTile + 1][tempYTile] == 12) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 13) {
						return 0;
					}
					else if (textMap[xTile + 1][tempYTile] == 14) {
						return 0;
					}
					std::list<Interactable>::reverse_iterator revIt;
					for (revIt = interactablesForMap.rbegin(); revIt != interactablesForMap.rend(); revIt++)
					{
						if (revIt->isInteracting(keyPressed, xTile, yTile, directionX, directionY, mapSizeX, mapSizeY)) {
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


	void loadMap(const char * filename) {
		ifstream openfile(filename);
		if (openfile.is_open()) {
			while (!openfile.eof()) {
				if (once == false) {
					openfile >> mapSizeX >> mapSizeY;
					once = true;
				}
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

	void returnPlayerToClosestHeal(PlayerCharacter &player) {

	}



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




	void drawMap() {

		// cout << "X : " << xPosition / 32 << " Y : " << yPosition / 32 << " Tile N : " << getWhatPlayerIsStandingOn(xPosition / 32, yPosition / 32) << "\n";

		for (int i = 0; i < mapSizeX; i++)
		{
			for (int j = 0; j < mapSizeY; j++)
			{
				if (textMap[i][j] == 1 || textMap[i][j] == 2 || textMap[i][j] == 0 || textMap[i][j] == 9) {

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

		
		
		
	}


	
};