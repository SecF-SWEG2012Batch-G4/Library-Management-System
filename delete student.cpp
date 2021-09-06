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
student* Cstud_info =new student [totalStudents];

int main(){
	int num, ID, x, jumper= 0;
	//showbook();
	cout<<"Enter the ID of the student you want to delete : ";
	cin>>ID;
	num= ID - 1001 ;
	x = totalStudents;
	totalStudents--;
	delete[] Cstud_info;
	Cstud_info = new student[totalStudents];

	 for (int i= 0; i <x; i++)
    {
        if (i != num)
        {
            Cstud_info[jumper].f_name = stud_info[i].f_name;
            Cstud_info[jumper].l_name = stud_info[i].l_name;
            Cstud_info[jumper].id = stud_info[i].id;
            Cstud_info[jumper].password = stud_info[i].password;
            Cstud_info[jumper].pn.areacode = stud_info[i].pn.areacode;
            Cstud_info[jumper].pn.num = stud_info[i].pn.num;

            jumper++;
        }
    }
    delete [] stud_info;
    stud_info = new student[totalStudents];
    for (int i= 0; i <totalStudents; i++)
    {

            stud_info[i].f_name = Cstud_info[i].f_name;
            stud_info[i].l_name = Cstud_info[i].l_name;
            stud_info[i].id = Cstud_info[i].id;
            stud_info[i].password = Cstud_info[i].password;
            stud_info[i].pn.areacode = Cstud_info[i].pn.areacode;
            stud_info[i].pn.num = Cstud_info[i].pn.num;



    }
cout<<"STUDENT DELETED";
}
