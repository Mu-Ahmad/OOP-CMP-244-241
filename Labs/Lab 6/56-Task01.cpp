//string programmer {"Arslan Iftikhar"};
//string data {"10/23/2020"}
//int lab {6};
/*
A journalist asked a programmer: What makes code bad?
Programmer: No comments.
*/

#include<iostream>
#include <cmath>
#include <vector>
#include<cstdlib>
#include <utility>
#include<iomanip>
#include<cstring>
#include <algorithm>
#define EMPTY_STRING '$'

using namespace std;

class Set
{
    private:
        //Private Data members..
        int size /*Original size..*/, main_index; // Pointer for adding new variable..
        char *data;
        static int rank;

        //Private Member Functions..
        void copier(const Set &set)
        {
            int idx; //counter variable..

            this->size = set.size;
            this->main_index = set.main_index;
            data = new char[this->size];

            for(idx = 0; idx < this->size; idx++)
            {
                data[idx] = set.data[idx];
            }
        }

        void cfree(void)
        {
            delete [] data;
        }

        void resize(const int SIZE)
        {
            char *data_temp;
            data_temp = new char[SIZE];
            
            memcpy(data_temp, data, size*sizeof(char)); //Copying data to new array..
            this->size = SIZE; //Updating the size..
            
            delete [] data;
            data = data_temp;

            data_temp = 0; //To remove the ambiguity this pointer becomes null..
            
        }

        bool is_exist(const char ELEMENT)
        {
            int idx = 0; //counter variable..
            
            for(idx = 0; idx < main_index; idx++)
            {
                if(data[idx] == ELEMENT)
                {   flag = idx;
                    return true;
                }
            }

            return false;
        }

        bool add(const char ELEMENT)
        {
            if(!(is_exist(ELEMENT)))
            {
                data[main_index++] = ELEMENT;
                return true;
            }
            else
                return false;
        }

        bool remove(const char ELEMENT)
        {
            if(is_exist(ELEMENT))
            {
                data[flag]  = EMPTY_STRING;
                shift(flag);
                return true;
            }

            return false;
        } 

        void shift(int flag) // will be used by remove() only..
        {
            int idx = 0; //counter variable..

            if (flag < main_index - 1)
            {
                for(idx = flag; idx < main_index; idx++)
                {
                    data[idx] = data[idx + 1];
                }
                data[main_index] = EMPTY_STRING;
                main_index--;
            }
            else
            main_index--;
        }

    public:
        //Public data members..
            int flag; //Find something ...

        //Constructors..
        Set(const Set &set)
        {
            copier(set);
            rank++;
        }
        
        Set(int size = 0, bool dollar = true)
        {
            int idx; //counter variable..
            this->size = size;
            this->main_index = 0;
            data = new char[size];

            if(dollar)
            for(idx = 0; idx < size; idx++)
            {
                data[idx] = EMPTY_STRING;
            }
            else
            {
                for(idx = 0; idx < size; idx++)
                cin>>data[idx];
                main_index++;
            }
            rank++;
        }

        //Public members functions..
        void show(void)
        {
            int idx = 0; //counter variable..
            
            for(idx = 0; idx < size; idx++)
            {
                if(data[idx] != EMPTY_STRING)
                cout<<data[idx]<<' ';
            }
            cout<<main_index;
            cout<<'\n';

        }
        
        void read(const int TIMES)
        {
            int idx; //counter variable..
            int holder;
            char keeper;

            if(size == main_index)
            {
                holder = size + TIMES;
                resize(holder);
            }

            for(idx = 0; idx < TIMES; idx++)
            {
                cin>>keeper;
                add(keeper);
            }
        }

        //Operator overload..
        Set operator + (const Set& set)
        {
            int idx = 0; //counter variable..
            const int SIZE = main_index + set.main_index;
            Set union_set(SIZE);
            
            for(idx = 0; idx < main_index; idx++)
            {
                union_set.data[union_set.main_index++] = data[idx];
            }

            for(idx = 0; idx < set.main_index; idx++)
            {
                union_set.add(set.data[idx]);
            }

            return union_set;
        }

