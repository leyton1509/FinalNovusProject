#include "../Sprites/PlayerCharacter.h"
#include "../Pokemon/PokemonManager.h"
#include "../Sprites/Button.h"
#include "../Sprites/AttackButton.h"
#include "../Sprites/PokemonStatBox.h"
#include "../Battle/PokemonTurn.h"
#include "../Battle/RouteMapping.h"
#include "../Sprites/SwitchPokemonButton.h"

// Class when a pokemon battke is needed
class InitiateBattle {

public:

	// Mouse positions
	double xMousePosition = 0;
	double yMousePosition = 0;

	// GUI info
	bool done = false;
	bool redraw = true;

	// Takes the screen size and the queue for inputs, the current player and the current location, and what type of battle it is
	InitiateBattle(int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue, PlayerCharacter& player, int locationNumber, int battleType) {

		
		ALLEGRO_EVENT event;

		// BG sprite
		ALLEGRO_BITMAP * background = al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Beach.jpg");

		// Reset the camera
		ALLEGRO_TRANSFORM trans;
		al_identity_transform(&trans);
		al_use_transform(&trans);
		al_draw_bitmap(background, 0, 0, 0);

		// Sprites for the pokemon
		ALLEGRO_BITMAP * otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");
		ALLEGRO_BITMAP * trainsersPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/backSprites.png");

		// Get the pokemon to fight against
		// Needs changing to a routing map
		PokemonManager pm = pm.instance();

		RouteMapping routeMapping = RouteMapping();
		Pokemon otherPokemon = routeMapping.getSinglePokemonFromRoute(1);

		//Pokemon otherPokemon = pm.getDefaultPokemon("Shaymin");

		// The number of the pokemon to use
		int currentPokemon = 0;

		//otherPokemon.setPokemonsLevel(50);
		//playerPokemon.setPokemonsLevel(50);

		player.addPokemon(pm.getDefaultPokemon("Charizard"));
		player.addPokemon(pm.getDefaultPokemon("Blastoise"));
		player.addPokemon(pm.getDefaultPokemon("Darkrai"));


		// Gets all the gui info
		// The hp bars
		// The buttons on screen
		PokemonStatBox otherPokemonStatBox = PokemonStatBox(otherPokemon, 256, 96, 510, 20, 320, 75, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokemonStatBox.png");
		PokemonStatBox trainersPokemonStatBox = PokemonStatBox(player.trainersParty[currentPokemon], 256, 96, 70, 20, 320, 75, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokemonStatBox.png");

		Button backBox = Button(256, 128, 5, 435, 445, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/BackBox.png");
		Button textBox = Button(256, 128, 500, 470, 345, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/TextBox.png");

		ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

		string textForTextBox[4] = { "A wild " + otherPokemon.pokemonName + " appeared!", "", "", ""};

		AttackButton attackButton1 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[0], 128, 64, 20, 450, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");
		AttackButton attackButton2 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[1],128, 64, 160, 450, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");
		AttackButton attackButton3 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[2],128, 64, 20, 520, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");
		AttackButton attackButton4 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[3],128, 64, 160, 520, 128, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/AttackButton.png");

		SwitchPokemonButton switchPokemonOneButton = SwitchPokemonButton(player.trainersParty[0], 64, 64, 540, 435, 80, 80, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png");
		switchPokemonOneButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonTwoButton = SwitchPokemonButton(player.trainersParty[1], 64, 64, 630, 435, 80, 80, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png");
		switchPokemonTwoButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonThreeButton = SwitchPokemonButton(player.trainersParty[2], 64, 64, 720, 435, 80, 80, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png");
		switchPokemonThreeButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonFourButton = SwitchPokemonButton(player.trainersParty[3], 64, 64, 540, 520, 80, 80, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png");
		switchPokemonFourButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonFiveButton = SwitchPokemonButton(player.trainersParty[4], 64, 64, 630, 520, 80, 80, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png");
		switchPokemonFiveButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonSixButton = SwitchPokemonButton(player.trainersParty[5], 64, 64, 720, 520, 80, 80, "../LeytonFinalProjectC++/Sprites/BattleSprites/SwitchPokemonButton.png");
		switchPokemonSixButton.isDisplayed = false;

		Button healPokemonButton = Button(64, 64, 300, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/HealingItemsButton.png");
		Button switchPokemonButton = Button(64, 64, 300, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/ChangePokemonButton.png");
		Button catchPokemonButton = Button(64, 64, 370, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokeballsButton.png");
		Button runPokemonButton = Button(64, 64, 370, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/RunButton.png");

		bool pokemonDeadNeedsToSwitch = false;

		bool battleFinished = false;
		int attackButtonClicked = 0;
		int switchPokemonButtonClicked = 0;

		if (battleType == 0) {
			// Wild encounter

			while (!battleFinished) {

				al_wait_for_event(queue, &event);

				switch (event.type)
				{
				case ALLEGRO_EVENT_TIMER:
					redraw = true;
					break;

				case ALLEGRO_EVENT_MOUSE_AXES:
					xMousePosition = event.mouse.x;
					yMousePosition = event.mouse.y;
					break;
				case ALLEGRO_EVENT_MOUSE_BUTTON_UP:

					if (runPokemonButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						battleFinished = true;
					}

					else if (switchPokemonButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						if (textBox.isDisplayed) {
							textBox.isDisplayed = false;
							switchPokemonOneButton.isDisplayed = true;
							switchPokemonTwoButton.isDisplayed = true;
							switchPokemonThreeButton.isDisplayed = true;
							switchPokemonFourButton.isDisplayed = true;
							switchPokemonFiveButton.isDisplayed = true;
							switchPokemonSixButton.isDisplayed = true;

						}
						else {
							textBox.isDisplayed = true;
							switchPokemonOneButton.isDisplayed = false;
							switchPokemonTwoButton.isDisplayed = false;
							switchPokemonThreeButton.isDisplayed = false;
							switchPokemonFourButton.isDisplayed = false;
							switchPokemonFiveButton.isDisplayed = false;
							switchPokemonSixButton.isDisplayed = false;
						}

					}

					else if (switchPokemonOneButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						switchPokemonButtonClicked = 1;
						if (!(strcmp(player.trainersParty[0].pokemonName.c_str(), "") == 0)) {
							if (currentPokemon != 0) {
								if (player.trainersParty[0].currentHealth != 0) {

									currentPokemon = 0;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);

									
								}
							}
						}
					}

					else if (switchPokemonTwoButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						switchPokemonButtonClicked = 2;
						if (!(strcmp(player.trainersParty[1].pokemonName.c_str(), "") == 0)) {
							if (currentPokemon != 1) {
								if (player.trainersParty[1].currentHealth != 0) {
									currentPokemon = 1;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
								}
							}
						}
					}

					else if (switchPokemonThreeButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						switchPokemonButtonClicked = 3;
						if (!(strcmp(player.trainersParty[2].pokemonName.c_str(), "") == 0)) {
							if (currentPokemon != 2) {
								if (player.trainersParty[2].currentHealth != 0) {
									currentPokemon = 2;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
								}
							}
						}
					}

					else if (switchPokemonFourButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						switchPokemonButtonClicked = 4;
						if (!(strcmp(player.trainersParty[3].pokemonName.c_str(), "") == 0)) {
							if (currentPokemon != 3) {
								if (player.trainersParty[3].currentHealth != 0) {
									currentPokemon = 3;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
								}
							}
						}
					}

					else if (switchPokemonFiveButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						switchPokemonButtonClicked = 5;
						if (!(strcmp(player.trainersParty[4].pokemonName.c_str(), "") == 0)) {
							if (currentPokemon != 4) {
								if (player.trainersParty[4].currentHealth != 0) {
									currentPokemon = 4;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
								}
							}
						}
					}

					else if (switchPokemonSixButton.hasBeenClicked(xMousePosition, yMousePosition)) {
						switchPokemonButtonClicked = 6;
						if (!(strcmp(player.trainersParty[5].pokemonName.c_str(), "") == 0)) {
							if (currentPokemon != 5) {
								if (player.trainersParty[5].currentHealth != 0) {
									currentPokemon = 5;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
								}
							}
						}
					}

					else if (attackButton1.hasBeenClicked(xMousePosition, yMousePosition)) {
						if (player.trainersParty[currentPokemon].pokemonsMoves[0].currentPowerPoints != 0) {
							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon, attackButton1.pokemonMove);

							if (otherPokemon.currentHealth <= 0) {
								int expGained = otherPokemon.experienceUponKill();
								player.trainersParty[currentPokemon].gainExperience(expGained);
								battleFinished = true;
							}
							if (player.trainersParty[currentPokemon].currentHealth <= 0) {
								battleFinished = true;
							}
							textForTextBox[0] = doTurn.textForTextBox[0];
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = doTurn.textForTextBox[2];
							textForTextBox[3] = doTurn.textForTextBox[3];

							player.trainersParty[currentPokemon].pokemonsMoves[0].useMove();
							attackButton1.pokemonMove.useMove();
						}
						else {
							textForTextBox[0] = attackButton1.pokemonMove.moveName + " is out of PP!";
							textForTextBox[1] = "";
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
					}
					else if (attackButton2.hasBeenClicked(xMousePosition, yMousePosition)) {
						if (player.trainersParty[currentPokemon].pokemonsMoves[1].currentPowerPoints != 0) {
							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon, attackButton2.pokemonMove);
							if (otherPokemon.currentHealth <= 0) {
								int expGained = otherPokemon.experienceUponKill();
								player.trainersParty[currentPokemon].gainExperience(expGained);
								battleFinished = true;
							}
							if (player.trainersParty[currentPokemon].currentHealth <= 0) {
								battleFinished = true;
							}
							textForTextBox[0] = doTurn.textForTextBox[0];
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = doTurn.textForTextBox[2];
							textForTextBox[3] = doTurn.textForTextBox[3];

							player.trainersParty[currentPokemon].pokemonsMoves[1].useMove();
							attackButton2.pokemonMove.useMove();
						}
						else {
							textForTextBox[0] = attackButton2.pokemonMove.moveName + " is out of PP!";
							textForTextBox[1] = "";
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
					}
					else if (attackButton3.hasBeenClicked(xMousePosition, yMousePosition)) {
						if (player.trainersParty[currentPokemon].pokemonsMoves[2].currentPowerPoints != 0) {
							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon, attackButton3.pokemonMove);
							if (otherPokemon.currentHealth <= 0) {
								int expGained = otherPokemon.experienceUponKill();
								player.trainersParty[currentPokemon].gainExperience(expGained);
								battleFinished = true;
							}
							if (player.trainersParty[currentPokemon].currentHealth <= 0) {
								battleFinished = true;
							}
							textForTextBox[0] = doTurn.textForTextBox[0];
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = doTurn.textForTextBox[2];
							textForTextBox[3] = doTurn.textForTextBox[3];

							player.trainersParty[currentPokemon].pokemonsMoves[2].useMove();
							attackButton3.pokemonMove.useMove();
						}
						else {
							textForTextBox[0] = attackButton3.pokemonMove.moveName + " is out of PP!";
							textForTextBox[1] = "";
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
					}
					else if (attackButton4.hasBeenClicked(xMousePosition, yMousePosition)) {
						if (player.trainersParty[currentPokemon].pokemonsMoves[3].currentPowerPoints != 0) {
							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon, attackButton4.pokemonMove);
							if (otherPokemon.currentHealth <= 0) {
								int expGained = otherPokemon.experienceUponKill();
								player.trainersParty[currentPokemon].gainExperience(expGained);
								battleFinished = true;
							}
							if (player.trainersParty[currentPokemon].currentHealth <= 0) {
								battleFinished = true;
							}
							textForTextBox[0] = doTurn.textForTextBox[0];
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = doTurn.textForTextBox[2];
							textForTextBox[3] = doTurn.textForTextBox[3];

							player.trainersParty[currentPokemon].pokemonsMoves[3].useMove();
							attackButton4.pokemonMove.useMove();
						}
						else {
							textForTextBox[0] = attackButton4.pokemonMove.moveName + " is out of PP!";
							textForTextBox[1] = "";
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
					}

					if (switchPokemonButtonClicked!=0) {
						int pokemonNinArray = switchPokemonButtonClicked - 1;
						if (!(strcmp(player.trainersParty[pokemonNinArray].pokemonName.c_str(), "") == 0)) {
							if (currentPokemon != pokemonNinArray) {
								if (player.trainersParty[pokemonNinArray].currentHealth != 0) {
									currentPokemon = pokemonNinArray;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
								}
							}
						}
						switchPokemonButtonClicked = 0;
					}

					if (player.trainersParty[currentPokemon].currentHealth <= 0) {
						pokemonDeadNeedsToSwitch = true;
					}

					//cout << "Other poke : " << otherPokemon.healthActual<< "\n";
					break;
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					done = true;
					battleFinished = true;
					break;
				}

				if (done)
					break;

				if (redraw && al_is_event_queue_empty(queue))
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_draw_scaled_bitmap(background, 0, 0, 400, 225, 0, 0, screenWidth, screenHeight, 0);
					al_draw_scaled_bitmap(otherPokemonSprite, (80 * otherPokemon.xPositionOnSpriteSheet), (80 * otherPokemon.yPositionOnSpriteSheet),       80, 80,    screenWidth*0.6, screenHeight * 0.25, screenWidth * 0.3, screenWidth * 0.3, 0);
					al_draw_scaled_bitmap(trainsersPokemonSprite, (80 * player.trainersParty[currentPokemon].xPositionOnSpriteSheet), (80 * player.trainersParty[currentPokemon].yPositionOnSpriteSheet), 80, 80, screenWidth * 0.15, screenHeight*0.42, screenWidth * 0.25, screenWidth * 0.25, 0);
					otherPokemonStatBox.drawSprite(otherPokemon);
					trainersPokemonStatBox.drawSprite(player.trainersParty[currentPokemon]);
					backBox.drawSprite();
					textBox.drawSprite();
					attackButton1.drawSprite();
					attackButton2.drawSprite();
					attackButton3.drawSprite();
					attackButton4.drawSprite();
					healPokemonButton.drawSprite();
					switchPokemonButton.drawSprite();
					catchPokemonButton.drawSprite();
					runPokemonButton.drawSprite();
					if (textBox.isDisplayed) {
						al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (500 + 15), (470 + 15), 0, (textForTextBox[0]).c_str());
						al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (500 + 15), (470 + 40), 0, (textForTextBox[1]).c_str());
						al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (500 + 15), (470 + 65), 0, (textForTextBox[2]).c_str());
						al_draw_text(fontSmaller, al_map_rgb(255, 255, 255), (500 + 15), (470 + 90), 0, (textForTextBox[3]).c_str());
					}

					if (switchPokemonOneButton.isDisplayed) {
						switchPokemonOneButton.drawSprite();
						switchPokemonTwoButton.drawSprite();
						switchPokemonThreeButton.drawSprite();
						switchPokemonFourButton.drawSprite();
						switchPokemonFiveButton.drawSprite();
						switchPokemonSixButton.drawSprite();
					}
					
					al_flip_display();
					redraw = false;
				}

			}
		}

		
		else if (battleType == 1) {
			// Pokemon encounter

		}

		otherPokemonStatBox.destroySprites();
		trainersPokemonStatBox.destroySprites();
		al_destroy_bitmap(background);
		al_destroy_bitmap(otherPokemonSprite);
		al_destroy_bitmap(trainsersPokemonSprite);
		al_destroy_bitmap(backBox.spriteImage);
		al_destroy_bitmap(attackButton1.spriteImage);
		al_destroy_bitmap(attackButton2.spriteImage);
		al_destroy_bitmap(attackButton3.spriteImage);
		al_destroy_bitmap(attackButton4.spriteImage);
		al_destroy_bitmap(runPokemonButton.spriteImage);
		al_destroy_bitmap(healPokemonButton.spriteImage);
		al_destroy_bitmap(catchPokemonButton.spriteImage);
		al_destroy_bitmap(switchPokemonButton.spriteImage);
		al_destroy_bitmap(textBox.spriteImage);


	}

};