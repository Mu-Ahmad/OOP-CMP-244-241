#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Players {
    private:
        const int playernum;
        int numofmatches;
        int *scores;
        char *status;
        static int numplayers;
        int numinnings () {
            int i, numofinnings = 0;
            for (i = 0 ; i < numofmatches ; i++) {
                if (status[i] == 'O') {
                    numofinnings++;
                }
            } 
                return numofinnings;
        }
    public:
        Players (int numofmatches, int playnum): playernum(playnum) {
            this->numofmatches = numofmatches;
            scores = new int [numofmatches];
            status = new char [numofmatches];
            numplayers++;
        }
        void readscorestatus() {
            int i;
            for (i = 0 ; i < numofmatches ; i++) {
                cin >> scores[i] >> status[i];
            }
        }
        int average() {
            int i, inn, sum = 0, avg;
            inn = numinnings();
            for (i = 0 ; i < numofmatches ; i++) {
                sum += scores[i];
            }
            avg = sum / inn;
            return avg;
        }
        void show() {
            int i;
            cout << "Player " << playernum << " has played " << numofmatches << " matches and " << numinnings() <<                 " innings" << '\n';
            cout << "Scores: ";
            for (i = 0 ; i < numofmatches ; i++) {
                cout << scores[i] << ' ';
            }
            cout << '\n';
        }
        void static numberplayers() {
            cout << "Number of Players: " << numplayers << '\n';
        }
        ~Players() {
            numplayers--;
            delete []scores;
            delete []status;
        }
};

int Players::numplayers = 0;

int main() {
    int p1matches, p2matches, p3matches, pno, numofop, x = 1, opnum, nummatches;
    cin >> p1matches >> p2matches >> p3matches;
    Players *players[4] = {nullptr, new Players(p1matches, 1), new Players(p2matches, 2), new Players(p3matches, 3)};
    cin >> numofop;
    while (x <= numofop) {
        cin >> opnum;
        switch(opnum) {
            case 1:
                cin >> pno;
                cout << "Average: " << players[pno]->average() << '\n';
                break;
            case 2:
                cin >> pno;
                players[pno]->show();
                break;
            case 3:
                Players::numberplayers();
                break;
            case 4:
                cin >> pno;
                cout << "Average: " << players[pno]->average() << '\n';
                break;
            case 5:
                cin >> pno;
                delete players[pno];
                players[pno] = 0;
                break;
            case 6:
                cin >> pno >> nummatches;
                if (players[pno]) {
                    delete players[pno];
                }
                players[pno] = new Players(nummatches, pno);
                break;
            case 7:
                cin >> pno;
                players[pno]->readscorestatus();
                break;
        }
        x++;
    }
    return 0;
}

