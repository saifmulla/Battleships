#include "gtest/gtest.h"
#include "battleships/Exports.H"
#include "battleships/Board.H"
#include "battleships/PrimaryBoard.H"
#include "battleships/TrackingBoard.H"
#include <iostream>
#include <cstdlib>

using namespace Battleships;

TEST(TestBoard, testPrimary){
	PrimaryBoard b;
	// Board* b = new PrimaryBoard();
}

TEST(TestBoard, testTracking){
	TrackingBoard b;
	// Board* b = new PrimaryBoard();
}

TEST(TestBoard, testRandom){
	int n(0);
	while(n<10){
		int r = rand() % 1+1;
		std::cout << r << std::endl;
		++n;
	}	
}


int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
