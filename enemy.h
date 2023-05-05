#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "character.h"

using namespace std;

class Enemy{
    public:
        Enemy();
        Enemy(string);
        int getHP();
        string getName();
        string getType();
        int getLevel();
        int getExp();
        int getAtk();
        int getDef();
        int getMagic();
        int getSpd();
        bool getTakenTurn();
        void setName(string);
        void setType(string);
        void setTakenTurn(int);
        void setLevel(int);
        void setHP(int);
        void setExp(int);
        void setAtk(int);
        void setDef(int);
        void setMagic(int);
        void setSpd(int);
        virtual int attack() {return 10;}
        void takeDamage(int);
        virtual void printInfo() = 0;
        virtual ~Enemy() {}

    private:
        string type;
        string name;
        int exp;
        int HP;
        int atk;
        int def;
        int magic;
        int spd;
        int level;
        bool takenTurn;





};
#endif