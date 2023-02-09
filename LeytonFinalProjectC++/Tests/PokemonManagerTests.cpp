#include "gtest/gtest.h"
#include "../Pokemon/PokemonManager.h"
class PokemonManagerTests : public ::testing::Test
{

protected:
	PokemonManager pokemonManager = pokemonManager.instance();


};


TEST_F(PokemonManagerTests, CheckPokemonManagerInstance) {
	ASSERT_NE(pokemonManager, NULL);
}
TEST_F(PokemonManagerTests, CheckFirstPokemon) {
	Pokemon testP =  pokemonManager.getDefaultPokemon("Charmander");
	ASSERT_EQ(testP.pokemonName, "Charmander");
	ASSERT_EQ(testP.level,1);
	testP.setPokemonsLevel(5);
	ASSERT_EQ(testP.level, 5);
	ASSERT_EQ(testP.pokemonName, "Charmander");
}