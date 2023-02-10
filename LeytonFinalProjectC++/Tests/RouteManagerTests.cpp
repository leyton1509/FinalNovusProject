#include "gtest/gtest.h"
#include "../Battle/RouteMapping.h"

// Class for testing pokemon move manager
class RouteManagerTests : public ::testing::Test
{

protected:
	RouteMapping routeMap = RouteMapping();
};


// Checks to see if experience is dependent on level
TEST_F(RouteManagerTests, CheckPokemonFromRoute) {
	Pokemon p = routeMap.getSinglePokemonFromRoute(1);
	string availablePokemon[5] = { "Bulbasaur", "Pidgey", "Bidoof", "Charmander", "Squirtle" };
	bool found = false;
	for (string& s : availablePokemon)
	{
		if(strcmp(s.c_str(), p.pokemonName.c_str()) == 0)
		{
			found = true;
			ASSERT_EQ(s, p.pokemonName);
		}
	}

	if(!found)
	{
		ASSERT_FALSE(true);
	}
	
}