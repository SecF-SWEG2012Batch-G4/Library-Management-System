
void chkavail()
{
    int     counter=0;
    int    *amount_check;
    string *name_check;
    string *author_check;
    char search_key[20];
    system("cls");
    Back:
        cout<<endl;
        char(201);
        for (int i=0;i<119;i++){
    cout<<char(2550);
    }

    cout<<setw(70)<<"Check if books are available"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }

    cout<<setw(70)<<"Enter book name of the book: ";
    cin>>search_key;

    strlwr(search_key);

    for(int i=0;i<20;i++){
        if (search_key == (book_info+i)->name )
        {
        ++counter;
        amount_check= &((book_info+i)->amount);
        name_check = &((book_info+i)->name);
        author_check=&((book_info+i)->author);
        }
        }
        system ("cls");
    cout<<char(201);
    for (int i=0;i<119;i++){
    cout<<char(2550);
    }

        cout<<setw(35)<<"Title \t"<<setw(15)<<"Author\t\t"<<setw(15)<<"Quantity Available"<<endl;

    for (int i=0;i<119;i++){
    cout<<char(2550);
    }

        if(counter!=0)
        {
           cout<<setw(35)<<*name_check<<"\t "<<setw(15)<<*(author_check)<<setw(15)<<"\t"<<*(amount_check);
           goto Back;
        }
        else
            {
            cout<<setw(45)<<"No results "<<endl;
        goto Back;
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
        cout<<setw(50)<<"Info for student "<<i+1<<endl;
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
        cout<<setw(70)<<"\nThe designated ID for this account is: "; cout<<(stud_info+i)->ID+i<<endl;;
}

}

