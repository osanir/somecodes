#include <iostream>
#include <list>
using namespace std;

struct Node{
    int num;
    double fact;
};

struct FactList{
    list<Node> myList;
    list<Node>::iterator iter;

    void checkList(int num);
    Node calculate(int num);
    void printList();
};

int main(){
    int num;
    FactList list;
    while( num != -1 ){
        cout << "Enter number: ";
        cin >> num;
        cout << list.calculate(num).num << " " << list.calculate(num).fact << endl; // daha önce bulunmuş mu kontrolü
        list.printList();
    }
}

void FactList::checkList(int num){
    iter = myList.begin();
    while( (*iter).num != num && (*iter).num < num && iter != myList.end() )
        iter = iter++;    
}

Node FactList::calculate(int num){
    checkList(num);
    Node temp;
    temp.num = num;
    temp.fact = 1;
    if ( (*iter).num == num )
        return (*iter);
    int base;
    if( !myList.empty() ){
        temp.fact = (*iter).fact;
        base = (*iter).num+1; 
    } else base = 1;
    for(int i = base; i<=num; i++){
        temp.fact *= i;
    }
    myList.insert(iter, temp) ;
    return temp;
}

void FactList::printList(){
    for( iter = myList.begin(); iter != myList.end(); iter++ ){
        cout << (*iter).num << " : " << (*iter).fact << endl; 
    }
}
