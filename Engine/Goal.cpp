#include "Goal.h"

Goal::Goal(std::default_random_engine e, Board & brd, Snake & snek)
{
	reSpawn(e, brd, snek);
}

void Goal::reSpawn(std::default_random_engine e, Board & brd, Snake & snek)
{
	std::uniform_int_distribution<int> Disx(0, brd.getBoardWidth() - 1);
	std::uniform_int_distribution<int> Disy(0, brd.getBoardHeight() - 1);
	
	do {
		loc.x = Disx(e);
		loc.y = Disy(e);
	} while (snek.isInTile(loc));

}

void Goal::draw(Board& brd) const
{
	brd.draw(loc, goalColor);
}

const Location & Goal::getLocation() const
{
	return loc;
}
