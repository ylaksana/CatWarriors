#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

class ClassException{
    public:
        ClassException();
        ClassException(string);
        string getIncorrectClass();

    private: 
        string incorrectClass;
};

class NameException{
    public:
        NameException();
        NameException(string);
        string getIncorrectName();

    private:
        string incorrectName;

};

class CharacterException{};
class PartyException{};
class EnemyException{};



#endif