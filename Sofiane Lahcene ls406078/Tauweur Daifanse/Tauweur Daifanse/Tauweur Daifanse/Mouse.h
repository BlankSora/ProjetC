#ifndef _MOUSE_H
#define _MOUSE_H


class Mouse {
  private:
    float x;

    float y;

    int type;


  public:
    Mouse(float x_, float y_, int type_);

    ~Mouse();

    void setXY(float x_, float y_);

    float getX();

    float getY();

    int getType();

    void setType(int type_);

};
#endif
