#include <iostream>
#include <fstream>
#include <ctime>
#include "character.h"
#include "character.cpp"
#include "partylist.h"
#include "partylist.cpp"
#include "classes.h"
#include "classes.cpp"
#include "classException.h"
#include "classException.cpp"
#include "enemy.h"
#include "enemy.cpp"
#include "enemyTypes.h"
#include "enemyTypes.cpp"
#include "enemyList.h"
#include "enemyList.cpp"

using namespace std;

void saveParty(PartyList &list, EnemyList &elist, int arraySize, string fileName, int env, int fightCount){
    ofstream fout;
    fout.open(fileName);


    if(!fout.is_open()){
        cout << "Failed to create save file." << endl;
        return;
    }

    fout << env << endl;
    fout << fightCount << endl;

    for(int i = 0; i < arraySize; i++){
        try{
            fout << list.getCharacter(i)->getName() << endl;
            fout << list.getCharacter(i)->getClass() << endl;
            fout << list.getCharacter(i)->getLevel() << endl;
            fout << list.getCharacter(i)->getExp() << endl;
            fout << list.getCharacter(i)->getMaxExp() << endl;
            fout << list.getCharacter(i)->getMaxHP() << endl;
            fout << list.getCharacter(i)->getHP() << endl;
            fout << list.getCharacter(i)->getMaxMana() << endl;
            fout << list.getCharacter(i)->getMana() << endl;
            fout << list.getCharacter(i)->getAtk() << endl;
            fout << list.getCharacter(i)->getDef() << endl;
            fout << list.getCharacter(i)->getMagic() << endl;
            fout << list.getCharacter(i)->getSpd() << endl;
            fout << list.getCharacter(i)->getTakenTurn() << endl;
            fout << list.getCharacter(i)->getProtect() << endl;
            cout << "Party member " << list.getCharacter(i)->getName() << " saved!" << endl;
        }
        catch(CharacterException e){}
    }
    for(int i = 0; i < arraySize; i++){
        try{
            fout << elist.getEnemy(i)->getName() << endl;
            fout << elist.getEnemy(i)->getType() << endl;
            fout << elist.getEnemy(i)->getExp() << endl;
            fout << elist.getEnemy(i)->getHP() << endl;
            fout << elist.getEnemy(i)->getAtk() << endl;
            fout << elist.getEnemy(i)->getDef() << endl;
            fout << elist.getEnemy(i)->getMagic() << endl;
            fout << elist.getEnemy(i)->getSpd() << endl;
            fout << elist.getEnemy(i)->getLevel() << endl;
            fout << elist.getEnemy(i)->getTakenTurn() << endl;
            cout << "Enemy " << elist.getEnemy(i)->getName() << " saved!" << endl;
        }
        catch(EnemyException e){}
    }

    fout.close();    
    cout << "Game saved!" << endl;
    
}

void loadParty(string inputFile, PartyList &list, EnemyList &elist, int &env, int& fightCount){
    string name, _class;
    int level, exp, maxExp, maxhp, hp, maxMana, mana, atk, def, magic, spd , takenTurn, protect;

    ifstream fin;
    fin.open(inputFile);

    if(!fin.is_open()){
        cout << "Could not read file." << endl;
        return;
    }

    fin >> env >> fightCount;
    fin.ignore();

    while(!fin.eof()){
        getline(fin, name);
        if(name != ""){
            getline(fin, _class);
            if((_class == "Ragdoll") || (_class == "Shorthair") || (_class == "MaineCoon")){
                fin >> level >> exp >> maxExp >> maxhp >> hp >> maxMana >> mana >> atk >> def >> magic >> spd >> takenTurn >> protect;
                
                if(_class == "Ragdoll"){
                    Ragdoll R1(name, _class, level, exp, maxExp, hp, atk, def, magic, spd, takenTurn, protect, maxhp, maxMana, mana);
                    list.addMember(R1);
                }
                else if(_class == "MaineCoon"){
                    MaineCoon MC1(name, _class, level, exp, maxExp, hp, atk, def, magic, spd, takenTurn, protect, maxhp, maxMana, mana);
                    list.addMember(MC1);
                }
                else if(_class == "Shorthair"){
                    Shorthair S1(name, _class, level, exp, maxExp, hp, atk, def, magic, spd, takenTurn, protect, maxhp, maxMana, mana);
                    list.addMember(S1);
                }
            }
            else{
                fin >> exp >> hp >> atk >> def >> magic >> spd >> level >> takenTurn;

                if(_class == "Dog"){
                    Dog D1(name, _class, exp, hp, atk, def, magic, spd, level, takenTurn);
                    elist.assignEnemy(D1);
                }
                else if(_class == "Bird"){
                    Bird B1(name, _class, exp, hp, atk, def, magic, spd, level, takenTurn);
                    elist.assignEnemy(B1);
                }
                else if(_class == "Fish"){
                    Fishman F1(name, _class, exp, hp, atk, def, magic, spd, level, takenTurn);
                    elist.assignEnemy(F1);
                }
                else if(_class == "BirdKing"){
                    BirdKing BK1(name, _class, exp, hp, atk, def, magic, spd, level, takenTurn);
                    elist.assignEnemy(BK1);
                }

            }
        
        }
        else{
            fin.ignore();
        }

        fin.ignore();
    }
        
    
}


