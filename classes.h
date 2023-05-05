#ifndef CLASSES_H
#define CLASSES_H

#include "character.h"

class Ragdoll : public Character{
    public:
        Ragdoll(string, string);
        Ragdoll(string _name, string _class, int _lvl, int _exp, int _maxexp, int _hp, int _atk, int _def, int _magic, int _spd, int _takenTurn, int _protect, int _maxHP, int _maxMana, int _mana);
        string getClass();
        void printInfo();
        void raiseStats();
        void attack(Enemy*&);
        ~Ragdoll() {}

};

class Shorthair : public Character{
    public:
        Shorthair(string, string);
        Shorthair(string _name, string _class, int _lvl, int _exp, int _maxexp, int _hp, int _atk, int _def, int _magic, int _spd, int _takenTurn, int _protect, int _maxHP, int _maxMana, int _mana);
        string getClass();
        void printInfo();
        void raiseStats();
        void attack(Enemy*&);
        ~Shorthair() {}

};

class MaineCoon : public Character{
    public:
        MaineCoon(string, string);
        MaineCoon(string _name, string _class, int _lvl, int _exp, int _maxexp, int _hp, int _atk, int _def, int _magic, int _spd, int _takenTurn, int _protect, int _maxHP, int _maxMana, int _mana);
        string getClass(); 
        void printInfo();
        void raiseStats();
        void attack(Enemy*&);
        ~MaineCoon() {}

};
#endif