#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "Const.h"
#include "MyControlEngine.h"
#include "string.h"

void MyGraphicEngine::Draw() {

	float x = mouse->getX();
	float y = mouse->getY();
	int type = mouse->getType();
	if (type) {
		GraphicPrimitives::drawFillTriangle2D(x - COTE / 2, y + COTE / 2, x - COTE / 2, y - COTE / 2, x + COTE / 2, y, type==3, type==1, type==2);
	}
	MyGraphicEngine::damier();
	MyGraphicEngine::toursdispos();
    GraphicPrimitives::drawText2D("Appuyez sur W pour lancer la vague", -0.4f, 0.9f, 0.0f, 0.0f, 1.0f);
	
	sprintf(money, "%s%d", "Gold ", game->getMoney());
	sprintf(vies, "%s%d", "Vies ", game->getVie());
	sprintf(wave, "%s%d", "Wave ", game->getWave());

	
	GraphicPrimitives::drawText2D(money, 0.7f, 0.9f, 1.0f, 1.0f, 0.0f);
	GraphicPrimitives::drawText2D(vies, -0.95f, 0.9f, 1.0f, 0.0f, 0.0f);
	GraphicPrimitives::drawText2D(wave, -0.95f, 0.8f, 0.0f, 0.0f, 1.0f);
	GraphicPrimitives::drawText2D("15 G", TOPLEFTX, POSACHATY-COTE, 1.0f, 1.0f, 0.0f);
	GraphicPrimitives::drawText2D("25 G", TOPLEFTX+2*COTE, POSACHATY - COTE, 1.0f, 1.0f, 0.0f);
	GraphicPrimitives::drawText2D("40 G", TOPLEFTX+4*COTE, POSACHATY - COTE, 1.0f, 1.0f, 0.0f);
	if (game->GAMEOVER) {
		GraphicPrimitives::drawText2D("GAME OVER", -0.2f, 0.75f, 1.0f, 0.0f, 0.0f);
	}
	if (game->VICTOIRE) {
		GraphicPrimitives::drawText2D("VICTOIRE", -0.2f, 0.75f, 0.0f, 1.0f, 0.0f);
	}
	//free(money);

	for (int i = 0; i < vaisseaux->size(); i++) {
		(*vaisseaux)[i]-> draw();
	}
	for (int j = 0; j < LIGNES; j++) {
		std::vector<Asteroide*> *asteroides = &rangeeAsteroides[j];
		for (int i = 0; i < asteroides->size(); i++) {
			(*asteroides)[i]->draw();
		}
	}
	for (int i = 0; i < missiles->size(); i++) {
		//std::cout << "hello" << std::endl;
		(*missiles)[i]->draw();
	}
    
}

void MyGraphicEngine::damier() {

	for (int i = 0; i < 11; i++) {
		GraphicPrimitives::drawLine2D(TOPLEFTX+i*COTE, TOPLEFTY, TOPLEFTX+i*COTE, TOPLEFTY - LIGNES*COTE, 1.0f, 1.0f, 1.0f);
	}
	for (int j = 0; j < LIGNES+1; j++) {
		GraphicPrimitives::drawLine2D(TOPLEFTX, TOPLEFTY - j * COTE, TOPLEFTX + 10 * COTE, TOPLEFTY - j * COTE, 1.0f, 1.0f, 1.0f);
	}
}

void MyGraphicEngine::toursdispos() {

	float x=TOPLEFTX;
	float y=POSACHATY;
	std::vector<float> vecx;
	std::vector<float> vecy;
	vecx = { x,x + COTE,x + COTE / 2 };
	vecy = { y,y,y + COTE };
	GraphicPrimitives::drawFillPolygone2D(vecx, vecy, 0, 1, 0);
	x = x + COTE * 2;
	vecx = { x,x + COTE,x + COTE / 2 };
	GraphicPrimitives::drawFillPolygone2D(vecx, vecy, 0, 0, 1);
	x = x + COTE * 2;
	vecx = { x,x + COTE,x + COTE / 2 };
	GraphicPrimitives::drawFillPolygone2D(vecx, vecy, 1, 0, 0);
}

