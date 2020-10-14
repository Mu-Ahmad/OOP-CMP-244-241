#include<iostream>
using namespace std;
class QuizResult
{
    int noOfStrudents;//5-20, default is 10
    int *marks;
    private://Functions to be used by public memeber functions
        void copyConstructor(const QuizResult &q)
        {
            noOfStrudents = q.noOfStrudents;
            marks = new int[noOfStrudents];
            for (int i = 0; i < noOfStrudents; i++)
            {
                marks[i] = q.marks[i];
            }
        }
        void free()
        {
            delete []marks;
        }
    public:
        QuizResult(int n)
        {
            if (n<=20 && n>=5)
                noOfStrudents = n;
            else
                noOfStrudents = 10;//Default Value

            marks = new int[noOfStrudents];
        }
        void readValues()
        {
            for (int i = 0; i < noOfStrudents; i++)
            {
                cin >> marks[i];
            }
        }
        void show()
        {
            for (int i = 0; i < noOfStrudents; i++)
            {
                cout << marks[i] << " ";
            }
            cout << "\n";
        }
        QuizResult(const QuizResult &q)
        {
            //To avoid code duplication a private function is used
            copyConstructor(q);
        }
        QuizResult operator = (const QuizResult &q)
        {
            free();
            copyConstructor(q);
            return *this;//To return the object created in/by this function
        }
        ~QuizResult()
        {
            free();
        }
};
int main()
{
    QuizResult q1(20);
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