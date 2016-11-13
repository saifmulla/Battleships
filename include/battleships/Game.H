#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H

/////////////////////////////////////////////
// Class Game
// pure abstract class
// this class acts as interface or pure abstract class, representing a skeleton
// or setting up a framework for game implementation in this library
// any new game type must be subclassed from this base class and must
// override pure virtual functions
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

#include "battleships/Exports.H"

namespace Battleships {

class EXPORTS Game {

public:

	/////////////////////////////////////////////
	// Initialise
	// This is a pure virtual function and must be implemented by polymorphic
	// class. Essentially this function can be used to undertake all the 
	// necessary setup required to start a particular instance of a game.
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
	virtual void initialise() = 0;

	/////////////////////////////////////////////
	// validate
	// this function is a pure virtual function and every subclass must 
	// implement this function based on its implementation, ideally this
	// function must be used to validate all the necessary setup done in
	// game initialsation therefore a final setup checkup could be done
	// before actually doing heavy processing.
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
	virtual void validate() = 0;

	/////////////////////////////////////////////
	// Play
	// This is a pure virtual function and must be implemented by every subclass
	// this is the function where you write all the code to call the low level 
	// implementation of game code such as classes and function related to run 
	// your game code
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
	virtual void play() = 0;

	/////////////////////////////////////////////
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

	virtual bool getResult() = 0;

};

} //end namespace

#endif