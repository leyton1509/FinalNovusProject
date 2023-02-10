#include "gtest/gtest.h"
#include "../Sprites/TrainerManager.h"

// Class for testing pokemon manager
class TrainerTests : public ::testing::Test
{

protected:
	TrainerManager trainerManager = TrainerManager();
};

// Added method for checking trainer get
TEST_F(TrainerTests, CheckGetTrainer) {
	Trainer t = trainerManager.getTrainer(1);
	ASSERT_EQ(t.name, "Elm");
}

