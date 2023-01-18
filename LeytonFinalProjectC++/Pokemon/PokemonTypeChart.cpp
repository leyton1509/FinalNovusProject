#include "../Pokemon/PokemonType.h"


class PokemonTypeChart {

public:

	double returnEffectiveNessOfMove(PokemonType::PokemonTypes typeOfMove, PokemonType::PokemonTypes typeOfPokemon, PokemonType::PokemonTypes type2OfPokemon) {
		double effectiveness = 1;
		effectiveness = effectiveness * returnEffectiveNessOfMove(typeOfMove, typeOfPokemon);
		effectiveness = effectiveness * returnEffectiveNessOfMove(typeOfMove, type2OfPokemon);
		return effectiveness;
	}

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
