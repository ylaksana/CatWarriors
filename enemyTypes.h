#ifndef ENEMYTYPES_H
#define ENEMYTYPES_H

#include "enemy.h"

using namespace std;

class Dog : public Enemy{
    public:
        Dog();
        Dog(string, string, int, int, int, int, int, int, int, int);
        ~Dog() {}
        int attack();
        void printInfo();
};
class Bird : public Enemy{
    public:
        Bird();
        Bird(string, string, int, int, int, int, int, int, int, int);
        ~Bird() {}
        int attack();
        void printInfo();

};
class Fishman : public Enemy{
    public:
        Fishman();
        Fishman(string, string, int, int, int, int, int, int, int, int);
        ~Fishman() {}
        int attack();
        void printInfo();
};

class BirdKing : public Enemy{
    public:
        BirdKing();
        BirdKing(string, string, int, int, int, int, int, int, int, int);
        ~BirdKing() {}
        int attack();
        void printInfo();
};

#endif