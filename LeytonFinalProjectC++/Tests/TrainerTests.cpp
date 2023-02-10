#include "gtest/gtest.h"
#include "../Sprites/TrainerManager.h"

// Class for testing pokemon manager
class TrainerTests : public ::testing::Test
{

protected:
	TrainerManager trainerManager = TrainerManager();

	bool mapHasTrainer(int mapN)
	{
		std::list<Trainer> trainers = trainerManager.getTrainersForMap(mapN);
		bool hasTrainer = false;
		for (Trainer& t : trainers)
		{
			return true;
		}
		return false;
	}
};

// Added method for checking trainer get
TEST_F(TrainerTests, CheckGetTrainer) {
	Trainer t = trainerManager.getTrainer(1);
	ASSERT_EQ(t.name, "Elm");
}

// Added method for checking trainer get for map
TEST_F(TrainerTests, CheckGetTrainerForMap) {
	
}
