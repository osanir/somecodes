#include <iostream>
#include <list>
#include <fstream>
#include <string.h>
using namespace std;

class User{
public:
    //User(){ id = Club::get_primary_key()}
    int user_id;
    char name[64];
    char surname[32];
    char mail[128];
    char phone[16];
};

class Club{
public:
    Club();
    void open_db();
    void close_db();
    list<User>::iterator search_user();
    void list_all();
    void add();
    void del( list<User>::iterator iter );
    void update( list<User>::iterator iter );
    void show_record( list<User>::iterator );
    void show_menu();
    void insert_order(User new_user);
private:
    list<User> students;
};