#pragma once
#include "Board.h"
#include "Graphics.h"

class Snake {
private:
	class Segment {
	public:
		void initHead(const Location& loc1);
		void initBody(Color f);
		void follow(const Segment& next);
		void moveby(const Location& delta_loc);
		void draw(Board& brd);
		const Location& getLoc()const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc1);
	void move(const Location& delta_loc);
	Location getSnekNextLoc(const Location& loc)const;
	void grow();
	bool isInTileExceptEnd(const Location& target)const;
	bool isInTile(const Location& target)const;
	void draw(Board& brd);
	
private:
	static constexpr Color headColor = Colors::LightGray;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegmentsCurrent = 1;
	
};