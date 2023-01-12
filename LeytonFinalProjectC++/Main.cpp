#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "Pokemon/MonsterManager.cpp"
#include <iostream>  

int main()
{

  MonsterManager availableMonsters;

  Monster charizard = availableMonsters.getDefaultMonster("Charizard");
  charizard.printMonsterDetails();

   // std::cout << charizard.monsterName << " " << charizard.physcialAttackBase << " " << charizard.healthBase << "\n";

    // Sets up the bare essentials
    al_init();
    // Enables keyboard inputs
    al_install_keyboard();

    // Timer and event queue to make sure 
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

    // Display with witdth * height
    ALLEGRO_DISPLAY* disp = al_create_display(1200, 800);

    // Changes font
    //ALLEGRO_FONT* font = al_create_builtin_font();


    // Register what events im interested in
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));


    al_start_timer(timer);

    if (!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
        return 1;
    }

    ALLEGRO_BITMAP* playerTest = al_load_bitmap("Assets/PlayerCharacterSpriteSheet.png");
    if (!playerTest)
    {
        printf("couldn't load mysha\n");
        return 1;
    }

    while (1)
    {

        bool redraw = true;
        ALLEGRO_EVENT event;

        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if ((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;


        


        if (redraw && al_is_event_queue_empty(queue))
        {
            // Sets screen to black
            al_clear_to_color(al_map_rgb(0, 0, 0));
            // Draws tge text in top left 
            //al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
            // Commits results
            // The first two are the position in the file, x -> y, then width and height, then x pos y pos, then another 0?
            al_draw_bitmap_region(playerTest, 0, 0, 64, 64, 100,100,0);
            al_flip_display();
            redraw = false;
        }
    }

    al_destroy_bitmap(playerTest);
    //al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}