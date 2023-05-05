#include "classes.h"

MaineCoon::MaineCoon(string name, string _class):Character(name,_class){
    setHP(110);
    setAtk(110);
    setDef(100);
    setMagic(40);
    setSpd(40);
    setMana(60);
    setMaxMana(60);
    setMaxHP(110);
    setMaxExp(100);
    setTakenTurn(false);
    setProtect(false);

}

MaineCoon::MaineCoon(string _name, string _class, int _lvl, int _exp, int _maxexp, int _hp, int _atk, int _def, int _magic, int _spd, int _takenTurn, int _protect, int _maxHP, int _maxMana, int _mana){
    setName(_name);
    setHP(_hp);
    setLevel(_lvl);
    setExp(_exp);
    setMaxExp(_maxexp);
    setClass(_class);
    setAtk(_atk);
    setDef(_def);
    setMagic(_magic);
    setSpd(_spd);
    setMana(_mana);
    setMaxMana(_maxMana);
    setMaxHP(_maxHP);
    setTakenTurn(_takenTurn);
    setProtect(_protect);

}

string MaineCoon::getClass(){
    return "MaineCoon";
}

void MaineCoon::printInfo(){
    cout << "Level " << getLevel() << " " << getClass() << endl;
    cout << "Name: " << getName() << endl;
    cout << "HP: " << getHP() << "/" << getMaxHP() << " | " << "Mana: " << getMana() << "/" << getMaxMana() << endl;
    cout << "EXP: " << getExp() << "/" << getMaxExp() << endl;
    cout << "ATK: " << getAtk() << " | DEF: " << getDef() << " | MAGIC: " << getMagic() << " | SPD: " << getSpd() << endl;
    cout << "---" << endl;
}

void MaineCoon::raiseStats(){
    setAtk(getAtk() + 3);
    setDef(getDef() + 3);
    setMagic(getMagic() + 0);
    setSpd(getSpd() + 1);
}

