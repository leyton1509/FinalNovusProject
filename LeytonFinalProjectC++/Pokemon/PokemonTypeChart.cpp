#include "../Pokemon/PokemonType.h"


class PokemonTypeChart {

public:

	double returnEffectiveNessOfMove(PokemonType::PokemonTypes typeOfMove, PokemonType::PokemonTypes typeOfPokemon) {

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
			default:
				break;
			}
			break;
		case PokemonType::Ice:

			break;
		case PokemonType::Fighting:
			break;
		case PokemonType::Poison:
			break;
		case PokemonType::Ground:
			break;
		case PokemonType::Flying:
			break;
		case PokemonType::Psychic:
			break;
		case PokemonType::Bug:
			break;
		case PokemonType::Rock:
			break;
		case PokemonType::Ghost:
			break;
		case PokemonType::Dark:
			break;
		case PokemonType::Dragon:
			break;
		case PokemonType::Steel:
			break;
		case PokemonType::Fairy:
			break;
		default:
			break;
		}

		return effectiveness;
	}

};
