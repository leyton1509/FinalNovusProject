#include "../Sprites/PlayerCharacter.h"
#include "../Pokemon/PokemonManager.h"
#include "../Sprites/Button.h"
#include "../Sprites/AttackButton.h"
#include "../Sprites/PokemonStatBox.h"
#include "../Battle/PokemonTurn.h"
#include "../Battle/RouteMapping.h"
#include "../Sprites/SwitchPokemonButton.h"
#include "../Sprites/ItemPokeBallButton.h"
#include "../Sprites/ItemPotionButton.h"
#include "../Sprites/Trainer.h"

// Class when a pokemon battke is needed
class InitiateBattle {

public:

	// Mouse positions
	double xMousePosition = 0;
	double yMousePosition = 0;

	// GUI info
	bool done = false;
	bool redraw = true;

	ALLEGRO_BITMAP* getBackGroundFromLocationNumber(int locationNumber) {
		switch (locationNumber)
		{
		case 1:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Bamboo.jpg");
			break;
		case 2:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Savanna.jpg");
			break;
		case 3:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Lavs.jpg");
			break;
		case 4:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Mine.jpg");
			break;
		case 5:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Plains.jpg");
			break;
		case 6:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Graveyard.jpg");
			break;
		case 7:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Waterfall.jpg");
			break;
		case 8:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/DarkForest.jpg");
			break;
		case 9:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Swamp.jpg");
			break;
		case 10:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Swamp2.jpg");
			break;
		case 11:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Snow.jpg");
			break;
		case 12:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Underwater.jpg");
			break;
		case 13:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Desert.jpg");
			break;
		case 14:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Beach.jpg");
			break;
		default:
			return  al_load_bitmap("../LeytonFinalProjectC++/Sprites/BattleSprites/Plains.jpg");
			break;
		}
	}

