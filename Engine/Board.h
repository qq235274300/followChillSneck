#pragma once

#include "Location.h"
#include "Graphics.h"

class Board {

public:
	Board(Graphics& gfx);
	void draw(const Location& loc, Color c);
	int getBoardWidth();
	int getBoardHeight();
	bool isInBoard(const Location& loc)const;
	void drawBorder();


private:
	static constexpr int cellDimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int boardWidth = 32;
	static constexpr int boardHeight = 24;

	static constexpr int borderPosx = 70;
	static constexpr int borderPosy = 50;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr Color borderColor = Colors::Blue;
	Graphics& gfx;
};
