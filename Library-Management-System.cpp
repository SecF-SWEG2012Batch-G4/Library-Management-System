#include<iostream>
#include<iomanip>//for setw
#include<string.h>
#include <cstdlib>// system("cls")
#include<cstdio>//gets

using namespace std;

int totalBooks = 7;
int totalStudents = 4;
int timetaken;
float payment;

void access(int &option);//navigates to either student or librarian
void librarian(string &f_name,string &l_name);//librarians menu
void student();//students menu
void new_entry();
void addstudent();
void chkavail();//check book availability
void showBooks();
void search();
void welcome();
void showCategory();
void removeBook();
void searchBook();
void report();
void issueReturn();
void showRate();

enum Genre{Fiction=0,Romance,Drama,Educational};
struct student;
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
   int status;
   string location;
   string studid;
   date return_date,issue_date,due_date;

};
 bookinfo* book_info
 { new bookinfo[totalBooks] {
            {"harry potter","Fiction",{12,23,2004},"J.K Rowlings",5,1001,4.8,0, "YC74"},
            {"Fluid Mechanics","Educational",{30,9,2017},"Bruce Roy Munson",2,1002,3.9,0, "gf20"},
            {"Intro to Computing","Educational",{02,12,2019},"Steven C Chapra",6,1003,2.3,0, "gf20"},
            {"Materials science ","Educational",{23,8,2021},"Steven C Chapra",2,1004,5,0, "HN78"},
            {"Perfect Chemistry","Romance",{28,02,2019},"Simone Elkeles",1,1005,4.8,0, "GT25"},
            {"Dune","Romance",{05,17,2017},"Frank Herbert",9,1006,4.1,0, "FR45"},
            {"Hamlet","Drama",{00,00,1601},"William Shakespeare",10,1007,4.6,0, "GH42"}
			}};
bookinfo* Cbook_info = new bookinfo [totalBooks];


struct phone
{
 int areacode;
 int number;
};

struct student
{
    string f_name,l_name,password;
    int sid;
    phone pn;
    string bookId;
}stud_info[50] = {{"tibebe","solomon","1234stud",1001,{251,911454554}},
           {"tsion","tesfaye","1234stud",1002, {251,911454554}},
           {"natnael","shimelis","1234stud",1003,{251,911454554}},
           {"natnael","menelik","1234stud",1004,{251,911454554}}
           };
/*struct student
{
    string f_name,l_name,password;
    int id;
    phone pn;
};
student * stud_info {new student[totalStudents] {{"tibebe","solomon","1234stud",1001,{251,911454554}},
           {"tsion","tesfaye","1234stud",100251,911454554}},
           {"natnael","shimelis","1234stud",1003,{251,911454554}},
           {"natnael","menelik","1234stud",1004,{251,911454554}}              coming soon
           }};
           student* Cstud_info =new student [totalStudents];*/


struct librarian
{
string f_name;
string l_name;
string password;
}
lib[20]={{"tibebe","solomon","1234lib"},
         {"tsion","tesfaye","1234lib"},
         {"natnael","shimelis","1234lib"},
         {"natnael","menelik","1234lib"}},*lib_info=lib;
int totalbooks=7;
int totalstudents=4;

int main()
{
   welcome();


};
void welcome()
{
    int option,*opt;
    opt=&option;

    cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }

 //   cout<<"_______________________________________________________________________________________________________________________\n"<<endl;

    cout<<setw(80)<<"Welcome to the Library Management System\n"<<endl;
// cout<<"_______________________________________________________________________________________________________________________\n"<<endl;

    for (int i=0;i<120;i++){
    cout<<char(2550);
    }
    system("pause");
    cout<<setw(70)<<"Are you a Librarian Press 1\n\n "<<endl;
    cout<<setw(70)<<"Are you a Student   Press 2 \n\n"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
//    cout<<"_______________________________________________________________________________________________________________________\n"<<endl;

    access(*opt);
}


