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
// searching for book
int main(){

int searchOption, bookId;
searchMenu:
system("cls");
cout<<"How would you like to search the book?"<<endl;
cout<<"\n 1. Using Book ID \n\n 2. Using Book title \n\n 3. Using Author name"<<endl;
cin>>searchOption;
switch (searchOption){
    case 1:{


    system ("cls");
    cout<<"Enter book ID: ";
   bool bookFound = false;
    cin>>bookId;
    for(int i=0; i<totalBooks; i++){
      if(bookId== (book_info+i)->id ){
        cout<<"Book ID: "<<(book_info+i)->id<<endl;
        cout<<"Book Genere: "<<(book_info+i)->category<<endl;
        cout<<"Book Name: "<<(book_info+i)->name<<endl;
        cout<<"Book Author: "<<(book_info+i)->author<<endl;
        bookFound = true;
       // cout<<"Date of Publication: "<<book.date.day<<"/"<<book.date.month<<"/"<<book.date.year<<endl;

      }}
      if (bookFound == false){
	   cout<<"There is no book with the given ID"<<endl;
	   system ("pause");
	  goto searchMenu;}
	  break;
  }

    case 2:{
    	system("cls");
    bool titleFound = false;
    cout<<"Enter book title: ";
    string bookTitle;
    cin.ignore();
    getline(cin, bookTitle);
    for (int i=0; i<totalBooks; i++){
        if(bookTitle==(book_info+i)->name ){
        cout<<"Book ID: "<<(book_info+i)->id<<endl;
        cout<<"Book Genere: "<<(book_info+i)->category<<endl;
        cout<<"Book Name: "<<(book_info+i)->category<<endl;
        cout<<"Book Author: "<<(book_info+i)->author<<endl;
        cout<<"Date of Publication: "<<(book_info+i)->dop.dd<<"/"<<(book_info+i)->dop.mm<<"/"<<(book_info+i)->dop.mm<<endl;
        titleFound = true;
        }}
         if (titleFound== false)
		 {cout<<"There is no book with the given name"<<endl;
		 system ("pause");
		 goto searchMenu;}
    break;
}
    case 3:{
    	system("cls");
    bool authorFound = false;
    cout<<"Enter Author of the Book: ";
    string bookAuthor;
    cin.ignore();
    getline (cin, bookAuthor);
    for (int i=0; i<totalBooks; i++){
        if(bookAuthor== (book_info+i)->author){
   cout<<"=====================================================================================================\n";
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book category"<<setw(20)<<"Rating\n";
    cout<<"=====================================================================================================\n";
    cout<< (book_info+i)->id<<setw(21)<< (book_info+i)->name<<setw(40)<< (book_info+i)->category<<setw(20)<< (book_info+i)->rating<<endl;
       authorFound= false;
	    }}
        if (authorFound== false)
		 {cout<<"There is no book with the given Author"<<endl;
		 system ("pause");
		goto searchMenu;}
		break;
    }
system("cls");
    default: { cout<<"Please enter your choice correctly"<<endl;}
    system("pause");
    system("cls");
    goto searchMenu;
}
}

