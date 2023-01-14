#include <fstream>
#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "../Sprites/PokemonGrass.cpp"
using namespace std;
class WorldMap {


public:

	ALLEGRO_BITMAP* mapBuffer = al_create_bitmap(1200, 800);
	ALLEGRO_BITMAP* mapTiles[2];

	int textMap[100][100];
	int loadCounterX = 0;
	int loadCounterY = 0;
	int mapSizeX = 0;
	int mapSizeY = 0;
	bool once = false;

	WorldMap() {
		PokemonGrass grass;
		mapTiles[0] = al_load_bitmap("C:/Users/Owner/source/repos/FinalNovusProject/LeytonFinalProjectC++/Sprites/MapSprites/BlackSquare.png");
		mapTiles[1] = grass.spriteImage;
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

	void drawMap() {
		for (int i = 0; i < mapSizeX; i++)
		{
			for (int j = 0; j < mapSizeY; j++)
			{
				al_draw_bitmap(mapTiles[textMap[i][j]], i*32, j*32, 0);
			}

		}
	}


	
};