void chkavail()
{
    int counter=0;
    int    *amount_check;
    string *name_check;
    string *author_check;
    char search_key[20];
    system("cls");
    Back:
        char(201);
        for (int i=0;i<119;i++){
    cout<<char(2550);
    }
 //   cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<setw(70)<<"Check if books are available"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
 //   cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<setw(70)<<"Enter book name of the book: ";
    cin>>search_key;

    strlwr(search_key);

    for(int i=0;i<20;i++){
        if (search_key == (book_info+i)->name && (book_info+i)->status == 0 )
        {
        ++counter;
        amount_check= &((book_info+i)->amount);
        name_check = &((book_info+i)->name);
        author_check=&((book_info+i)->author);

        }
        }
    cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
   // cout<<"\t\t ______________________________________________________________________"<<endl;
        cout<<setw(35)<<"Title \t"<<setw(15)<<"|Author\t\t"<<setw(15)<<"|Quantity Available"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
 //   cout<<"\t\t ______________________________________________________________________"<<endl;
        if(counter !=0)
        {
           cout<<setw(35)<<*name_check<<"\t "<<setw(15)<<*(author_check)<<setw(15)<<"\t"<<*(amount_check);
        }
        else
            {
            cout<<setw(45)<<"No results "<<endl;
        goto Back;
            }

}

void access(int &option)
{

    int counter=0;
    string password,f_name,l_name,*avail_check;

    entry:
    cout<<endl<<"Input: ";cin>>option;
system("cls");
    if (option==1)
    {
//////librarians login page
    lib_log:
        cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    cout<<setw(70)<<"Enter your librarian info to login: "<<endl;
  //  cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    cout<<endl<<"User name: ";
    cin>>f_name;
    cin>>l_name;
    cout<<"Password: ";
    cin>>password;

      for(int i=0;i<20;i++)
        {
             if(f_name==(lib_info+i)->f_name && l_name==(lib_info+i)->l_name && password==(lib_info+i)->password)
        {
        counter++;
        avail_check = &((lib_info+i)->f_name);
        }
        }
        if(counter==1)
        {
          return librarian(f_name,l_name);
        }
        else
            {
            cout<<setw(70)<<"No results "<<endl;
        goto lib_log;
            }
   }

//////students login page
else if (option==2)
   {
       stud_log:
           cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    cout<<endl<<setw(70)<<"Enter your student info to login: "<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
  //  cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    cout<<"User name: ";
    cin>>f_name;
    cin>>l_name;

    cout<<"Password: ";
    cin>>password;

    for(int i=0;i<20;i++)
    {
    if(f_name==(stud_info+i)->f_name && l_name==(stud_info+i)->l_name && password==(stud_info+i)->password)
    {
       avail_check = &((stud_info+i)->f_name);
       counter++;
    }
    }
    if (counter!=0)
    {

    }
    else
    {
       cout<<setw(70)<<"Invalid input,Please Try Again"<<endl;
       goto stud_log;
    }
}
}

