#include "gtest/gtest.h"
#include "../Battle/RouteMapping.h"

// Class for testing pokemon move manager
class RouteManagerTests : public ::testing::Test
{

protected:
	RouteMapping routeMap = RouteMapping();

	// Generates a random pokemon and checks its on the pokemon that can be generated
	bool checkPokemonFromRouteRandom()
	{
		Pokemon p = routeMap.getSinglePokemonFromRoute(1);
		string availablePokemon[5] = { "Bulbasaur", "Pidgey", "Bidoof", "Charmander", "Squirtle" };
		for (string& s : availablePokemon)
		{
			if (strcmp(s.c_str(), p.pokemonName.c_str()) == 0)
			{
				return true;
			}
		}

		return false;
	}

	// checks to see if the level is generated within the correct range
	bool checkPokemonFromRouteRandomLevel()
	{
		Pokemon p = routeMap.getSinglePokemonFromRoute(1);
		if(p.level <= 7 && p.level >= 3)
		{
			return true;
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

// Checks to see if a random pokemon is got from the route and is a random level
TEST_F(RouteManagerTests, CheckPokemonFromRouteRandomLevel) {
	ASSERT_TRUE(checkPokemonFromRouteRandomLevel());
	ASSERT_TRUE(checkPokemonFromRouteRandomLevel());
	ASSERT_TRUE(checkPokemonFromRouteRandomLevel());
	ASSERT_TRUE(checkPokemonFromRouteRandomLevel());
}