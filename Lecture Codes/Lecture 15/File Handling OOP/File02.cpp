#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

class Student{
	char fName[10], sName[10], rNo[11];//Roll no has 10 characters + 1 null character
	float cgpa;
public:
	Student(){}
	Student(const char fn[], const char sn[], const char r[], float cgpa){
		set(fName, sName, rNo, cgpa);
	}
	void set(const char fn[], const char sn[], const char r[], float cgpa){
		strcpy(fName, fn);
		strcpy(sName, sn);
		strcpy(rNo, r);
		this->cgpa = cgpa;
	} 
	friend ostream& operator << (ostream &, const Student &);
};
ostream& operator << (ostream &out, const Student &st){
	out << st.rNo << ' ' << left << setw(10) << st.fName << ' ' << setw(10) << st.sName << ' ' << setw(4) << fixed
		<< setprecision(2) << st.cgpa << '\n';
	return out;
}
int main(){
	#define COUNT 5
    Student s[COUNT];
	char fName[COUNT][10]={"Qasim", "Aslam","Muhammad", "Shahzad","Adnan"};
	char sName[COUNT][10]={"Munir", "Raza", "Khawar", "Amin","Rasool"};
	char rNo[COUNT][11]={"BCSF01M001","BCSF01M002","BCSF01M004","BCSF01M007","BCSF01M009"};
	float cgpa[COUNT]={3.15,3.2,2.86,3.34,3.78};
	int i;
	for (i=0;i<COUNT;i++)
		s[i].set(fName[i], sName[i], rNo[i], cgpa[i]);
	ofstream out("students.bin", ios::binary);
	out.write ( (char*) s, sizeof(Student) * COUNT );
	out.close();

	ifstream in("students.bin", ios::binary);
	in.seekg(0, ios::end);	//Move file pointer to the end of file
	int count = in.tellg() / sizeof(Student);	//tell returns the current file position
	in.seekg(0);			//Move file pointer to the start of file
	Student *newS = new Student [count];	
	in.read ( (char*) newS, sizeof(Student) * count );
	for (i=0;i<count;i++)
		cout << newS[i];
	in.close();
	delete []newS;
    return 0;
}

