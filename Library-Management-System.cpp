#include<iostream>
using namespace std;



struct student{
string f_name,l_name, sid, bookId;
} stud[50] = {
            {"tibebe","solomon","1234stud"},
           {"tsion","tesfaye","1234stud"},
           {"natnael","shimelis","1234stud"},
           {"natnael","menelik","1234stud"}};

struct date{
int dd,mm,yy;
};

struct bookinfo{
int id;
string  name, author;
date dop;
int status=0;
string studid;
date return_date,issue_date;
} book[50]={
            {1,"Harry potter","J.K Rowlings",{12,23,2004}},
            {2,"Fundamentals of Fluid Mechanics","Bruce Roy Munson",{30,9,2017}},
            {3,"Introduction To Computing","Steven C Chapra",{02,12,2019}}};

void issuebooks(void){
    int bookid, returnedbookid;
    string sname;
    int counter = 0;
    int choice;
    char option;

Menu:
    cout<< "**************** Issue Menu ****************"<<endl;
    cout<<"**********************************************"<<endl;
    cout<< "1. Issue book "<<endl;
    cout<< "2. View issued books"<<endl;
    cout<< "3. Remove issued book"<<endl;
    cout<< "4. Exit"<<endl;
    cout<<endl;
    cin>>choice;

    switch (choice){

case 1:{
    cout<<"Enter book Id: ";
    cin>>bookid;
for (int i=0; i<50; i++){
    if (bookid == book[i].id){
        cout<<"Name of the book: "<<book[i].name<<endl;
        cout<<"Author of the book: "<<book[i].author<<endl;
        cout<<"ID of the book: "<<book[i].id<<endl;
        cout<<"Date of Publish: "<<book[i].dop.dd<<"/"<<book[i].dop.mm<<"/"<<book[i].dop.yy<<endl;
Menu2:  cout<< "Do you want to borrow this book. Press 'Y' for Yes and 'N' for No "<<endl;
        cin>>option;
        if (option == 'Y'|| option == 'y'){
            book[i].status+=1;

            cout<<"Enter your ID: ";
            cin>> stud[counter].sid;
            stud[counter].bookId= bookid;
            book[counter].studid=stud[counter].sid;
            counter++;
            cout<<"Enter the issue date in (day,month,year) format: ";
            cin>>book[i].issue_date.dd>>book[i].issue_date.mm>>book[i].issue_date.yy;
            cout<<"Enter the return date in(day,month,year) format: ";
            cin>>book[i].return_date.dd>>book[i].return_date.mm>>book[i].return_date.yy;
            cout<<endl;
        }
        else if(option == 'N'|| option == 'n')
            goto Menu;
        else {
            cout<<"Wrong Input! Please try again.."<<endl;
            goto Menu2;
        }
    }
    else if( book[i].id == 0 ){
        cout<<"Sorry but this book ID does not exist"<<endl;
        goto Menu;
        }
}
    break;
    }
case 2: {
        for (int i= 0; i<50; i++){
            if (book[i].status == 1){
                cout<<"ID of borrower \t"<<"Book name \t"<< "Book author \t"<< "Return date"<<endl;
                cout<<book[i].studid<<"\t"<<book[i].name<<"\t"<<book[i].author<<book[i].return_date.dd<<"/"<<book[i].return_date.mm<<"/"<<book[i].return_date.yy<<endl;
            }
        }
        goto Menu;
        break;


}
case 3: {
        cout<<"Enter book ID: ";
        cin>>returnedbookid;
        for (int i= 0; i<50; i++){
            if (returnedbookid == book[i].id){
                book[i].status=0;
}
        }
        cout<<"Book updated"<<endl<<endl;
        goto Menu;
    break;
    }
    }
};

int main() {
    issuebooks();


    return 0;
}