	// Takes the screen size and the queue for inputs, the current player and the current location, and the opponent
	InitiateBattle(Trainer& opponent, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue, PlayerCharacter& player, int locationNumber) {
		bool battleFinished = false;

		ALLEGRO_EVENT event;

		// BG sprite
		ALLEGRO_BITMAP* background = getBackGroundFromLocationNumber(locationNumber);

		// Reset the camera
		ALLEGRO_TRANSFORM trans;
		al_identity_transform(&trans);
		al_use_transform(&trans);
		al_draw_bitmap(background, 0, 0, 0);

		// Sprites for the pokemon
		ALLEGRO_BITMAP* otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");
		ALLEGRO_BITMAP* trainsersPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/backSprites.png");

		int currentPokemonOpponent = 0;

		// The number of the pokemon to use
		int currentPokemon = 0;

		if (!player.isAllPokemonInPartyDead()) {
			currentPokemon = player.getFirstAlivePokemon();

		}
		else {
			return;
		}

		// Gets all the gui info
		// The hp bars
		// The buttons on screen
		PokemonStatBox otherPokemonStatBox = PokemonStatBox(opponent.trainersTeam[currentPokemonOpponent], 256, 96, 510, 20, 320, 75);
		PokemonStatBox trainersPokemonStatBox = PokemonStatBox(player.trainersParty[currentPokemon], 256, 96, 70, 20, 320, 75);

		ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

		// Add conversion for trainer name
		string textForTextBox[4] = { "Trainer appeared!", "", "", "" };


		AttackButton attackButton1 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[0], 128, 64, 20, 450, 128, 64);
		AttackButton attackButton2 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[1], 128, 64, 160, 450, 128, 64);
		AttackButton attackButton3 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[2], 128, 64, 20, 520, 128, 64);
		AttackButton attackButton4 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[3], 128, 64, 160, 520, 128, 64);

		SwitchPokemonButton switchPokemonOneButton = SwitchPokemonButton(64, 64, 540, 435, 80, 80);
		switchPokemonOneButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonTwoButton = SwitchPokemonButton(64, 64, 630, 435, 80, 80);
		switchPokemonTwoButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonThreeButton = SwitchPokemonButton(64, 64, 720, 435, 80, 80);
		switchPokemonThreeButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonFourButton = SwitchPokemonButton(64, 64, 540, 520, 80, 80);
		switchPokemonFourButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonFiveButton = SwitchPokemonButton(64, 64, 630, 520, 80, 80);
		switchPokemonFiveButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonSixButton = SwitchPokemonButton(64, 64, 720, 520, 80, 80);
		switchPokemonSixButton.isDisplayed = false;

		ItemPotionButton potionButtonOne = ItemPotionButton(4, 64, 64, 540, 435, 80, 80);
		potionButtonOne.isDisplayed = false;

		ItemPotionButton potionButtonTwo = ItemPotionButton(5, 64, 64, 630, 435, 80, 80);
		potionButtonTwo.isDisplayed = false;

		ItemPotionButton potionButtonThree = ItemPotionButton(6, 64, 64, 720, 435, 80, 80);
		potionButtonThree.isDisplayed = false;

		Button healPokemonButton = Button(64, 64, 300, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/HealingItemsButton.png");
		Button switchPokemonButton = Button(64, 64, 300, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/ChangePokemonButton.png");
		Button catchPokemonButton = Button(64, 64, 370, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokeballsButton.png");
		Button runPokemonButton = Button(64, 64, 370, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/RunButton.png");

		Button backBox = Button(256, 128, 5, 435, 445, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/BackBox.png");
		Button textBox = Button(256, 128, 500, 470, 345, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/TextBox.png");

		int attackButtonClicked = 0;
		int switchPokemonButtonClicked = 0;
		int healItemButtonClicked = 0;
		bool pokemonIsDead = false;
		int shouldHealInSwitch = -1;

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

				if (switchPokemonButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					if (textBox.isDisplayed) {
						textBox.isDisplayed = false;
						switchPokemonOneButton.isDisplayed = true;
						switchPokemonTwoButton.isDisplayed = true;
						switchPokemonThreeButton.isDisplayed = true;
						switchPokemonFourButton.isDisplayed = true;
						switchPokemonFiveButton.isDisplayed = true;
						switchPokemonSixButton.isDisplayed = true;


					}
					else if (!textBox.isDisplayed && switchPokemonOneButton.isDisplayed) {
						shouldHealInSwitch = -1;
						textBox.isDisplayed = true;
						switchPokemonOneButton.isDisplayed = false;
						switchPokemonTwoButton.isDisplayed = false;
						switchPokemonThreeButton.isDisplayed = false;
						switchPokemonFourButton.isDisplayed = false;
						switchPokemonFiveButton.isDisplayed = false;
						switchPokemonSixButton.isDisplayed = false;

					}

				}

				else if (healPokemonButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					if (textBox.isDisplayed) {
						textBox.isDisplayed = false;
						potionButtonOne.isDisplayed = true;
						potionButtonTwo.isDisplayed = true;
						potionButtonThree.isDisplayed = true;

					}
					else if (!textBox.isDisplayed && potionButtonOne.isDisplayed) {
						textBox.isDisplayed = true;
						potionButtonOne.isDisplayed = false;
						potionButtonOne.isDisplayed = false;
						potionButtonOne.isDisplayed = false;
						switchPokemonOneButton.isDisplayed = false;
						switchPokemonTwoButton.isDisplayed = false;
						switchPokemonThreeButton.isDisplayed = false;
						switchPokemonFourButton.isDisplayed = false;
						switchPokemonFiveButton.isDisplayed = false;
						switchPokemonSixButton.isDisplayed = false;
					}

				}
				else if (potionButtonOne.hasBeenClicked(xMousePosition, yMousePosition)) {
					healItemButtonClicked = 1;
				}
				else if (potionButtonTwo.hasBeenClicked(xMousePosition, yMousePosition)) {
					healItemButtonClicked = 2;

				}
				else if (potionButtonThree.hasBeenClicked(xMousePosition, yMousePosition)) {
					healItemButtonClicked = 3;
				}
				else if (switchPokemonOneButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 1;
				}

				else if (switchPokemonTwoButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 2;
				}

				else if (switchPokemonThreeButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 3;
				}

				else if (switchPokemonFourButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 4;
				}

				else if (switchPokemonFiveButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 5;
				}

				else if (switchPokemonSixButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 6;
				}
				else if (attackButton1.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 1;
				}
				else if (attackButton2.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 2;
				}
				else if (attackButton3.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 3;
				}
				else if (attackButton4.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 4;
				}

				// Add code for when the buttons are clicked


				if (switchPokemonButtonClicked != 0) {
					int pokemonNinArray = switchPokemonButtonClicked - 1;
					if (!(strcmp(player.trainersParty[pokemonNinArray].pokemonName.c_str(), "") == 0)) {
						if (shouldHealInSwitch != -1) {
							if (player.trainersParty[pokemonNinArray].currentHealth < player.trainersParty[pokemonNinArray].healthActual) {
								player.itemManager.usePotion(player.trainersParty[pokemonNinArray], shouldHealInSwitch);
								shouldHealInSwitch = -1;

								textBox.isDisplayed = true;
								switchPokemonOneButton.isDisplayed = false;
								switchPokemonTwoButton.isDisplayed = false;
								switchPokemonThreeButton.isDisplayed = false;
								switchPokemonFourButton.isDisplayed = false;
								switchPokemonFiveButton.isDisplayed = false;
								switchPokemonSixButton.isDisplayed = false;

								PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], opponent.trainersTeam[currentPokemonOpponent]);


							}
						}
						else {
							if (currentPokemon != pokemonNinArray) {
								if (player.trainersParty[pokemonNinArray].currentHealth != 0) {
									currentPokemon = pokemonNinArray;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];

									textBox.isDisplayed = true;
									switchPokemonOneButton.isDisplayed = false;
									switchPokemonTwoButton.isDisplayed = false;
									switchPokemonThreeButton.isDisplayed = false;
									switchPokemonFourButton.isDisplayed = false;
									switchPokemonFiveButton.isDisplayed = false;
									switchPokemonSixButton.isDisplayed = false;

									if (pokemonIsDead) {
										pokemonIsDead = false;
									}

									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], opponent.trainersTeam[currentPokemonOpponent]);
								}
							}
						}

					}
					switchPokemonButtonClicked = 0;
				}

				else if (healItemButtonClicked != 0) {

					int potionID = -1;

					if (healItemButtonClicked == 1) {
						if (player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID) > 0) {
							potionID = potionButtonOne.potion.inividualItemID;
						}

					}
					else if (healItemButtonClicked == 2) {
						if (player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID) > 0) {
							potionID = potionButtonTwo.potion.inividualItemID;
						}

					}
					else if (healItemButtonClicked == 3) {
						if (player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID) > 0) {
							potionID = potionButtonThree.potion.inividualItemID;
						}
					}

					if (potionID != -1) {
						potionButtonOne.isDisplayed = false;
						potionButtonTwo.isDisplayed = false;
						potionButtonThree.isDisplayed = false;
						shouldHealInSwitch = potionID;

						switchPokemonOneButton.isDisplayed = true;
						switchPokemonTwoButton.isDisplayed = true;
						switchPokemonThreeButton.isDisplayed = true;
						switchPokemonFourButton.isDisplayed = true;
						switchPokemonFiveButton.isDisplayed = true;
						switchPokemonSixButton.isDisplayed = true;
					}


					// Need to get which pokemon to heal
					healItemButtonClicked = 0;
				}

				else if (attackButtonClicked != 0) {
					if (!pokemonIsDead) {
						int attackButtonN = attackButtonClicked - 1;
						if (player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].currentPowerPoints != 0) {

							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], opponent.trainersTeam[currentPokemonOpponent], player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN]);
							
							
							if (opponent.trainersTeam[currentPokemonOpponent].currentHealth <= 0) {
								int expGained = opponent.trainersTeam[currentPokemonOpponent].experienceUponKill();
								player.trainersParty[currentPokemon].gainExperience(expGained);

								if (!opponent.isAllPokemonInPartyDead()) {
									currentPokemon = doTurn.getNextPokemonForOpponent(opponent, currentPokemonOpponent, player.trainersParty[currentPokemon]);
								}
								else {
									battleFinished = true;
								}
							}

							textForTextBox[0] = doTurn.textForTextBox[0];
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = doTurn.textForTextBox[2];
							textForTextBox[3] = doTurn.textForTextBox[3];

							player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].useMove();


							if (attackButtonClicked == 1) {
								attackButton1.pokemonMove.useMove();
							}
							else if (attackButtonClicked == 2) {
								attackButton2.pokemonMove.useMove();
							}
							else if (attackButtonClicked == 3) {
								attackButton3.pokemonMove.useMove();
							}
							else if (attackButtonClicked == 4) {
								attackButton4.pokemonMove.useMove();
							}
						}
						else {
							textForTextBox[0] = player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].moveName + " is out of PP!";
							textForTextBox[1] = "";
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
						attackButtonClicked = 0;
					}

				}

				if (player.trainersParty[currentPokemon].currentHealth <= 0) {

					if (player.isAllPokemonInPartyDead()) {
						// Add teleporting to nearest heal
						cout << "All pokemon dead\n";
						battleFinished = true;
					}
					pokemonIsDead = true;
					textBox.isDisplayed = false;
					switchPokemonOneButton.isDisplayed = true;
					switchPokemonTwoButton.isDisplayed = true;
					switchPokemonThreeButton.isDisplayed = true;
					switchPokemonFourButton.isDisplayed = true;
					switchPokemonFiveButton.isDisplayed = true;
					switchPokemonSixButton.isDisplayed = true;
				}


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
				al_draw_scaled_bitmap(otherPokemonSprite, (80 * opponent.trainersTeam[currentPokemonOpponent].xPositionOnSpriteSheet), (80 * opponent.trainersTeam[currentPokemonOpponent].yPositionOnSpriteSheet), 80, 80, screenWidth * 0.6, screenHeight * 0.25, screenWidth * 0.3, screenWidth * 0.3, 0);
				if (!pokemonIsDead) {
					al_draw_scaled_bitmap(trainsersPokemonSprite, (80 * player.trainersParty[currentPokemon].xPositionOnSpriteSheet), (80 * player.trainersParty[currentPokemon].yPositionOnSpriteSheet), 80, 80, screenWidth * 0.15, screenHeight * 0.42, screenWidth * 0.25, screenWidth * 0.25, 0);
				}


				if (switchPokemonOneButton.isDisplayed) {
					switchPokemonOneButton.drawSprite(player.trainersParty[0]);
					switchPokemonTwoButton.drawSprite(player.trainersParty[1]);
					switchPokemonThreeButton.drawSprite(player.trainersParty[2]);
					switchPokemonFourButton.drawSprite(player.trainersParty[3]);
					switchPokemonFiveButton.drawSprite(player.trainersParty[4]);
					switchPokemonSixButton.drawSprite(player.trainersParty[5]);
				}

				if (potionButtonOne.isDisplayed) {
					potionButtonOne.drawSprite(player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID));
					potionButtonTwo.drawSprite(player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID));
					potionButtonThree.drawSprite(player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID));
				}

				otherPokemonStatBox.drawSprite(opponent.trainersTeam[currentPokemonOpponent]);
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

				al_flip_display();
				redraw = false;
			}

		}
		
	}

	// Takes the screen size and the queue for inputs, the current player and the current location
	InitiateBattle(int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue, PlayerCharacter& player, int locationNumber) {

		bool battleFinished = false;

		ALLEGRO_EVENT event;

		// BG sprite
		ALLEGRO_BITMAP * background = getBackGroundFromLocationNumber(locationNumber);

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

		if (!player.isAllPokemonInPartyDead()) {
			currentPokemon = player.getFirstAlivePokemon();
			
		}
		else {
			return;
		}
		

		//otherPokemon.setPokemonsLevel(50);
		//playerPokemon.setPokemonsLevel(50);

		// Gets all the gui info
		// The hp bars
		// The buttons on screen
		PokemonStatBox otherPokemonStatBox = PokemonStatBox(otherPokemon, 256, 96, 510, 20, 320, 75);
		PokemonStatBox trainersPokemonStatBox = PokemonStatBox(player.trainersParty[currentPokemon], 256, 96, 70, 20, 320, 75);

		Button backBox = Button(256, 128, 5, 435, 445, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/BackBox.png");
		Button textBox = Button(256, 128, 500, 470, 345, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/TextBox.png");

		ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

		string textForTextBox[4] = { "A wild " + otherPokemon.pokemonName + " appeared!", "", "", ""};

		AttackButton attackButton1 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[0], 128, 64, 20, 450, 128, 64);
		AttackButton attackButton2 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[1],128, 64, 160, 450, 128, 64);
		AttackButton attackButton3 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[2],128, 64, 20, 520, 128, 64);
		AttackButton attackButton4 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[3],128, 64, 160, 520, 128, 64);

		SwitchPokemonButton switchPokemonOneButton = SwitchPokemonButton( 64, 64, 540, 435, 80, 80);
		switchPokemonOneButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonTwoButton = SwitchPokemonButton(64, 64, 630, 435, 80, 80);
		switchPokemonTwoButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonThreeButton = SwitchPokemonButton(64, 64, 720, 435, 80, 80);
		switchPokemonThreeButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonFourButton = SwitchPokemonButton(64, 64, 540, 520, 80, 80);
		switchPokemonFourButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonFiveButton = SwitchPokemonButton(64, 64, 630, 520, 80, 80);
		switchPokemonFiveButton.isDisplayed = false;

		SwitchPokemonButton switchPokemonSixButton = SwitchPokemonButton(64, 64, 720, 520, 80, 80);
		switchPokemonSixButton.isDisplayed = false;

		Button healPokemonButton = Button(64, 64, 300, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/HealingItemsButton.png");
		Button switchPokemonButton = Button(64, 64, 300, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/ChangePokemonButton.png");
		Button catchPokemonButton = Button(64, 64, 370, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokeballsButton.png");
		Button runPokemonButton = Button(64, 64, 370, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/RunButton.png");

		ItemPokeBallButton pokeballButtonOne = ItemPokeBallButton(1, 64, 64, 540, 435, 80,80);
		pokeballButtonOne.isDisplayed = false;

		ItemPokeBallButton pokeballButtonTwo = ItemPokeBallButton(2, 64, 64, 630, 435, 80, 80);
		pokeballButtonTwo.isDisplayed = false;

		ItemPokeBallButton pokeballButtonThree = ItemPokeBallButton(3, 64, 64, 720, 435, 80, 80);
		pokeballButtonThree.isDisplayed = false;

		ItemPotionButton potionButtonOne = ItemPotionButton(4, 64, 64, 540, 435, 80, 80);
		potionButtonOne.isDisplayed = false;

		ItemPotionButton potionButtonTwo = ItemPotionButton(5, 64, 64, 630, 435, 80, 80);
		potionButtonTwo.isDisplayed = false;

		ItemPotionButton potionButtonThree = ItemPotionButton(6, 64, 64, 720, 435, 80, 80);
		potionButtonThree.isDisplayed = false;

		int attackButtonClicked = 0;
		int switchPokemonButtonClicked = 0;
		int healItemButtonClicked = 0;
		int catchItemButtonClicked = 0;
		bool pokemonIsDead = false;
		int shouldHealInSwitch = -1;

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
					else if (!textBox.isDisplayed && switchPokemonOneButton.isDisplayed) {
						shouldHealInSwitch = -1;
						textBox.isDisplayed = true;
						switchPokemonOneButton.isDisplayed = false;
						switchPokemonTwoButton.isDisplayed = false;
						switchPokemonThreeButton.isDisplayed = false;
						switchPokemonFourButton.isDisplayed = false;
						switchPokemonFiveButton.isDisplayed = false;
						switchPokemonSixButton.isDisplayed = false;

					}


				}

				else if (healPokemonButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					if (textBox.isDisplayed) {
						textBox.isDisplayed = false;
						potionButtonOne.isDisplayed = true;
						potionButtonTwo.isDisplayed = true;
						potionButtonThree.isDisplayed = true;

					}
					else if (!textBox.isDisplayed && potionButtonOne.isDisplayed) {
						textBox.isDisplayed = true;
						potionButtonOne.isDisplayed = false;
						potionButtonOne.isDisplayed = false;
						potionButtonOne.isDisplayed = false;
						switchPokemonOneButton.isDisplayed = false;
						switchPokemonTwoButton.isDisplayed = false;
						switchPokemonThreeButton.isDisplayed = false;
						switchPokemonFourButton.isDisplayed = false;
						switchPokemonFiveButton.isDisplayed = false;
						switchPokemonSixButton.isDisplayed = false;
					}

				}

				else if (catchPokemonButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					if (textBox.isDisplayed) {
						textBox.isDisplayed = false;
						pokeballButtonOne.isDisplayed = true;
						pokeballButtonTwo.isDisplayed = true;
						pokeballButtonThree.isDisplayed = true;
					}
					else if(!textBox.isDisplayed && pokeballButtonOne.isDisplayed) {
						textBox.isDisplayed = true;
						pokeballButtonOne.isDisplayed = false;
						pokeballButtonTwo.isDisplayed = false;
						pokeballButtonThree.isDisplayed = false;
					}

				}

				else if (pokeballButtonOne.hasBeenClicked(xMousePosition, yMousePosition)) {
					catchItemButtonClicked = 1;
				}
				else if (pokeballButtonTwo.hasBeenClicked(xMousePosition, yMousePosition)) {
					catchItemButtonClicked = 2;

				}
				else if (pokeballButtonThree.hasBeenClicked(xMousePosition, yMousePosition)) {
					catchItemButtonClicked = 3;

				}


				else if (potionButtonOne.hasBeenClicked(xMousePosition, yMousePosition)) {
					healItemButtonClicked = 1;
				}
				else if (potionButtonTwo.hasBeenClicked(xMousePosition, yMousePosition)) {
					healItemButtonClicked = 2;

				}
				else if (potionButtonThree.hasBeenClicked(xMousePosition, yMousePosition)) {
					healItemButtonClicked = 3;
				}


				else if (switchPokemonOneButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 1;
				}

				else if (switchPokemonTwoButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 2;
				}

				else if (switchPokemonThreeButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 3;
				}

				else if (switchPokemonFourButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 4;
				}

				else if (switchPokemonFiveButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 5;
				}

				else if (switchPokemonSixButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					switchPokemonButtonClicked = 6;
				}

				else if (attackButton1.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 1;
				}
				else if (attackButton2.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 2;
				}
				else if (attackButton3.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 3;
				}
				else if (attackButton4.hasBeenClicked(xMousePosition, yMousePosition)) {
					attackButtonClicked = 4;
				}

				if (switchPokemonButtonClicked!=0) {
					int pokemonNinArray = switchPokemonButtonClicked - 1;
					if (!(strcmp(player.trainersParty[pokemonNinArray].pokemonName.c_str(), "") == 0)) {
						if (shouldHealInSwitch != -1) {
							if (player.trainersParty[pokemonNinArray].currentHealth < player.trainersParty[pokemonNinArray].healthActual) {
								player.itemManager.usePotion(player.trainersParty[pokemonNinArray], shouldHealInSwitch);
								shouldHealInSwitch = -1;

								textBox.isDisplayed = true;
								switchPokemonOneButton.isDisplayed = false;
								switchPokemonTwoButton.isDisplayed = false;
								switchPokemonThreeButton.isDisplayed = false;
								switchPokemonFourButton.isDisplayed = false;
								switchPokemonFiveButton.isDisplayed = false;
								switchPokemonSixButton.isDisplayed = false;

								PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);


							}
						}
						else {
							if (currentPokemon != pokemonNinArray) {
								if (player.trainersParty[pokemonNinArray].currentHealth != 0) {
									currentPokemon = pokemonNinArray;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];

									textBox.isDisplayed = true;
									switchPokemonOneButton.isDisplayed = false;
									switchPokemonTwoButton.isDisplayed = false;
									switchPokemonThreeButton.isDisplayed = false;
									switchPokemonFourButton.isDisplayed = false;
									switchPokemonFiveButton.isDisplayed = false;
									switchPokemonSixButton.isDisplayed = false;

									if (pokemonIsDead) {
										pokemonIsDead = false;
									}

									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
								}
							}
						}

					}
					switchPokemonButtonClicked = 0;
				}

				else if (attackButtonClicked!=0) {
					if (!pokemonIsDead) {
						int attackButtonN = attackButtonClicked - 1;
						if (player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].currentPowerPoints != 0) {

							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon, player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN]);
							if (otherPokemon.currentHealth <= 0) {
								int expGained = otherPokemon.experienceUponKill();
								player.trainersParty[currentPokemon].gainExperience(expGained);
								battleFinished = true;
							}

							textForTextBox[0] = doTurn.textForTextBox[0];
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = doTurn.textForTextBox[2];
							textForTextBox[3] = doTurn.textForTextBox[3];

							player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].useMove();


							if (attackButtonClicked == 1) {
								attackButton1.pokemonMove.useMove();
							}
							else if (attackButtonClicked == 2) {
								attackButton2.pokemonMove.useMove();
							}
							else if (attackButtonClicked == 3) {
								attackButton3.pokemonMove.useMove();
							}
							else if (attackButtonClicked == 4) {
								attackButton4.pokemonMove.useMove();
							}
						}
						else {
							textForTextBox[0] = player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].moveName + " is out of PP!";
							textForTextBox[1] = "";
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
						attackButtonClicked = 0;
					}
						
				}
				else if (catchItemButtonClicked!=0) {

					int pokeBallID = -1;

					if (catchItemButtonClicked == 1) {
						if (player.itemManager.getAmountOfItem(pokeballButtonOne.pokeball.inividualItemID) > 0) {
							pokeBallID = pokeballButtonOne.pokeball.inividualItemID;
						}
							
					}
					else if (catchItemButtonClicked == 2) {
						if (player.itemManager.getAmountOfItem(pokeballButtonTwo.pokeball.inividualItemID) > 0) {
							pokeBallID = pokeballButtonTwo.pokeball.inividualItemID;
						}
							
					}
					else if (catchItemButtonClicked == 3) {
						if (player.itemManager.getAmountOfItem(pokeballButtonThree.pokeball.inividualItemID) > 0) {
							pokeBallID = pokeballButtonThree.pokeball.inividualItemID;
						}
					}

					if (pokeBallID!=-1) {
						bool caughtPokemon = player.itemManager.usePokeball(otherPokemon, pokeBallID);
						if (caughtPokemon) {
							player.addPokemon(otherPokemon);
							battleFinished = true;
						}
						else {
							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], otherPokemon);
							textForTextBox[0] = otherPokemon.pokemonName + " broke free!";
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
						textBox.isDisplayed = true;
						pokeballButtonOne.isDisplayed = false;
						pokeballButtonTwo.isDisplayed = false;
						pokeballButtonThree.isDisplayed = false;
					}

						
					catchItemButtonClicked = 0;
						
				}
				else if (healItemButtonClicked != 0) {

					int potionID = -1;

					if (healItemButtonClicked == 1) {
						if (player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID) > 0) {
							potionID = potionButtonOne.potion.inividualItemID;
						}

					}
					else if (healItemButtonClicked == 2) {
						if (player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID) > 0) {
							potionID = potionButtonTwo.potion.inividualItemID;
						}

					}
					else if (healItemButtonClicked == 3) {
						if (player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID) > 0) {
							potionID = potionButtonThree.potion.inividualItemID;
						}
					}

					if (potionID!=-1) {
						potionButtonOne.isDisplayed = false;
						potionButtonTwo.isDisplayed = false;
						potionButtonThree.isDisplayed = false;
						shouldHealInSwitch = potionID;

						switchPokemonOneButton.isDisplayed = true;
						switchPokemonTwoButton.isDisplayed = true;
						switchPokemonThreeButton.isDisplayed = true;
						switchPokemonFourButton.isDisplayed = true;
						switchPokemonFiveButton.isDisplayed = true;
						switchPokemonSixButton.isDisplayed = true;
					}


					// Need to get which pokemon to heal
					healItemButtonClicked = 0;
				}


				if (player.trainersParty[currentPokemon].currentHealth <= 0) {

					if (player.isAllPokemonInPartyDead()) {
						// Add teleporting to nearest heal
						cout << "All pokemon dead\n";
						battleFinished = true;
					}
					pokemonIsDead = true;
					textBox.isDisplayed = false;
					switchPokemonOneButton.isDisplayed = true;
					switchPokemonTwoButton.isDisplayed = true;
					switchPokemonThreeButton.isDisplayed = true;
					switchPokemonFourButton.isDisplayed = true;
					switchPokemonFiveButton.isDisplayed = true;
					switchPokemonSixButton.isDisplayed = true;
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
				if (!pokemonIsDead) {
					al_draw_scaled_bitmap(trainsersPokemonSprite, (80 * player.trainersParty[currentPokemon].xPositionOnSpriteSheet), (80 * player.trainersParty[currentPokemon].yPositionOnSpriteSheet), 80, 80, screenWidth * 0.15, screenHeight * 0.42, screenWidth * 0.25, screenWidth * 0.25, 0);
				}
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
					switchPokemonOneButton.drawSprite(player.trainersParty[0]);
					switchPokemonTwoButton.drawSprite(player.trainersParty[1]);
					switchPokemonThreeButton.drawSprite(player.trainersParty[2]);
					switchPokemonFourButton.drawSprite(player.trainersParty[3]);
					switchPokemonFiveButton.drawSprite(player.trainersParty[4]);
					switchPokemonSixButton.drawSprite(player.trainersParty[5]);
				}

				if (pokeballButtonOne.isDisplayed) {
					pokeballButtonOne.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonOne.pokeball.inividualItemID));
					pokeballButtonTwo.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonTwo.pokeball.inividualItemID));
					pokeballButtonThree.drawSprite(player.itemManager.getAmountOfItem(pokeballButtonThree.pokeball.inividualItemID));

				}

				if (potionButtonOne.isDisplayed) {
					potionButtonOne.drawSprite(player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID));
					potionButtonTwo.drawSprite(player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID));
					potionButtonThree.drawSprite(player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID));

				}
					
				al_flip_display();
				redraw = false;
			}

			
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