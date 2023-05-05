#include "classException.h"

ClassException::ClassException(){
    incorrectClass = "None";
}

ClassException::ClassException(string _class){
    incorrectClass = _class;
}

string ClassException::getIncorrectClass(){
    return incorrectClass;
}

NameException::NameException(){
    incorrectName = "None";
}

NameException::NameException(string _name){
    incorrectName = _name;
}

string NameException::getIncorrectName(){
    return incorrectName;
}