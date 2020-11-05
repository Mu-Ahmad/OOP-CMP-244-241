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
	#define QUIT 5
    Student s[COUNT];
	char fName[COUNT][10]={"Qasim", "Aslam","Muhammad", "Shahzad","Adnan"};
	char sName[COUNT][10]={"Munir", "Raza", "Khawar", "Amin","Rasool"};
	char rNo[COUNT][11]={"BCSF01M001","BCSF01M002","BCSF01M004","BCSF01M007","BCSF01M009"};
	float cgpas[COUNT]={3.15,3.2,2.86,3.34,3.78};
	int i, choice, count, n;
	char fn[10], sn[10], r[11];
	float cgpa;
	Student student, *newS;
	for (i=0;i<COUNT;i++)
		s[i].set(fName[i], sName[i], rNo[i], cgpas[i]);
	fstream file("students.bin", ios::binary | ios::in | ios::out);
	if (file.fail()){//means file open operation failed, because file does not exist or created
		ofstream out("students.bin");//Create new file
		out.close();					//close file
		file.open("students.bin", ios::binary | ios::in | ios::out);	//Re open file in fstream
	}
	file.write ( (char*) s, sizeof(Student) * COUNT );

	do{
		cout << "\t\t1.	Show all records\n";
		cout << "\t\t2.	Add new record\n";
		cout << "\t\t3.	Show nth record\n";
		cout << "\t\t4.	Modify nth record\n";
		cout << "\t\t5.	Quit\n";	
		cin >> choice;
		switch (choice){
			case 1:
				file.seekg(0, ios::end);
				count = file.tellg() / sizeof(Student);
				file.seekg(0);
				newS = new Student [count];	
				file.read ( (char*) newS, sizeof(Student) * count );
				for (i=0;i<count;i++)
					cout << newS[i];
				delete []newS;
				break;
			case 2:
				cout << "Enter name of the student:";
				cin >> fn >> sn;
				cout << "Enter roll no of the student:";		
				cin >> r;
				cout << "Enter CGPA of the student:";
				cin >> cgpa;
				student.set (fn, sn, r, cgpa);
				file.write ( (char*) &student, sizeof(Student) );
				break;
			case 3:
				cout << "Enter Record No:";
				cin >> n;
				n--;
				file.seekg(sizeof (Student) * n);
				file.read ( (char*) &student, sizeof(Student) );
				cout << student;
				break;
			case 4:
				cout << "Enter Record No:";
				cin >> n;
				n--;
				file.seekp(sizeof (Student) * n);
				cout << "Enter name of the student:";
				cin >> fn >> sn;
				cout << "Enter roll no of the student:";		
				cin >> r;
				cout << "Enter CGPA of the student:";
				cin >> cgpa;
				student.set (fn, sn, r, cgpa);
				file.write ( (char*) &student, sizeof(Student) );
				break;
		}
	}while (choice!=QUIT);
	file.close();
	cout << "\n\n\t\tThanks for using this program\n";
    return 0;
}

