#include <iostream>
using namespace std;
 
class QuizResult{

int noOfStrudents;//5-15, default is 10
int *marks;
public:
    QuizResult(int n)
    {
        noOfStrudents = n;
        marks  = new int [n];
    }
    QuizResult(const QuizResult &q)
    {
        noOfStrudents = q.noOfStrudents;
        marks = new int [noOfStrudents]; 
        for(int i=0;i<noOfStrudents;i++)
        {
            marks[i] = q.marks[i];
        }
        //marks = q.marks;
    }
    void read()
    {
        for(int i= 0;i<noOfStrudents;i++)
        {
            cin >> marks[i];
        }
    }
    void show()
    {
        for(int i = 0;i<noOfStrudents;i++)
        {
            cout << marks[i] <<" ";
        }
        cout << "\n";
    }
    void scale(int value)
    {
        for(int i=0;i<noOfStrudents;i++)
        {
           marks[i] +=value;
        } 
    }
};

int main()
{
 
int n, value;

cin >> n;

QuizResult q1(n);

q1.read();  //input n values

q1.show();

QuizResult q2 = q1;

cin >> n >> value;

if (n==1)
{   
 q1.scale (value);
} //increase marks of all students for quiz 1

else 
q2.scale (value); //increase marks of all students for quiz 2

q1.show();

q2.show();
 
return 0;
}
