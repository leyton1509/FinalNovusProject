#include <string>

class PokemonType {

	public:

		enum PokemonTypes
		{
			Normal,
			Fire,
			Water,
			Grass,
			Electric,
			Ice,
			Fighting,
			Poison,
			Ground,
			Flying,
			Psychic,
			Bug,
			Rock,
			Ghost,
			Dark,
			Dragon,
			Steel,
			Fairy,
			None
		};

        std::string getStringFromEnumType(PokemonType::PokemonTypes type) {
            switch (type)
            {
            case PokemonType::Normal:
                return "Normal";
            case PokemonType::Fire:
                return "Fire";
            case PokemonType::Water:
                return "Water";
            case PokemonType::Grass:
                return "Grass";
            case PokemonType::Electric:
                return "Electric";
            case PokemonType::Ice:
                return "Ice";
            case PokemonType::Fighting:
                return "Fighting";
            case PokemonType::Poison:
                return "Poison";
            case PokemonType::Ground:
                return "Ground";
            case PokemonType::Flying:
                return "Flying";
            case PokemonType::Psychic:
                return "Psychic";
            case PokemonType::Bug:
                return "Bug";
            case PokemonType::Rock:
                return "Rock";
            case PokemonType::Ghost:
                return "Ghost";
            case PokemonType::Dark:
                return "Dark";
            case PokemonType::Dragon:
                return "Dragon";
            case PokemonType::Steel:
                return "Steel";
            case PokemonType::Fairy:
                return "Fairy";
            case PokemonType::None:
                return "";
            default:
                return "";
            }
        }

        PokemonType::PokemonTypes getEnumFromStringMove(std::string typeString) {
            if (typeString.compare("Normal") == 0) {
                return PokemonType::PokemonTypes::Normal;
            }
            else if (typeString.compare("Fire") == 0) {
                return PokemonType::PokemonTypes::Fire;
            }
            else if (typeString.compare("Water") == 0) {
                return PokemonType::PokemonTypes::Water;
            }
            else if (typeString.compare("Grass") == 0) {
                return PokemonType::PokemonTypes::Grass;
            }
            else if (typeString.compare("Electric") == 0) {
                return PokemonType::PokemonTypes::Electric;
            }
            else if (typeString.compare("Ice") == 0) {
                return PokemonType::PokemonTypes::Ice;
            }
            else if (typeString.compare("Poison") == 0) {
                return PokemonType::PokemonTypes::Poison;
            }
            else if (typeString.compare("Ground") == 0) {
                return PokemonType::PokemonTypes::Ground;
            }
            else if (typeString.compare("Flying") == 0) {
                return PokemonType::PokemonTypes::Flying;
            }
            else if (typeString.compare("Psychic") == 0) {
                return PokemonType::PokemonTypes::Psychic;
            }
            else if (typeString.compare("Bug") == 0) {
                return PokemonType::PokemonTypes::Bug;
            }
            else if (typeString.compare("Rock") == 0) {
                return PokemonType::PokemonTypes::Rock;
            }
            else if (typeString.compare("Ghost") == 0) {
                return PokemonType::PokemonTypes::Ghost;
            }
            else if (typeString.compare("Dark") == 0) {
                return PokemonType::PokemonTypes::Dark;
            }
            else if (typeString.compare("Dragon") == 0) {
                return PokemonType::PokemonTypes::Dragon;
            }
            else if (typeString.compare("Steel") == 0) {
                return PokemonType::PokemonTypes::Steel;
            }
            else if (typeString.compare("Fairy") == 0) {
                return PokemonType::PokemonTypes::Fairy;
            }
            else {
                return PokemonType::PokemonTypes::None;
            }
        }

};



