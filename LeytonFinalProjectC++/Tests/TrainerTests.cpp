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
	ASSERT_TRUE(mapHasTrainer(1));
}


// Testing in line of sight function
TEST_F(TrainerTests, CheckLineOfSight) {
	Trainer t = trainerManager.getTrainer(1);

	t.setPositions(5, 5, 0, 1, 1);
	ASSERT_TRUE(t.isInLineOfSight(5, 4));
	ASSERT_TRUE(t.isInLineOfSight(5, 3));
	ASSERT_TRUE(t.isInLineOfSight(5, 2));
	ASSERT_TRUE(t.isInLineOfSight(5, 1));
	

	t.setPositions(5, 5, 0, -1, 1);
	ASSERT_TRUE(t.isInLineOfSight(5, 6));
	ASSERT_TRUE(t.isInLineOfSight(5, 7));
	ASSERT_TRUE(t.isInLineOfSight(5, 8));
	ASSERT_TRUE(t.isInLineOfSight(5, 9));

	t.setPositions(5, 5, 1, 0, 1);
	ASSERT_TRUE(t.isInLineOfSight(6, 5));
	ASSERT_TRUE(t.isInLineOfSight(7, 5));
	ASSERT_TRUE(t.isInLineOfSight(8, 5));
	ASSERT_TRUE(t.isInLineOfSight(9, 5));
	t.setPositions(5, 5, -1, 0, 1);
	ASSERT_TRUE(t.isInLineOfSight(4, 5));
	ASSERT_TRUE(t.isInLineOfSight(3, 5));
	ASSERT_TRUE(t.isInLineOfSight(2, 5));
	ASSERT_TRUE(t.isInLineOfSight(1, 5));

	
}