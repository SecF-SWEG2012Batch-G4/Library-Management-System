#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;
//string nbooks[100][8];
//int  *ptr=*nbooks;//new books


//shared pointer
void access();//navigates to either student or librarian
void librarian(string &f_name,string &l_name);//librarians menu
void student(string &f_name, string &l_name);//students menu
void new_entry();

void books();
void Search();
void overduecalc();//coming soon


enum Genre{Fiction=0,Romance,Drama,Educational};
struct date
{
    int dd,mm,yy;
};

struct bookinfo
{
   string name;
   string genre;//(category)
   date dop;//Date of publication
   string author;
   int amount;//how many books there are
   int id;//book id
   float rating;//(out of 5)
   bool avail;//books availability
}
book[100]={{"Harry potter","Fiction",12,23,2004,"J.K Rowlings",5,10,4.8,true}};//array of structures

struct student
{

    string f_name;
    string l_name;
    string password;

}
stud[20]={{"tibebe","solomon","1234stud"},
           {"tsion","tesfaye","1234stud"},
           {"natnael","shimelis","1234stud"},
           {"natnael","menelik","1234stud"}},*stud_info=stud;

struct librarian
{
string f_name ;
string l_name;
string password;
}
lib[20]={{"tibebe","solomon","1234lib"},
         {"tsion","tesfaye","1234lib"},
         {"natnael","shimelis","1234lib"},
         {"natnael","menelik","1234lib"}},*lib_info=lib;


int main()
{

    //new_entry();
    cout<<"\n\n"<<endl;
    cout<<setw(80)<<"Welcome to the library management system\n"<<endl;
    cout<<setw(80)<<"_________________________________________\n"<<endl;
    cout<<setw(70)<<"Are you a Librarian Press 1\n\n "<<endl;
    cout<<setw(70)<<"Are you a Student   Press 2 \n\n"<<endl;
    //Search();
    access();
}

void access()
{
    string password,f_name,l_name;
    entry:
    int option;
    cin>>option;
    if (option==1)
    {
//////librarians login page
    lib_log:
    cout<<setw(70)<<"Enter your librarian info to login: "<<endl;
    cout<<"User name: ";
    cin>>f_name;
    cin>>l_name;
    cout<<"Password: ";
    cin>>password;

    for(int i=0;i<20;i++)
    {

    if(f_name==(lib_info+i)->f_name && l_name==(lib_info+i)->l_name && password==(lib_info+i)->password)
   {
        librarian(f_name,l_name);
   }
    else
        cout<<""<<endl;
      //  goto lib_log;
   }

   }

//////students login page
else if (option==2)
   {
       stud_log:
    cout<<setw(70)<<"Enter your student info to login: "<<endl;
    cout<<"User name: ";
    cin>>f_name;
    cin>>l_name;

    cout<<"Password: ";

    for(int i=0;i<20;i++)
    {
    if(f_name==(stud_info+i)->f_name && l_name==(stud_info+i)->l_name && password==(stud_info+i)->password)
    {
       student(f_name,l_name);
    }
    else
    {
       cout<<"Invalid input,Please Try Again"<<endl;
      // goto stud_log;
    }
}
}

};

void librarian(string &f_name,string &l_name)
{

       int option;
       Back:
    cout<<setw(45)<<"Hello "<<f_name<<" "<<l_name<<"...\n\n";
    cout<<setw(60)<<"What would you like to do.\n\n";

    cout<<setw(60)<<"1.Add new user/Student.\n"<<endl;//.Add new user
    cout<<setw(60)<<"2.Add books to the shelves.\n"<<endl;//Add new books
    cout<<setw(60)<<"3.Check book availability.\n"<<endl;//Check availability
    cout<<setw(60)<<"4.Check out a book.\n"<<endl;//Borrow a book
    cout<<setw(60)<<"5.Overdue notification\n"<<endl;//Over due notification &calculate payment
    cout<<setw(60)<<"6.Classify books by category.\n"<<endl;//Classification books by category    (already a void search)
    cout<<setw(60)<<"7.Classify books by rating/high reader.\n"<<endl;//rating & ranking
    cout<<setw(60)<<"8.Set duration limit on availability.\n"<<endl;//Set duration limit
    cout<<setw(60)<<"9.Produce statistical report.\n"<<endl;//Set duration limit
    cin>>option;
    if (option==2)
    {
        new_entry();
    }
    else
    {
        cout<<"Go back";
        goto Back;}

};

