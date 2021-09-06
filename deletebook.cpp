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
            {"Fundamentals of Fluid Mechanics","Educational",{30,9,2017},"Bruce Roy Munson",2,11,3.9,true},
            {"Introduction To Computing","Educational",{02,12,2019},"Steven C Chapra",6,12,2.3,true},
            {"Materials science ","Educational",{23,8,2021},"Steven C Chapra",2,13,5,true},
            {"Perfect Chemistry","Romance",{28,02,2019},"Simone Elkeles",1,14,4.8,true},
            {"Dune","Romance",{05,17,2017},"Frank Herbert",9,15,4.1,true},
            {"Hamlet","Drama",{00,00,1601},"William Shakespeare",10,16,4.6,true}
			}};
bookinfo* Cbook_info = new bookinfo [totalBooks];

int main(){
	int num, x, jumper= 0;
	//showbook();
	cout<<"Enter the number of the book you want to delete from the list above: ";
	cin>>num;
	num--;// since we will be deleting an index
	x = totalBooks;
	totalBooks--;
	delete[] Cbook_info;
	Cbook_info = new bookinfo[totalBooks];
	
	 for (int i= 0; i <x; i++)
    {
        if (i != num)
        {
            Cbook_info[jumper].name = book_info[i].name;
            Cbook_info[jumper].category = book_info[i].category;
            Cbook_info[jumper].dop = book_info[i].dop;
            Cbook_info[jumper].author = book_info[i].author;
            Cbook_info[jumper].amount = book_info[i].amount;
            Cbook_info[jumper].id = book_info[i].id;
            Cbook_info[jumper].rating = book_info[i].rating;
            Cbook_info[jumper].avail = book_info[i].avail;
            jumper++;
        }
    }
    delete [] book_info;
    book_info = new bookinfo[totalBooks];
    for (int i= 0; i <totalBooks; i++)
    {
        
            book_info[i].name = Cbook_info[i].name;
            book_info[i].category = Cbook_info[i].category;
            book_info[i].dop = Cbook_info[i].dop;
            book_info[i].author = Cbook_info[i].author;
            book_info[i].amount = Cbook_info[i].amount;
            book_info[i].id = Cbook_info[i].id;
            book_info[i].rating = Cbook_info[i].rating;
            book_info[i].avail = Cbook_info[i].avail;
            
    }
cout<<"BOOK DELETED";
}
			
			
