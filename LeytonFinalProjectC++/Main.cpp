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


// The width of the screen
int screenWidth = 900;
// The height of the screen
int screenHeight = 600;
// If the camera has been initialised
bool initalisedCamera = false;

// A must init function that ensures a certain module is initialised
void must_init(bool test, const char* description)
{
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

// Updates the camera based on the position of the player
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

    // Sets up the pokemon in pokemon manager
    PokemonManager pm = pm.instance();
 
    // Inits allegro, keyboard and mouse
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_mouse(), "mouse");

    // Initialise the timer
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");

    // Initialise the queue
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    // Initialise the display
    ALLEGRO_DISPLAY* disp = al_create_display(screenWidth, screenHeight);
    must_init(disp, "display");

    // Initialse primitives
    must_init(al_init_primitives_addon(), "primitives");

    // Initialise fonts
    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    // Has to initialse addons for fonts, ttfs and images
    must_init(al_init_font_addon(), "fonts");
    must_init(al_init_ttf_addon(), "ttfs");
    must_init(al_init_image_addon(), "image addon");

    // Adds the mouse, keyboard, display and timer events
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    // The camera
    ALLEGRO_TRANSFORM camera;

    // Simple GUI info
    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    // Title screen class
    TitleScreen gameTitleScreen = TitleScreen(screenWidth, screenHeight);
    //Whether to run title screen
    bool runTitleScreen = true;
    //Whether to run overworld screen
    bool runOverWorld = false;
    // If its a new game
    bool newGame = false;
    // Mouse position
    double xMousePosition = 0;
    double yMousePosition = 0;

    // Start the timer
    al_start_timer(timer);
    ////////////////////////////////////////////////

    // Title screen loop
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
            // Checks to see if the has clicked for title screen has been clicked
            // Checks to see its load or new game when clicked again
            if (gameTitleScreen.hasClicked = true) {
                int resultOfClick = gameTitleScreen.handleButtonClick(xMousePosition, yMousePosition);
                if (resultOfClick == 1) {
                    runTitleScreen = false;
                    newGame = true;
                    runOverWorld = true;
                }
                else if (resultOfClick == 2) {
                    runTitleScreen = false;
                    newGame = false;
                    runOverWorld = true;
                }
            }
            gameTitleScreen.hasClicked = true;
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            // Finishes the loop upon close
            done = true;
            break;
        }

        if (done)
            break;

        // Draw loop
        // Draws the title screen
        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            gameTitleScreen.drawScreen();
            al_flip_display();
            redraw = false;
        }

    }

    // Destroys the sprites for the title screen

    gameTitleScreen.destroyAllSprites();

    ////////////////////////////////////////////////

    // The player character 
    PlayerCharacter player = PlayerCharacter();

    // Add any test pokemon here, can be removed later
    player.addPokemon(pm.getDefaultPokemon("Groudon"));
    player.addPokemon(pm.getDefaultPokemon("Kyogre"));
    player.trainersParty[0].setPokemonsLevel(1);
    player.trainersParty[1].setPokemonsLevel(25);

    // Sets the players pos position
    player.setAllPositions(13, 10);
    // Creates a world map, with height width and text file name
    WorldMap worldMap = WorldMap(screenWidth, screenHeight, "../LeytonFinalProjectC++/WorldMap/TextMaps/MapOne.txt", 1);
    // Creates a camera position at 0,0
    float cameraPosition[2] = { 0,0 };
    // How many frames have passed
    int framecounter = 1;
    // Keys array for different key presses
    // w a s d e
    bool keys[5] = {false, false ,false ,false, false};

    // Runs while the run overworld option is true
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

            // Sets the done to true when closed
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            runOverWorld = false;
            break;

        case ALLEGRO_EVENT_KEY_UP:
            // Upon key up, set the key in the array to false
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
            // Upon key down, set the key in the array to true
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

        // Break if done
        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            // Checks for interaction
            if (keys[4]) {
                
                // Has the different checks for the interactions based on the players direction
                // Passed in the player, queue, key pressed, player position information and screen size
                // Does this for each direction
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

            // If not interacting, checks to see if w a s d has been pressed
            // gets the tile the playerr is standing on - can be removed
            /// Checks to see if the player can move and if they can calls player. move character based on their direction and tile
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

            // Clears the background
            al_clear_to_color(al_map_rgb(0, 0, 0));

            // Drwas the map first
            worldMap.drawMap();
            // Then the player
            player.drawSprite();
            // Checks to see if the player has walked onto a change map tile
            worldMap.checkToChangeMaps(player);

            // On the third frame of every turn
            // Check to see if the player is on pokemon grass
            // Generates a random number if they are and if the num is 2 initate a wild pokemon battle
            // Based on the location
            // Sets the keys to false to make sure the player isnt moving after battle
            // Sets the new encounter location
            // If all the pokemon are dead it returns the player to the nearest heal spot
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
            // On frames 19, 39 and 59, check to see if a player walks in front of any of the trainers on the map
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

            // Updates the camera based on player position

            cameraUpdate(cameraPosition, player.xPosition, player.yPosition, player.spritewidth, player.spriteHeight);
            al_identity_transform(&camera);
            al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
            al_use_transform(&camera);

            // Must call flip display
            al_flip_display();
            // Redraw false when completed
            redraw = false;
        }

        // If it gets to frame 60, set it back to frame 1 otherwise ++
        if (framecounter == 60) {
            framecounter = 1;
        }
        else {
            framecounter++;
        }

        
    }

    //////////////////////////////////////////


    // Destroy all sprites on map
    worldMap.destroyAllSprites();

    // Destroy the player image 
    // Drop controls of move and keyboard
    // Clean up queues
    al_destroy_bitmap(player.spriteImage);
    al_uninstall_keyboard();
    al_destroy_font(font);
    al_ungrab_mouse();
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}