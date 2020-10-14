#include <iostream>
#include <iomanip>
using namespace std;

class Matrix{
    int **data, rows, cols;
    void copyValues(Matrix const &matrix){
      rows = matrix.rows, cols = matrix.cols;
      initMatrix(rows,cols);
      for (int i = 0; i<rows; i++){
          for (int j = 0; j<cols; j++){
            this->data[i] = matrix.data[i];
          }
        }
    }
  public:
    Matrix(int ROWS=2, int COLS=2){ // Default row and cols are 2
      rows = ROWS, cols = COLS;
      initMatrix(rows,cols);
    }

    Matrix(Matrix const &matrix){
      copyValues(matrix);
    }

    Matrix operator = (Matrix const &matrix){
      free();
      copyValues(matrix);
      return *this;
    }

    void initMatrix(const int ROWS, const int COLS){
        rows = ROWS;
        cols = COLS;
        data = new int*[rows];
        for (int i=0;i<rows;i++)
            data[i] = new int [cols];
    }
    void insertValues(){
        int i, j, entry;
        cout << "Enter all values: ";
        for (i = 0; i<rows; i++){
            for (j = 0; j<cols; j++){
                cin >> entry;
                data[i][j] = entry;
            }
        }
    }
    Matrix mulRow(){
        int j, k, n;
        cout << "Enter Row No. and value to be multiplied.\n";
        cin >> k >> n;
        for (j = 0; j<cols; j++)
            data[k-1][j] *= n;
        return *this;
    }

    Matrix mulCol(){
        int i, k, n;
        cout << "Enter Column No. and value to be multiplied.\n";
        cin >> k >> n;
        for (i = 0; i<rows; i++)
            data[i][k-1] *= n;
        return *this;
    }

    Matrix addRow(){
        int i, j, k;
        cout << "Enter Rows to be added.(Result will be stored in second row)\n";
        cin >> j >> k;
        for(i = 0; i < cols; i++)
            data[j-1][i] += data[k-1][i];
        return *this;
    }

    Matrix addCol(){
        int i, j, k;
        cout << "Enter Columns to be added.(Result will be stored in second column)\n";
        cin >> j >> k;
        for(i = 0; i < rows; i++)
            data[i][k-1] += data[i][j-1];
        return *this;
    }

    Matrix subractRow(){
        int i, j, k;
        cout << "Enter Rows to be Subtracted.(Result will be stored in second row)\n";
        cin >> j >> k;
        for(i = 0; i < cols; i++)
            data[j-1][i] -= data[k-1][i];
        return *this;
    }

    Matrix subractCol(){
        int i, j, k;
        cout << "Enter Columns to be Subtracted.(Result will be stored in second column)\n";
        cin >> j >> k;
        for(i = 0; i < rows; i++)
            data[i][k-1] -= data[i][j-1];
        return *this;
    }

     void show(){
        int i,j;
        cout << '\n';
        for (i=0;i<rows;i++){
            for (j=0;j<cols;j++)
                cout << setw(2) << data[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }

    Matrix implementOp (int n){
        switch(n){
            case 1:
                return mulRow();
            case 2:
                return mulCol();
            case 3:
                return addRow();
            case 4:
                return addCol();
            case 5:
                return subractRow();
            case 6:
                return subractCol();
            case 7:
                return *this;
            default:
                cout << "Invalid Operation.\n";
                return *this;
        }
    }

    void free(){
        for (int i=0;i<rows;i++)
            delete []data[i];
        delete data;
    }
    void displayMenu()const{
      cout << "\t\t\t************************************\n"
           << "\t\t\t*               Menu               *\n"
           << "\t\t\t************************************\n";
      cout << "\t1. Multiply kth row with some scalar value.\n"
           << "\t2. Multiply kth col with some scalar value.\n"
           << "\t3. Add jth row into kth row.\n"
           << "\t4. Add jth col into kth col.\n"
           << "\t5. Subtract jth row from kth row.\n"
           << "\t6. Subtract jth col from kth col\n"
           << "\t7. Display Matrix.\n\n\n\n\n";
    }
    // ~Matrix(){
    //   free();
    // }
};

int main() {
    int rows, cols, totalOp, opNo;
    cout << "Enter No. of rows and columns: ";
    cin >> rows >> cols;
    Matrix matrix;
    matrix.initMatrix(rows,cols);
    matrix.insertValues();
    matrix.show();
    matrix.displayMenu();
    cout << "Enter count of Operation to be performed: ";
    cin >> totalOp;
    for (int i = 0; i< totalOp; i++){
      cout << "\nEnter Choice: ";
        cin >> opNo;
        matrix.implementOp(opNo).show();
    }
    cout << "\t\t\t************************************\n"
         << "\t\t\t* Program terminated successfully. *\n"
         << "\t\t\t************************************\n";
    return 0;
}
