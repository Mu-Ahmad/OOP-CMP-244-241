#include <iostream>
#include <fstream>
#include <string.h>			//To use strcpy function
#include <stdio.h>			//To use remove() function, to delete file
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
	#define QUIT 6
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
	if (file.fail()){//check if file successfully opened
		ofstream out("students.bin");//Otherwise create a new file
		out.close();				//close file
		file.open("students.bin", ios::binary | ios::in | ios::out);//Reopen in reading+writing mode
	}
	file.write ( (char*) s, sizeof(Student) * COUNT );

	do{
		cout << "\t\t1.	Show all records\n";
		cout << "\t\t2.	Add new record\n";
		cout << "\t\t3.	Show nth record\n";
		cout << "\t\t4.	Modify nth record\n";
		cout << "\t\t5.	Delete nth record\n";
		cout << "\t\t6.	Quit\n";	
		cin >> choice;
		switch (choice){
			case 1://Show All Records
				file.seekg(0, ios::end);
				count = file.tellg() / sizeof(Student);//Counting number of objects
				file.seekg(0);
				newS = new Student [count];	
				file.read ( (char*) newS, sizeof(Student) * count );
				for (i=0;i<count;i++)
					cout << newS[i];
				delete []newS;
				break;
			case 2://Add New Record
				cout << "Enter name of the student:";
				cin >> fn >> sn;
				cout << "Enter roll no of the student:";		
				cin >> r;
				cout << "Enter CGPA of the student:";
				cin >> cgpa;
				student.set (fn, sn, r, cgpa);
				file.seekp(0, ios::end);
				file.write ( (char*) &student, sizeof(Student) );
				break;
			case 3://Show Nth Record
				cout << "Enter Record No:";
				cin >> n;
				n--;
				file.seekg(sizeof (Student) * n);
				file.read ( (char*) &student, sizeof(Student) );
				cout << student;
				break;
			case 4://Modify Nth Record
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
			case 5://Delete nth record
				cout << "Enter Record No:";
				cin >> n;
				file.seekg(0, ios::end);
				count = file.tellg() / sizeof(Student);
				file.seekg(0);
				newS = new Student [count];	
				file.read ( (char*) newS, sizeof(Student) * count );
				if (n > count){	//Check file has n records?
					if (count == 0) cout << "Sorry no record in the file\n";
					else			cout << "Sorry, File has less than n records\n";
					break;
				}

				n--;
				file.close();

				remove ("students.bin");//delete complete file

				ofstream out ("students.bin",ios::binary);//file recreated
				out.write ( (char*) newS, sizeof(Student)* n );	//store first n-1 records
				//Skip nth record and store next records
				out.write ( (char*) &newS[n+1], sizeof(Student)* (count-n-1) );							
				out.close();	//close file
				delete []newS;	//Delete array
				file.open("students.bin", ios::binary | ios::in | ios::out);//Reopen file
				break;
		}
	}while (choice!=QUIT);
	file.close();
	cout << "\n\n\t\tThanks for using this program\n";
    return 0;
}

