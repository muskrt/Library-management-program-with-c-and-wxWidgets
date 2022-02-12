
#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <wx/msgdlg.h>
#include <wx/string.h>
//#include <wx/msgdlg.h>
#include <map>
#include <vector>
#include <typeinfo>
using namespace std;
class library{
private:
    //desk reseravations map<desknumber,list<id,name>>
    map<int,pair<int,char*>> All_desksk;
public:
    vector<wxString> members( );
    int memberCounts();
    int obj=54;
};

class DataBase{
private:
    //personal_db_path;
    //members_db_path;
    //book_db_path;
public:
    //return related path to caller object
    char* getpath(char* name);
    virtual bool Search(int id)=0;



};

class Desk:public library{};;

class book:public library,virtual public DataBase{

    public:
    bool Search(int id);
    void add(char** args);
    void Remove(char** args);
};

class personel:public library,virtual public DataBase{

    public:
    bool Search(int id);
    bool add(char** args);
    bool Remove(char* name,char* email,char* tel,int id);
};

class Library_members:public library,virtual public DataBase{

    public:
    bool Search(int id);

    void add(char** args);
    void Remove(char** args);

    void add_book(char**);
    void remove_book(char**);



};


////stedents.search()
////sutdents.add(name,id,etc)
/////personals.search()
////personal.add()





#endif // LIBRARY_H
