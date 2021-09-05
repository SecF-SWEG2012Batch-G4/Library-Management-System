#include<iostream>
using namespace std;



struct student{
string sname, sid, bookId;
};

struct Date{
int dd,mm,yy;
};

struct book{
string bId, bName, bAuthor;
Date publishDate;
int status=0;
string studid;
};

void issuebooks(void){
 string bookid, returnedbookid;
    string sname;
    student s1[50];
    book b1[50];
    int counter = 0;
   // b1[0]={}
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
    if (bookid == b1[i].bId){
        cout<<"Name of the book: "<<b1[i].bName<<endl;
        cout<<"Author of the book: "<<b1[i].bAuthor<<endl;
        cout<<"ID of the book: "<<b1[i].bId<<endl;
        cout<<"Date of Publish: "<<b1[i].publishDate.dd<<"/"<<b1[i].publishDate.mm<<"/"<<b1[i].publishDate.yy<<endl;
Menu2:  cout<< "Do you want to borrow this book. Press 'Y' for Yes and 'N' for No ";
        cin>>option;
        if (option == 'Y'|| option == 'y'){
            b1[i].status+=1;

            cout<<"Enter your name: ";
            cin>>s1[counter].sname;
            cout<<"Enter your ID: ";
            cin>> s1[counter].sid;
            s1[counter].bookId= bookid;
            b1[counter].studid=s1[counter].sid;
            counter++;
            cout<<"When is the return date in(day,month,year): ";
            cin>>b1[i].publishDate.dd>>b1[i].publishDate.mm>>b1[i].publishDate.yy;
        }
        else if(option == 'N'|| option == 'n')
            goto Menu;
        else {
            cout<<"Wrong Input! Please try again.."<<endl;
            goto Menu2;
        }
    }
    else
        cout<<"Sorry but this book ID does not exist"<<endl;
        goto Menu;
}
    break;
    }
case 2: {
        for (int i= 0; i<50; i++){
            if (b1[i].status == 1){
                cout<<"ID of borrower \t"<<"Book name \t"<< "Book author \t"<< "Return date"<<endl;
                cout<<b1[i].studid<<"\t"<<b1[i].bName<<"\t"<<b1[i].bAuthor<<b1[i].publishDate.dd<<"/"<<b1[i].publishDate.mm<<"/"<<b1[i].publishDate.yy;
            }
        }
        break;


}
case 3: {
        cout<<"Enter book ID: ";
        cin>>returnedbookid;
        for (int i= 0; i<50; i++){
            if (returnedbookid == b1[i].bId){
                b1[i].status=0;
}
        }

        cout<<"Book updated";

    }
    }
};

int main() {
    issuebooks();


    return 0;
}
