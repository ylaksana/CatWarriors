#include "partylist.h"

PartyList::PartyList(){
    count = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        partyList[i] = nullptr;
    }
}

PartyList::~PartyList(){
    for(int i = 0; i < MAX_SIZE; i++){
        if(partyList[i] != nullptr){
            delete partyList[i];
            partyList[i] = nullptr;
        }
    }
}

void PartyList::addMember(Character& _cat){
    int idx;
   
    if(count < MAX_SIZE){
        for(int i = 0; i < MAX_SIZE; i++){
            if(partyList[i] == nullptr){
                idx = i;
                break;
            }
        }
        if(_cat.getClass() == "Ragdoll"){
            partyList[idx] = new Ragdoll((Ragdoll &) _cat);
            count++;
        }
        else if(_cat.getClass() == "Shorthair"){
            partyList[idx] = new Shorthair((Shorthair &) _cat);
            count++;
        }
        else if(_cat.getClass() == "MaineCoon"){
            partyList[idx] = new MaineCoon((MaineCoon &) _cat);
            count++;
        }
        
    }
    
    
    else{
        cout << "Party is full!" << endl;
    }

}

void PartyList::dismissMember(string& name){
    bool nameFound = false;
    int idx;
    for(int i = 0; i < MAX_SIZE; i++){
        if(partyList[i] != nullptr){
            if(partyList[i]->getName() == name){
                idx = i;
                nameFound = true;
            }
        }
    }

    if(nameFound){
        delete partyList[idx];
        partyList[idx] = nullptr;
        count--;
        cout << name << " has been removed from party." << endl;
    }

    else{
        throw NameException();
    }
}

void PartyList::death(int idx){
    cout << "Party member " << partyList[idx]->getName() << " has been died..." << endl;
        delete partyList[idx];
        partyList[idx] = nullptr;
        count--;

}

void PartyList::partySummary() const{
    bool foundMember = false;
    for(int i = 0; i < MAX_SIZE; i++){
        if(partyList[i] != nullptr){
            foundMember = true;
            break;
        }
    }
    if(foundMember){
        for(int i = 0; i < MAX_SIZE; i++){
            if(partyList[i] != nullptr){
                partyList[i]->printInfo();
            }
        }
    }
    else{
        cout << "Party is empty." << endl;
        throw PartyException();
    }
}

bool PartyList::checkParty(){
    bool foundMember = false;
    for(int i = 0; i < MAX_SIZE; i++){
        if(partyList[i] != nullptr){
            foundMember = true;
            return foundMember;
        }
    }

    return foundMember;
}

Character*& PartyList::getCharacter(int idx){
    if(partyList[idx] == nullptr){
        throw CharacterException();
    }
    return partyList[idx];
}

bool PartyList::checkPartyTurns(){
    for(int i = 0; i < MAX_SIZE; i++){
        if(partyList[i] != nullptr){
            if(partyList[i]->getTakenTurn() == 0){
                return false;
            }
        }
    }

    return true;
}

void PartyList::restParty(){
    for(int i = 0; i < MAX_SIZE; i++){
        if(partyList[i] != nullptr){
            partyList[i]->setHP(partyList[i]->getMaxHP());
            partyList[i]->setMana(partyList[i]->getMaxMana());
        }
    }
}

void PartyList::resetParty(){
    for(int i = 0; i < MAX_SIZE; i++){
        if(partyList[i] != nullptr){
            delete partyList[i];
            partyList[i] = nullptr;
        }
    }
}


