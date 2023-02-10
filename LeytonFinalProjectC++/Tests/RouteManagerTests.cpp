#include "gtest/gtest.h"
#include "../Battle/RouteMapping.h"

// Class for testing pokemon move manager
class RouteManagerTests : public ::testing::Test
{

protected:
	RouteMapping routeMap = RouteMapping();

	bool checkPokemonFromRouteRandom()
	{
		Pokemon p = routeMap.getSinglePokemonFromRoute(1);
		string availablePokemon[5] = { "Bulbasaur", "Pidgey", "Bidoof", "Charmander", "Squirtle" };
		bool found = false;
		for (string& s : availablePokemon)
		{
			if (strcmp(s.c_str(), p.pokemonName.c_str()) == 0)
			{
				return true;
			}
		}

		return false;
	}
};



// Checks to see if a random pokemon is got from the route
TEST_F(RouteManagerTests, CheckPokemonFromRoute) {
	ASSERT_TRUE(checkPokemonFromRouteRandom());
	ASSERT_TRUE(checkPokemonFromRouteRandom());
	ASSERT_TRUE(checkPokemonFromRouteRandom());
	ASSERT_TRUE(checkPokemonFromRouteRandom());
	
}