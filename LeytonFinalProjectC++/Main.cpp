#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include "MonsterManager.cpp"
#include <iostream>  
using namespace sf;

int main()
{

  // MonsterManager availableMonsters;

  //Monster charizard = availableMonsters.getDefaultMonster("Charizard");
  //charizard.printMonsterDetails();

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
    ALLEGRO_FONT* font = al_create_builtin_font();


    // Register what events im interested in
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    return 0;
}