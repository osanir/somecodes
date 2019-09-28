#include <iostream>
#include "include/person.h"
using namespace std;

int main(){
    Person females[2];
    Person males[2];
   //string name, int sHair, int dHair, int sGender, int dGender;

    females[0].initPerson("Ayşe", 1, 2, 2, 1);
    females[1].initPerson("Fatma", 2, 2, 2, 1);

    males[0].initPerson("Ali", 2, 1, 1, 2);
    males[1].initPerson("Mehmet", 2, 2, 1, 2);
    string kerem = "aaci";
    string muco = "bbci";
    cout << kerem.compare(muco);
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            females[i].compare(&males[j]);
        }
    }

    for(int i=0; i<2; i++){
        females[i].printInfo();
        males[i].printInfo();
    }

    return 0;
}