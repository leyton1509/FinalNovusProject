#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "Pokemon/PokemonManager.cpp"
#include "Sprites/PlayerCharacter.cpp"

#include <iostream>  
#include "WorldMap/WorldMap.cpp"


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

    ALLEGRO_DISPLAY* disp = al_create_display(1200, 800);
    must_init(disp, "display");

    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");
    //ALLEGRO_BITMAP* mysha = al_load_bitmap("Sprites/PlayerSprites/PlayerCharacterSpriteSheet.png");
    //must_init(mysha, "mysha");

    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    double xMousePosition = 0;
    double yMousePosition = 0;

    
    PlayerCharacter player = PlayerCharacter();
    WorldMap worldMap = WorldMap();

    al_start_timer(timer);
    while (1)
    {
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
            break;


        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_W) {
                player.moveCharacter("w");
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_S) {
                player.moveCharacter("s");
   
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_A) {
                player.moveCharacter("a");
     
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_D) {
                player.moveCharacter("d");
            
            }
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
           
            al_clear_to_color(al_map_rgb(0, 0, 0));
            //al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");

            //al_draw_bitmap(mysha, 100, 100, 0);

            worldMap.drawMap();

            player.drawSprite();

            al_flip_display();

            redraw = false;
        }

    }


    al_destroy_bitmap(player.spriteImage);
    al_uninstall_keyboard();
    //al_destroy_bitmap(mysha);
    al_destroy_font(font);
    al_ungrab_mouse();
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}