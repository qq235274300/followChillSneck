#pragma once
class Location {
public:

	bool  operator==(const Location& loc)const  {
	return loc.x == x && loc.y == y;
	}

	void add(const Location& loc) {
		x += loc.x;
		y += loc.y;
	};
	
	int x = 0;
	int y = 0;
};