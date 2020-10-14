#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Matrix{
    public:
    int **data, rows, cols;
    void set(const int ROWS, const int COLS){
        rows = ROWS;
        cols = COLS;
        data = new int*[ROWS];
        for (int i=0;i<ROWS;i++)
        data[i] = new int [COLS];
    }
    Matrix first(int row,int k){
        for(int j = 0;j<cols;j++)
        data[row-1][j] *=k;
		return *this; 
    }
    Matrix second(int col,int k){
        for(int j = 0;j<rows;j++)
        data[j][col-1] *=k;
		return *this; 
    }
    Matrix third(int r1,int r2){
        for(int j = 0;j<cols;j++)
        data[r2-1][j] +=data[r1-1][j] ; 
    	return *this;
	}
    Matrix fourth(int c1,int c2){
        for(int j = 0;j<rows;j++)
        data[j][c2-1] +=data[j][c1-1] ;
		return *this; 
    }
    Matrix fifth(int r1,int r2){
        for(int j = 0;j<cols;j++)
        data[r2-1][j] -=data[r1-1][j] ;
		return *this; 
    }
    Matrix sixth(int c1,int c2){
        for(int j = 0;j<rows;j++)
        data[j][c2-1] -=data[j][c1-1] ;
		return *this; 
    }
    void show(){
        for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++)
         cout << data[i][j]<<' ';
            cout <<'\n';
        }
    }
    
    
    
    
};
int main() {
    Matrix m1;
    int r,c,r1,r2,c1,to_col,c2,k,choice,value,to_row;
    cin >> r >> c;
    m1.set(r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
        cin >> m1.data[i][j]; 
    }
    }
    cin >> value;
    for(int i=0;i<value;i++)
    {
        cin >> choice;
        if(choice == 1)
        {
            cin >> to_row >> k;
            m1.first(to_row,k).show();
        }
        if(choice == 2)
        {
            cin >> to_col >> k;
            m1.second(to_col,k).show();
        }
        if(choice == 3)
        {
            cin >> r1 >> r2;
            m1.third(r1,r2).show();
            
        }
        if(choice == 4)
        {
            cin >> c1 >> c2;
            m1.fourth(c1,c2).show();
        }
        if(choice == 5)
        {
            cin >> r1 >> r2;
            m1.fifth(r1,r2).show();
        }
        if(choice == 6)
        {
          cin >> c1 >> c2;
            m1.sixth(c1,c2).show();  
        }
        if(choice == 7)
        {
         
            m1.show();  
        }
        
    }   
    return 0;
}
