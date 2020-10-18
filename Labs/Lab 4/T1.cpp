#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class QuizResult{
    public:
    QuizResult(int num) {
        if (num < 5 || num > 15) {
            noOfStrudents = 10;
        }
        else {
            noOfStrudents = num;
        }
    }   
    void read() {
        int i;
        marks = new int [noOfStrudents];
        for (i = 0 ; i < noOfStrudents ; i++) {
            cin >> marks[i];
        }
    }
    void show() {
        int i;
        for (i = 0 ; i < noOfStrudents ; i++) {
            cout << marks[i] << ' ';
        }
        cout << '\n';
    }
    QuizResult(const QuizResult &m) {
        noOfStrudents = m.noOfStrudents;
        marks = new int[noOfStrudents];
        for (int i = 0 ; i < noOfStrudents ; i++)        
            marks[i] = m.marks[i];
    }
    void scale(int val) {
        int i;
        for (i = 0 ; i < noOfStrudents ; i++) {
            marks[i] += val;
        }
    }
    private:
    int noOfStrudents;//5-15, default is 10
    int *marks;
};

int main(){

    int n, value;

    cin >> n;

    QuizResult q1(n);

    q1.read();  //input n values

    q1.show();

    QuizResult q2 = q1;

    cin >> n >> value;

    if (n==1)   q1.scale (value); //increase marks of all students for quiz 1

    else        q2.scale (value); //increase marks of all students for quiz 2

    q1.show();

    q2.show();

    return 0;
}