void student(string &f_name, string &l_name)
{
  entrance:
    cout<<setw(45)<<"Hello  "<<f_name<<" "<<l_name<<"..."<<"\n\n";
    cout<<setw(70)<<"What would you like to do\n\n";
    cout<<setw(65)<<"1.Search for a book.\n\n";
    cout<<setw(60)<<"2.Check book availability..\n"<<endl;
    cout<<setw(60)<<"3.Check out a book..\n"<<endl;//Borrow a book
    cout<<setw(60)<<"4.Return a book..\n"<<endl;
    cout<<setw(60)<<"5.Overdue notification\n"<<endl;//Over due notification &calculate payment
    cout<<setw(60)<<"6.Classify books by category.\n"<<endl;//Classification books by category    (already a void search)
    cout<<setw(60)<<"7.Classify books by rating/high reader.\n"<<endl;//rating & ranking

int option;
cin>>option;
if (option==1)
{
 Search();
}

else
{
    cout<<"invalid input";
goto entrance;
}

};

void Search()
{

    int genre;
    cout<<setw(75)<<"Here are all our available genre's: "<<endl;
    cout<<setw(75)<<"Fiction       PRESS "<<Fiction<<endl;
    cout<<setw(75)<<"\nRomance     PRESS "<<Romance<<endl;
    cout<<setw(75)<<"\nDrama       PRESS "<<Drama<<endl;
    cout<<setw(75)<<"\nEducational PRESS "<<Educational<<endl;
    cin>>genre;

    if(genre==0)
    {
       cout<<"HP";
    }
    else if(genre==1)
    {
    cout<<"Romance";
    }
    else if(genre==2)
    {
cout<<"Drama";
    }
    else if(genre==4)
    {
        cout<<"Educational";

    }
    else
        cout<<"BS"<<endl;
    /*
     cout<<setw(26)<<"Title"<<setw(11)<<"|Genre"<<setw(24)<<"|Date of publication"<<"|Author"<<"|Amount"<<"|ID\n\n";
    cout<<setw(30)<<book[0].name<<" | "<<book[0].genre<<" | "<<book[0].dop.dd<<"-"<<book[0].dop.mm<<"-"<<book[0].dop.yy<<" | "<<book[0].author<<" | "<<book[0].amount<<" | "<<book[0].id;
*/
};

void new_entry()
{
    int amount;
    cout<<"How many books do you want to register: ";
    cin>>amount;
    cout<<"Register a new book: "<<endl;
    for(int i=1;i<amount+1;i++)
    {
    cout<<"Name: ";      cin>>book[i].name;
   cout<<"Genre: "; cin>>book[i].genre;
    cout<<"Date of publication: "; cin>>book[i].dop.dd>>book[i].dop.mm>>book[i].dop.yy;
    cout<<"Amount available: "; cin>>book[i].amount;
    cout<<"Id no: "; cin>>book[i].id;
    }

system("cls");

cout<<"Repository: "<<endl;
cout<<"Name: "; cout<<"Genre: "; cout<<"Date of publication: ";  cout<<"Amount available: ";   cout<<"Id no: "; cout<<endl;
     for(int i=0;i<amount+1;i++)
     {
    cout<<book[i].name<<" ";
    cout<<book[i].genre<<" ";
    cout<<book[i].dop.dd<<book[i].dop.mm<<book[i].dop.yy<<" ";
    cout<<book[i].amount<<" ";
    cout<<book[i].id<<" "<<endl;
     }

};

