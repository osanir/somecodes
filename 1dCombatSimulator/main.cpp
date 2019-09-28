#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

struct Army{
    string _name;
    int _numOfTroops;
    int _health;
    int _attack;
    float _attackChance;
};

void initArmy( Army* soldier, string name, int numOfTroops, int health, int attack, int attackChance){
    soldier->_name          = name;
    soldier->_numOfTroops   = numOfTroops;
    soldier->_health        = health;
    soldier->_attack     = attack;
    soldier->_attackChance  = attackChance;
}

int main(){
    Army red, blue;
    initArmy( &red, "knigt", 135, 120, 150, 0.0f );
    initArmy( &blue, "goblin", 795, 100, 100, 0.0f );

    int curHealthRed  = red._health;
    int curHealthBlue = blue._health;

    mt19937 randGen( time(NULL) );
    uniform_real_distribution<float> dice( 0.f, 1.f );    

    char turn = 'r';
    
    cout << "Before battle:" << endl;
    cout << blue._name << "'s number of troops: " << blue._numOfTroops << endl;
    cout << red._name << "'s number of troops: " << red._numOfTroops << endl << endl;

    while( red._numOfTroops > 0 && blue._numOfTroops > 0) {
        if( curHealthBlue <=0 ){
            curHealthBlue = blue._health;
            blue._numOfTroops--;
        }
        if( curHealthRed <=0 ){
            curHealthRed = red._health;
            red._numOfTroops--;
        }
        switch (turn){
            case 'r':
                if( dice(randGen) > red._attackChance ){
                    curHealthBlue -= red._attack;
                }
                turn = 'b';
                break;
            case 'b':
                if( dice(randGen) > blue._attackChance ){
                    curHealthRed -= blue._attack;
                }
                turn = 'r';
                break;
            
            default: break;
        }
    }

   // for(int i=0; i<30; i++)
   // cout << "Random: " << dice(randGen) << endl;

    cout << "After battle:" << endl;
    cout << blue._name << "'s number of troops: " << blue._numOfTroops << endl;
    cout << red._name << "'s number of troops: " << red._numOfTroops << endl;

}

