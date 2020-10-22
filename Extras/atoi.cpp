#include<iostream>
#include<vector>
#include<string>

using namespace std;

int chartoint(char ch);
int stringtoint(string str);

int main(void)
{
    int char_holder, string_holder;
    
    char_holder = chartoint('9');
    string_holder = stringtoint("12350");
    cout<<"Char Result: "<<char_holder<<"\nString Result: "<<string_holder<<'\n';
    return 0;
}

int chartoint(char ch)
{
    char cake = ch;
    int temp_int = int(ch) - 48; //0 is 48 so get ascii of character and subtract the 48 you will get the int..
    return temp_int;
}

int stringtoint(string str)
{
    int temp_int = 0 /*total to be return*/ , idx, place_value = 1 ;/*setting the place value should be unit at start*/ 
    int str_size = str.size(); //how many times loop has to be run..
    for(idx = str_size - 1; idx >= 0; idx--)
    {
        temp_int = temp_int + (chartoint(str[idx]) * place_value);
        place_value = place_value * 10;
    }
    
    return temp_int;
}