void addstudent()
{
    int n;
    cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    cout<<setw(70)<<"How many new users do you want to register.";
    cin>>n;
        n+=totalstudents;


    for (int i=totalstudents;i<n;i++)
    {
        for (int i=0;i<119;i++){
    cout<<char(2550);
    }
        cout<<setw(50)<<"Info for new student of ID:0"<<i+1<<endl;
        for (int i=0;i<119;i++){
    cout<<char(2550);
    }
        cout<<setw(0)<<"\nEnter the Full name of the student: ";     cin>>(stud_info+i)->f_name>>(stud_info+i)->l_name;
        cout<<setw(40)<<"\nEnter the Area code for the student: ";    cin>>(stud_info+i)->pn.areacode;
        cout<<setw(40)<<"\nEnter the Phone Number for the student: "; cin>>(stud_info+i)->pn.number;
        cout<<setw(40)<<"\nEnter a password for this account: ";       cin>>(stud_info+i)->password;
    }

    system("cls");

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }


    cout<<setw(70)<<"INFORMATION FOR ALL STUDENTS"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
     for (int i=0;i<n;i++)
    {
        for (int i=0;i<119;i++){
    cout<<char(2550);
    }
        cout<<setw(70)<<"Info for student: "<<i+1<<endl;
        for (int i=0;i<119;i++){
    cout<<char(2550);
    }
        cout<<setw(70)<<"\nFull name : ";                            cout<<(stud_info+i)->f_name<<" "<<(stud_info+i)->l_name<<endl;
        cout<<setw(70)<<"\nArea code for the student: ";             cout<<(stud_info+i)->pn.areacode<<endl;;
        cout<<setw(70)<<"\nPhone Number : ";                         cout<<(stud_info+i)->pn.number<<endl;;
        cout<<setw(70)<<"\nPassword for this account: ";             cout<<(stud_info+i)->password<<endl;;
        cout<<setw(70)<<"\nThe designated ID for this account is: "; cout<<(stud_info+i)->sid+i<<endl;;
}

}

void librarian(string &f_name,string &l_name)
{

       int option;
       system("cls");
       Back:
           cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    mainlibmenu:
      //     cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<setw(45)<<"Welcome "<<f_name<<" "<<l_name<<"...\n\n";

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
      //     cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<setw(60)<<"What would you like to do.\n\n";
    cout<<setw(60)<<"1.Add new user/Student.\n"<<endl;//.Add new user
    cout<<setw(60)<<"2.Add books to the shelves.\n"<<endl;//Add new books
    cout<<setw(60)<<"3.Check book availability.\n"<<endl;//Check availability
    cout<<setw(60)<<"4.Show all books.\n"<<endl;
    cout<<setw(60)<<"5.Show books by category\n"<<endl;
    cout<<setw(60)<<"6.Remove book\n"<<endl;
   /* cout<<setw(60)<<"7.Search Student\n"<<endl;
    cout<<setw(60)<<"8.Delete a Student\n"<<endl;         coming soon
    cout<<setw(60)<<"9.View all students\n"<<endl;*/
    //cout<<setw(60)<<"7.Give Satistical Report\n"<<endl;
    cout<<setw(60)<<"7. Exit"<<endl;
    //cout<<setw(60)<<"9.Delete a Student\n"<<endl; coming soon
    cin>>option;
    switch (option){

    case 1:{
    	addstudent();
		break;
    }
    case 2:
    {
        new_entry();
        break;
        system ("pause");
        goto mainlibmenu;
    }
    case 3:
    {
        chkavail();
        break;
        system ("pause");
         goto mainlibmenu;
    }
    case 4: {
    	showBooks();
    	break;
    	system ("pause");
    	 goto mainlibmenu;
    }
    case 5: {
    	showCategory();
    	system ("pause");
    	 goto mainlibmenu;
    	break;
    }
    case 6: {
    	removeBook();
    	system ("pause");
    	 goto mainlibmenu;
    	break;
    }
    /*case 7: {
    report();
    	break;
    }*/
    case 7: {
    	exit(0);
    	break;
    }


}
}

