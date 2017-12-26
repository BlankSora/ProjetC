#include "Asteroide.h"
#include "libGraph\GraphicPrimitives.h"
#include "Const.h"

Asteroide::Asteroide(float x_, float y_, int type_) {

	x = x_;
	y = y_;
	type = type_;
	switch (type_) {
	case 1:
		speed = 0.0001;
		vie = 40;
		gold = 3;
		break;
	case 2:
		speed = 0.0002;
		vie = 80;
		gold = 4;
		break;
	case 3:
		speed = 0.0001;
		vie = 250;
		gold = 6;
		break; 
	}
	
}

void Asteroide::move() {

	x = x - speed;
}

void Asteroide::draw() {

	int r = (type == 3);
	int g = (type == 1);
	int b = (type == 2);
	GraphicPrimitives::drawFillRect2D(x, y, COTE, COTE, r, g, b);
}

int Asteroide::getGold() {

	return gold;
}

float Asteroide::getY() {

	return y;
}

float Asteroide::getX() {

	return x;
}

int Asteroide::getVie() {

	return vie;
}

void Asteroide::setVie(int vie_) {

	vie = vie_;
}

