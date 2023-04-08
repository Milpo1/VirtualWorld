#include "Point.h"
Point::Point() {
	this->x = -1;
	this->y = -1;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::getX() const {
	return this->x;
}

int Point::getY() const {
	return this->y;
}

void Point::setCoords(int x, int y) {
	this->x = x;
	this->y = y;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
	return out << "(" << point.getX() << ", " << point.getY() << ")";
}

Point Point::getRandomUnitVector() {
	int dx = 0, dy = 0;
	if (chooseRand()) dx = chooseRand(-1, 1);
	else dy = chooseRand(-1, 1);
	return Point(dx, dy);
}
	
Point Point::operator+(Point& right) {
	return Point(this->x + right.x, this->y + right.y);
}

Point Point::operator-(Point& right) {
	return Point(this->x - right.x, this->y - right.y);
}

Point Point::operator*(int scale) {
	return Point(this->x*scale,this->y*scale);
}

int intRandRange(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int chooseRand(int a, int b) {
	return intRandRange(0, 1) == 1 ? b : a;
}