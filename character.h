#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>
#include "enemy.h"

using namespace std;

class Character{
    public:
        Character();
        Character(string, string);
        void setHP(int);
        void setLevel(int);
        void setClass(string);
        void setName(string);
        void setExp(int);
        int getHP();
        string getName();
        int getLevel();
        int getExp();
        void setAtk(int);
        void setDef(int);
        void setMagic(int);
        void setSpd(int);
        void setMaxExp(int);
        void setTakenTurn(int);
        void setProtect(int);
        void setMana(int);
        void setMaxMana(int);
        void setMaxHP(int);
        int getAtk();
        int getDef();
        int getMagic();
        int getSpd();
        int getMana();
        int getMaxExp();
        int getMaxHP();
        int getMaxMana();
        bool getProtect();
        bool getTakenTurn();
        virtual void attack(Enemy*&) = 0;
        void takeDamage(int);
        void gainExp(int);
        virtual void raiseStats() = 0;
        virtual void printInfo();
        virtual string getClass() = 0;
        virtual ~Character() {}
    private:
        int HP;
        string characterName;
        int characterLevel;
        int Exp;
        string characterClass;
        int ATK;
        int DEF;
        int MAGIC;
        int SPD;
        int maxExp;
        int maxHP;
        int mana;
        int maxMana;
        bool takenTurn;
        bool protect;
        

};

#endif