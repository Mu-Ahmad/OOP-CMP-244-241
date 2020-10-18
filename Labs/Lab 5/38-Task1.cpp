#include <iostream>
using namespace std;

class Player{
	const int playerNum;
	int MatchCount;
	int *scores;
	char *scoreStatus;
	int inings=0;
	bool lifeStatus = true;
	static int count;//shows number of players

public:
    Player(int x):playerNum(count+1){
        this->MatchCount = x;
        scores = new int [MatchCount];
        scoreStatus = new char [MatchCount];
        count++;
    }
    
        void getScores(){
        if(lifeStatus == true){ 
        for(int i =0;i<MatchCount;i++)
        cin >> scores[i] >> scoreStatus[i];
   		 }
    }
    int ShowIng(){
        inings =0;
        for(int i=0;i<MatchCount;i++)
        if(scoreStatus[i] == 'O') inings++;
        return inings;
    }
    void calculateAverage(){
        int average,sum = 0;
        if(lifeStatus == true){ 
        for(int i=0;i<MatchCount;i++)
        sum+=scores[i];
        average = sum/ShowIng();
        cout << "Average: "<< average<< endl;
    	}
	}
    
    void showScores(){
        if(lifeStatus == true){ 
        cout << "Scores: ";
        for(int i=0;i<MatchCount;i++)
        cout << scores[i] << " ";
        cout << endl;
    	}
	}
    void deleteplayer(){
        if(lifeStatus == true){ 
        lifeStatus = false;
        count--;
        }
    }
    void createplayer(){
        cin >> MatchCount;
        if(lifeStatus == false){ 
        lifeStatus = true;
        count++;
        }
    }
    
	void showplay(){
    	cout << "Player "<<playerNum << " has played "<< MatchCount << " matches and "<<ShowIng()<<" innings";
    	cout << endl;
	}
	void showplayerCount(){
   		 cout << "Number of Players: "<<count<<endl;
}
};

int Player::count=0;

int main(){
    int matchCount1,matchCount2,matchCount3,operations,choice,i;
    cin >> matchCount1>>matchCount2>>matchCount3;
    Player player[3]= {Player(matchCount1),Player(matchCount2),Player(matchCount3)};
    cin >> operations;
    int playernum,counter;
    for(i=0;i<operations;i++)
    {
    cin >> choice;
    if(choice == 1){
    cin >> playernum;
    player[playernum-1].calculateAverage();    
    }    
    else if(choice == 2){
    cin >> playernum;
    player[playernum-1].showplay();
    player[playernum-1].showScores();
    
    }
    else if(choice == 3){
    player[0].showplayerCount();   
    }
    else if(choice == 4){
    cin >> playernum;
    player[playernum-1].calculateAverage();    
    }
    else if(choice == 5){
    cin >> playernum;
    player[playernum-1].deleteplayer();    
    }
    else if(choice == 6){
    cin >> playernum;
    player[playernum-1].createplayer();    
    }
    else if(choice == 7){
        cin >> playernum;
        player[playernum-1].getScores();
    }    
    }
    return 0;
}
