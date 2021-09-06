#include<iostream>
#include<iomanip>
using namespace std;
int totalStudents= 5;
enum Genre{Fiction=0,Romance,Drama,Educational};
struct phone
{
 int areacode;
 int num;
};
struct student
{
    string f_name,l_name,password;
    int id;
    phone pn;
};
student * stud_info {new student[totalStudents] {{"tibebe","solomon","1234stud",1001,{251,911454554}},
           {"tsion","tesfaye","1234stud",1002,{251,911454554}},
           {"natnael","shimelis","1234stud",1003,{251,911454554}},
           {"natnael","menelik","1234stud",1004,{251,911454554}}
           }};
        int main(){

       	for(int i =0; i<totalStudents; i++){

    cout<<"=====================================================================================================\n";
    cout<<"No"<<setw(15)<<"Student ID"<<setw(30)<<"First Name"<<setw(30)<<"Last name"<<setw(20)<<"Phone number"<<setw(15)<<"\n";
    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<i+1<<")"<<setw(15)<<(stud_info+i)->id<<setw(30)<<(stud_info+i)->f_name<<setw(27)<<(stud_info+i)->l_name<<setw(18)<<"+"<<(stud_info+i)->pn.areacode<<(stud_info+i)->pn.num<<endl;
}
return 0;
        }
