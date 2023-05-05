#ifndef ENEMYLIST_H
#define ENEMYLIST_H
#include <iostream>
#include <cstdlib>
#include "enemy.h"
#include "enemyTypes.h"

using namespace std;

const int SIZE = 4;

class EnemyList{
    public:
        EnemyList();
        ~EnemyList();
        void spawnEnemies();
        bool checkEnemyList();
        void enemySummary();
        void enemyDeath(int);
        bool checkEnemyTurns();
        void spawnBoss();
        Enemy* &getEnemy(int);
        void assignEnemy(Enemy&);
    private:
        Enemy *enemyList[SIZE];
        int count;

};

#endif