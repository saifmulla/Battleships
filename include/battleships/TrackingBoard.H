#ifndef BATTLESHIPS_TRACKINGBOARD_H
#define BATTLESHIPS_TRACKINGBOARD_H

#include "Battleships/Board.H"
#include <vector>

namespace Battleships {

class EXPORTS TrackingBoard : public Board {

private:
	std::vector<std::vector<int>> grid_;
public:
	TrackingBoard();

	virtual void display() override;

	virtual void initialise() override;

	// virtual std::shared_ptr<std::vector<std::vector<int>>> getBoard() override;
	virtual std::vector<std::vector<int>>& getBoard() override;

	virtual const int getCell(int x, int y) const override;

	virtual void setCell(int x, int y, int value) override;

};	

}// end namespace

#endif