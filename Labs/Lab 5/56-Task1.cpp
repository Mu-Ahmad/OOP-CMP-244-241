#include<iostream>
#include<string>

using namespace std;

class player
{
    private:
        //Private Data members
        
        const int PLAYER_NUMBER;
        int number_of_matches, *scores;
        char *status;
        
        
        //Private member function
        int count_innings(void)
        {
            int idx, count = 0;

            for(idx = 0; idx < number_of_matches; idx++)
            {
                if(this->status[idx] == 'O')
                {
                    count++;
                }
            }
            
            return count;
        }
        int total_score(void)
        {
            int total_score = 0;
            for(int idx = 0; idx < number_of_matches; idx++)
            {
                total_score += scores[idx];
            }
            return total_score;
        }
    public:
        static int number_of_players;
       //constructor
        player(int number_of_matches, int player_number) : PLAYER_NUMBER(player_number)
        {
            int idx;

            this->number_of_matches = number_of_matches;
            this->scores = new int [number_of_matches];
            this->status = new char [number_of_matches];
            number_of_players++;
        }
       
        //Member functions
        void read_scores_status(void) //?
        {
            int idx;
            for(idx = 0; idx < number_of_matches; idx++)
            {
                cin>>scores[idx]>>status[idx];
            }
        }

        float player_average(void)
        {
            int innings, scores;
            float average;

            innings = count_innings();
            scores = total_score();
            average = scores/innings;

            return average;
        }

        void show(void)
        {
            int idx;
            cout<<"Player " <<PLAYER_NUMBER<<" has played "<<number_of_matches<<" matches and "<<count_innings() <<" innings\n";
            cout<<"Scores: ";
            for(idx = 0; idx < number_of_matches; idx++)
            {
                cout<<this->scores[idx]<<' ';
            }
            cout<<'\n';
        }

        static int n_of_players (void)
        {
            return number_of_players;
        }

    //Destructor
    ~player(void)
    {
        delete [] scores;
        delete [] status;
        number_of_players--;
    }

};

int player::number_of_players = 0; //Initialize the static member

int main(void) 
{
    int p1, index, p2, p3, operations, idx, sel, player_number, average;
    player *players[3];
    
    cin>>p1>>p2>>p3;
    
    players[0] = new player(p1, 1);
    players[1] = new player(p2, 2);
    players[2] = new player(p3, 3);
    
   cin>>operations;
    
    for(idx = 0; idx < operations; idx++)
    {
        cin>>sel;
        switch(sel)
        {
            case 1:
                cin>>player_number;
                player_number--;
                average = players[player_number]->player_average();
                cout<<"Average: "<<average<<'\n';
                break;
            case 2:
                cin>>player_number;
                player_number--;
                players[player_number]->show();
                break;
            case 3:
                cout<<"Number of Players: "<<player::n_of_players()<<"\n";
                break;
            case 4:
                 cin>>player_number;
                 player_number--;
                average = players[player_number]->player_average();
                cout<<"Average: "<<average<<'\n';
                break;
            case 5:
                cin>>player_number;
                player_number--;
                    delete players[player_number];
                break;
            case 6:
                int match;
                cin>>player_number>>match;
                player_number--;
                players[player_number] = new player(match, player_number);
                break;
            case 7:
                cin>>player_number;
                player_number--;
                players[player_number]->read_scores_status();
                break;
            default:
                cout<<"Invalid input";
                break;
        }
    }
    return 0;
}