#pragma once
#include <chrono>


class Game {
  public:
    int money;

    int wavenb;

    bool wave;

    int vies;

    bool GAMEOVER=  false;

	bool VICTOIRE = false;

    std::chrono::time_point<std::chrono::system_clock> time=  std::chrono::system_clock::now();

    Game(int money_, int wave_, int vies_) :
    		money(money_),
    		wavenb(wave_),
    		wave(false),
    		vies(vies_){};

    void setMoney(int money_);

    void setWave(int wave_);

    bool isWave();

    int getMoney();

    int getWave();

    //bool isWave();
    void setIsWave(bool wave_);

    void setTime(std::chrono::time_point<std::chrono::system_clock> time_);

    std::chrono::time_point<std::chrono::system_clock> getTime();

    void setVie(int vies_);

    int getVie();

};
