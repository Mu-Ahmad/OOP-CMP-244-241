#include <iostream>
#include<string>
using namespace std;
string _newString(string word,int pos=0)
{
    string a = "";
    if (pos==word.length())
    {
        return a;
    }
    else
    {
        if (pos<=word.length())
        {
            a += word.at(pos);
            pos++;
            if (pos<word.length())
            {
                a+='*';
            }
            
        }
    }
    return (a +_newString(word,pos));
}
int main()
{
    cout << _newString("");
    return 0;
}