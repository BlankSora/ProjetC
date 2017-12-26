#pragma once
#include "libGraph/GraphicPrimitives.h"
#include <time.h>
#include <chrono>
class Vaisseau {
public:
	Vaisseau(float x, float y, int type);
	void draw();
	std::chrono::time_point<std::chrono::system_clock> Vaisseau::getTime();
	void Vaisseau::setTime(std::chrono::time_point<std::chrono::system_clock> time_);
	//std::vector<float> vecx;
	//std::vector<float> vecy;
	float x;
	float y;
	int type;
	int power;
	float freq;
	std::chrono::time_point<std::chrono::system_clock> time = std::chrono::system_clock::now();
	float vitesse = 0.0003;
};
