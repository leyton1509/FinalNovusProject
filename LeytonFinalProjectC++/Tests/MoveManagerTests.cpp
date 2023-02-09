#include "gtest/gtest.h"
#include "../Pokemon/Moves/MoveManager.h"
// Class for testing pokemon manager
class MoveManagerTests : public ::testing::Test
{

protected:
	MoveManager moveManager = moveManager.instance();
};