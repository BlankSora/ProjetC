#pragma once


class Missile {
  private:
    float x;

    float y;

    float speed;

    int puissance;


  public:
    Missile(float x_, float y_, float speed_, int puissance_) :
    		x(x_),
    		y(y_),
    		speed(speed_),
    		puissance(puissance_) {};

    void draw();

    void move();

    float getX();

    float getY();

    int getPuissance();

};
