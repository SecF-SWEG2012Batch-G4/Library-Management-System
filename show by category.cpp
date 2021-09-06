#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int totalBooks= 8;
enum Genre{Fiction=0,Romance,Drama,Educational};
struct date
{
    int dd,mm,yy;
};
 struct bookinfo
{
   string name;
   string category;//(category)
   date dop;//Date of publication
   string author;
   int amount;//how many books there are
   int id;//book id
   float rating;//(out of 5)
   bool avail;//books availability
};
 bookinfo* book_info
 { new bookinfo[totalBooks] {
            {"harry potter","Fiction",{12,23,2004},"J.K Rowlings",5,10,4.8,true},
            {"Fundamentals of Fluid Mechanics","Educational",{30,9,2017},"Bruce Roy Munson",2,11,3.9,true},
            {"Introduction To Computing","Educational",{02,12,2019},"Steven C Chapra",6,12,2.3,true},
            {"Materials science ","Educational",{23,8,2021},"Steven C Chapra",2,13,5,true},
            {"Perfect Chemistry","Romance",{28,02,2019},"Simone Elkeles",1,14,4.8,true},
            {"Dune","Romance",{05,17,2017},"Frank Herbert",9,15,4.1,true},
            {"Hamlet","Drama",{00,00,1601},"William Shakespeare",10,16,4.6,true}
			}};
int main(){

	   categoryOption:
       string cat;
       cout<<"Please enter the category you'd like to view: ";
//cin.ignore();
   getline(cin, cat);
   bool showCat= false;
   for(int i =0; i<totalBooks; i++){

    if(cat==(book_info+i)->category){
    cout<<"=====================================================================================================\n";
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book Author"<<setw(20)<<"Rating\n";
    cout<<"=====================================================================================================\n";
    cout<<(book_info+i)->id<<setw(21)<<(book_info+i)->name<<setw(20)<<(book_info+i)->author<<setw(20)<<(book_info+i)->rating<<endl;
     showCat= true;}
    //else{cout<<"Sorry, we don't have books with that genre "<<endl;
   // goto categoryOption;}
    }
    if (showCat= false)
	{cout<<"Sorry, we don't have books with that genre "<<endl;
    goto categoryOption;}
}



