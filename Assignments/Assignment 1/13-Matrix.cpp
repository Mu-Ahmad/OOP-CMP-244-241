#include <bits/stdc++.h>
using namespace std;

struct Bag{
    int *data, currentSize, maxSize;

    void init(const int SIZE){
        maxSize = SIZE;
        currentSize = 0;
        data = new int[maxSize];
    }
    void add(const int ELEMENT){
        if (currentSize == maxSize)
            return;
        data [ currentSize++ ] = ELEMENT;
    }
    bool isExist ( const int ELEMENT ){
  		int i;
  		for ( i = 0; i < currentSize; i++)
  			if(ELEMENT == data[i])
  				return true;
  		return false;
  	}
    void print() const {
        int i;
        for (i=0;i<currentSize;i++)
                cout << data[i] << ' ';
        cout << '\n';
    }
    Bag merge (const Bag &b){
  		Bag newBag;int i;
  		int size = currentSize + b.currentSize;
  		newBag.init(size);
  		for ( i=0 ; i < currentSize ; i++)
  			newBag.data [ newBag.currentSize++ ] = data [i];
  		for ( i=0 ; i < b.currentSize ; i++)
  			newBag.add (b.data[i]);
  		return newBag;
  	}
    int indexOf (const int ELEMENT){
      for(int i = 0; i < currentSize; i++)
        if(ELEMENT == data[i])
          return i;
      return -1;
    }
    void resize (const int newSize){
  		data = (int*)realloc(data,newSize*sizeof(int));
  		maxSize = newSize;
  	}
    bool has(const Bag &bag){
      int i;
      if (currentSize < bag.currentSize)
        return false;
      for(i=0;i<bag.currentSize;i++)
        if(!(isExist(bag.data[i])))
          return false;
      return true;
    }
    void free(){
        delete data;
    }
};

int main() {
    int SIZE, Elements, num, index;
    srand(time(0));
    cout << "Enter capacity and number of values of 1st bag: ";
    cin >> SIZE >> Elements;
    Bag bag1;
    bag1.init(SIZE);
    for(int i = 0; i<Elements; i++){
        num = rand()%100;
        bag1.add(num);
    }

    cout << "Enter capacity and number of values of 2nd bag: ";
    cin >> SIZE >> Elements;
    Bag bag2;
    bag2.init(SIZE);
    for(int i = 0; i<Elements; i++){
        num = bag1.data[i];
        bag2.add(num);
    }
    cout << "Bag1 : ";
    bag1.print();
    cout << "Bag2 : ";
    bag2.print();
    if(bag1.has(bag2))
      cout << "B1 has B2.\n";
    else
      cout << "B1 don't have B2.\n";
    cout << "Enter value to get index(bag1): ";
    cin >> num;
    cout << "Index is: " << bag1.indexOf(num) << '\n';
    bag1.free();
    bag2.free();

    return 0;
}