void displayClasses(){
    
    cout << "-----" << endl;
    cout << "Ragdoll - A big fluffy cat warrior that rolls around like a ball to attack and defend" << endl << "High HP, Normal ATK and DEF, Low MAGIC and Low SPEED" << endl;
    cout << "---" << endl;
    cout << "Shorthair - A swift and agile cat warrior that has fast reactions that allow it to strike and dodge with great dexterity." << endl << "Medium HP, High ATK, Low DEF, Low MAGIC, High SPEED" << endl;
    cout << "---" << endl;
    cout << "MaineCoon - A huge feline warrior that is powerful and sturdy, able to deal massive damage and take hits." << endl << "Normal HP, Big ATK and DEF, Medium MAGIC and Low SPEED" << endl;
    cout << "---" << endl;
}

void fastestSpeed(PartyList &_partyList, EnemyList &_enemyList, string &type, int &idx){
    int fastestIdx = 0;
    int fastestSpd = 0;
    string entityType = "";

    for(int i = 0; i < MAX_SIZE; i++){
        try{
            if((_partyList.getCharacter(i) != nullptr) && (_partyList.getCharacter(i)->getSpd() > fastestSpd) && (_partyList.getCharacter(i)->getTakenTurn() == false)){
                fastestSpd = _partyList.getCharacter(i)->getSpd();
                fastestIdx = i;
                entityType = "cat";
                
            }
            if((_enemyList.getEnemy(i) != nullptr) && (_enemyList.getEnemy(i)->getSpd() > fastestSpd) && (_enemyList.getEnemy(i)->getTakenTurn() == false)){
                fastestSpd = _enemyList.getEnemy(i)->getSpd();
                fastestIdx = i;
                entityType = "enemy";
            }
        }
        catch(CharacterException e) {}
        catch(EnemyException e) {}
    }

    idx = fastestIdx;
    type = entityType;
}

void initializeClass(string _class, string _name, PartyList &list){

    if(_class == "Ragdoll"){
        Ragdoll R1(_name,_class);
        list.addMember(R1);
    }
    else if(_class == "Shorthair"){
        Shorthair S1(_name,_class);
        list.addMember(S1);
    }
    else if(_class == "MaineCoon"){
        MaineCoon MC1(_name,_class);
        list.addMember(MC1);
    }
    else{
        throw ClassException(_class);
    }

}

