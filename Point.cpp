#include "Point.h"
Point::Point() {
	this->x = -1;
	this->y = -1;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::getX() {
	return this->x;
}

int Point::getY() {
	return this->y;
}

void Point::setCoords(int x, int y) {
	if (x != -1) this->x = x;
	if (y != -1) this->y = y;
}
	
Point Point::operator+(Point& right) {
	Point res;
	res.x = this->x + right.x;
	res.y = this->y + right.x;
	return res;
}

Point Point::operator-(Point& right) {
	Point res;
	res.x = this->x - right.x;
	res.y = this->y - right.x;
	return res;
}
