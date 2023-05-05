#include "enemy.h"


Enemy::Enemy(){
    name = "None";
    HP = 0;
    exp = 0;
    type = "None";
    atk = 0;
    def = 0;
    magic = 0;
    spd = 0;
    level = 0;
    takenTurn = false;

}
Enemy::Enemy(string classType){
    name = "None";
    HP = 0;
    exp = 0;
    type = classType;
    atk = 0;
    def = 0;
    magic = 0;
    spd = 0;
    level = 0;
    takenTurn = true;
}
int Enemy::getHP(){
    return HP;
}
string Enemy::getName(){
    return name;
}
string Enemy::getType(){
    return type;
}
int Enemy::getLevel(){
    return level;
}
int Enemy::getExp(){
    return exp;
}
int Enemy::getAtk(){
    return atk;
}
int Enemy::getDef(){
    return def;
}
int Enemy::getMagic(){
    return magic;
}
int Enemy::getSpd(){
    return spd;
}
bool Enemy::getTakenTurn(){
    return takenTurn;
}
void Enemy::setName(string _name){
    name = _name;
}
void Enemy::setTakenTurn(int _takenTurn){
    takenTurn = _takenTurn;
}
void Enemy::setType(string _type){
    type =_type;
}
void Enemy::setLevel(int _level){
    level = _level;
}
void Enemy::setHP(int _hp){
    HP = _hp;
}
void Enemy::setExp(int _exp){
    exp = _exp;
}
void Enemy::setAtk(int _atk){
    atk = _atk;
}
void Enemy::setDef(int _def){
    def = _def;
}
void Enemy::setMagic(int _magic){
    magic = _magic;
}
void Enemy::setSpd(int _spd){
    spd = _spd;
}

void Enemy::takeDamage(int damage){
    int dmgTaken;
    dmgTaken = damage - (0.3 * def);
    if(dmgTaken > 0){
        HP = HP - dmgTaken;
        cout << name << " takes " << dmgTaken << " damage!" << endl;
    }
    else{
        cout << name << " takes 0 damage!" << endl;
    }
    
}

