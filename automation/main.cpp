#include <iostream>
#include "club.h"
using namespace std;

int main(){
    Club myClub;

    myClub.open_db();
    myClub.show_menu();
    myClub.close_db();

}