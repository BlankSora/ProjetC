#pragma once
class Asteroide
{
	float x;
	float y;
	float speed;
	int vie;
	int type;
	int gold;
public:
	Asteroide(float x_, float y_, int type_);
	void move();
	void draw();
	int getGold();
	float getY();
	float getX();
	int getVie();
	void setVie(int vie_);
};