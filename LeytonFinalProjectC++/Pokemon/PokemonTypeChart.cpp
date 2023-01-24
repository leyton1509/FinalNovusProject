#include "../Pokemon/PokemonType.h"

// Class to handle the effectiveness of moves on different types
class PokemonTypeChart {

public:

	// Returns the effectiveness of a move depending on both of the types of a pokemon
	// * 4 if its really weak to the move
	// * 2 if its weak to the move
	// * 1 if its not weak or strong
	// * 0.5 if its resistent to the move
	// * 0.25 if its really resistent to the move
	double returnEffectivenessOfMove(PokemonType::PokemonTypes typeOfMove, PokemonType::PokemonTypes typeOfPokemon, PokemonType::PokemonTypes type2OfPokemon) {
		double effectiveness = 1;
		effectiveness = effectiveness * returnEffectivenessOfMove(typeOfMove, typeOfPokemon);
		effectiveness = effectiveness * returnEffectivenessOfMove(typeOfMove, type2OfPokemon);
		return effectiveness;
	}

	// Calculates the effectiveness on a single type
	double returnEffectivenessOfMove(PokemonType::PokemonTypes typeOfMove, PokemonType::PokemonTypes typeOfPokemon) {

		double effectiveness = 1;

		switch (typeOfMove)
		{
		case PokemonType::Normal:

				switch (typeOfPokemon)
				{
				case PokemonType::Normal:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Fire:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Water:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Grass:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Electric:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Ice:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Fighting:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Poison:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Ground:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Flying:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Psychic:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Bug:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Rock:
					effectiveness = effectiveness * 0.5;
					break;
				case PokemonType::Ghost:
					effectiveness = effectiveness * 0;
					break;
				case PokemonType::Dark:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Dragon:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::Steel:
					effectiveness = effectiveness * 0.5;
					break;
				case PokemonType::Fairy:
					effectiveness = effectiveness * 1;
					break;
				case PokemonType::None:
					effectiveness = effectiveness * 1;
					break;
				default:
					break;
				}

			break;
		case PokemonType::Fire:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Water:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Grass:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Electric:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 0;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Ice:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Fighting:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 0;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Poison:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Ground:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 0;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Flying:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Psychic:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 0;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Bug:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Rock:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Ghost:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 0;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Dark:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Dragon:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 0;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Steel:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		case PokemonType::Fairy:
			switch (typeOfPokemon)
			{
			case PokemonType::Normal:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fire:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Water:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Grass:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Electric:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ice:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Fighting:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Poison:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Ground:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Flying:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Psychic:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Bug:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Rock:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Ghost:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::Dark:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Dragon:
				effectiveness = effectiveness * 2;
				break;
			case PokemonType::Steel:
				effectiveness = effectiveness * 0.5;
				break;
			case PokemonType::Fairy:
				effectiveness = effectiveness * 1;
				break;
			case PokemonType::None:
				effectiveness = effectiveness * 1;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		return effectiveness;
	}

};
