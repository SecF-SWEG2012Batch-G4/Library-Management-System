#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int timetaken;
float payment;
int totalBooks= 7;

struct student{
string f_name,l_name, sid, bookId;
};
student* stud  { new student[50] {
            {"tibebe","solomon","0634"},
           {"tsion","tesfaye","0645"},
           {"natnael","shimelis","0524"},
           {"natnael","menelik","0535"}}};

struct date{
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
   //bool avail;//books availability
   string studid;
   date return_date,issue_date,due_date;
};
 bookinfo* book_info { new bookinfo[totalBooks] {
            {"harry potter","Fiction",{12,23,2004},"J.K Rowlings",5,10,4.8, 0},
            {"Fundamentals of Fluid Mechanics","Educational",{30,9,2017},"Bruce Roy Munson",3.9,12, 4.5, 0},
            {"Introduction To Computing","Educational",{02,12,2019},"Steven C Chapra",6,2.3, 0},
            {"Materials science ","Educational",{23,8,2021},"Steven C Chapra",2,6,5,0},
            {"Perfect Chemistry","Romance",{28,02,2019},"Simone Elkeles",1,38631,4.8,0},
            {"Dune","Romance",{05,17,2017},"Frank Herbert",9,125896,5,0},
            {"Hamlet","Drama",{00,00,1601},"William Shakespeare",10,4582,4.6,0}
			}};
		//book* book_info = new book; //array of structures


void issuebooks(void){
    int bookid, returnedbookid;
    string sname;
    int counter = 0;
    int choice;
    char option;

Menu:
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
	cout<<setw(10)<<"Book ID"<<setw(35)<<"Book Name"<<setw(35)<<"Book category"<<setw(25)<<"Rating\n";
	cout<<"=====================================================================================================\n";
for (int i= 0; i<totalBooks; i++){
        if (book_info[i].status == 0)
            {
               cout<<setw(10)<<(book_info+i)->id<<setw(40) <<(book_info+i)->name<<setw(30)<< (book_info+i)->category<<setw(20)<< (book_info+i)->rating<<endl;
            }

        }
        goto Menu;
        break;
    }
case 2:{
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
            cin>> stud[counter].sid;
            stud[counter].bookId= bookid;
            book_info[counter].studid=stud[counter].sid;
            counter++;
            cout<<"Enter the issue date in (day,month,year) format: ";
            cin>>book_info[i].issue_date.dd>>book_info[i].issue_date.mm>>book_info[i].issue_date.yy;
            cout<<"The due date is: ";
            book_info[i].due_date.dd= (book_info[i].issue_date.dd + 5 );
            cout<<book_info[i].due_date.dd<<"/"<<book_info[i].issue_date.mm<<"/"<<book_info[i].issue_date.yy;
            cout<<endl;
            cout<< " \t Book Issued Sucessfully! "<<endl<<endl;
            goto Menu;
        }
       else if(option == 'N'|| option == 'n')
            goto Menu;
        else {
            cout<<"Wrong Input! Please try again.."<<endl;
            goto Menu2;
        }
    }
    else if (book_info[i].id == 0 ) {
        cout<<"Sorry but this book ID does not exist"<<endl;
        goto Menu;
        }
}

    break;
    }

case 3: {
		 cout<<setw(10)<<"ID of borrower"<<setw(35)<<"Book name"<<setw(35)<< "Book author"<<setw(25)<< "Due date"<<endl;
		 	cout<<"=====================================================================================================\n";
        for (int i= 0; i<totalBooks; i++){
        	if (book_info[i].status == 1)
            {
                cout<<setw(10)<< stud[i].sid <<setw(40)<< book_info[i].name<<setw(30)<< book_info[i].author<<setw(20)<<book_info[i].due_date.dd<<"/"<<book_info[i].issue_date.mm<<"/"<<book_info[i].issue_date.yy<<endl<<endl;
            }

        }
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
            else if (timetaken > 10 && timetaken<= 30){//15 birr per day
                payment = (5 * 5 + (timetaken - 10) * 15 );
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
        	goto Menu;
    break;
    }
    }
}
};

int main() {


    issuebooks();


    return 0;
}

