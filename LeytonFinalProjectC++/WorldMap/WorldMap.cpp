#include <fstream>
#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/PokemonGrass.cpp"
#include "../Sprites/PlayerCharacter.h"
using namespace std;
class WorldMap {


public:

	ALLEGRO_BITMAP* mapBuffer;
	ALLEGRO_BITMAP* mapTiles[15];

	int textMap[100][100];
	int xBorderSize = 15;
	int yBorderSize = 15;
	int loadCounterX = 0;
	int loadCounterY = 0;
	int mapSizeX = 0;
	int mapSizeY = 0;
	bool once = false;
	int screenWidth;
	int screenHeight;
	int locationNumber = 0;


	WorldMap(int _screenWidth, int _screenHeight) {
		cout << "Creating new world map\n";
		screenWidth = _screenWidth;
		screenHeight = _screenHeight;
		mapBuffer = al_create_bitmap(screenWidth, screenHeight);
		PokemonGrass grass = PokemonGrass();
		mapTiles[0] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		mapTiles[1] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		mapTiles[2] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		mapTiles[3] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		mapTiles[4] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		mapTiles[5] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		mapTiles[6] = grass.spriteImage;
		mapTiles[7] = grass.spriteImage;
		mapTiles[8] = grass.spriteImage;
		mapTiles[9] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		mapTiles[10] = al_load_bitmap("../LeytonFinalProjectC++/Sprites/MapSprites/PokemonCentre.png");
		cout << grass.spriteImage << " Grass sprite \n";
		loadMap("../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt");
		cout << mapSizeX << " " << mapSizeY << " \nloaded map\n";
	}

	void destroyAllSprites() {

		
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
				}
				else {
					return 0;
				}
			}
			return 1;

		}

	}


	void loadMap(const char * filename) {
		cout << filename << "";
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



	int getWhatPlayerIsStandingOn(int xTile, int yTile) {

		int tempYTile = yTile + 1;
		int tile = 0;
		if (xTile >= 0 && xTile <= screenWidth && tempYTile >= 0 && tempYTile <= screenHeight) {
			tile = textMap[xTile][tempYTile];
		}
		else {
			tile = 0;
		}
		cout << "Player on : " << tile << "at : " << xTile << "," << yTile << " .\n";
		return tile;
	}




	void drawMap(float xPosition, float yPosition) {

		for (int i = 0; i < mapSizeX; i++)
		{
			for (int j = 0; j < mapSizeY; j++)
			{
				if (textMap[i][j] == 1 || textMap[i][j] == 2 || textMap[i][j] == 0 || textMap[i][j] == 9) {

				}else if (textMap[i][j] == 10){
					al_draw_scaled_bitmap(mapTiles[textMap[i][j]], 0, 0, 85, 82, i*32, j *32, i * 32 * 5, j * 32 * 4, 0);
				}
				else {
					al_draw_bitmap(mapTiles[textMap[i][j]], i * 32, j * 32, 0);
				}
				
			}
		}
	}


	
};