#pragma once
class Point
{
	int x, y;
public:
	Point();
	Point(int x, int y);

	int getX();
	int getY();

	void setCoords(int x, int y = -1);


	Point operator+(Point& right);
	Point operator-(Point& right);
};
