#include <string>
#include <iostream>

using namespace std;

struct Character{
    int hair;   // 0 unknown, 1 blonde, 2 black
    int gender; // 0 unknown, 1 male, 2 female
};

class Person{
public:
    Person();
    Person(int sHair, int dHair, int sGender, int dGender);
    void initPerson(string name, int sHair, int dHair, int sGender, int dGender);
    void compare(Person* person);
    void printInfo();

private:
    string _name;
    Character _self;
    Character _desire;
    Person* _part;
};