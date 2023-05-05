#ifndef PARTYLIST_H
#define PARTYLIST_H

#include "character.h"
#include "classException.h"
#include "classes.h"

using namespace std;

const int MAX_SIZE = 4;

class PartyList{
    public:
        PartyList();
        ~PartyList();
        Character* &getCharacter(int);
        void addMember(Character&);
        void dismissMember(string&);
        void partySummary() const;
        bool checkParty();
        bool checkPartyTurns();
        void restParty();
        void resetParty();
        void death(int);

    private:
        Character *partyList[MAX_SIZE];
        int count;

};

#endif