void MaineCoon::attack(Enemy*& _enemy){
    int skillInput;
    bool validSkill = false;
    int moveDmg;
    cout << endl << "Skills" << endl;
    cout << "---" << endl;
    cout << "1 - Pounce" << endl;
    cout << "2 - Bread" << endl;
    cout << "3 - Vomit" << endl;
    cout << "4 - Body Tackle" << endl;
    while(!validSkill){
        cin >> skillInput;
        if(skillInput == 1){
            moveDmg = getAtk()/2;
            _enemy->takeDamage(moveDmg);
            cout << getName() << " lunges at " << _enemy->getName() << " with its powerful legs, slashing with its claws!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else if(skillInput == 2){
            setHP(getHP() + 30);
            cout << getName() << " rests in a bread formation, healing itself for 30 health!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else if(skillInput == 3){
            moveDmg = getMagic()/2;
            _enemy->takeDamage(moveDmg);
            cout << getName() << " vomits at " << _enemy->getName() << "!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else if(skillInput == 4){
            moveDmg = getAtk()/2 + 30;
            _enemy->takeDamage(moveDmg);
            cout << getName() << " recklessly crashes into " << _enemy->getName() << " with great force!" << endl;
            setHP(getHP() - (moveDmg/3));
            if(getMana() >= 0){
                setMana(getMana() - 20);
            }
            cout << getName() << " is hurt in the process, taking " << moveDmg/3 - 10 << " damage!" << endl;
            validSkill = true;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }
}

Ragdoll::Ragdoll(string name, string _class):Character(name,_class){
    setHP(150);
    setAtk(95);
    setDef(65);
    setMagic(30);
    setSpd(60);
    setMaxExp(110);
    setMana(60);
    setMaxMana(60);
    setMaxHP(150);
    setTakenTurn(false);
    setProtect(false);
}

Ragdoll::Ragdoll(string _name, string _class, int _lvl, int _exp, int _maxexp, int _hp, int _atk, int _def, int _magic, int _spd, int _takenTurn, int _protect, int _maxHP, int _maxMana, int _mana){
    setName(_name);
    setHP(_hp);
    setLevel(_lvl);
    setExp(_exp);
    setMaxExp(_maxexp);
    setClass(_class);
    setAtk(_atk);
    setDef(_def);
    setMagic(_magic);
    setSpd(_spd);
    setMana(_mana);
    setMaxMana(_maxMana);
    setMaxHP(_maxHP);
    setTakenTurn(_takenTurn);
    setProtect(_protect);

}


string Ragdoll::getClass(){
    return "Ragdoll";
}

void Ragdoll::printInfo(){
    cout << "Level " << getLevel() << " " << getClass() << endl;
    cout << "Name: " << getName() << endl;
    cout << "HP: " << getHP() << "/" << getMaxHP() << " | " << "Mana: " << getMana() << "/" << getMaxMana() << endl;
    cout << "EXP: " << getExp() << "/" << getMaxExp() << endl;
    cout << "ATK: " << getAtk() << " | DEF: " << getDef() << " | MAGIC: " << getMagic() << " | SPD: " << getSpd() << endl;
    cout << "---" << endl;
    // cout << "Has taken turn: " << getTakenTurn() << " | " << "Protected: " << getProtect() << endl;
}

void Ragdoll::raiseStats(){
    setAtk(getAtk() + 3);
    setDef(getDef() + 2);
    setMagic(getMagic() + 1);
    setSpd(getSpd() + 2);
}

void Ragdoll::attack(Enemy*& _enemy){
    int skillInput;
    bool validSkill = false;
    int moveDmg;
    cout << endl << "Skills" << endl;
    cout << "---" << endl;
    cout << "1 - Scratch" << endl;
    cout << "2 - Bread" << endl;
    cout << "3 - Fluff" << endl;
    cout << "4 - Fluffball" << endl;
    while(!validSkill){
        cin >> skillInput;
        if(skillInput == 1){
            moveDmg = getAtk()/3;
            _enemy->takeDamage(moveDmg);
            cout << getName() << " scratches at " << _enemy->getName() << "!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 5);
            }
            validSkill = true;
        }
        else if(skillInput == 2){
            setHP(getHP() + 30);
            cout << getName() << " rests in a bread formation, healing itself for 30 health!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else if(skillInput == 3){
            cout << getName() << " puffs up! Any attack will now bounce off!" << endl;
            setProtect(1);
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else if(skillInput == 4){
            moveDmg = getAtk()/2;
            _enemy->takeDamage(moveDmg);
            cout << getName() << " recklessly rolls towards " << _enemy->getName() << "!" << endl;
            setHP(getHP() - (moveDmg/2));
            if(getMana() >= 0){
                setMana(getMana() - 15);
            }
            cout << getName() << " hurts itself, taking " << moveDmg/2 << " damage!" << endl;
            validSkill = true;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }
}


Shorthair::Shorthair(string name, string _class):Character(name,_class){
    setHP(80);
    setAtk(120);
    setDef(40);
    setMagic(30);
    setSpd(130);
    setMaxExp(100);
    setMana(60);
    setMaxMana(60);
    setMaxHP(80);
    setTakenTurn(false);
    setProtect(false);

}

Shorthair::Shorthair(string _name, string _class, int _lvl, int _exp, int _maxexp, int _hp, int _atk, int _def, int _magic, int _spd, int _takenTurn, int _protect, int _maxHP, int _maxMana, int _mana){
    setName(_name);
    setHP(_hp);
    setLevel(_lvl);
    setExp(_exp);
    setMaxExp(_maxexp);
    setClass(_class);
    setAtk(_atk);
    setDef(_def);
    setMagic(_magic);
    setSpd(_spd);
    setMana(_mana);
    setMaxMana(_maxMana);
    setMaxHP(_maxHP);
    setTakenTurn(_takenTurn);
    setProtect(_protect);

}


string Shorthair::getClass(){
    return "Shorthair";
}


void Shorthair::attack(Enemy*& _enemy){
    int skillInput;
    bool validSkill = false;
    int moveDmg;
    cout << endl << "Skills" << endl;
    cout << "---" << endl;
    cout << "1 - Multiswipe" << endl;
    cout << "2 - Hiss" << endl;
    cout << "3 - Anticipate" << endl;
    cout << "4 - Quick Strike" << endl;
    while(!validSkill){
        cin >> skillInput;
        if(skillInput == 1){
            moveDmg = 5*(0.1 * getAtk());
            _enemy->takeDamage(moveDmg);
            cout << getName() << " swipes furiously at " << _enemy->getName() << "!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 15);
            }
            validSkill = true;
        }
        else if(skillInput == 2){
            _enemy->setAtk(_enemy->getAtk()/2);
            cout << getName() << " hisses loudly at " << _enemy->getName() << ", lowering its attack!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else if(skillInput == 3){
            cout << getName() << " prepares itself for an attack..." << endl;
            setProtect(1);
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else if(skillInput == 4){
            moveDmg = getAtk()/5;
            _enemy->takeDamage(moveDmg);
            cout << getName() << " strikes quickly at " << _enemy->getName() << "!" << endl;
            if(getMana() >= 0){
                setMana(getMana() - 10);
            }
            validSkill = true;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }
}

void Shorthair::raiseStats(){
    setAtk(getAtk() + 3);
    setDef(getDef() + 1);
    setMagic(getMagic() + 1);
    setSpd(getSpd() + 4);
}

void Shorthair::printInfo(){
    cout << "Level " << getLevel() << " " << getClass() << endl;
    // cout << "A seasoned warrior who deals swift attacks with a blade." << endl;
    cout << "Name: " << getName() << endl;
    cout << "HP: " << getHP() << "/" << getMaxHP() << " | " << "Mana: " << getMana() << "/" << getMaxMana() << endl;
    cout << "EXP: " << getExp() << "/" << getMaxExp() << endl;
    cout << "ATK: " << getAtk() << " | DEF: " << getDef() << " | MAGIC: " << getMagic() << " | SPD: " << getSpd() << endl;
    cout << "---" << endl;
}