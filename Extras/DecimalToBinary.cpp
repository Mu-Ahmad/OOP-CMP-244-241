/******************************************************************************

Works for Positive number contribute to make it working for negative numbers too

*******************************************************************************/
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
    std::stringstream superString;
    string binaryString;
    binaryString = " ";
    long long number;
    cin >> number;
    if(number == 0) cout << 0;
    else if(number >0){
    while(number>0){
        superString <<  number%2;
        number/=2;
    }
	binaryString += superString.str();
 	reverse(binaryString.begin(), binaryString.end()); 
	cout <<binaryString;
}
    return 0;
}
