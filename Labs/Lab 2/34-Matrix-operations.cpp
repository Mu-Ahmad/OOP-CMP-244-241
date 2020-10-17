#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Matrix{
    int **data, rows, columns;
    void set(const int ROWS, const int COLUMNS){
        rows = ROWS;
        columns = COLUMNS;
        data = new int*[ROWS];
        for (int i=0;i<ROWS;i++)
            data[i] = new int [COLUMNS];
    }
    void read(){
        int i,j;
        for (i=0;i<rows;i++)
            for (j=0;j<columns;j++)
                cin >> data[i][j];
    }
     void multiply(int row ,int elem)
    {
         int i, j;
            i = row - 1;
            for (j = 0 ; j < columns ; j++) {
                data[i][j] = data[i][j] * elem;   
            }
    }
    void interchange(const int c1 , const int c2)
    {
        int rand;
        int column1 = (c1 - 1);
        int column2 = (c2 - 1);
        for (int i = 0 ; i < rows ; i++)
        {
            rand = data[i][column1];
            data[i][column1] = data[i][column2];
            data[i][column2] = rand;
        }   
    }
    void show(){
        int i,j;
        for (i=0;i<rows;i++){
            for (j=0;j<columns;j++)
                cout << data[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    void free(){
        for (int i=0;i<rows;i++)
            delete []data[i];
        delete data;
    }
};

int main(){
    srand(time(0));
    int r, c;
    cin >> r >> c;
    Matrix m1;
    m1.set(r,c);
    m1.read();
    m1.show();
    int ele, rowm;
    cin >> ele >> rowm;
    m1.multiply(rowm, ele);
    m1.show();
    int co1, co2;
    cin >> co1 >> co2;
    m1.interchange(co1, co2);
    m1.show();
    m1.free();

    return 0;
}
