#include "Missile.h"
#include "libGraph\GraphicPrimitives.h"
#include "Const.h"

void Missile::draw() {

	//std::cout << " A(): " << vecx[0] << std::endl;
	//GraphicPrimitives::drawFillPolygone2D(vecx, vecy, r, g, b);
	GraphicPrimitives::drawFillRect2D(x, y, COTE / 2, COTE / 2, 1.0, 1.0, 1.0);
}

void Missile::move() {

	//std::cout << x << std::endl;
	x = x + speed;
	//std::cout << speed << std::endl;
}

float Missile::getX() {

	return x;
}

float Missile::getY() {

	return y;
}

int Missile::getPuissance() {

	return puissance;
}

