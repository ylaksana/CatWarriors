#include "enemyTypes.h"

Bird::Bird(){
    setName("Parrot");
    setType("Bird");
    setLevel(5);
    setHP(120);
    setExp(140);
    setAtk(100);
    setDef(40);
    setMagic(50);
    setSpd(120);
    setTakenTurn(0);
}

Bird::Bird(string _name, string _type, int _exp, int _hp, int _atk, int _def, int _magic, int _spd, int _level, int _takenTurn){
    setName(_name);
    setType(_type);
    setLevel(_level);
    setHP(_hp);
    setExp(_exp);
    setAtk(_atk);
    setDef(_def);
    setMagic(_magic);
    setSpd(_spd);
    setTakenTurn(_takenTurn);
}

void Bird::printInfo(){
    cout << getName() << " | Level " << getLevel() << " | HP: " << getHP() << " | " << "Speed: " << getSpd() << endl;
}

int Bird::attack(){
    srand((int)time(0));
    int chooseAttack = rand() % 3 + 1;
    int dmg;
    string atkName;
    if(chooseAttack == 1){
        atkName = "Peck";
        dmg = getAtk()/4;
    }
    else if(chooseAttack == 2){
        atkName = "Talon Strike";
        dmg = getAtk()/2;
    }
    else if(chooseAttack == 3){
        atkName = "Wing Dive";
        dmg = getAtk()/3;
    }
    cout << getName() << " used " << atkName << "! ";

    return dmg;
}

Dog::Dog(){
    setName("Husky Malamute");
    setType("Dog");
    setLevel(5);
    setHP(120);
    setExp(150);
    setAtk(100);
    setDef(80);
    setMagic(10);
    setSpd(20);
    setTakenTurn(0);
}

Dog::Dog(string _name, string _type, int _exp, int _hp, int _atk, int _def, int _magic, int _spd, int _level, int _takenTurn){
    setName(_name);
    setType(_type);
    setLevel(_level);
    setHP(_hp);
    setExp(_exp);
    setAtk(_atk);
    setDef(_def);
    setMagic(_magic);
    setSpd(_spd);
    setTakenTurn(_takenTurn);
}

void Dog::printInfo(){
    cout << getName() << " | Level " << getLevel() << " | HP: " << getHP() << " | " << "Speed: " << getSpd() << endl;
}

int Dog::attack(){
    srand((int)time(0));
    int chooseAttack = rand() % 3 + 1;
    int dmg;
    string atkName;
    if(chooseAttack == 1){
        atkName = "Bite";
        dmg = getAtk()/4;
    }
    else if(chooseAttack == 2){
        atkName = "Claw Strike";
        dmg = getAtk()/3;
    }
    else if(chooseAttack == 3){
        atkName = "Tackle";
        dmg = getAtk()/2;
    }
    cout << getName() << " used " << atkName << "! ";

    return dmg;
}

Fishman::Fishman(){
    setName("Goldfish");
    setType("Fish");
    setLevel(5);
    setHP(100);
    setExp(100);
    setAtk(40);
    setDef(20);
    setMagic(20);
    setSpd(70);
    setTakenTurn(0);
}

Fishman::Fishman(string _name, string _type, int _exp, int _hp, int _atk, int _def, int _magic, int _spd, int _level, int _takenTurn){
    setName(_name);
    setType(_type);
    setLevel(_level);
    setHP(_hp);
    setExp(_exp);
    setAtk(_atk);
    setDef(_def);
    setMagic(_magic);
    setSpd(_spd);
    setTakenTurn(_takenTurn);
}

void Fishman::printInfo(){
    cout << getName() << " | Level " << getLevel() << " | HP: " << getHP() << " | " << "Speed: " << getSpd() << endl;
}

int Fishman::attack(){
    srand((int)time(0));
    int chooseAttack = rand() % 3 + 1;
    int dmg;
    string atkName;
    if(chooseAttack == 1){
        atkName = "Tail Strike";
        dmg = 0.3 * getAtk();
    }
    else if(chooseAttack == 2){
        atkName = "Water Blast";
        dmg = 0.4 * getAtk();
    }
    else if(chooseAttack == 3){
        atkName = "Splash Water";
        dmg = 0.2 * getAtk();
    }
    cout << getName() << " used " << atkName << "! ";

    return dmg;
}

BirdKing::BirdKing(){
    setName("The Sorcerer's Owl");
    setType("BirdKing");
    setLevel(5);
    setHP(400);
    setExp(300);
    setAtk(100);
    setDef(90);
    setMagic(20);
    setSpd(100);
    setTakenTurn(0);
}

BirdKing::BirdKing(string _name, string _type, int _exp, int _hp, int _atk, int _def, int _magic, int _spd, int _level, int _takenTurn){
    setName(_name);
    setType(_type);
    setLevel(_level);
    setHP(_hp);
    setExp(_exp);
    setAtk(_atk);
    setDef(_def);
    setMagic(_magic);
    setSpd(_spd);
    setTakenTurn(_takenTurn);
}

int BirdKing::attack(){
    srand((int)time(0));
    int chooseAttack = rand() % 3 + 1;
    int dmg;
    string atkName;
    if(chooseAttack == 1){
        atkName = "Flaming Wing";
        dmg = getAtk()/2;
    }
    else if(chooseAttack == 2){
        atkName = "Magic Beak";
        dmg = getAtk()/3;
    }
    else if(chooseAttack == 3){
        atkName = "Howling Winds";
        dmg = getAtk()/2;
    }
    cout << getName() << " used " << atkName << "! ";

    return dmg;
}
void BirdKing::printInfo(){
    cout << getName() << " | Level " << getLevel() << " | HP: " << getHP() << " | " << "Speed: " << getSpd() << endl;
}