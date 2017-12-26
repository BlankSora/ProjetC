#pragma once

#include "Libgraph\Engine.h"
#include "Libgraph\GameEngineBase.h"
#include "Vaisseau.h"
#include "Missile.h"
#include "Game.h"
#include "Asteroide.h"



class MyGameEngine : public GameEngineBase {
  private:
    std::vector<Vaisseau*> * vaisseaux;

    //std::vector<Asteroide*>* asteroides;
    
    std::vector<Missile*> * missiles;

    std::vector<Asteroide*> * rangeeAsteroides;

    bool * tours;

    //int compteur = 0;
    
    Game * game;

    //int nbasteroides;
    
    int asteroideActuel;


  public:
    inline MyGameEngine(Game * game_, std::vector<Vaisseau*> * vaisseaux_, std::vector<Asteroide*> rangeeAsteroides_[], std::vector<Missile*> * missiles_, bool * tours_) :vaisseaux(vaisseaux_),
    		rangeeAsteroides(rangeeAsteroides_),
    		missiles(missiles_),
    		tours(tours_),
    		game(game_)
    	{
    	};

    virtual void idle();

};