        Set operator - (Set &set)
        {
            int idx = 0; //counter variable..
            const int SIZE = main_index;
            Set difference_set(SIZE);

            for(idx = 0; idx < main_index; idx++)
            {
                if(!(set.is_exist(data[idx])))
                    difference_set.add(data[idx]);
            }

            return difference_set;
        }

        Set& operator + (const char ELEMENT)
        {
            if(size == main_index)
            {
                int holder = size + 1;
                resize(holder);
            }

            add(ELEMENT);

            return *this;
        }

          Set& operator - (const char ELEMENT)
        {
            remove(ELEMENT);
            
            return *this;
        }

        Set operator = (const Set &set)
        {
            cfree();
            copier(set);

            return set;
        }

        bool operator == ( Set &set)
        {
            int idx; //counter variable..
            int tester; //checking all existence..
            for(idx = 0; idx < main_index; idx++)
            {
                if(!(set.is_exist(data[idx])))
                    return false;
            }
            if(main_index == set.main_index)
            return true;
            return false;
        }
        
        bool operator != ( Set &set)
        {
            int idx; //counter variable..
            int tester; //checking all existence..
            for(idx = 0; idx < main_index; idx++)
            {
                if(!(set.is_exist(data[idx])))
                    return true;
            }
            if(main_index != set.main_index)
            return true;
            return false;
        }

        void operator * (const Set &set)
        {
            int idx, kdx; //counter variables..
            cout<<'{';
            for(idx = 0; idx < main_index; idx++)
            {
                for(kdx = 0; kdx < set.main_index; kdx++)
                {
                    cout<<'('<<data[idx]<<','<<set.data[kdx]<<')';
					if(idx == main_index-1 && kdx == set.main_index - 1)
					break;
					cout<<',';
                }
               
            }
            cout<<"}\n";
        }

        //Friends..
        friend ostream& operator<<(ostream &os, const Set &set);

        ~Set()//Destructor..
        {
            cfree();
        }

};

int Set::rank = 0; //Static Variable intialized to 0..

//Global Functions
ostream& operator<< (ostream &os, const Set &set)
{
    int idx = 0; //counter variable..

    if(set.main_index == 0)
    {
        os << "EMPTY SET";
        cout<<'\n';
        return os;
    }
    else
    {
        for(idx = 0; idx < set.main_index; idx++)
        {   
            if(set.data[idx] != EMPTY_STRING)
            os<< set.data[idx]<<" ";
        }
    cout<<'\n';
    }
    return os;
}

int main(void)
{
    int idx; //counter variable..
    int operations, holder, set1 ,set2, sel;
    char k;
    Set sets[5];

    cin>>operations;

    for(idx = 0; idx < operations; idx++)
    {
        cin>>sel;
        switch(sel)
        {
            case 1:
                cin >> set1 >> set2 >> holder;
                sets[holder-1] = sets[set1-1] +sets[set2-1];
                break;
            case 2:
                cin>>set1>> set2;
                sets[set1-1] * sets[set2-1];
                break;
            case 3:
               cin >> set1 >> set2 >>holder;
               sets[holder-1] = sets[set1-1]  - sets[set2-1];
               break;
            case 4:
                cin>>set1>>k;
                sets[set1-1] + k;
                break;
            case 5:
                cin>>set1>>k;
                sets[set1-1] - k;
                break;
            case 6:
                cin>>set1>>set2;
                if(sets[set1-1] == sets[set2-1])
                    cout<<"TRUE\n";
                else
                {
                    cout<<"FALSE\n";
                }
                break;
            case 7:
                cin>>set1>>set2;
                if(sets[set1-1] != sets[set2-1])
                    cout<<"TRUE\n";
                else
                    cout<<"FALSE\n";
                break;
            case 8:
                cin>>set1;
                cout<<sets[set1-1];
                break;
            case 9:
                cin>>set1>>holder;
                sets[set1-1].read(holder);
                break;
            case 10:
                cin>>set1>>set2;
                sets[set1-1] = sets[set2-1];
                break;
            default:
                cout<<"Invalid Input";
                break;

        }
    }
    return 0;
}