int main(){
    string name, className, saveFile;
    int fightCount = 0;
    PartyList partyList;
    EnemyList enemyList;
    int envNum = 0;
        
    string inputValue = "-1";

    while(inputValue != "3"){
        cout << endl;
        cout << "======CAT WARRIORS======" << endl << endl;
        cout << "1 - New Game" << endl;
        cout << "2 - Load Game" << endl;
        cout << "3 - Exit" << endl;

        getline(cin, inputValue);

        if(inputValue == "1"){
            inputValue = -1;
            while(inputValue != "4"){
                cout << endl;
                cout << "=== NEW GAME MENU ===" << endl << endl;
                if(partyList.checkParty() == false){
                    cout << "Welcome to Catasia, a land filled with mystery, wonders, and most importantly, cats." << endl;
                    cout << "To start an adventure, add a cat warrior to the team!" << endl << endl;
                }
                if(partyList.checkParty()){
                    cout << "0 - Begin Adventure!" << endl;
                }
                cout << "1 - Add Party Member" << endl;
                cout << "2 - Dismiss Party Member" << endl;
                cout << "3 - Party Summary" << endl;
                cout << "4 - Back" << endl;

                getline(cin, inputValue);

                if(inputValue == "1"){
                    bool validClass = false;
                    while(!validClass){
                        cout << "Input a name for party member (Press 0 to cancel):" << endl;
                        getline(cin, name);
                        if(name != "0"){   
                            cout << endl;
                            cout << "Choose a class for party member (Press 0 to cancel):" << endl;
                            displayClasses();
                        }
                        else{
                            break;
                        }
                    
                        try{
                            cin >> className;
                            if(className != "0"){
                                initializeClass(className, name, partyList);
                                validClass = true;
                                partyList.partySummary();
                                cin.ignore();
                            }
                            else{
                                validClass = true;
                                cin.ignore();
                            }
                        }
                        catch(ClassException &e){
                            cout << endl << "Invalid class: (" << e.getIncorrectClass() << "). Please enter one of the classes listed above."<< endl;
                            cout << "(Press Enter to continue.)" << endl;
                            cin.ignore();
                        }
                    }
            
                }

                else if(inputValue == "2"){
                    bool validName = false;
                    while(!validName){
                        try{
                            partyList.partySummary();
                            cout << "Enter the name of the party member you want to remove (Press 0 to cancel):" << endl;
                            getline(cin, name);
                            if(name == "0"){
                                validName = true;
                            }
                            else{
                                partyList.dismissMember(name);
                                cout << "(Press Enter to continue.)" << endl;
                                cin.ignore();
                                validName = true;
                                
                            }
                        }
                        catch(NameException &e){
                            cout << "Party member not found. Please re-enter the name of party member to remove." << endl;
                            cout << "(Press Enter to continue.)" << endl;
                            cin.ignore();
                        }
                        catch(PartyException &e){
                            cout << "(Press Enter to continue.)" << endl;
                            cin.ignore();
                            break;
                        }
                    }
                    
                }

                else if(inputValue == "3"){
                    try{
                        partyList.partySummary();
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                    }
                    catch(PartyException &e){
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                    }
                }

                else if(inputValue == "4"){
                    partyList.resetParty();
                    break;
                }

                else if(inputValue == "0"){
                    if(partyList.checkParty()){
                        cout << endl << "Your party sets off for their adventure!" << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                        cin.ignore();
                        break;
                    }
                    else{
                        inputValue = "-1";
                        cout << "Invalid Input. Please input one of the options above." << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                    }
                }

                else{
                    cout << "Invalid input. Choose one of the following options." << endl;
                    cout << "(Press Enter to continue.)" << endl;
                    cin.ignore();
                }
            }

            if(inputValue == "0" && partyList.checkParty()){
                break;
            }
        }
        else if(inputValue == "2"){
            inputValue = -1;
            while(inputValue != "3"){
                cout << endl;
                cout << "=== LOAD MENU ===" << endl << endl;
                cout << "1 - Load save file" << endl;
                cout << "2 - Back" << endl;

                getline(cin, inputValue);

                if(inputValue == "1"){
                    cout << "Enter name of save file (Press 0 to cancel load):" << endl;
                    cin >> saveFile;
                    if(saveFile != "0"){
                        loadParty(saveFile, partyList, enemyList, envNum, fightCount);
                        cin.ignore();
                        break;
                    }
                }
                else if(inputValue == "2"){
                    break;
                }

                else{
                    cout << "Invalid input. Choose one of the following options." << endl;
                    cout << "(Press Enter to continue.)" << endl;
                    cin.ignore();
                }
            }

            if(partyList.checkParty()){
                break;
            }
        }

        else if(inputValue == "3"){
            return 0;
        }

        else{
            cout << "Invalid input. Choose one of the following options." << endl;
            cout << "(Press Enter to continue.)" << endl;
            cin.ignore();
        }
    }

    while(inputValue != "5"){
        string fastestType = "";
        int idx = 0;
        if(partyList.checkParty() && !enemyList.checkEnemyList()){
            cout << endl << "What will your party do now?" << endl << "---" << endl;
            cout << "1 - Set out to travel" << endl;
            cout << "2 - Rest for the night" << endl;
            cout << "3 - View Party" << endl;
            cout << "4 - Save progress" << endl;
            cout << "5 - Quit game" << endl;

            
            getline(cin, inputValue);
        }   

        if(inputValue == "1"){
            int moveDmg;
            int chooseCat;
            int enemyIdx;
            envNum = rand() % 4 + 1;
            if(partyList.checkParty() && !enemyList.checkEnemyList()){
                if(fightCount < 1){
                    if(envNum == 1){
                        cout << "Your party travels through a mountain valley...clawing at the walls to climb." << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();

                        cout << "While journeying, they are ambushed by enemy pets!" << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                        cin.ignore();
                    }
                    else if(envNum == 2){
                        cout << "Your party travels climbs a volcano...At its peak, a marvelous scenic view can be seen." << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();

                        cout << "After some viewing, your party descends the volcano, but is met with attacking pets!" << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                    }
                    else if(envNum == 3){
                        cout << "Your party travels through a dark cavern...Giant crystals illuminate its interior with a fluorescent glow..." << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                        

                        cout << "Your cat warriors paw at the long hanging vines in the cavern." << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();

                        cout << "Suddenly, enemy pets emerge from the shadows!" << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                    }
                    else if(envNum == 4){
                        cout << "Your party travels through a field of tall grass..." << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();

                        cout << "Journeying further, they play with long horsetails at a nearby pond..." << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();

                        cout << "While playing with horsetails, some enemy pets emerge from the tall grass!" << endl;
                        cout << "(Press Enter to continue.)" << endl;
                        cin.ignore();
                    }
                    enemyList.spawnEnemies();
                }
                else{
                    cout << "Before your party stands a wizard's castle..." << endl;
                    cout << "However, your party feel an ominous gust of wind..." << endl;
                    cout << "Something big is approaching..." << endl;

                    cout << "(Press Enter to continue.)" << endl;
                    cin.ignore();

                    cout << "'You shall not pass!'" << endl;
                    cout << "(Press Enter to continue.)" << endl;
                    cin.ignore();

                    enemyList.spawnBoss();
                }
            }
            while(enemyList.checkEnemyList() && partyList.checkParty()){
                if(partyList.checkPartyTurns() && enemyList.checkEnemyTurns()){
                    for(int i = 0; i < MAX_SIZE; i++){
                        try{
                            partyList.getCharacter(i)->setTakenTurn(0);
                            enemyList.getEnemy(i)->setTakenTurn(0);
                        }
                        catch(CharacterException e){}
                        catch(EnemyException e){}
                    }
                }
                fastestSpeed(partyList, enemyList, fastestType, idx);
                if(fastestType == "cat"){
                    bool turnOver = false;
                    while(!turnOver){
                        cout << endl;
                        enemyList.enemySummary();
                        cout << endl << "What will " << partyList.getCharacter(idx)->getName() << " do?" << endl << "---" << endl;
                        cout << "1 - Attack" << endl;
                        cout << "2 - Save" << endl;
                        cout << "3 - View Party" << endl;
                        cout << "4 - Quit Game" << endl;
                        cout << endl;

                        getline(cin, inputValue);
                            
                        if(inputValue == "1"){
                            bool existsEnemy = true;
                            while(existsEnemy){
                                try{
                                    enemyList.enemySummary();
                                    cout << "Which enemy would you like to attack? (Press 0 to cancel attack.)" << endl;
                                    cin >> enemyIdx;
                                    if((enemyIdx <= 4) && (enemyIdx > 0)){
                                        partyList.getCharacter(idx)->attack(enemyList.getEnemy(enemyIdx - 1));
                                        partyList.getCharacter(idx)->setTakenTurn(1);
                                        if(enemyList.getEnemy(enemyIdx - 1)->getHP() <= 0){
                                            int expGained = enemyList.getEnemy(enemyIdx - 1)->getExp();
                                            enemyList.enemyDeath(enemyIdx - 1);
                                            partyList.getCharacter(idx)->gainExp(expGained);
                                        }
                                        existsEnemy = false;
                                        turnOver = true;
                                        cout << "(Press Enter to continue.)" << endl << endl;
                                        cin.ignore();
                                        cin.ignore();
                                    }
                                    else if(enemyIdx == 0){
                                        existsEnemy = false;
                                        cin.ignore();
                                    }
                                    else{
                                        cout << "Invalid input. Choose one of the enemies above." << endl;
                                        cout << "(Press Enter to continue.)" << endl << endl;
                                        cin.ignore();
                                    }
                                }
                                catch(EnemyException e){
                                    cout << "There's no enemy there!" << endl;
                                    cout << "(Press Enter to continue.)" << endl << endl;
                                    cin.ignore();
                                }
                            }
                        }
                        else if(inputValue == "2"){
                            partyList.partySummary();
                            cout << "Would you like to save your progress? If so, what would you like to name this file?" << endl << "(Type the file name with .txt prefix)" << endl << "(Press 9 to cancel save)" << endl;
                            getline(cin, saveFile);
                            if(saveFile != "9"){
                                    saveParty(partyList, enemyList, 4, saveFile, envNum, fightCount);
                                    cout << "(Press Enter to continue.)" << endl << endl;
                                    cin.ignore();
                            }
                        }
                        else if(inputValue == "3"){
                            partyList.partySummary();
                            cout << "(Press Enter to continue.)" << endl << endl;
                            cin.ignore();
                        }

                        else if(inputValue == "4"){
                            return 0;
                        }
                        else{
                            cout << "Invalid input." << endl;
                            cout << "(Press Enter to continue.)" << endl << endl;
                            cin.ignore();
                        }

                    }
                }
                else if(fastestType == "enemy"){
                    try{
                        moveDmg = enemyList.getEnemy(idx)->attack();
                        while(true){
                            srand((int)time(0));
                            chooseCat = rand() % 4 + 1;
                            if(partyList.getCharacter(chooseCat-1) != nullptr){
                                partyList.getCharacter(chooseCat-1)->takeDamage(moveDmg);
                                enemyList.getEnemy(idx)->setTakenTurn(1);
                                if(partyList.getCharacter(chooseCat-1)->getHP() <= 0){
                                    partyList.death(chooseCat-1);
                                }
                                cout << "(Press Enter to continue.)" << endl << endl;
                                cin.ignore();
                                break;
                            }

                        }
                    }
                    catch(CharacterException e){}
                    catch(EnemyException e){}
                    
                }
            }
            fightCount++;
            if(enemyList.checkEnemyList() == false && fightCount > 1){
                cout << "'CAAAAAAAAW!'" << endl;
                cout << "(Press Enter to continue.)" << endl << endl;
                cin.ignore();

                cout << "The giant owl bursts into a thousand sparkles!" << endl;
                cout << "Your team rejoices as they've triumphed over the castle's guardian." << endl;
                cout << "(Press Enter to continue.)" << endl << endl;
                cin.ignore();

                cout << "The team prepares itself for its trek through the castle." << endl;
                cout << "To be continued..." << endl;
                cout << "(Press Enter to continue.)" << endl << endl;
                cin.ignore();
                return 0;
            }

            else if(enemyList.checkEnemyList() == false){
                cout << "All enemy pets have been defeated! Your cat warriors move on further and rest for a bit." << endl;
                for(int i = 0; i < MAX_SIZE; i++){
                    if(partyList.getCharacter(i) != nullptr){
                        partyList.getCharacter(i)->setTakenTurn(0);
                    }
                }
                cout << "(Press Enter to continue.)" << endl << endl;
                cin.ignore();
                
            }

            else{
                cout << "Unfortunately, your party's journey ends here...maybe in another timeline, things may have been better..." << endl;
                cout << "(Press Enter to continue.)" << endl << endl;
                cin.ignore();
                return 0;
            }
        }
        
        else if(inputValue == "2"){
            partyList.restParty();
            cout << "Your party rests for the night and are fully healed." << endl;
            cout << "(Press Enter to continue.)" << endl << endl;
            cin.ignore();
        }
        else if(inputValue == "3"){
            partyList.partySummary();
            cout << "(Press Enter to continue.)" << endl << endl;
            cin.ignore();
        }
        else if(inputValue == "4"){
            partyList.partySummary();
            cout << "Would you like to save your progress? If so, what would you like to name this file?" << endl << "(Type the file name with .txt prefix)" << endl << "(Press 9 to cancel save)" << endl;
            getline(cin, saveFile);
            if(saveFile != "9"){
                saveParty(partyList, enemyList, 4, saveFile, envNum, fightCount);
                cout << "(Press Enter to continue.)" << endl << endl;
                cin.ignore();
            }
        }
        else if(inputValue == "5"){
            return 0;
        }
        else{
            cout << "Invalid Input!" << endl;
            cout << "(Press Enter to continue.)" << endl << endl;
            cin.ignore();
        }
        
    }

    return 0;
}