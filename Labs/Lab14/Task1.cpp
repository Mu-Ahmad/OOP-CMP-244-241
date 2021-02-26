#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>

using namespace std;

class Painting{
    protected:
    string title,aName;
    int value;
    public:
    Painting(string t, string n){
        title=t;
        aName=n;
        value=400;
    }
    void display(){
        cout<<"\tPainting Title: "<<title<<endl;
        cout<<"\tArtist Name: "<<aName<<endl;
        cout<<"\tPrice: $"<<value<<endl;
        cout<<endl;
    }
};


class FamousPainting:public Painting{
    public:
    FamousPainting(string t, string n):Painting(t,n){
        Painting::value=25000;
    }
    
    
};
int main() {

    Painting* p[3];
    
    string t,n;
    for(int i=0;i<10;i++){
        cout<<"Painting Title:";getline(cin,t);
        cout<<"Artist's Name:";getline(cin,n);
        if(strcmp(n.c_str(),"Degas")==0 || strcmp(n.c_str(),"Monet")==0 || strcmp(n.c_str(),"Picasso")==0 || strcmp(n.c_str(),"Rembrandt")==0){
            p[i] = new FamousPainting(t,n);
        }else{
            p[i] = new Painting(t,n);
        }
}
    for(int i=0;i<10;i++){
        cout<<"Painting "<<i+1<<":"<<endl;
        p[i]->display();
}
    return 0;
}
