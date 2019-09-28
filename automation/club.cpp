// TODO: UPDATE FIELD
// TODO: SPACE ERROR IN NAMES
#include "club.h"

Club::Club(){

}

void Club::open_db(){
    FILE *file;
    file = fopen("users.db", "r");

    while( 1 ){
        User new_user;
        fscanf(file, "%d", &new_user.user_id);
        fscanf(file, "%s", new_user.name);
        fscanf(file, "%s", new_user.surname);
        fscanf(file, "%s", new_user.mail);
        fscanf(file, "%s", new_user.phone);
        if( feof(file) ) break; // check end of file
        
        insert_order(new_user);
    }
    fclose(file);
}

void Club::close_db(){
    FILE *file;
    file = fopen("users.db", "w");
    list<User>::iterator iter;

    iter = students.begin();
    while( iter != students.end() ){
        fprintf(file, "%10d ", iter->user_id);
        fprintf(file, "%15s ", iter->name);
        fprintf(file, "%15s ", iter->surname);
        fprintf(file, "%30s    ", iter->mail);
        fprintf(file, "%10s\n", iter->phone);
        iter++;
    }
    fclose(file);
}

list<User>::iterator Club::search_user(){
    int id;
    cout << "Enter the student ID: " ;
    cin >> id;
    cin.ignore(256, '\n');

    list<User>::iterator iter;
    iter = students.begin();
    while(iter != students.end() ){
        if( iter->user_id == id )
            return iter;
        iter++;
    }
    cout << "Could not found any record." << endl;
    return iter;
}

void Club::list_all(){
    list<User>::iterator iter;
    int counter = 1;
    iter = students.begin();
    printf("     Student ID            Name         Surname                         E-Mail           Phone\n");
    while( iter != students.end() ){
        printf("%3d  %10d %15s %15s %30s    +90%10s\n", counter++, iter->user_id, iter->name, iter->surname, iter->mail, iter->phone ); 
        iter++;
    }
}

void Club::add(){
    User new_user;

    cout << "Student ID: ";
    cin >> new_user.user_id;
    cin.ignore(256, '\n');

    cout << "Name:       ";
    cin >> new_user.name;
    cin.ignore(256, '\n');

    cout << "Surname:    ";
    cin >> new_user.surname;
    cin.ignore(256, '\n');
    
    cout << "E-Mail:     ";
    cin >> new_user.mail;
    cin.ignore(256, '\n');

    cout << "Phone:      ";
    cin >> new_user.phone;
    cin.ignore(256, '\n');

    cout << endl << endl;

    insert_order(new_user);

}

void Club::del(list<User>::iterator iter){
    students.erase(iter);
}

void Club::update(list<User>::iterator iter){
    //// NOT COMPLETED
    show_record(iter);
    User user;
    user.user_id = iter->user_id;
    strcpy(user.name, iter->name);
    strcpy(user.surname, iter->surname);
    strcpy(user.mail, iter->mail);
    strcpy(user.phone, iter->phone);

    cout << "Enter the new values (leave blank to avoid changes)" << endl << endl;

    cout << "Student ID: ";
    cin >> user.user_id;
    cin.ignore(256, '\n');

    cout << "Name:       ";
    cin >> user.name;
    cin.ignore(256, '\n');

    cout << "Surname:    ";
    cin >> user.surname;
    cin.ignore(256, '\n');
    
    cout << "E-Mail:     ";
    cin >> user.mail;
    cin.ignore(256, '\n');

    cout << "Phone:      ";
    cin >> user.phone;
    cin.ignore(256, '\n');

    if( user.user_id != -1)
        iter->user_id = user.user_id;
    if( strcmp(user.name, " ") != 0)
        strcpy(iter->name, user.name);
    if( strcmp(user.surname, " ") != 0)
        strcpy(iter->surname, user.surname);
    if( strcmp(user.mail, " ") != 0)
        strcpy(iter->mail, user.mail);
    if( strcmp(user.phone, " ") != 0)
        strcpy(iter->phone, user.phone);
}

void Club::show_record(list<User>::iterator iter){
    if( iter != students.end() ){
        printf("Student ID            Name         Surname                         E-Mail           Phone\n");
        printf("%10d %15s %15s %30s    +90%10s\n", iter->user_id, iter->name, iter->surname, iter->mail, iter->phone ); 
    }
}

void Club::show_menu(){
    cout << "KtuSec Panel" << endl;
    cout << endl << endl;
    cout << "1. List All"       << endl;
    cout << "2. Add Record"     << endl;
    cout << "3. Delete Record"  << endl;
    cout << "4. Update Record"  << endl;
    cout << "5. Show Record"    << endl;

    int ch;
    cin >> ch;
    cin.ignore(256, '\n');
    switch(ch){
        case 1:
            list_all();
            break;
        case 2:
            add();
            break;
        case 3:
            del(search_user());
            break;
        case 4:
            update(search_user());
            break;
        case 5:
                show_record(search_user());
            break;
        default:
            break;
    }
}

void Club::insert_order(User new_user){
    list<User>::iterator iter;
    iter = students.begin();
    while( iter != students.end() && new_user.user_id >= iter->user_id ){
        iter++;
    }
    students.insert(iter, new_user);
}

