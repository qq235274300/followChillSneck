#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx):
	gfx(gfx)
{
	
}

void Board::draw(const Location & loc, Color c)
{
	const int off_x = borderPosx+ borderPadding;
	const int off_y = borderPosy+ borderPadding;
	gfx.DrawRectDim(loc.x*cellDimension+ off_x + cellPadding, loc.y*cellDimension+ off_y + cellPadding, cellDimension-2* cellPadding, cellDimension- 2 * cellPadding, c);
}

int Board::getBoardWidth()
{
	return boardWidth;
}

int Board::getBoardHeight()
{
	return boardHeight;
}

bool Board::isInBoard(const Location& loc) const
{
	return loc.x>=0&&loc.x<boardWidth&&loc.y>=0&&loc.y<boardHeight;
}

void Board::drawBorder()
{
	const int top = borderPosy;
	const int left = borderPosx;
	const int right = borderPosx + 2 * (borderWidth + borderPadding) + boardWidth * cellDimension;
	const int bottom = top + 2 * (borderWidth + borderPadding) + boardHeight * cellDimension;
	
	//top 
	gfx.DrawRect(left, top, right, top + borderWidth,borderColor);
	//left
	gfx.DrawRect(left,top + borderWidth, left+ borderWidth, bottom-borderWidth, borderColor);
	//right
	gfx.DrawRect(left+ borderWidth+ 2*borderPadding+ boardWidth * cellDimension, top + borderWidth, right, bottom - borderWidth, borderColor);
	//bottom
	gfx.DrawRect(left, top+ borderWidth + 2 * borderPadding + boardHeight * cellDimension, right, bottom, borderColor);

	
	
}
