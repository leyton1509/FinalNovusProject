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
#include "../Sprites/UserOption.h"


// Class when a pokemon battke is needed
class InitiateBattle {

public:

	// Mouse positions
	double xMousePosition = 0;
	double yMousePosition = 0;

	// GUI info
	bool done = false;
	bool redraw = true;

	bool battleFinished;
	ALLEGRO_EVENT event;

	// BG sprite
	ALLEGRO_BITMAP* background;

	ALLEGRO_BITMAP* otherPokemonSprite;
	ALLEGRO_BITMAP* trainsersPokemonSprite;

	// Returns the map bitmp from the location number
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


	void loadInititalParts(int locationNumber) {
		 battleFinished = false;
		 // BG sprite
		 background = getBackGroundFromLocationNumber(locationNumber);
		 // Reset the camera
		 ALLEGRO_TRANSFORM trans;
		 al_identity_transform(&trans);
		 al_use_transform(&trans);
		 al_draw_bitmap(background, 0, 0, 0);
		 otherPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/frontSprites.png");
		 trainsersPokemonSprite = al_load_bitmap("../LeytonFinalProjectC++/Sprites/PokemonSprites/backSprites.png");
		 
	}

	// Takes the screen size and the queue for inputs, the current player and the current location, and the opponent
	InitiateBattle(Trainer& opponent, int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue, PlayerCharacter& player, int locationNumber) {
		

		loadInititalParts(locationNumber);
		

		
		// Sprites for the pokemon
		

		int currentPokemonOpponent = 0;

		// The number of the pokemon to use
		int currentPokemon = 0;

		// Gets the first valid pokemon
		// Breaks if there is no valid
		if (!player.isAllPokemonInPartyDead()) {
			currentPokemon = player.getFirstAlivePokemon();

		}
		else {
			return;
		}


		// The stat boxes for each pokemon
		PokemonStatBox otherPokemonStatBox = PokemonStatBox(256, 96, 510, 20, 320, 75);
		PokemonStatBox trainersPokemonStatBox = PokemonStatBox(256, 96, 70, 20, 320, 75);

		// The font to use
		ALLEGRO_FONT* fontSmaller = al_load_font("MagzoSemiBold-GOraO.otf", 16, NULL);

		// The text to display
		string textForTextBox[4] = { "Trainer appeared!", "", "", "" };

		// The attack buttons with the pokemons attacks
		AttackButton attackButton1 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[0], 128, 64, 20, 450, 128, 64);
		AttackButton attackButton2 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[1], 128, 64, 160, 450, 128, 64);
		AttackButton attackButton3 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[2], 128, 64, 20, 520, 128, 64);
		AttackButton attackButton4 = AttackButton(player.trainersParty[currentPokemon].pokemonsMoves[3], 128, 64, 160, 520, 128, 64);

		// The switch buttons for each pokemon
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

		// The potion buttons for each potion

		ItemPotionButton potionButtonOne = ItemPotionButton(4, 64, 64, 540, 435, 80, 80);
		potionButtonOne.isDisplayed = false;

		ItemPotionButton potionButtonTwo = ItemPotionButton(5, 64, 64, 630, 435, 80, 80);
		potionButtonTwo.isDisplayed = false;

		ItemPotionButton potionButtonThree = ItemPotionButton(6, 64, 64, 720, 435, 80, 80);
		potionButtonThree.isDisplayed = false;

		// The options to choose buttons, heal, switch, catch and run

		Button healPokemonButton = Button(64, 64, 300, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/HealingItemsButton.png");
		Button switchPokemonButton = Button(64, 64, 300, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/ChangePokemonButton.png");
		Button catchPokemonButton = Button(64, 64, 370, 450, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/PokeballsButton.png");
		Button runPokemonButton = Button(64, 64, 370, 520, 64, 64, "../LeytonFinalProjectC++/Sprites/BattleSprites/RunButton.png");

		// The back box for the buttons
		Button backBox = Button(256, 128, 5, 435, 445, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/BackBox.png");
		// The text box
		Button textBox = Button(256, 128, 500, 470, 345, 165, "../LeytonFinalProjectC++/Sprites/BattleSprites/TextBox.png");

		// Sets an int for which button has been clicked
		int attackButtonClicked = 0;
		int switchPokemonButtonClicked = 0;
		int healItemButtonClicked = 0;
		bool pokemonIsDead = false;
		// If the switch should heal the pokemon not switch pokemon
		int shouldHealInSwitch = -1;

		// Loops until the battle is finished
		// ALLEGRO control loop
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

				// Checks to see if the switch pokemon has been clicked and displays the switched pokemon
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
					// Turns off the switched pokemon buttons
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

				// Checks to see if the heal button has been clicked
				else if (healPokemonButton.hasBeenClicked(xMousePosition, yMousePosition)) {
					// If its displayed, un display it, if its not display them
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

				// Checks to see which option button has been clicked
				// Sets it to the value of that button
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

				// If the button has been clicked

				// If its the switch button
				if (switchPokemonButtonClicked != 0) {
					// Gets the pokemon n in array
					int pokemonNinArray = switchPokemonButtonClicked - 1;
					// Checks if the pokemon is not empty
					if (!(strcmp(player.trainersParty[pokemonNinArray].pokemonName.c_str(), "") == 0)) {
						// If it should be a heal
						if (shouldHealInSwitch != -1) {
							// Makes sure that the health is not full
							if (player.trainersParty[pokemonNinArray].currentHealth < player.trainersParty[pokemonNinArray].healthActual) {
								// Uses the potion
								player.itemManager.usePotion(player.trainersParty[pokemonNinArray], shouldHealInSwitch);
								shouldHealInSwitch = -1;
								// Undisplays the switch options
								textBox.isDisplayed = true;
								switchPokemonOneButton.isDisplayed = false;
								switchPokemonTwoButton.isDisplayed = false;
								switchPokemonThreeButton.isDisplayed = false;
								switchPokemonFourButton.isDisplayed = false;
								switchPokemonFiveButton.isDisplayed = false;
								switchPokemonSixButton.isDisplayed = false;

								// Runs the opponents turn
								PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], opponent.trainersTeam[currentPokemonOpponent]);
							}
						}
						else {
							// If its not the current pokemon
							if (currentPokemon != pokemonNinArray) {
								// If the pokemon isnt dead
								if (player.trainersParty[pokemonNinArray].currentHealth != 0) {
									// Sets the current pokemon and the attack buttons
									currentPokemon = pokemonNinArray;
									attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
									attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
									attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
									attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];

									// Turns off the switch info
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
									// Runs the opponents turn
									PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], opponent.trainersTeam[currentPokemonOpponent]);
								}
							}
						}

					}
					switchPokemonButtonClicked = 0;
				}

				// If the heal button is clicked
				else if (healItemButtonClicked != 0) {

					int potionID = -1;

					// Gets the id of the potion used
					// Only returns if the player has enough of the item
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

					// Ifs its valid
					// Sets the potions to false, should heal in switch to the id, and brings up the pokemon to use it on
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

				// If the attack button is clicked
				else if (attackButtonClicked != 0) {
					// Checks to see if its not dead
					if (!pokemonIsDead) {
						// Gets which attack to use
						int attackButtonN = attackButtonClicked - 1;
						// Gets if the current power points is > 0
						if (player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].currentPowerPoints != 0) {

							// Does the pokemon turn
							PokemonTurn doTurn = PokemonTurn(player.trainersParty[currentPokemon], opponent.trainersTeam[currentPokemonOpponent], player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN]);
							
							// If the opponent dies
							// Gain exoeruence, check for evolution 
							if (opponent.trainersTeam[currentPokemonOpponent].currentHealth <= 0) {
								int expGained = opponent.trainersTeam[currentPokemonOpponent].experienceUponKill();
								PokemonManager pm = pm.instance();
								pair<bool, pair<int, int>> experienceInfo = player.trainersParty[currentPokemon].gainExperience(expGained);

								if (experienceInfo.first) {
									string headerText = player.trainersParty[currentPokemon].pokemonName + " is evolving into " + player.trainersParty[currentPokemon].evolutionName;
									std::list<std::string> buttonStrings = {};
									buttonStrings.push_back("Evolve ");
									buttonStrings.push_back("Don't Evolve ");
									UserOption us = UserOption(headerText, buttonStrings, 5, 180, 30, screenWidth, screenHeight, queue);
									int result = us.valueOfResult;
									// Evolves the pokemon if it evolves and the user says yes
									if (result != -1 && result == 0) {
										Pokemon p = pm.getDefaultPokemon(player.trainersParty[currentPokemon].evolutionName);
										player.trainersParty[currentPokemon].pokemonName = p.pokemonName;
										player.trainersParty[currentPokemon].healthBase = p.healthBase;
										player.trainersParty[currentPokemon].physcialAttackBase = p.physcialAttackBase;
										player.trainersParty[currentPokemon].physicalDefenceBase = p.physicalDefenceBase;
										player.trainersParty[currentPokemon].specialAttackBase = p.specialAttackBase;
										player.trainersParty[currentPokemon].specialDefenceBase = p.specialDefenceBase;
										player.trainersParty[currentPokemon].speedBase = p.speedBase;
										player.trainersParty[currentPokemon].xPositionOnSpriteSheet = p.xPositionOnSpriteSheet;
										player.trainersParty[currentPokemon].yPositionOnSpriteSheet = p.yPositionOnSpriteSheet;
										player.trainersParty[currentPokemon].pokemonTypeOne = p.pokemonTypeOne;
										player.trainersParty[currentPokemon].pokemonTypeTwo = p.pokemonTypeTwo;
										player.trainersParty[currentPokemon].levelUpMoveSet = p.levelUpMoveSet;
										player.trainersParty[currentPokemon].evolutionLevel = p.evolutionLevel;
										player.trainersParty[currentPokemon].evolutionName = p.evolutionName;
									}
								}

								pair<int, int> moveInfo = experienceInfo.second;

								MoveManager mm = mm.instance();

								// If the move is valid, then give the user the option to select wghuch move to replace
								if (moveInfo.first != -1) {
									Move move = mm.getMoveDetails(moveInfo.first);
									string headerText = player.trainersParty[currentPokemon].pokemonName + " is learning " + move.moveName;
									std::list<std::string> buttonStrings = {};
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[0].moveName);
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[1].moveName);
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[2].moveName);
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[3].moveName);
									buttonStrings.push_back("Don't learn!");
									UserOption us = UserOption(headerText, buttonStrings, 5, 180, 30, screenWidth, screenHeight, queue);
									int positionToPutMove = us.valueOfResult;
									cout << "Result of poll: " << positionToPutMove << "\n";
									// Puts the move in the correct position
									if (positionToPutMove != -1 && positionToPutMove < 4) {
										player.trainersParty[currentPokemon].pokemonsMoves[positionToPutMove] = move;
										if (positionToPutMove == 0) {
											attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
										}

										else if (positionToPutMove == 1) {
											attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
										}
									
										else if (positionToPutMove == 2) {
											attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
										}
										else if (positionToPutMove == 3) {
											attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
										}
								
										
									}
									
								}

								// If all the opponents pokemon are not dead, then get the next pokemon
								// if they are then add some money to player and finish
								if (!opponent.isAllPokemonInPartyDead()) {
									currentPokemonOpponent = doTurn.getNextPokemonForOpponent(opponent, currentPokemonOpponent, player.trainersParty[currentPokemon]);
								}
								else {

									player.addMoney(100 * opponent.numberOfPokemonInParty);

									battleFinished = true;
								}
							}

							// Updates the text from do turn

							textForTextBox[0] = doTurn.textForTextBox[0];
							textForTextBox[1] = doTurn.textForTextBox[1];
							textForTextBox[2] = doTurn.textForTextBox[2];
							textForTextBox[3] = doTurn.textForTextBox[3];

							// Uses the move
							player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].useMove();

							// Uses the move inside the button

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
							// Sets the text to say PP is out
							textForTextBox[0] = player.trainersParty[currentPokemon].pokemonsMoves[attackButtonN].moveName + " is out of PP!";
							textForTextBox[1] = "";
							textForTextBox[2] = "";
							textForTextBox[3] = "";
						}
						attackButtonClicked = 0;
					}

				}

				// Checks to see if the players pokemon is dead

				if (player.trainersParty[currentPokemon].currentHealth <= 0) {
					// If all pokemon are dead then set battle finished to true
					if (player.isAllPokemonInPartyDead()) {
						battleFinished = true;
					}
					// Brings up the switching if not every pokemon is dead
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

			// Breaks if done
			if (done) {
				break;
			}

			// Draws the screen
			if (redraw && al_is_event_queue_empty(queue))
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				// Draws the background
				al_draw_scaled_bitmap(background, 0, 0, 400, 225, 0, 0, screenWidth, screenHeight, 0);
				// Drwas the trainer and opponent pokemon
				al_draw_scaled_bitmap(otherPokemonSprite, (80 * opponent.trainersTeam[currentPokemonOpponent].xPositionOnSpriteSheet), (80 * opponent.trainersTeam[currentPokemonOpponent].yPositionOnSpriteSheet), 80, 80, screenWidth * 0.6, screenHeight * 0.25, screenWidth * 0.3, screenWidth * 0.3, 0);
				if (!pokemonIsDead) {
					al_draw_scaled_bitmap(trainsersPokemonSprite, (80 * player.trainersParty[currentPokemon].xPositionOnSpriteSheet), (80 * player.trainersParty[currentPokemon].yPositionOnSpriteSheet), 80, 80, screenWidth * 0.15, screenHeight * 0.42, screenWidth * 0.25, screenWidth * 0.25, 0);
				}

				// If the switch pokemon should be displayed, display all
				if (switchPokemonOneButton.isDisplayed) {
					switchPokemonOneButton.drawSprite(player.trainersParty[0], otherPokemonSprite);
					switchPokemonTwoButton.drawSprite(player.trainersParty[1], otherPokemonSprite);
					switchPokemonThreeButton.drawSprite(player.trainersParty[2], otherPokemonSprite);
					switchPokemonFourButton.drawSprite(player.trainersParty[3], otherPokemonSprite);
					switchPokemonFiveButton.drawSprite(player.trainersParty[4], otherPokemonSprite);
					switchPokemonSixButton.drawSprite(player.trainersParty[5], otherPokemonSprite);
				}

				// If the potion buttons should be displayed, display them
				if (potionButtonOne.isDisplayed) {
					potionButtonOne.drawSprite(player.itemManager.getAmountOfItem(potionButtonOne.potion.inividualItemID));
					potionButtonTwo.drawSprite(player.itemManager.getAmountOfItem(potionButtonTwo.potion.inividualItemID));
					potionButtonThree.drawSprite(player.itemManager.getAmountOfItem(potionButtonThree.potion.inividualItemID));
				}

				// Draws the stat boxes for each pokemon
				otherPokemonStatBox.drawSprite(opponent.trainersTeam[currentPokemonOpponent]);
				trainersPokemonStatBox.drawSprite(player.trainersParty[currentPokemon]);
				backBox.drawSprite();
				textBox.drawSprite();
				// Drwas the rest of the buttons
				attackButton1.drawSprite();
				attackButton2.drawSprite();
				attackButton3.drawSprite();
				attackButton4.drawSprite();
				healPokemonButton.drawSprite();
				switchPokemonButton.drawSprite();
				catchPokemonButton.drawSprite();
				runPokemonButton.drawSprite();

				// If the text box is displayed, display the text
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
	InitiateBattle(int screenWidth, int screenHeight, ALLEGRO_EVENT_QUEUE* queue, PlayerCharacter& player, int locationNumber, int routeNumber) {

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
		PokemonManager pm = pm.instance();

		// Gets the route mapping 
		RouteMapping routeMapping = RouteMapping();
		Pokemon otherPokemon = routeMapping.getSinglePokemonFromRoute(routeNumber);

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
		PokemonStatBox otherPokemonStatBox = PokemonStatBox(256, 96, 510, 20, 320, 75);
		PokemonStatBox trainersPokemonStatBox = PokemonStatBox(256, 96, 70, 20, 320, 75);

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
								PokemonManager pm = pm.instance();
								pair<bool, pair<int, int>> experienceInfo = player.trainersParty[currentPokemon].gainExperience(expGained);

								if (experienceInfo.first) {

									string headerText = player.trainersParty[currentPokemon].pokemonName + " is evolving into " + player.trainersParty[currentPokemon].evolutionName;
									std::list<std::string> buttonStrings = {};
									buttonStrings.push_back("Evolve ");
									buttonStrings.push_back("Don't Evolve ");
									UserOption us = UserOption(headerText, buttonStrings, 5, 180, 30, screenWidth, screenHeight, queue);
									int result = us.valueOfResult;
									if (result != -1 && result == 0) {
										Pokemon p = pm.getDefaultPokemon(player.trainersParty[currentPokemon].evolutionName);
										player.trainersParty[currentPokemon].pokemonName = p.pokemonName;
										player.trainersParty[currentPokemon].healthBase = p.healthBase;
										player.trainersParty[currentPokemon].physcialAttackBase = p.physcialAttackBase;
										player.trainersParty[currentPokemon].physicalDefenceBase = p.physicalDefenceBase;
										player.trainersParty[currentPokemon].specialAttackBase = p.specialAttackBase;
										player.trainersParty[currentPokemon].specialDefenceBase = p.specialDefenceBase;
										player.trainersParty[currentPokemon].speedBase = p.speedBase;
										player.trainersParty[currentPokemon].xPositionOnSpriteSheet = p.xPositionOnSpriteSheet;
										player.trainersParty[currentPokemon].yPositionOnSpriteSheet = p.yPositionOnSpriteSheet;
										player.trainersParty[currentPokemon].pokemonTypeOne = p.pokemonTypeOne;
										player.trainersParty[currentPokemon].pokemonTypeTwo = p.pokemonTypeTwo;
										player.trainersParty[currentPokemon].levelUpMoveSet = p.levelUpMoveSet;
										player.trainersParty[currentPokemon].evolutionLevel = p.evolutionLevel;
										player.trainersParty[currentPokemon].evolutionName = p.evolutionName;
									}
									
								}

								pair<int, int> moveInfo = experienceInfo.second;

								MoveManager mm = mm.instance();

								if (moveInfo.first != -1) {
									Move move = mm.getMoveDetails(moveInfo.first);
									string headerText = player.trainersParty[currentPokemon].pokemonName + " is learning " + move.moveName;
									std::list<std::string> buttonStrings = {};
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[0].moveName);
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[1].moveName);
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[2].moveName);
									buttonStrings.push_back("Replace " + player.trainersParty[currentPokemon].pokemonsMoves[3].moveName);
									buttonStrings.push_back("Don't learn!");
									UserOption us = UserOption(headerText, buttonStrings, 5, 180, 30, screenWidth, screenHeight, queue);
									int positionToPutMove = us.valueOfResult;
									cout << "Result of poll: " << positionToPutMove << "\n";
									if (positionToPutMove != -1 && positionToPutMove < 4) {
										player.trainersParty[currentPokemon].pokemonsMoves[positionToPutMove] = move;
										if (positionToPutMove == 0) {
											attackButton1.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[0];
										}

										else if (positionToPutMove == 1) {
											attackButton2.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[1];
										}

										else if (positionToPutMove == 2) {
											attackButton3.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[2];
										}
										else if (positionToPutMove == 3) {
											attackButton4.pokemonMove = player.trainersParty[currentPokemon].pokemonsMoves[3];
										}


									}

								}
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
					switchPokemonOneButton.drawSprite(player.trainersParty[0], otherPokemonSprite);
					switchPokemonTwoButton.drawSprite(player.trainersParty[1], otherPokemonSprite);
					switchPokemonThreeButton.drawSprite(player.trainersParty[2], otherPokemonSprite);
					switchPokemonFourButton.drawSprite(player.trainersParty[3], otherPokemonSprite);
					switchPokemonFiveButton.drawSprite(player.trainersParty[4], otherPokemonSprite);
					switchPokemonSixButton.drawSprite(player.trainersParty[5], otherPokemonSprite);
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