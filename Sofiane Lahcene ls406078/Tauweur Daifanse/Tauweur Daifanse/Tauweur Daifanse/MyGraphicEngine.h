#pragma once
#include "Libgraph\Engine.h"
#include "Libgraph\GraphicPrimitives.h"
#include "Vaisseau.h"
#include "Mouse.h"
#include "Asteroide.h"
#include "Missile.h"
#include "Game.h"

class Vaisseau;
class Asteroide;
class Missile;
class Mouse;
class Game;

class MyGraphicEngine : public GraphicEngineBase {
  private:
    std::vector<Vaisseau*> * vaisseaux;

    std::vector<Asteroide*> * rangeeAsteroides;

    std::vector<Missile*> * missiles;

    Mouse * mouse;

    Game * game;

    char * money=  (char *)malloc(13);

    char * vies=  (char *)malloc(8);

    char * wave=  (char *)malloc(15);


  public:
    inline MyGraphicEngine(Game * game_, std::vector<Vaisseau *> * vaisseaux_, std::vector<Asteroide *> rangeeAsteroides_[], std::vector<Missile *> * missiles_, Mouse * mouse_) :
    		mouse(mouse_),
    		rangeeAsteroides(rangeeAsteroides_),
    		vaisseaux(vaisseaux_),
    		missiles(missiles_),
    		game(game_)
            {};


    virtual void Draw();

    void damier();

    void toursdispos();

};
