#include "Snake.h"
#include <assert.h>

void Snake::Segment::initHead(const Location& loc1)
{
	loc = loc1;
	c = Snake::headColor;
}

void Snake::Segment::initBody(Color f)
{
	c = f;
}

void Snake::Segment::follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::moveby(const Location& delta_loc)
{
	//assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void Snake::Segment::draw(Board& brd)
{
	brd.draw(loc,c);
}

const Location & Snake::Segment::getLoc()const
{
	return loc;
}

Snake::Snake(const Location& loc1)
{
	constexpr int nBodyColor = 4;
	constexpr Color colorArray[nBodyColor] = {
		{10,100,32},
		{ 10,130,48 },
		{ 10,160,48 },
		{ 10,130,48 }
	};
	for (int i =0; i < nSegmentsMax; ++i) {
		segments[i].initBody(colorArray[i%nBodyColor]);
	}
		
	segments[0].initHead(loc1);
}

void Snake::move(const Location& delta_loc)
{
	for (int i = nSegmentsCurrent-1; i > 0; --i) {
		segments[i].follow(segments[i-1]);
	}
	segments[0].moveby(delta_loc);
}

Location Snake::getSnekNextLoc(const Location& loc) const
{
	Location loc1 = segments[0].getLoc();
	loc1.add(loc);
	return loc1;
}

void Snake::grow()
{
	if (nSegmentsCurrent < nSegmentsMax) {
		
		++nSegmentsCurrent;
	}
	
}

bool Snake::isInTileExceptEnd(const Location& target) const
{
	bool inTie = false;
	for (int i = 0; i < nSegmentsCurrent - 1; ++i) {
		if (segments[i].getLoc() == target) {
			inTie= true;
		}
	}
	return inTie;
}
bool Snake::isInTile(const Location& target) const
{
	bool inTie = false;
	for (int i = 0; i < nSegmentsCurrent; ++i) {
		if (segments[i].getLoc() == target) {
			inTie = true;
		}
	}
	return inTie;
}

void Snake::draw(Board& brd)
{
	for (int i = 0; i <nSegmentsCurrent; ++i) {
		segments[i].draw(brd);
	}
}
