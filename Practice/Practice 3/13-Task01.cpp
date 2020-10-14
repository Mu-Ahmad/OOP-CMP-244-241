#include <iostream>

using namespace std;

class QuizResult{
    int noOfStudents;//5-15, default is 10
    int *marks;
    void copyValues (const QuizResult &quiz){
      this->noOfStudents = quiz.noOfStudents;
      marks = new int[noOfStudents];
      for (int i=0;i<noOfStudents;i++)
          marks[i] = quiz.marks[i];
    }
    public:
        QuizResult(int n=10){     // Default value
            setNoOfStudents(n);
        }

        QuizResult(const QuizResult &quiz){                  // Copy constructor
            copyValues(quiz);
        }

        QuizResult operator = (const QuizResult &quiz ){    // Assignment Operator
          free();
          copyValues(*this);
          return *this;
        }

        void setNoOfStudents(int n){
          noOfStudents = n;
          if ( n > 15 || n < 5) n = 10;     // Default value
          marks = new int [noOfStudents];
        }


        void read(){
            int val;
            for (int i = 0; i<noOfStudents; i++){
              cout << "Enter marks of student " << i+1 << ": ";
                cin >> val;
                marks[i] = val;
            }
        }

        void show() const{
            for(int i = 0; i<noOfStudents; i++)
                cout << marks[i] << ' ';
            cout << '\n';
        }


        void scale (int val){
            for(int i = 0; i<noOfStudents; i++)
                marks[i] += val;
        }

        void free() const{
          delete []marks;
        }

        ~QuizResult(){
          free();
        }
};

int main(){
    int n, value;
    cout << "Enter No. of Students: ";
    cin >> n;
    QuizResult q1(n);
    q1.read();  //input n values
    cout << "\nQ1:\t\t ";
    q1.show();
    QuizResult q2(q1);
    cout << "\nQ2:(copy)\t ";
    q2.show();
    cout << "\nSelect Quiz to scale (1 0r 2): ";
    cin >> n;
    cout << "Enter scaling vlaue: ";
    cin >> value;
    if (n==1)   q1.scale (value); //increase marks of all students for quiz 1
    else        q2.scale (value); //increase marks of all students for quiz 2
    cout << "\nQ1:\t\t ";
    q1.show();
    cout << "\nQ2:\t\t ";
    q2.show();
    return 0;
}
