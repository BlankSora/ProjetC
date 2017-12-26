#pragma once
#include "Libgraph\Engine.h"
#include "Vaisseau.h"
#include "Mouse.h"
#include "Asteroide.h"
#include "Game.h"
#include "Missile.h"


class MyControlEngine : public ControlEngineBase {
  private:
    std::vector<Vaisseau*> * vaisseaux;

    std::vector<Asteroide*> * rangeeAsteroides;

    std::vector<Missile*> * missiles;

    int type=  0;

    int money=  0;

    bool * tours;

    Mouse * mouse;

    Game * game;


  public:
    inline MyControlEngine(Game * game_, std::vector<Vaisseau*> * vaisseaux_, std::vector<Asteroide*> rangeeAsteroides_[], std::vector<Missile*> * missiles_, bool * tours_, Mouse * mouse_) :
    		vaisseaux(vaisseaux_),
    		rangeeAsteroides(rangeeAsteroides_),
    		missiles(missiles_),
    		mouse(mouse_),
    		tours(tours_),
    		game(game_)
    	{};

    virtual void MouseCallback(int button, int state, int x, int y);

    //virtual void MotionCallback(int x, int y);
    virtual void PassiveMotionCallback(int x, int y);

    virtual void KeyboardCallback(unsigned char key, int x, int y);

    int convertPos(float x, float y);

};