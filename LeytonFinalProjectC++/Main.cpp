#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>


#include "Pokemon/PokemonManager.h"
#include "Sprites/PlayerCharacter.h"
#include "Pokemon/Moves/MoveManager.h"
#include <iostream>  
#include "WorldMap/WorldMap.h"
#include "TitleScreen/TitleScreenHeader.h"
#include "Battle/InitiateBattle.h"
#include "Pokemon/PokemonTypeChart.h"



int screenWidth = 900;
int screenHeight = 600;
bool initalisedCamera = false;

//MonsterManager availableMonsters;

//Monster charizard = availableMonsters.getDefaultMonster("Charizard");
// charizard.printMonsterDetails();
// The first two are the position in the file, x -> y, then width and height, then x pos y pos, then another 0?
//al_draw_bitmap_region(playerTest, 0, 0, 64, 64, 100, 100, 0);

void must_init(bool test, const char* description)
{
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

void cameraUpdate(float* cameraPosition, float x, float y, int width, int height) {
    
    if (!initalisedCamera) {
        cameraPosition[0] = -(screenWidth / 2) + (x + (width / 2));
        cameraPosition[1] = -(screenHeight / 2) + (y + (height / 2));
        initalisedCamera = true;
        cout << "in\n";
    }
    /*
    
    if (x > screenWidth * 0.8) {
        cameraPosition[0] = -(screenWidth / 2) + (x +32);
    }
    else if (x < screenWidth * 0.2) {
        cameraPosition[0] = -(screenWidth / 2) + (x-32);
    }
    }

    if (y < screenHeight * 0.2) {
        cameraPosition[1] = -(screenHeight / 2) + (y + 32);
    }
    else if (y > screenHeight * 0.2) {
        cameraPosition[1] = -(screenHeight / 2) + (y -32);
    }
    */
    cameraPosition[0] = -(screenWidth / 2) + (x + (width / 2));
    cameraPosition[1] = -(screenHeight / 2) + (y + (height / 2));
    


    //cameraPosition[0] = -(screenWidth / 2) + (x + (width / 2));
    //cameraPosition[1] = -(screenHeight / 2) + (y + (height / 2));

}


int main()
{

 
    PokemonManager pm = pm.instance();
   

    

    
  
    


    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_mouse(), "mouse");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    ALLEGRO_DISPLAY* disp = al_create_display(screenWidth, screenHeight);
    must_init(disp, "display");

    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_font_addon(), "fonts");

    must_init(al_init_ttf_addon(), "ttfs");

    must_init(al_init_image_addon(), "image addon");

    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    
    ALLEGRO_TRANSFORM camera;

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    TitleScreen gameTitleScreen = TitleScreen(screenWidth, screenHeight);

    bool runTitleScreen = true;
    bool runOverWorld = false;
    bool newGame = false;
    double xMousePosition = 0;
    double yMousePosition = 0;



    al_start_timer(timer);
    ////////////////////////////////////////////////

    while (runTitleScreen) {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {

        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;

            // Handle mouse movement
        case ALLEGRO_EVENT_MOUSE_AXES:
            xMousePosition = event.mouse.x;
            yMousePosition = event.mouse.y;
            break;

            // Handle mouse click
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if (gameTitleScreen.hasClicked = true) {
                int resultOfClick = gameTitleScreen.handleButtonClick(xMousePosition, yMousePosition);
                if (resultOfClick == 1) {
                    cout << "Clicked :" << resultOfClick << " at " << xMousePosition << " " << yMousePosition << "\n";
                    runTitleScreen = false;
                    newGame = true;
                    runOverWorld = true;
                }
                else if (resultOfClick == 2) {
                    cout << "Clicked :" << resultOfClick << " at " << xMousePosition << " " << yMousePosition << "\n";
                    runTitleScreen = false;
                    newGame = false;
                    runOverWorld = true;
                }
            }
            gameTitleScreen.hasClicked = true;
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;

        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            gameTitleScreen.drawScreen();

            al_flip_display();
            redraw = false;
        }

    }

    gameTitleScreen.destroyAllSprites();


    ////////////////////////////////////////////////

    PlayerCharacter player = PlayerCharacter();
    player.addPokemon(pm.getDefaultPokemon("Groudon"));
    player.addPokemon(pm.getDefaultPokemon("Kyogre"));
    
    player.trainersParty[0].setPokemonsLevel(1);
    player.trainersParty[1].setPokemonsLevel(25);
    //player.xPosition = screenWidth / 2;
    //player.yPosition = screenHeight / 2;
    player.setAllPositions(13, 10);
    WorldMap worldMap = WorldMap(screenWidth, screenHeight, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt", 1);
    float cameraPosition[2] = { 0,0 };

    int framecounter = 1;
    // w a s d e
    bool keys[5] = {false, false ,false ,false, false};

    while (runOverWorld) {

        al_wait_for_event(queue, &event);

        switch (event.type)
        {

        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;

            // Handle mouse movement
        case ALLEGRO_EVENT_MOUSE_AXES:
            xMousePosition = event.mouse.x;
            yMousePosition = event.mouse.y;
            break;

            // Handle mouse click
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            break;


        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            runOverWorld = false;
            break;

        case ALLEGRO_EVENT_KEY_UP:
            if (event.keyboard.keycode == ALLEGRO_KEY_W) {
                keys[0] = false;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_S) {
                keys[1] = false;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_A) {
                keys[2] = false;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_D) {
                keys[3] = false;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_E) {
                keys[4] = false;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_W) {
                keys[0] = true;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_S) {
                keys[1] = true;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_A) {
                keys[2] = true;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_D) {
                keys[3] = true;
            }

            else if (event.keyboard.keycode == ALLEGRO_KEY_E) {
                keys[4] = true;

            }
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {

            if (keys[4]) {
                
                if (player.directionY == 1) {
                    int interacted = worldMap.interact(player, queue, "w", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition, screenWidth, screenHeight);
                    keys[4] = false;
                    if (interacted) {
                        keys[0] = false;
                        keys[1] = false;
                        keys[2] = false;
                        keys[3] = false;
                        keys[4] = false;
                    }
                }
                else if (player.directionY == -1) {
                    int interacted = worldMap.interact(player, queue, "s", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition, screenWidth, screenHeight);
                    keys[4] = false;
                    if (interacted) {
                        keys[0] = false;
                        keys[1] = false;
                        keys[2] = false;
                        keys[3] = false;
                    }

                }

                else if (player.directionX == -1) {
                   int interacted = worldMap.interact(player, queue, "a", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition, screenWidth, screenHeight);
                    keys[4] = false;
                    if (interacted) {
                        keys[0] = false;
                        keys[1] = false;
                        keys[2] = false;
                        keys[3] = false;
                    }

                }
                else if (player.directionX == 1) {
                    int interacted = worldMap.interact(player, queue, "d", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition, screenWidth, screenHeight);
                    keys[4] = false;
                    if (interacted) {
                        keys[0] = false;
                        keys[1] = false;
                        keys[2] = false;
                        keys[3] = false;
                    }

                }
            }

            else if (keys[0] && !keys[1] && !keys[2] && !keys[3]) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                int canPlayerMove = worldMap.canPlayerMove("w", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition);
                if (canPlayerMove == 1) {
                    player.moveCharacter("w");
                }
            } else if (keys[1] && !keys[0] && !keys[2] && !keys[3]) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                int canPlayerMove = worldMap.canPlayerMove("s", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition);
                if (canPlayerMove == 1) {
                    player.moveCharacter("s");
                }
            }
            else if (keys[2] && !keys[1] && !keys[0] && !keys[3]) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                int canPlayerMove = worldMap.canPlayerMove("a", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition);
                if (canPlayerMove == 1) {
                    player.moveCharacter("a");
                }
            }
            else if (keys[3] && !keys[1] && !keys[2] && !keys[0]) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                int canPlayerMove = worldMap.canPlayerMove("d", player.directionX, player.directionY, player.xTilePosition, player.yTilePosition);
                if (canPlayerMove == 1) {
                    player.moveCharacter("d");
                }
            }

            al_clear_to_color(al_map_rgb(0, 0, 0));

            worldMap.drawMap();
            player.drawSprite();
            worldMap.checkToChangeMaps(player);

            if (framecounter == 3) {

                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                if (tilePlayerIsStandingOn == 6 || tilePlayerIsStandingOn == 7 || tilePlayerIsStandingOn == 8) {
                    if (!player.isTheSameSquareAsLastEncounter()) {
                        int encounterRan =  (rand() % 3) + 1;
                        if (encounterRan == 2) {
                            keys[0] = false;
                            keys[1] = false;
                            keys[2] = false;
                            keys[3] = false;
                            keys[4] = false;
                            InitiateBattle initiateBattle = InitiateBattle(screenWidth, screenHeight, queue, player, worldMap.locationNumber, worldMap.routeNumber);
                            if (player.isAllPokemonInPartyDead()) {
                                worldMap.returnPlayerToClosestHeal(player);
                                player.resetPlayer(player.xTilePosition, player.yTilePosition);
                            }
                            else {
                                player.setNewEncounterLocation();
                            }
                        }
                        
                    }
                }
                
            }
            else if (framecounter == 19 || framecounter == 39 || framecounter == 59) {
               bool battleHappened = worldMap.checkForTrainerBattle(player, queue);
               if (battleHappened) {
                   keys[0] = false;
                   keys[1] = false;
                   keys[2] = false;
                   keys[3] = false;
                   keys[4] = false;
               }
            }

            cameraUpdate(cameraPosition, player.xPosition, player.yPosition, player.spritewidth, player.spriteHeight);
            al_identity_transform(&camera);
            al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
            al_use_transform(&camera);

            al_flip_display();

            redraw = false;
        }

        if (framecounter == 60) {
            framecounter = 1;
        }
        else {
            framecounter++;
        }

        
    }

    //////////////////////////////////////////



    worldMap.destroyAllSprites();

    al_destroy_bitmap(player.spriteImage);
    al_uninstall_keyboard();
    al_destroy_font(font);
    al_ungrab_mouse();
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}