void student(string &f_name,  string &l_name )
{

  entrance:
      cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
    mainstumenu:
   //   cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<setw(45)<<"Welcome  "<<f_name<<" "<<l_name<<"..."<<"\n\n";

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
   // cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<setw(70)<<"What would you like to do\n\n";
    cout<<setw(65)<<"1.Search for a book.\n\n";
    cout<<setw(60)<<"2.Check book availability.\n\n";
    cout<<setw(60)<<"3.Check out/Return a book.\n\n";//Borrow a book

    cout<<setw(60)<<"4. Show all books. \n\n";
    cout<<setw(60)<<"5.Classify books by category.\n\n";//Classification books by category    (already a void search)
    cout<<setw(60)<<"6.Classify books by rating/high reader.\n\n";//rating & ranking

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
  //  cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;

int option;
cin>>option;
switch (option){

case 1:
{
 searchBook();
 system ("pause");
    	 goto mainstumenu;
 break;
}
case 2:
{
    chkavail();
    system ("pause");
    	 goto mainstumenu;
    break;
}
case 3: {
	issueReturn();
	system ("pause");
    	 goto mainstumenu;
	break;
}
case 4: {
	showBooks();
	system ("pause");
    	 goto mainstumenu;
	break;
}
case 5: {
	showCategory();
	system ("pause");
    	 goto mainstumenu;
	break;
}
case 6: {
	showRate();
	system ("pause");
    	 goto mainstumenu;
	break;
		}
	}
}
void search()
{
    int searchOption, bookId;
searchMenu:
system("cls");
cout<<"How would you like to search the book?"<<endl;
cout<<"\n 1. Using Book ID \n2. Using Book title \n3. Using Author name \n"<<endl;
cout<<"\nEnter your choice: ";
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
        cout<<"Date of Publication: "<<(book_info+i)->dop.dd<<"/"<<(book_info+i)->dop.mm<<"/"<<(book_info+i)->dop.mm<<endl;
      cout<<"Shelf: "<<(book_info+i)->location<<endl;
        bookFound = true;


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
        cout<<"Shelf: "<<(book_info+i)->location<<endl;
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
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book Author"<<setw(20)<<"Rating"<<setw(15)<<"Shelf"<<setw(20)<<"\n";
    cout<<"=====================================================================================================\n";
    cout<<(book_info+i)->id<<setw(25)<<(book_info+i)->name<<setw(30)<<(book_info+i)->author<<setw(10)<<(book_info+i)->rating<<setw(15)<<(book_info+i)->location<<setw(20)<<endl;
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
};

void new_entry()
{
    int amount;
    system("cls");
    cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }

    cout<<setw(70)<<"Adding book registry"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
  //  cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<setw(70)<<"How many books do you want to register: ";

    cin>>amount;
    cout<<"Register a new book: "<<endl;
    for(int i=7;i<amount+7;i++)
    {
        cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
   cout<<" Book "<<i-6<<endl;
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
   cout<<"Name: ";                cin>>(book_info+i)->name;
   cout<<"Genre: ";               cin>>(book_info+i)->category;
   cout<<"Date of publication: "; cin>>(book_info+i)->dop.dd>>(book_info+i)->dop.mm>>(book_info+i)->dop.yy;
   cout<<"Amount available: ";    cin>>(book_info+i)->amount;
   cout<<"Id no: ";               cin>>(book_info+i)->id;
   cout<<"Shelf location: ";      cin>>(book_info+i)->location;
    }

system("cls");
    cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }

//cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
cout<<setw(60)<<"Repository: "<<endl;
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
cout<<"Name: "<<"\t"; cout<<"Genre: "<<"\t"; cout<<"Date of publication: "<<"\t";  cout<<"Amount available: "<<"\t";   cout<<"Id no: "<<"\t";  cout<<"Shelf location: ";  cout<<endl;
     for(int i=0;i<amount+7;i++)
     {

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
 //   cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;
    cout<<(book_info+i)->name<<" "<<"\t";
    cout<<char(250)*15;
    cout<<(book_info+i)->category<<" "<<"\t";
    cout<<(book_info+i)->dop.dd<<(book_info+i)->dop.mm<<(book_info+i)->dop.yy<<" "<<"\t";
    cout<<(book_info+i)->amount<<" "<<"\t";
    cout<<(book_info+i)->id<<" "<<endl;
    cout<<(book_info+i)->location<<" "<<endl;;
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }
   //     cout<<setw(45)<<"\t\t ______________________________________________________________________"<<endl;

     }
}
void showBooks(){
	cout<<"=====================================================================================================\n";
    cout<<"No"<<setw(15)<<"Book ID"<<setw(30)<<"Book Name"<<setw(30)<<"Book category"<<setw(20)<<"Rating"<<setw(15)<<"shelf"<<"\n";

    for(int i =0; i<totalBooks; i++){


    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<i+1<<")"<<setw(15)<<(book_info+i)->id<<setw(35)<<(book_info+i)->name<<setw(25)<<(book_info+i)->category<<setw(18)<<(book_info+i)->rating<<setw(15)<<(book_info+i)->location<<endl;
}
}
void showCategory(){
		   categoryOption:
       string cat;
       cout<<"Please enter the category you'd like to view: ";
//cin.ignore();
   getline(cin, cat);
   bool showCat= false;
   for(int i =0; i<totalBooks; i++){

    if(cat==(book_info+i)->category){
     cout<<"=====================================================================================================\n";
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book Author"<<setw(20)<<"Rating"<<setw(15)<<"Shelf"<<setw(20)<<"\n";
    cout<<"=====================================================================================================\n";
    cout<<(book_info+i)->id<<setw(25)<<(book_info+i)->name<<setw(30)<<(book_info+i)->author<<setw(10)<<(book_info+i)->rating<<setw(15)<<(book_info+i)->location<<setw(20)<<endl;
     showCat= true;}
    //else{cout<<"Sorry, we don't have books with that genre "<<endl;
   // goto categoryOption;}
    }
    if (showCat== false)
	{cout<<"Sorry, we don't have books with that genre "<<endl;}
}
void removeBook(){

	int num,ID, x, jumper= 0;

	cout<<"Enter the ID of the book you want to delete: ";
	cin>>ID;
	num= ID - 1001 ;
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
            Cbook_info[jumper].status = book_info[i].status;
            Cbook_info[jumper].location = book_info[i].location;
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
            book_info[i].status = Cbook_info[i].status;
            book_info[i].location= Cbook_info[i].location;

    }
