#include "battleships/BattleShips.H"
#include "battleships/PrimaryBoard.H"
#include "battleships/TrackingBoard.H"
#include "battleships/Validator.H"

void Battleships::BattleShips::initialise()
{
	// 1. create objects for tracking boards for both players
	trackingBoards_[0] = new Battleships::TrackingBoard();
	trackingBoards_[1] = new Battleships::TrackingBoard();

	// 2. create objects for primary boards for both players
	primaryBoards_[0] = new Battleships::PrimaryBoard();
	primaryBoards_[1] = new Battleships::PrimaryBoard();

	// 3. initialise primary boards for filling ship positions
	trackingBoards_[0]->initialise();
	trackingBoards_[1]->initialise();

	primaryBoards_[0]->initialise();
	primaryBoards_[1]->initialise();

	// 4. bind object of Validate class to valid
	valid_ = new Battleships::Validator();
}

void Battleships::BattleShips::validate()
{
	// 1. validate primary boards to check if 17 boxes are full and 
	// ships appropriately positioned
	valid_->checkPrimaryBoard(primaryBoards_[0]->getBoard());
	valid_->checkPrimaryBoard(primaryBoards_[1]->getBoard());
	// 2. also validate if all the values of tracking boards are set to -1

}

void Battleships::BattleShips::play()
{
	// TODO: this option selection and grid selection must be more elegant
	while(true){
		int x = -1;
		int y = -1;
		int selection = 0;
		std::cout << this->player1_ << " input grid index to fire: ";
		std::cin >> x >> y;
		// get the value of cell from primary board of player 2
		int value1 = primaryBoards_[1]->getCell(x,y);
		// now set this value in the cell of tracking board of player 1
		trackingBoards_[0]->setCell(x,y,value1);
		std::cout << "Would you like to see your boards? (1 => yes or 0 => no) ";
		std::cin >> selection;

		// if selection is 1 then display boards for user
		if(selection == 1){
			this->primaryBoards_[0]->display();
			this->trackingBoards_[0]->display();
		}
		// valid_->displayBoard(trackingBoards_[0]->getBoard());

		if(valid_->getWinner(this->trackingBoards_[0]->getBoard()))
		{
			std::cout << "Congratulations!!! *** " << 
			this->player1_ << " Wins " << std::endl;
			break;
		}

		std::cout << this->player2_ << " input grid index to fire: ";
		std::cin >> x >> y;

		// get the value of cell from primary board of player 1
		int value2 = primaryBoards_[0]->getCell(x,y);
		// now set this value in the cell of tracking board of player 2
		trackingBoards_[1]->setCell(x,y,value2);
		std::cout << "Would you like to see your boards? (1 => yes or 0 => no) ";
		std::cin >> selection;

		// if selection is 1 then display boards for user
		if(selection == 1){
			this->primaryBoards_[1]->display();
			this->trackingBoards_[1]->display();
		}
		// valid_->displayBoard(trackingBoards_[1]->getBoard());

		if(valid_->getWinner(this->trackingBoards_[1]->getBoard()))
		{
			std::cout << "Congratulations!!! *** " << 
			this->player2_ << " *** wins " << std::endl;
			break;
		}
	}
}

bool Battleships::BattleShips::getResult()
{
	return true;
}

////// constructor \\\\\\\\\\\\\\\//

Battleships::BattleShips::BattleShips(
	const std::string player1,
	const std::string player2
	)
:primaryBoards_(0),trackingBoards_(0),valid_(0),player1_(player1),player2_(player2)
{
	primaryBoards_.resize(2);
	trackingBoards_.resize(2);
}

const std::string& Battleships::BattleShips::getPlayer1() const {
	return this->player1_;
}

const std::string& Battleships::BattleShips::getPlayer2() const {
	return this->player2_;
}