#pragma once
#include "Board.h"
#include "Snake.h"
#include <random>

class Goal {
	
public:
	Goal(std::default_random_engine e, Board& brd, Snake& snek);
	void reSpawn(std::default_random_engine e,Board& brd,Snake& snek);
	void draw(Board& brd)const;
	const Location& getLocation()const;


private:
	Location loc;
	static constexpr Color goalColor = Colors::Red;
};
