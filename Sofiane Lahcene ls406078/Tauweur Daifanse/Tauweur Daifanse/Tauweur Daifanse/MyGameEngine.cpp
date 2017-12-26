#include "MyGameEngine.h"
#include <chrono>
#include "Const.h"

void MyGameEngine::idle() {

	if (!game->GAMEOVER && !game->VICTOIRE) {

		//generate wave

		if (game->isWave()) {
			std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed = now - game->getTime();
			int wave = game->getWave();
			float spawnFreq = ceil(2.0 / wave);
			//int nbasteroides = wave + LIGNES - 1;
			int nbasteroides = wave%5 + LIGNES - 1;
			if (elapsed.count() > spawnFreq && nbasteroides > asteroideActuel) {
				//std::cout << "nbasteroides" << nbasteroides << std::endl;
				//std::cout << "asteroideActuel" << asteroideActuel << std::endl;
				if (wave < 5) {
					int random = rand() % LIGNES;
					//asteroides->push_back(new Asteroide(0.9, TOPLEFTY - COTE * (random + 1), 1));
					rangeeAsteroides[random].push_back(new Asteroide(0.9, TOPLEFTY - COTE * (random + 1), 1));
				}
				else if (wave < 10) {
					int random = rand() % LIGNES;
					int randomType = rand() % 10;
					int type = 1 + (randomType <= (wave - 3));
					//asteroides->push_back(new Asteroide(0.9, TOPLEFTY - COTE * (random + 1), 1));
					rangeeAsteroides[random].push_back(new Asteroide(0.9, TOPLEFTY - COTE * (random + 1), type));
				}
				else {
					int random = rand() % LIGNES;
					int randomBlue = rand() % 4;
					int randomRed = rand() % 10;
					int typeInter = 2 - (randomBlue == 0);
					int typeFinal = typeInter + (randomRed <= (wave - 8));
					//asteroides->push_back(new Asteroide(0.9, TOPLEFTY - COTE * (random + 1), 1));
					rangeeAsteroides[random].push_back(new Asteroide(0.9, TOPLEFTY - COTE * (random + 1), typeFinal));
				}

				asteroideActuel = asteroideActuel + 1;
				game->setTime(std::chrono::system_clock::now());
			}

			// fin de vague

			//if (asteroides->empty() && nbasteroides == asteroideActuel) {
			bool empty = true;
			for (int i = 0; i < LIGNES;i++) {
				if (!rangeeAsteroides[i].empty()) {
					empty = false;
				}
			}
			if (empty && nbasteroides == asteroideActuel) {
				game->setIsWave(false);
				asteroideActuel = 0;
				game->VICTOIRE = true;
				//game->setWave(game->getWave() + 1);
			}
		}


		for (int i = 0; i < LIGNES;i++) {
			std::vector<Asteroide*> *asteroides = &rangeeAsteroides[i];
			for (int j = 0; j < asteroides->size(); j++) {
				Asteroide *asteroide = (*asteroides)[j];
				asteroide->move();
				if (asteroide->getX() < TOPLEFTX) {
					std::cout << "vie - 1" << std::endl;
					game->setVie(game->getVie() - 1);
					if (game->getVie() == 0) {
						game->GAMEOVER = true;
					}
					
					asteroides->erase(asteroides->begin() + j);
				}
			}
		}
		//std::cout << compte << std::endl;
		//std::cout << missiles->size() << std::endl;

		//missile move

		for (int i = 0; i < missiles->size(); i++) {
			Missile *missile = (*missiles)[i];
			missile->move();
			//std::cout << missile->getX() << std::endl;
			if (missile->getX() > 1) {
				//std::cout << "delete" << std::endl;
				missiles->erase(missiles->begin() + i);
			}
			int colonne = (TOPLEFTY - (missile->getY() - 0.0001))/COTE;
			/*
			if (!rangeeAsteroides[colonne].empty()) {
				std::vector<Asteroide*> *asteroides = &rangeeAsteroides[colonne];
				Asteroide *asteroide = rangeeAsteroides[colonne][0];
				if (asteroide->getX() < missile->getX()) {
					if (asteroide->getVie() <= missile->getPuissance()) {
						game->setMoney(game->getMoney() + asteroide->getGold());
						//(&rangeeAsteroides)[colonne]->erase((&rangeeAsteroides)[colonne]->begin() + 0);
						asteroides->erase(asteroides->begin());
					}
					else {
						asteroide->setVie(asteroide->getVie() - missile->getPuissance());
					}
					missiles->erase(missiles->begin() + i);

				}
			}
			*/
			for (int j = 0; j < rangeeAsteroides[colonne].size();j++) {
				std::vector<Asteroide*> *asteroides = &rangeeAsteroides[colonne];
				Asteroide *asteroide = rangeeAsteroides[colonne][j];
				if (asteroide->getX() < missile->getX()) {
					if (asteroide->getVie() <= missile->getPuissance()) {
						game->setMoney(game->getMoney() + asteroide->getGold());
						//(&rangeeAsteroides)[colonne]->erase((&rangeeAsteroides)[colonne]->begin() + 0);
						asteroides->erase(asteroides->begin() + j);
					}
					else {
						asteroide->setVie(asteroide->getVie() - missile->getPuissance());
					}
					missiles->erase(missiles->begin() + i);

				}
			}
		}

		//shoot missile

		for (int i = 0; i < vaisseaux->size(); i++) {
			Vaisseau *vaisseau = (*vaisseaux)[i];
			if (game->isWave()) {
				std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
				std::chrono::duration<double> elapsed = now - vaisseau->getTime();
				//std::cout << elapsed.count() << std::endl;
				if (elapsed.count() > 1.0 / vaisseau->freq) {
					//std::cout << vaisseau->vitesse << std::endl;
					missiles->push_back(new Missile(vaisseau->x + COTE, vaisseau->y + COTE / 4, vaisseau->vitesse, vaisseau->power));
					vaisseau->setTime(now);
				}
			}
		}
	}
}

