#include <iostream>

#include "Libgraph\Engine.h"
#include "Libgraph\ControlEngineBase.h"
#include "Libgraph\GameEngineBase.h"
#include "Libgraph\GraphicEngineBase.h"
#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "MyGraphicEngine.h"
#include "Vaisseau.h"
#include "Mouse.h"
#include "Const.h"
#include "Asteroide.h"
#include "Missile.h"
#include "Game.h"
#include <vector>

int main(int argc, char* argv[]){
	// mettre mouse et tours dans Game
	Mouse *mouse = new Mouse(TOPLEFTX, TOPLEFTY,0);
    Engine e(argc,argv);
    
	std::vector<Vaisseau*> vaisseaux;
	std::vector<Asteroide*> asteroides;
	std::vector<Missile*> missiles;
	bool tours[10*LIGNES] = { false };
	//std::vector<Asteroide*> rangeeAsteroides[LIGNES];
	std::vector<Asteroide*> rangeeAsteroides[LIGNES];
	//std::array<std::vector<Asteroide*>> rangeeAsteroides;
	for (int i = 0; i < LIGNES;i++) {
		rangeeAsteroides[i] = std::vector<Asteroide*>();
	}
	Game *game = new Game(MONEY, 0,VIE);
    
    GraphicEngineBase* ge = new MyGraphicEngine(game,&vaisseaux,rangeeAsteroides,&missiles,mouse);
    GameEngineBase* gme = new MyGameEngine(game,&vaisseaux, rangeeAsteroides,&missiles,tours);
	ControlEngineBase* ce = new MyControlEngine(game, &vaisseaux, rangeeAsteroides, &missiles, tours, mouse);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
