#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Player{
    int NoOfMatches;
    int *scores;
    char *matchStatus;
    static int playerCount;
     int countInnings(){
        int count=0;
        for (int i = 0; i<NoOfMatches; i++)
            if (matchStatus[i] == 'O') 
                count++;
        return count;
     }
    public:
        Player(int NoOfMatches){
            this->NoOfMatches = NoOfMatches;
            this->scores = new int[this->NoOfMatches];
            this->matchStatus = new char[this->NoOfMatches];
            playerCount++;
        }
        void read(){
            int scores;
            char matchStatus;
            for(int i=0; i<NoOfMatches; i++){
                cin >> scores >> matchStatus;
                this->scores[i] = scores;
                this->matchStatus[i] = matchStatus;
            }
        }
        static int getPlayerCount(){
            return playerCount;
        }
        float calAvg(){
            int sum=0;
            float avg=0;
            for (int i=0; i<NoOfMatches; i++)
                sum += this->scores[i];
            avg = sum/countInnings();
            return avg;
        }
        void show(int const p){
            cout << "Player " << p
                 << " has played " << this->NoOfMatches
                 << " matches and " << countInnings() << " innings\n" 
                 << "Scores: ";
            for(int i=0; i<this->NoOfMatches; i++){
                cout << this->scores[i] << ' ';
            }
            cout << '\n';
        }
    ~Player(){
        playerCount--;
        delete []scores;
        delete []matchStatus; 
    }
};

int Player::playerCount = 0;
int main() {
    int n1, n2, n3, noOfOp, choice, pNo, nm;
    cin >> n1 >> n2 >> n3;
    Player *p[3] = {
        new Player(n1), 
        new Player(n2), 
        new Player(n3)
    };
    cin >> noOfOp;
    while(noOfOp > 0){
        cin >> choice;
        switch(choice){
            case 1:
                cin >> pNo;
                cout << p[pNo-1]->calAvg();
                break;
            case 2:
                cin >> pNo;
                p[pNo-1]->show(pNo);
                break;
            case 3:
                cout << "Number of Players: " << Player::getPlayerCount() << '\n';
                break;
            case 4:
                cin >> pNo;
                cout << "Average: " << p[pNo-1]->calAvg() << '\n';
                break;
            case 5:
                cin >> pNo;
                delete p[pNo-1];
                break;
            case 6:
                cin >> pNo >> nm;
                delete p[pNo-1];
                p[pNo-1]= new Player(nm);
                break;
            case 7:
                cin >> pNo;
                p[pNo-1]->read();
                break;
            
        }
        noOfOp--;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
