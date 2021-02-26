#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define KEY_NOT_EXIST -1
#define DIFFRENT_SIZES -2
#define ARRAY_ALREADY_FULL -3

class collection
{
private:
    int *data;
    int size;
    int currentSize;

public:
    collection(const int SIZE = -1)
    {
        size = SIZE;
        currentSize = 0;
        data = new int[size];
        if (size == 1)
            addElement(-1);
    }
    //Constructor Overloading
    collection(int *arr, const int arrSIZE)
    {
        size = arrSIZE;
        currentSize = 0;
        for (int i = 0; i < size; i++)
        {
            data[i] = arr[i];
        }
    }
    //Add element
    bool addElement(const int element)
    {
        if (currentSize < size)
        {
            data[currentSize++] = element;
            return true;
        }
        else if (currentSize == size)
            throw ARRAY_ALREADY_FULL;
        return false;
    }
    //Getter
    int getSize()
    {
        return size;
    }
    //Copy Constructor
    collection(collection &col)
    {
        size = col.size;
        currentSize = col.currentSize;
        data = new int[size];
        for (int i = 0; i < currentSize; i++)
            data[i] = col.data[i];
    }
    //Couunt ELement
    int countElement(int key)
    {
        int count = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (data[i] == key)
            {
                count++;
            }
        }
        //If count is zero then it means that key doesn't exist in collection
        if (count == 0)
            throw KEY_NOT_EXIST;
        return count;
    }
    //Assignment Operator Ovreload
    collection &operator=(collection &col)
    {
        if (size = col.size)
        {
            currentSize = col.currentSize;
            for (int i = 0; i < currentSize; i++)
                data[i] = col.data[i];
        }
        throw DIFFRENT_SIZES;
        return *this;
    }
    //Comparison Operator
    bool operator==(collection &col)
    {
        if (size == col.size)
        {
            if (currentSize == col.currentSize)
            {
                for (int i = 0; i < currentSize; i++)
                {
                    if (countElement(data[i]) == col.countElement(col.data[i]))
                        return true;
                }
            }
        }
        return false;
    }
    //Increment Operators
    void operator++(const int element)
    {
        if (element < 0)
            addElement(element);
        else
            addElement(-1);
    }
    //Addition Binary
    collection &operator+(collection &col)
    {
        collection *temp;
        temp = new collection(size);
        if (currentSize = col.currentSize)
        {
            for (int i = 0; i < currentSize; i++)
            {
                temp->data[i] = data[i] + col.data[i];
            }
        }
        else
            throw DIFFRENT_SIZES;
        return *temp;
    }
    //Destructor
    ~collection()
    {
        delete[] data;
        data = NULL;
        currentSize = size = 0;
    }
    //Ostream Operator Overload
    friend ostream &operator<<(ostream &, collection &);
};
ostream &operator<<(ostream &out, collection &col)
{
    for (int i = 0; i < col.currentSize; i++)
    {
        out << col.data[i] << " ";
    }
    out << endl;
    return out;
}

int main()
{
    int *array;
    try
    {
        int n, operation;
        collection *col;
        cin >> n;
        while (n != 0)
        {
            int value;
            cin >> operation;
            switch (operation)
            {
            case 1:
            {
                cin >> value;
                col = new collection(value);
                break;
            }
            case 2:
                cin >> value;
                col->operator++(value);
                break;
            case 3:
                cout << *col;
                break;
            case 4:
            {
                cin >> value;
                array = new int[value];
                for (int i = 0; i < value; i++)
                {
                    cin >> array[i];
                }
                col = new collection(array, value);
                break;
            }
            case 5:
            {
                collection copied = *col;
                cout << copied << endl;
                break;
            }
            case 6:
                delete col;
                break;
            case 7:
                cin >> value;
                cout << col->countElement(value);
                break;
            case 8:
            {
                collection assigned(col->getSize());
                assigned = *col;
                cout << assigned << endl;
                break;
            }
            case 9:
            {
                collection addition(col->getSize());
                cout << addition + *col;
                break;
            }
            case 10:
            {
                collection compared(col->getSize());
                cout << (compared == *col);
                break;
            }

                n--;
            }
        }
    }
    catch (int type)
    {
        if (type == KEY_NOT_EXIST)
            cout << "KEY_NOT_EXIST\n";
        else if (type == DIFFRENT_SIZES)
            cout << "DIFFRENT_SIZES\n";
        else if (type == ARRAY_ALREADY_FULL)
            cout << "ARRAY_ALREADY_FULL\n";
    }

    return 0;
}

