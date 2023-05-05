#include "character.h"


Character::Character(){
    characterName = "None";
    HP = 0;
    characterLevel = 0;
    Exp = 0;
    characterClass = "None";
    ATK = 0;
    DEF = 0;
    MAGIC = 0;
    SPD = 0;
    maxExp = 0;

}

Character::Character(string _name, string _class){
    characterName = _name;
    HP = 0;
    characterLevel = 5;
    Exp = 0;
    characterClass = _class;
    ATK = 0;
    DEF = 0;
    MAGIC = 0;
    SPD = 0;
    maxExp = 0;

}

void Character::setName(string _name){
    characterName = _name;
}

void Character::setHP(int hp){
    HP = hp;
}

void Character::setLevel(int lvl){
    characterLevel = lvl;
}

void Character::setClass(string className){
    characterClass = className;
}

void Character::setMaxExp(int _maxExp){
    maxExp = _maxExp;
}

string Character::getName(){
    return characterName;
}

int Character::getHP(){
    return HP;
}

int Character::getLevel(){
    return characterLevel;
}

int Character::getExp(){
    return Exp;
}

int Character::getMaxExp(){
    return maxExp;
}

void Character::setTakenTurn(int turn){
    takenTurn = turn;
}

void Character::setExp(int _exp){
    Exp = _exp;
}

void Character::setAtk(int _atk){
    ATK = _atk;
}

void Character::setDef(int _def){
    DEF = _def;
}

void Character::setMagic(int _magic){
    MAGIC = _magic;
}

void Character::setSpd(int _spd){
    SPD = _spd;
}
void Character::setProtect(int value){
    protect = value;
}
void Character::setMana(int _mana){
    mana = _mana;
}
void Character::setMaxMana(int _maxMana){
    maxMana = _maxMana;
}
void Character::setMaxHP(int _maxHP){
    maxHP = _maxHP;
}

int Character::getAtk(){
    return ATK;
}

int Character::getDef(){
    return DEF;
}

int Character::getMagic(){
    return MAGIC;
}

int Character::getSpd(){
    return SPD;
}

bool Character::getTakenTurn(){
    return takenTurn;
}

int Character::getMaxHP(){
    return maxHP;
}

int Character::getMana(){
    return mana;
}

int Character::getMaxMana(){
    return maxMana;
}

bool Character::getProtect(){
    return protect;
}

void Character::gainExp(int _exp){
    Exp = Exp + _exp;
    cout << characterName << " gained " << _exp << " experience points!" << endl;
    if(Exp > maxExp){
        while(Exp > maxExp){
            characterLevel++;
            raiseStats();
            cout << characterName << " leveled up to " << characterLevel << "!" << endl;
            Exp = Exp - maxExp;
            maxExp += 0.25 * maxExp;
        }
    }
}


void Character::printInfo(){
    cout << "Average person with no class." << endl;
    cout << "Name: " << characterName << endl;
    cout << "Level " << characterLevel << " " << characterClass << endl;
    cout << "HP: " << HP << endl;
    cout << "EXP: " << Exp << endl;
}

void Character::takeDamage(int enemyDamage){
    int damageTaken;
    damageTaken = enemyDamage - (DEF/3);
    if(protect == true && characterClass == "Ragdoll"){
        cout << "The attack bounces off of " << characterName << "!" << endl;
        cout << characterName << " takes 0 damage!" << endl;
        protect = false;
    }
    else if(protect == true && characterClass == "Shorthair"){
        cout << characterName << " dodges the attack with quick reflex!" << endl;
        cout << characterName << " takes 0 damage!" << endl;
        protect = false;
    }
    else if(damageTaken > 0){
        HP = (HP - damageTaken);
        cout << characterName << " has taken " << damageTaken << " damage!" << endl;
    }
    else{
        cout << characterName << " has taken 0 damage!" << endl;
    }
}