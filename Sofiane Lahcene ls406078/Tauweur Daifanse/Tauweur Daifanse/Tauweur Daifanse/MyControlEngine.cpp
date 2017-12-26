
#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "Vaisseau.h"
#include "Asteroide.h"
#include "Missile.h"
#include "Mouse.h"
#include "Game.h"
#include "Const.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		float posx = (x - 400) / 400.f;
		float posy = (y - 300) / -300.f;
		if (posx > TOPLEFTX && posy < TOPLEFTY && posx < BOTTOMRIGHTX && posy > BOTTOMRIGHTY) {
			float newx = floor(posx / COTE) * COTE;
			float newy = floor(posy / COTE) * COTE;
			//std::cout << convertPos(newx, newy) << std::endl;
			if (type != 0 && tours[convertPos(newx,newy)] == false && game->getMoney() >= money) {
				vaisseaux->push_back(new Vaisseau(newx, newy, type));
				tours[convertPos(newx, newy)] = true;
				game->setMoney(game->getMoney() - money);
			}
			type = 0;
			mouse->setType(0);
			money = 0;
		}
		else if (posx > TOPLEFTX && posx < (TOPLEFTX + COTE) && posy < (POSACHATY + COTE) && posy > (POSACHATY)) {
			//std::cout << "type 1" << std::endl;
			type = 1;
			money = 15;
			mouse->setType(1);
		}
		else if (posx > (TOPLEFTX + 2*COTE) && posx < (TOPLEFTX + 3*COTE) && posy > POSACHATY && posy < (POSACHATY + COTE)) {
			type = 2;
			money = 25;
			mouse->setType(2);
		}
		else if (posx > (TOPLEFTX + 4*COTE) && posx < (TOPLEFTX + 5*COTE) && posy > POSACHATY && posy < (POSACHATY + COTE)) {
			type = 3;
			money = 40;
			mouse->setType(3);
		}
		else {
			//std::cout << "type 0" << std::endl;
			
			type = 0;
			mouse->setType(0);
		}
		//vaisseaux->push_back(new Vaisseau((x - 400) / 400.f, (y - 300) / -300.f,0));
    }
	
}

//virtual void MotionCallback(int x, int y);
void MyControlEngine::PassiveMotionCallback(int x, int y) {

	float posx = (x - 400) / 400.f;
	float posy = (y - 300) / -300.f;
	mouse->setXY(posx, posy);
}

void MyControlEngine::KeyboardCallback(unsigned char key, int x, int y) {

	if (key == 'w' && !game->isWave() && missiles->empty()) {
		game->setWave(game->getWave() + 1);
		game->setIsWave(true);
		game->setTime(std::chrono::system_clock::now());
		//generateWave();
	}
}

int MyControlEngine::convertPos(float x, float y) {

	int nbCOTE = (x - TOPLEFTX)/(COTE-0.0001);
	int nbY = (TOPLEFTY - y) / (COTE - 0.0001);
	nbY = nbY - 1;
	//std::cout << nbCOTE << std::endl;
	//std::cout << nbY << std::endl;
	return nbY * 10 + nbCOTE;
}

