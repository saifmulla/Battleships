#include "gtest/gtest.h"
#include "battleships/Exports.H"
#include "battleships/Board.H"
#include "battleships/PrimaryBoard.H"
#include "battleships/TrackingBoard.H"
#include "battleships/Validator.H"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace Battleships;

TEST(TestBoard, testPrimary){
	Board* b = new PrimaryBoard();
	b->initialise();
	Validator valid;
	ASSERT_TRUE(valid.checkPrimaryBoard(b->getBoard()));
}

TEST(TestBoard, testTracking){

	// needless to have a enum class a better way would be a 
	// mock
	enum class Ships : int {
		One = 1, // ship with 1 squares
		Two, // ship with 2 squares
		Three, // ship with 3 squares
		Four, // ship with 4 squares
		Five //ship with 5 squares
	};
	TrackingBoard* t = new TrackingBoard();
	t->initialise();
	Validator valid;
	ASSERT_FALSE(valid.getWinner(t->getBoard()));
	// just fake a winner here
	std::vector<std::vector<int>>& grid = t->getBoard();
	for(int i = 1;i<=5;++i)
		grid[i][4] = static_cast<int>(Ships::Five);//five

	grid[0][0] = grid[0][1] = static_cast<int>(Ships::Two);//two
	grid[0][3] = grid[0][4] = grid[0][5] = grid[0][6] = static_cast<int>(
		Ships::Four
		);//four

	for(int i = 1;i<=3;++i)
		grid[i][1] = grid[i][6] = static_cast<int>(Ships::Three);
	
	ASSERT_TRUE(valid.getWinner(t->getBoard()));
}

TEST(TestBoard, testRandom){
	int n(0);
	while(n<10){
		int r = rand() % 2;
		++n;
	}	
}


int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
