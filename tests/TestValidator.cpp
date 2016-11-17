#include "gtest/gtest.h"
#include "battleships/Validator.H"
#include <iostream>
#include <vector>

using namespace Battleships;

TEST(TestValidator,displayboard){
	// create 2d grid
	std::vector<std::vector<int>> grid;
	grid.resize(10);
	for(int i = 0; i < 10; ++i){
		grid[i].resize(10);
		for(int j = 0; j<3; ++j)
			grid[i][j] = 1;
	}
	
	Validator validate;
	// ASSERT_TRUE(validate.testboard());
	validate.displayBoard(grid);
}


int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}