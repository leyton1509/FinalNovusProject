#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "Pokemon/PokemonManager.cpp"
#include "Sprites/PlayerCharacter.h"

#include <iostream>  
#include "WorldMap/WorldMap.h"
#include "TitleScreen/TitleScreenHeader.h"

int screenWidth = 900;
int screenHeight = 600;


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

void cameraUpdate(float * cameraPosition, float x, float y, int width, int height) {
    /*

    if (x > screenWidth * 0.7) {
        cameraPosition[0] = -(cameraPosition[0] + x + (width));
    }
    else if (x < screenWidth * 0.3) {
        cameraPosition[0] = -(cameraPosition[0] - x -(width));
    }
    else if (y < screenHeight * 0.3) {
        cameraPosition[1] = -(cameraPosition[1] + y + (height));
    }
    else if (y > screenHeight * 0.7) {
        cameraPosition[1] = -(cameraPosition[1] -y- (height));
    }
    */
    
        
     cameraPosition[0] = -(screenWidth / 2) + (x + (width / 2));
     cameraPosition[1] = -(screenHeight / 2) + (y + (height / 2));
    
   
}

int main()
{
   
// charizard.printMonsterDetails();
// The first two are the position in the file, x -> y, then width and height, then x pos y pos, then another 0?
//al_draw_bitmap_region(playerTest, 0, 0, 64, 64, 100, 100, 0);

    


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
    //player.xPosition = screenWidth / 2;
    //player.yPosition = screenHeight / 2;
    player.setAllPositions(0, 0);
    WorldMap worldMap = WorldMap(screenWidth, screenHeight);
    float cameraPosition[2] = { 0,0 };


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


        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_W) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                int canPlayerMove = worldMap.canPlayerMove("w", player.directionX, player.directionY);
                if (canPlayerMove == 1) {
                    player.moveCharacter("w");
                }
               
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_S) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                player.moveCharacter("s");

            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_A) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                player.moveCharacter("a");

            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_D) {
                int tilePlayerIsStandingOn = worldMap.getWhatPlayerIsStandingOn(player.xTilePosition, player.yTilePosition);
                player.moveCharacter("d");

            }
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {

            al_clear_to_color(al_map_rgb(0, 0, 0));

            worldMap.drawMap(player.xPosition, player.yPosition);
            player.drawSprite();



            cameraUpdate(cameraPosition, player.xPosition, player.yPosition, player.spritewidth, player.spriteHeight);
            al_identity_transform(&camera);
            al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
            al_use_transform(&camera);

            al_flip_display();

            redraw = false;
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