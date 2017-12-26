
#include "Mouse.h"

Mouse::Mouse(float x_, float y_, int type_) {

	x = x_;
	y = y_;
	type = type_;
}

Mouse::~Mouse() {

}

void Mouse::setXY(float x_, float y_) {

	x = x_;
	y = y_;
}

float Mouse::getX() {

	return x;
}

float Mouse::getY() {

	return y;
}

int Mouse::getType() {

	return type;
}

void Mouse::setType(int type_) {

	type = type_;
}

