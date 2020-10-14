#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;
class Matrix
{
    int **matrix,rows,cols;
private:
    /* data */
public:
    Matrix(const int ROWS,const int COLS)
    {
        rows = ROWS;
        cols = COLS;
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
    }
    void initRandom()
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j]=rand()%10;         
    }
    void show()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << setw(2) << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void rowMultiplication()
    {
        int rowNumber,value;
        cout << "Enter Row Number: ";
        cin >> rowNumber;
        cout << "Enter value to be multiplied:";
        cin >> value;
        for (int j = 0; j < cols; j++)
            matrix[rowNumber-1][j] = matrix[rowNumber-1][j]*value;       
    }
    void colMultiplication()
    {
        int colNumber,value;
        cout << "Enter Columns Number: ";
        cin >> colNumber;
        cout << "Enter value to be multiplied:";
        cin >> value;
        for (int i = 0; i < rows; i++)
            matrix[i][colNumber-1] = matrix[i][colNumber-1]*value;       
    }
    void rowAddition()
    {
        int row_1,row_2;
        cout << "Enter Row-1:";
        cin >> row_1;
        cout << "Enter Row-2:";
        cin >> row_2;
        for (int j = 0; j < cols; j++)
            matrix[row_2-1][j] = matrix[row_1-1][j]+matrix[row_2-1][j];   
    }
    void colAddition()
    {
        int col_1,col_2;
        cout << "Enter Columns-1:";
        cin >> col_1;
        cout << "Enter Columns-2:";
        cin >> col_2;
        for (int i = 0; i < rows; i++)
            matrix[i][col_2-1] = matrix[i][col_1-1]+matrix[i][col_2-1];   
    }
    void rowSubtraction()
    {
        int row_1,row_2;
        cout << "Enter Row-1:";
        cin >> row_1;
        cout << "Enter Row-2:";
        cin >> row_2;
        for (int j = 0; j < cols; j++)
            matrix[row_2-1][j] = matrix[row_2-1][j]-matrix[row_1-1][j];   
    }
    void colSubtraction()
    {
        int col_1,col_2;
        cout << "Enter Columns-1:";
        cin >> col_1;
        cout << "Enter Columns-2:";
        cin >> col_2;
        for (int i = 0; i < rows; i++)
            matrix[i][col_2-1] = matrix[i][col_2-1]-matrix[i][col_1-1];   
    }
    void free()
    {
        for (int i=0;i<rows;i++)
            delete []matrix[i];
        delete []matrix;        
    }
};
int main()
{
    srand(time(0));
    int rows,cols;
    cout << "Enter No. of Rows:";
    cin >> rows;
    cout << "Enter No. of Columns:";
    cin >> cols;
    Matrix m1(rows,cols);
    m1.initRandom();
    m1.show();

    cout << "Enter total No. of operations to be performed: ";
    int totalOptions;
    cin >> totalOptions;
    cout << "1-multiply kth row with some scalar value"<<endl;
    cout << "2-multiply kth col with some scalar value"<<endl;
    cout << "3-add jth row into kth row"<<endl;
    cout << "4-add jth col into kth col"<<endl;
    cout << "5-subtract jth row from kth row"<<endl;
    cout << "6-subtract jth col from kth col"<<endl;
    cout << "7-show matrix elements in proper format"<<endl;
    while(totalOptions!=0)
    {
        int choice;
        cout << "Enter operation to be performed";
        cin >> choice;   
        if(choice ==1)
            m1.rowMultiplication();
        else if(choice ==2)
            m1.colMultiplication();
        else if(choice ==3)
            m1.rowAddition();
        else if(choice ==4)
            m1.colAddition();
        else if(choice ==5)
            m1.rowSubtraction();
        else if(choice ==6)
            m1.colSubtraction();
        else if(choice ==7)
            m1.show();

        totalOptions -=1;    
    }

    m1.free();
    return 0;
}