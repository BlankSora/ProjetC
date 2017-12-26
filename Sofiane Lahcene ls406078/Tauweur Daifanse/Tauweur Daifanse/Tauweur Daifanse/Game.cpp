
#include "Game.h"

void Game::setMoney(int money_) {

	money = money_;
}

void Game::setWave(int wave_) {

	wavenb = wave_;
}

bool Game::isWave() {

	return wave;
}

int Game::getMoney() {

	return money;
}

int Game::getWave() {

	return wavenb;
}

//bool isWave();
void Game::setIsWave(bool wave_) {

	wave = wave_;
}

void Game::setTime(std::chrono::time_point<std::chrono::system_clock> time_) {

	time = time_;
}

std::chrono::time_point<std::chrono::system_clock> Game::getTime() {

	return time;
}

void Game::setVie(int vies_) {

	vies = vies_;
}

int Game::getVie() {

	return vies;
}

