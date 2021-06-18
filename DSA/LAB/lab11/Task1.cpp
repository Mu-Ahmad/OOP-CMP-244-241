// Name: Muhammad Ahmad
// Roll: BCSF19M509


#include <iostream>
#include <set>
#include <random>

using namespace std;

// Using Pseudo random number generator
// number generator function seeded with some deterministic value
int Hash1(string key, int size){
	long long ascii_sum = 0;
	int m = 1e9 + 9;
	for(int i=0; i<key.size(); i++){
		unsigned int seed = ascii_sum;
		std::minstd_rand0 r1 (seed);
		int random = r1()%100000000;
		int mul = (i%3 == 0) ? 1 : random;
		ascii_sum += (key[i]*mul);
	}
	return (ascii_sum /key.size()) % size;
}

//Double Hashing
int Hash2(string key, int size){
    int H1 = Hash1(key, size);
    long long ascii_sum = 0;
    for(int i=0; i<key.size(); i++){
    	int offset = (i%3 == 0) ? H1 : 1; 
      	ascii_sum += ((key[i]-'a'+1) + offset);
	}
	return ascii_sum % size;
}

//polynomial rolling hash function.
// source cp-algorithm
int Hash3(string const& s, int size) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value%size;
}

int main(){
	//to read keys from fruits.txt file attached in folder
	freopen("fruits.txt", "r", stdin);
	
	// We will collect hash generated for every key in a set data structure so in the end we 
	// can get count of unique hashes and make sure that no collision takes place 
	int input_key_count = 86;


	//They even work for some lower values than this
	//But I hastely find these to be working
	int size1 = 950; 
	int size2 = 834;
	int size3 = 1200;

	set<int> hash_set1;
	set<int> hash_set2;
	set<int> hash_set3;
	string key;

	for(int i=0; i<86; i++){
		getline(cin, key);

		hash_set1.insert(Hash1(key, size1));
		hash_set2.insert(Hash2(key, size2));
		hash_set3.insert(Hash2(key, size3));
	}
	
	cout << size1 <<" size: hash_set1 unique hashes: "<< hash_set1.size()<<'\n';
	cout << size2 <<" size: hash_set2 unique hashes: "<< hash_set2.size()<<'\n';
	cout << size3 <<" size: hash_set3 unique hashes: "<< hash_set3.size()<<'\n';
	
	return 0;
}