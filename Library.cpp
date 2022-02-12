#include "Library.hpp"
bool book::Search(int id){


return true;
}
void book::add(char** args){
fstream db("books.txt",ios::app|ios::out);



char* barcode=args[0];
char* isbn=args[1];
char* author=args[2];
char* name=args[3];

db<<barcode<<","<<isbn<<","<<author<<","<<name<<endl;
db.close();
wxMessageBox(_("added to the library"),"Library Stok");
    }
void book::Remove(char** args){

vector<string> stok_file;
fstream db("books.txt",ios::in|ios::out);
int barcode=stoi(args[0]);
string line;
while(getline(db,line)) stok_file.push_back(line);

vector<string>::iterator it=stok_file.begin();

while(it!=stok_file.end()){
    stringstream Line{*it};
    string Barcode;
    getline(Line,Barcode,',');

        if(stoi(Barcode)==barcode){
            it=stok_file.erase(it);
break;
        }
it++;
    }
db.close();
ofstream Db{"books.txt",ios::out};
for(const string& myline:stok_file) Db<<myline<<endl;
Db.close();
wxMessageBox("removed from the library","Library Stok");
    }




 vector<wxString> library::members(){

fstream db("members.txt",ios::in);
if(db.is_open())
    db.close();
db.open("members.txt",ios::in);
vector<wxString> choices;
choices.clear();
string line="";
while(getline(db,line)) choices.push_back((wxString)line);

    //wxString choices_val[2]={'a','b'};


    //vector<wxString> choices(choices_val,choices_val+2);

db.close();
return choices;

}
int library::memberCounts(){
fstream db("members.txt",ios::in);

int size=0;
string line="";
while(getline(db,line)) size++;

db.close();
return size;

}





bool personel::Search(int id){

return false;
}
bool personel::add(char** args){
    fstream file("db.test");
if(args[2])
    return false;
else
    return true;
}
bool personel::Remove(char* name,char* email,char* tel,int id){
return false;
}




void Library_members::add_book(char** args){

fstream db("members.txt",ios::in);
vector<string> all_lines;
all_lines.clear();
char* id=args[0];
int ID=atoi(id);
string barcode=args[1];

string line;
while(getline(db,line)) all_lines.push_back(line);

vector<string>::iterator it;
for(it=all_lines.begin();it!=all_lines.end();it++){
    stringstream Line{*it};
    string memberID,name,tel,email;
    string regbooks[3];

    getline(Line,memberID,',');
    getline(Line,name,',');
    getline(Line,tel,',');
    getline(Line,email,',');
    getline(Line,regbooks[0],',');
    getline(Line,regbooks[1],',');
    getline(Line,regbooks[2],',');
        if(stoi(memberID)==ID){

            if(regbooks[0]=="-"){
                regbooks[0]=barcode;
                string member{memberID+","+name+","+tel+","+email+","+regbooks[0]+","+ regbooks[1] +","+ regbooks[2]};
                *it=member;
                wxMessageBox("Book Delivered","Deliver Book");
                break;
            }
            else if (regbooks[1]=="-"){
                regbooks[1]=barcode;
                string member{memberID +","+ name +","+ tel +","+ email +","+ regbooks[0] +","+ regbooks[1]+","+ regbooks[2] };
                *it=member;
                wxMessageBox("Book Delivered","Deliver Book");
                break;
            }
            else if (regbooks[2]=="-"){
                regbooks[2]=barcode;
                string member={memberID +","+ name +","+ tel +","+ email +","+ regbooks[0] +","+ regbooks[1] +","+ regbooks[2]};
                *it=member;
                wxMessageBox("Book Delivered","Deliver Book");
                break;
            }
            else{
                wxMessageBox("cant deliver book limit is reached","Deliver Book");
                break;
            }

        }

    }
db.close();
ofstream Db{"members.txt",ios::out};
for(const string& myline:all_lines) Db<<myline<<endl;
Db.close();

}
void Library_members::remove_book(char** args){

fstream db("members.txt",ios::in);
vector<string> all_lines;
all_lines.clear();

string ID=args[0];
string barcode=args[1];

string line="";
while(getline(db,line)) all_lines.push_back(line);

vector<string>::iterator it;
for(it=all_lines.begin();it!=all_lines.end();it++){
    stringstream Line{*it};
    string memberID,name,tel,email;
    string regbooks[3];

    getline(Line,memberID,',');
    getline(Line,name,',');
    getline(Line,tel,',');
    getline(Line,email,',');
    getline(Line,regbooks[0],',');
    getline(Line,regbooks[1],',');
    getline(Line,regbooks[2],',');
        if(memberID==ID){
            if(regbooks[0]==barcode){
                string member{memberID+","+name+","+tel+","+email+","+ "-" +","+ regbooks[1] +","+ regbooks[2]};
                *it=member;
                wxMessageBox("Book Delivered","Take Delivery");
                break;
            }
            else if(regbooks[1]==barcode){
                string member{memberID +","+ name +","+ tel +","+ email +","+ regbooks[0] +","+ "-" +","+ regbooks[2]};
                *it=member;
                wxMessageBox("Book Delivered","Take Delivery");
                break;
            }
            else if(regbooks[2]==barcode){
                string member{memberID +","+ name +","+ tel +","+ email +","+ regbooks[0] +","+ regbooks[1] +","+ "-"};
                *it=member;
                wxMessageBox("Book Delivered","Take Delivery");
                break;
            }
            else{
                wxMessageBox("not found","Take Delivery");
                break;
            }

        }

    }
db.close();
ofstream Db{"members.txt",ios::out};
for(const string& newline:all_lines) Db<<newline<<endl;
Db.close();
wxMessageBox("registered","Take Out Book");
}
bool Library_members::Search(int id){

return false;
    }
void Library_members::add(char** args){

ofstream db{"members.txt",ios::app};
if(db.is_open()){
    db<<args[0]<<","<<args[1]<<","<<args[2]<<","<<args[3]<<",-,-,-"<<endl;
    db.close();
    wxMessageBox("Registered To The Library","Member Registration");

}
else{
wxMessageBox("Can't Access The Database","Member Registration");

}


    }
void Library_members::Remove(char** args){


    }

