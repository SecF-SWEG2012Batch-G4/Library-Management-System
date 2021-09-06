#include<iostream>
#include<iomanip>
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
            {" Fluid Mechanics","Educational",{30,9,2017},"Bruce Roy Munson",2,11,3.9,true},
            {"Introduction To Computing","Educational",{02,12,2019},"Steven C Chapra",6,12,2.3,true},
            {"Materials science ","Educational",{23,8,2021},"Steven C Chapra",2,13,5,true},
            {"Perfect Chemistry","Romance",{28,02,2019},"Simone Elkeles",1,14,4.8,true},
            {"Dune","Romance",{05,17,2017},"Frank Herbert",9,15,4.1,true},
            {"Hamlet","Drama",{00,00,1601},"William Shakespeare",10,16,4.6,true}
			}};
			int main(){
//show book
    cout<<"=====================================================================================================\n";
    cout<<"No"<<setw(15)<<"Book ID"<<setw(30)<<"Book Name"<<setw(30)<<"Book category"<<setw(20)<<"Rating"<<setw(15)<<"\n";

    for(int i =0; i<totalBooks; i++){


    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<i+1<<")"<<setw(15)<<(book_info+i)->id<<setw(35)<<(book_info+i)->name<<setw(25)<<(book_info+i)->category<<setw(18)<<(book_info+i)->rating<<endl;
}
    return 0;

}

