#include <iostream> 
#include <vector>	 
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 16

void initPlayers(vector<char> &v){
	for (char ch='A' ; ch < 'A'+SIZE ; ch++	)
		v.push_back(ch);
}
void generateRandomScores(vector<int> &v, const int S){
	for (int i=0;i<S;i++)
		v.push_back(rand()%50+50);//generate random number in range 50-100
}
void compareAndShowScores(vector<char> &players, vector<int> &scores){
	int i;
	vector<char> newPlayers;
	for (i=0;i<players.size();i++)
		cout << players[i] << "  ";
	cout << '\n';
	for (i=0;i<players.size();i++)
		cout << scores[i] << ' ';
	cout << "\nWinners: ";
	for (i=0;i<players.size();i+=2){
		if (scores[i]<scores[i+1]){
			cout << players[i+1] << ' ';
			newPlayers.push_back(players[i+1]);
		}
		else{
			cout << players[i] << ' ';
			newPlayers.push_back(players[i]);
		}
	}
	cout << "\n================================================================\n";
	players = newPlayers;//using overloaded assignment operator in class vector
}
int main() {
	srand(time(0));
	vector <char> players;
	vector <int> scores;
	initPlayers(players);
	while (players.size()>1){
		generateRandomScores(scores, players.size());
		compareAndShowScores(players, scores);
	}
	return 0;
}
