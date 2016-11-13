#include "gtest/gtest.h"
#include "battleships/BattleShips.H"
#include <iostream>
#include <cstdlib>

using namespace Battleships;

TEST(TestBattleShips, construct){
	BattleShips battleship("saif","hadi");
}

TEST(TestBattleShips, functions){
	BattleShips* battle = new BattleShips("saif","hadi");
	std::string& p1 = const_cast<std::string&>(battle->getPlayer1());
	EXPECT_EQ("saif",p1);
	EXPECT_EQ("hadi",battle->getPlayer2());
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}