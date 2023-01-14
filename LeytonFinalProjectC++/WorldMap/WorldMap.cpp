#include <fstream>
#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/PokemonGrass.cpp"
using namespace std;
class WorldMap {


public:

	ALLEGRO_BITMAP* mapBuffer;;
	ALLEGRO_BITMAP* mapTiles[3];

	int textMap[100][100];
	int loadCounterX = 0;
	int loadCounterY = 0;
	int mapSizeX = 0;
	int mapSizeY = 0;
	bool once = false;

	WorldMap(int screenWidth, int screenHeight) {
		mapBuffer = al_create_bitmap(screenWidth, screenHeight);
		PokemonGrass grass;
		mapTiles[0] = al_load_bitmap("C:/Users/Owner/source/repos/FinalNovusProject/LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		mapTiles[1] = al_load_bitmap("C:/Users/Owner/source/repos/FinalNovusProject/LeytonFinalProjectC++/Sprites/MapSprites/PlainColourGreen.png");
		mapTiles[2] = grass.spriteImage;
		cout << grass.spriteImage << " ";
		loadMap("C:/Users/Owner/source/repos/FinalNovusProject/LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt");
		cout << mapSizeX << " " << mapSizeY << " \nloaded map\n";
	}

	void loadMap(const char * filename) {
		cout << filename << "";
		ifstream openfile(filename);
		if (openfile.is_open()) {
			cout << "file open \n";
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

	void drawMap(int xPositionOfPlayer, int yPositionOfPlayer) {

		cout << "X:" << xPositionOfPlayer << " , Y:" << yPositionOfPlayer << " \n";

		for (int i = xPositionOfPlayer - 50; i < xPositionOfPlayer + 50; i++)
		{
			for (int j = yPositionOfPlayer - 25; j < yPositionOfPlayer + 25; j++)
			{
				if (i > 0 && i < mapSizeX && j > 0 && j < mapSizeY) {

					// al_draw_bitmap(mapTiles[textMap[i][j]],  i /32 * 32 , j / 32 * 32,0);
					//al_draw_bitmap(mapTiles[1], i * 32, j * 32, 0);
				}
				
			}

		}


		//for (int i = 0; i < mapSizeX; i++)
		//{
		//	for (int j = 0; j < mapSizeY; j++)
		//	{
		//		al_draw_bitmap(mapTiles[textMap[i][j]], i*32, j*32, 0);
		//	}
		//}
	}


	
};