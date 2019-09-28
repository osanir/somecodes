#include "../include/person.h"

Person::Person(){ 
    _self.hair = 0; 
    _desire.hair = 0;
    _self.gender = 0;
    _desire.gender = 0;
}

Person::Person(int sHair, int dHair, int sGender, int dGender){ 
    _self.hair = sHair; 
    _desire.hair = dHair;
    _self.gender = sGender;
    _desire.gender = dGender;
    _part = nullptr;
}

void Person::initPerson(string name, int sHair, int dHair, int sGender, int dGender){
    _name = name;
    _self.hair = sHair; 
    _desire.hair = dHair;
    _self.gender = sGender;
    _desire.gender = dGender;
    _part = nullptr;
}


void Person::compare(Person* person){
    if( ((this->_desire.hair == person->_self.hair ) && (this->_desire.gender == person->_self.gender))
        && ((this->_self.hair == person->_desire.hair) && (this->_self.gender == person->_desire.gender))    ){
        this->_part = person;
        person->_part = this;
    }
}

void Person::printInfo(){
    cout << "İsim\t: " << this->_name << endl;
    cout << "Partner\t: " << this->_part->_name << endl << endl;
}
