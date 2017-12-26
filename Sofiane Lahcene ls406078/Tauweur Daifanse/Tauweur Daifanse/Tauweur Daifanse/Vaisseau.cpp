
#include "Vaisseau.h"
#include "Const.h"

Vaisseau::Vaisseau(float x, float y, int type) {

	this->x = x;
	this->y = y;
	this->type = type;
	switch (type) {
	case 1:
		this->power = 10;
		this->freq = 0.5;
		break;
	case 2:
		this->power = 15;
		this->freq = 1.0;
		break;
	case 3:
		this->power = 60;
		this->freq = 0.75;
		break;
	}

	/*std::cout << " A(): " << vecy[2] << std::endl;*/
	int r = (type == 3);
	int g = (type == 1);
	int b = (type == 2);
}

void Vaisseau::draw() {

	//std::cout << " A(): " << vecx[0] << std::endl;
	int r = (type == 3);
	int g = (type == 1);
	int b = (type == 2);
	GraphicPrimitives::drawFillTriangle2D(x,y,x,y+COTE,x+COTE,y+COTE/2, r, g, b);
}

std::chrono::time_point<std::chrono::system_clock> Vaisseau::getTime()
{
	return time;
}



void Vaisseau::setTime(std::chrono::time_point<std::chrono::system_clock> time_) {
	time = time_;
}

