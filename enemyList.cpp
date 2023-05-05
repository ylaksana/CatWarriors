#include "enemyList.h"

EnemyList::EnemyList(){
    count = 0;
    for(int i = 0; i < SIZE; i++){
        enemyList[i] = nullptr;
    }
}
EnemyList::~EnemyList(){
    for(int i = 0; i < SIZE; i++){
        delete enemyList[i];
        enemyList[i] = nullptr;
    }
}
void EnemyList::spawnEnemies(){
    int chooseEnemy;
    for(int i = 0; i < SIZE; i++){
        chooseEnemy = rand() % 3 + 1;
        if(chooseEnemy == 1){
            Dog D1;
            enemyList[i] = new Dog((Dog &) D1);
            count++;
        }
        else if(chooseEnemy == 2){
            Bird B1;
            enemyList[i] = new Bird((Bird &) B1);
            count++;
        }
        else if(chooseEnemy == 3){
            Fishman F1;
            enemyList[i] = new Fishman((Fishman &) F1);
            count++;
        }  
    }
    
}

bool EnemyList::checkEnemyList(){
    bool foundMember = false;
    for(int i = 0; i < MAX_SIZE; i++){
        if(enemyList[i] != nullptr){
            foundMember = true;
            return foundMember;
        }
    }

    return foundMember;
}
void EnemyList::enemySummary(){
    for(int i = 0; i < SIZE; i++){
        if(enemyList[i] != nullptr){
            cout << i+1 << " - ";
            enemyList[i]->printInfo();
        }
    }
}
void EnemyList::enemyDeath(int idx){
        cout << enemyList[idx]->getName() << " has been slain!" << endl;
        delete enemyList[idx];
        enemyList[idx] = nullptr;
        count--;
}


void EnemyList::assignEnemy(Enemy& _enemy){
    int idx;
    if(count < SIZE){
        for(int i = 0; i < MAX_SIZE; i++){
            if(enemyList[i] == nullptr){
                idx = i;
                break;
            }
        }

        if(_enemy.getType() == "Dog"){
            enemyList[idx] = new Dog((Dog &) _enemy);
            count++;
        }
        else if(_enemy.getType() == "Bird"){
            enemyList[idx] = new Bird((Bird &) _enemy);
            count++;
        }
        else if(_enemy.getType() == "Fish"){
            enemyList[idx] = new Fishman((Fishman &) _enemy);
            count++;
        }
        else if(_enemy.getType() == "BirdKing"){
            enemyList[idx] = new BirdKing((BirdKing &) _enemy);
            count++;
        }
    }
}

Enemy*& EnemyList::getEnemy(int idx){
    if(enemyList[idx] == nullptr){
        throw EnemyException();
    }
    
    return enemyList[idx];
}

bool EnemyList::checkEnemyTurns(){
    for(int i = 0; i < MAX_SIZE; i++){
        if(enemyList[i] != nullptr){
            if(enemyList[i]->getTakenTurn() == 0){
                return false;
            }
        }
    }

    return true;
}

void EnemyList::spawnBoss(){
    BirdKing BK1;
    enemyList[0] = new BirdKing((BirdKing &) BK1);
}