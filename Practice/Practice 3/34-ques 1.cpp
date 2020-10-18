#include <iostream>

using namespace std;

class QuizResult {
	int noOfStudents;//5-20, default is 10
	int *marks;
	void copy(const QuizResult &m) {
		int i;
		noOfStudents = m.noOfStudents;
		marks = new int [noOfStudents];
		for (i = 0 ; i < noOfStudents ; i++) {
			marks[i] = m.marks[i];
		}
	}
	void freeMemory() {
		delete []marks;
	}
	public:
		QuizResult(int noOfStudents) {
			if (noOfStudents < 5 || noOfStudents > 20) {
				noOfStudents = 10;
			}
			this->noOfStudents = noOfStudents;
			marks = new int [noOfStudents];
		}
		void readValues() {
			int i;
			for (i = 0 ; i < noOfStudents ; i++) {
				cin >> marks[i];
			}
		}
		void show() {
			int i;
			for (i = 0 ; i < noOfStudents ; i++) {
				cout << marks[i] << ' ';
			}
			cout << '\n';
		}
		QuizResult (const QuizResult &m) {
			copy(m);
		}
		QuizResult operator = (const QuizResult &m) {
			freeMemory();
			copy(m);
		}	
		~QuizResult() {
			freeMemory();
		}
};

int main() {
	QuizResult q1(6);
	q1.readValues();//Read values from user, preferably from file
	q1.show();
	cout <<"===============\n";
	QuizResult q2 = q1;
	q2.show();
	cout <<"===============\n";
	q2 = q1;
	q2.show();
	return 0;
}
