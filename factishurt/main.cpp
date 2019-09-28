#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

struct Node{
    int num;
    double fact;
};

struct FactList{
    void getInput();
    list<Node> myList;
    list<Node>::iterator iter;
    Node input;
    
    FactList();
    void conditions();
    bool checkList();
    void findBiggest();
    void calculate(bool flag);
    void addList();
    void printList();
};

int main(){
    FactList list;
    while( list.input.num != -1 ){
        list.getInput();
        list.conditions();    
        list.printList();
    }
}

FactList::FactList(){
    input.num = 1;
    input.fact = 1;
}

void FactList::getInput(){
    cout << "Enter number: ";
    cin >> input.num;
    input.fact = 1;
}

void FactList::conditions(){
    if( myList.empty() ){
        calculate( 0 );
    } else if ( checkList() ){
            input.fact = (*iter).fact;
    } else {
        findBiggest();
        calculate( 1 );
    }
    addList();
}

bool FactList::checkList(){
    for( iter = myList.begin(); iter != myList.end(); iter++ ){
        if( (*iter).num == input.num )
            return true;
    }
    return false;
}

void FactList::findBiggest(){
    iter = myList.begin();
    while( iter != myList.end() ){
        if( input.num < (*iter).num ){
            iter--;
            break;
        }
    iter++;
    }
    
}

void FactList::calculate( bool flag=false ){
    Node temp;
    if( flag ){
        temp.num = (*iter).num+1;
        temp.fact = (*iter).fact;
    }else{
        temp.num = 1;
        temp.fact = 1;
    }
    for( int i = temp.num; i<=input.num; i++){
        temp.fact *= i;
    }
    input.fact = temp.fact;
}

void FactList::addList(){   // input ilk sıraya yerleşmeye çalışırsa??
    if( myList.empty() ){
        myList.push_back(input);
        return;
    }
    else if( (*myList.begin()).num > input.num ){
            myList.push_front(input);
            return;
        }
    else {
        for( iter = myList.begin(); iter != myList.end(); iter++){
            if( input.num < (*iter).num ){
                iter--;
                myList.insert( iter, input);
                return;
            }
        }
    }
    myList.push_back(input);    
}

void FactList::printList(){
    if ( myList.empty() ){
        cout << "List is empty!" << endl;
        return;
    } 

    iter = myList.begin();
    while( iter != myList.end() ){
        printf("%d's fact is %.0lf\n", (*iter).num, (*iter).fact);
        iter++;
    }

}