cout<<"BOOK DELETED";
}
void searchBook(){
	int searchOption, bookId;
searchMenu:
system("cls");
cout<<"How would you like to search the book?"<<endl;
cout<<"\n 1. Using Book ID \n2. Using Book title \n3. Using Author name \n"<<endl;
cout<<"\nEnter your choice: ";
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
        cout<<"Date of Publication: "<<(book_info+i)->dop.dd<<"/"<<(book_info+i)->dop.mm<<"/"<<(book_info+i)->dop.mm<<endl;
      cout<<"Shelf: "<<(book_info+i)->location<<endl;
        bookFound = true;


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
        cout<<"Shelf: "<<(book_info+i)->location<<endl;
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
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book Author"<<setw(20)<<"Rating"<<setw(15)<<"Shelf"<<setw(20)<<"\n";
    cout<<"=====================================================================================================\n";
    cout<<(book_info+i)->id<<setw(25)<<(book_info+i)->name<<setw(30)<<(book_info+i)->author<<setw(10)<<(book_info+i)->rating<<setw(15)<<(book_info+i)->location<<setw(20)<<endl;
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
void issueReturn(){
	   int bookid, returnedbookid;
    string sname;
    int counter = 0;
    int choice;
    char option;

Menu:
	system ("cls");
    cout<< "**************** Issue Menu ****************"<<endl;
    cout<<"**********************************************"<<endl;
    cout<< "1. List of available books "<<endl;
    cout<< "2. Issue book "<<endl;
    cout<< "3. View issued books"<<endl;
    cout<< "4. Remove issued book"<<endl;
    cout<< "5. Exit"<<endl;
    cout<<endl;
    cin>>choice;

    switch (choice){

case 1:{
	system ("cls");
	cout<<setw(10)<<"Book ID"<<setw(35)<<"Book Name"<<setw(35)<<"Book category"<<setw(25)<<"Rating\n";
	cout<<"=====================================================================================================\n";
for (int i= 0; i<totalBooks; i++){
        if (book_info[i].status == 0)
            {
               cout<<setw(10)<<(book_info+i)->id<<setw(40) <<(book_info+i)->name<<setw(30)<< (book_info+i)->category<<setw(20)<< (book_info+i)->rating<<endl;
            }

        }
        system ("pause");
        goto Menu;
        break;
    }
case 2:{
	system ("cls");
    cout<<"Enter book Id: ";
    cin>>bookid;
for (int i=0; i<totalBooks; i++){
    if (bookid == book_info[i].id){
        cout<<"Name of the book: "<<book_info[i].name<<endl;
        cout<<"Author of the book: "<<book_info[i].author<<endl;
        cout<<"ID of the book: "<<book_info[i].id<<endl;
        cout<<"Date of Publish: "<<book_info[i].dop.dd<<"/"<<book_info[i].dop.mm<<"/"<<book_info[i].dop.yy<<endl<<endl;
Menu2:  cout<< " \t Do you want to borrow this book. Press 'Y' for Yes and 'N' for No "<<endl;
        cin>>option;
        if (option == 'Y'|| option == 'y'){
          book_info[i].status=1;
			//book_info[i].avail= false;
            cout<<"Enter your ID: ";
            cin>> stud_info[counter].sid;
            stud_info[counter].bookId= bookid;
            book_info[counter].studid=stud_info[counter].sid;
            counter++;
            cout<<"Enter the issue date in (day,month,year) format: ";
            cin>>book_info[i].issue_date.dd>>book_info[i].issue_date.mm>>book_info[i].issue_date.yy;
            cout<<"The due date is: ";
            book_info[i].due_date.dd= (book_info[i].issue_date.dd + 5 );
            cout<<book_info[i].due_date.dd<<"/"<<book_info[i].issue_date.mm<<"/"<<book_info[i].issue_date.yy;
            cout<<endl;
            cout<< " \t Book Issued Sucessfully! "<<endl<<endl;
            system ("pause");
            goto Menu;
        }
       else if(option == 'N'|| option == 'n')

            goto Menu;
        else {
            cout<<"Wrong Input! Please try again.."<<endl;
            goto Menu2;
        }
    }
    else  {
        cout<<"Sorry but this book ID does not exist"<<endl;
        system ("pause");
        goto Menu;
        }
}

    break;
    }

case 3: {
	system ("cls");

		 cout<<setw(10)<<"ID of borrower"<<setw(35)<<"Book name"<<setw(35)<< "Book author"<<setw(25)<< "Due date"<<endl;
		 	cout<<"=====================================================================================================\n";
        for (int i= 0; i<totalBooks; i++){
        	if (book_info[i].status == 1)
            {
                cout<<setw(10)<< stud_info[i].sid <<setw(40)<< book_info[i].name<<setw(30)<< book_info[i].author<<setw(20)<<book_info[i].due_date.dd<<"/"<<book_info[i].issue_date.mm<<"/"<<book_info[i].issue_date.yy<<endl<<endl;
            }

        }


        system ("pause");
        goto Menu;
        break;


}
case 4: {
	for (int i=0; i<totalBooks; i++){
        cout<<"Enter book ID: ";
        cin>>returnedbookid;
        cout<<"Enter return date in (day/month/year) format: ";
        cin>>book_info[i].return_date.dd>>book_info[i].return_date.mm>>book_info[i].return_date.yy;
        //overdue payment checker
        //Normal duration time limit for borrowed book= 5 days.

        if (book_info[i].issue_date.mm == book_info[i].return_date.mm)
		{
            timetaken = (book_info[i].return_date.dd - book_info[i].issue_date.dd );
overdue_calc:
            if (timetaken<=5){
                payment=0;
            }
            else if (timetaken>5 && timetaken<=10){ //5 birr per day
                payment= ((timetaken - 5) * 5);
            }
            else if (timetaken > 10 && timetaken<= 30){//10 birr per day
                payment = (5 * 5 + (timetaken - 10) * 15);
            }


            cout<< "Your overdue payment is: "<<payment<< " Birr."<<endl;

        }
        else if (book_info[i].issue_date.mm  < book_info[i].return_date.mm){
                if (book_info[i].return_date.mm == 3)
                {
                     timetaken= (book_info[i].return_date.dd  + ( 28 - book_info[i].issue_date.dd ));
    Notify:         if ( timetaken > 30){
                	cout<< "You took more than 30 days to return this book."<<endl;
                	cout<<"Your Membership to this library is canceled and your due payment is 300 birr!"<<endl;
				}
                }
                else if (book_info[i].return_date.mm == 2 && book_info[i].return_date.mm == 4 && book_info[i].return_date.mm== 6 && book_info[i].return_date.mm== 8 &&
                        book_info[i].return_date.mm== 9 && book_info[i].return_date.mm==11 )
                {
                    timetaken= (book_info[i].return_date.dd  + ( 31 - book_info[i].issue_date.dd ));
                    goto Notify;
                }
                else
                {
                    timetaken= (book_info[i].return_date.dd + ( 30 - book_info[i].issue_date.dd ));
                    goto Notify;
                }


        }

        for (int i= 0; i<totalBooks; i++)
		{
            if (returnedbookid == book_info[i].id){
               book_info[i].status=0;
			}
		}
			cout<<" \t Book updated! "<<endl<<endl;
			system("pause");
        	goto Menu;
    break;
    }
    }
}
}
void showRate(){
	int rateSearch;
rateSection:
	system ("cls");
cout<<"welcome to the rating section"<<endl;
cout<<"How would you like to view the rating?"<<endl;
cout<<"1. Rating of a specific book \n2. Rating by category \n3. High rated books \n4. Back to main menu"<<endl;
cout<<"\nEnter your choice: ";
cin>>rateSearch;
bool rateBook = false;
if (rateSearch==1){
    int searchId;
   enterID:
   system ("cls");
   cout<<"Please enter the ID of the book: ";
    cin>>searchId;
    for (int i=0; i<totalBooks; i++){
    if(searchId ==(book_info+i)->id){
        cout<<"The rating of the book is "<<(book_info+i)->rating<<endl;
		rateBook= true;}}
    if (rateBook == false)
	{cout<<"There is no book with the given ID";
    goto enterID; }

}
else if (rateSearch==2){
    string category;
  enterCategory:
  	system ("cls");
    cout<<"Please enter the category you'd like to check"<<endl;
      cin>>category;
      bool rateCat = false;
    for (int i=0; i<totalBooks; i++){

    if(category== (book_info+i)->category){

   cout<<"=====================================================================================================\n";
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book Author"<<setw(20)<<"Rating"<<setw(15)<<"Shelf"<<setw(20)<<"\n";
    cout<<"=====================================================================================================\n";
    cout<<(book_info+i)->id<<setw(25)<<(book_info+i)->name<<setw(30)<<(book_info+i)->author<<setw(10)<<(book_info+i)->rating<<setw(15)<<(book_info+i)->location<<setw(20)<<endl;
	}}
    if(rateCat== false)
	{cout<<"The category you entered doesn't exist";
    goto enterCategory;}


    }

else if (rateSearch==3){
	bool highRate= false;
   for (int i=0; i<totalBooks; i++){
    if((book_info+i)->rating>4.5){
      cout<<"=====================================================================================================\n";
    cout<<"Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book Author"<<setw(20)<<"Rating"<<setw(15)<<"Shelf"<<setw(20)<<"\n";
    cout<<"=====================================================================================================\n";
    cout<<(book_info+i)->id<<setw(25)<<(book_info+i)->name<<setw(30)<<(book_info+i)->author<<setw(10)<<(book_info+i)->rating<<setw(15)<<(book_info+i)->location<<setw(20)<<endl;
	 highRate= true;}}
	if (highRate == false)
	{cout<<"Sorry there are no books with rating more than 4.5 "<<endl;}

}

else {cout<<"Please enter a valid choice"<<endl;
goto rateSection; }
}


