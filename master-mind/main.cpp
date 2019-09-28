#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

bool showMatches(vector<int>, vector<int>);

int main(int argc, char ** argv){
    int digit = 3;
    int upperLimit = 6;
    if( argc == 3){
        int digit = atoi(argv[1]);
        int upperLimit = atoi(argv[2]);
    } else{
        cout << "./mastermind <digit> <upper-limit>" << endl;
    }
    srand(time(NULL));
    
    vector<int> inputNumber;
    vector<int> inputGuess;
    // Random secret number generator
    for(int i=0; i<digit; i++)
        inputNumber.push_back( (rand()%upperLimit+1) );
    // Print random secret number    
   // for(int i=0; i<digit; i++)
     //   cout << inputNumber[i] << " ";
       // cout << endl;

    int guess;
    int counter = 0;
    do{
        cout << "Enter your guess: " ;
        cin >> guess;

        inputGuess.clear();
        // User Guess >> Vector Array 
        for(int i=1; i<=digit; i++){
            inputGuess.push_back(guess%10);
            guess /= 10;
        }

        ;

        counter++;
    }while( showMatches(inputNumber, inputGuess) );

    

}

bool showMatches(vector<int> number, vector<int> guess){
    int rev = number.size();
    int won = number.size();
    int matches[2] = {0,0};
    for(int i=0; i<number.size(); i++){
        if(  guess[rev-1-i] == number[i] ){
            matches[0] += 1;
            won--;
        }
        else{
            for(int j=0; j<number.size(); j++){
                if( guess[rev-1-j] == number[i] ){
                    matches[1] += 1;
                    break;
                }
            }
        }
    }
    while( matches[0] > 0 ){
        cout << "*";
        matches[0] -= 1;
    }
    while( matches[1] > 0 ){
        cout << "-";
        matches[1] -= 1;
    }
    cout << endl;
    if( won == 0 ){
        cout << "You Won!" << endl;
        return 0;
    }
    return 1;
}
