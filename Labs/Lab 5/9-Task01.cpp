#include <iostream>

#define deb(x)                std::cout<< #x << ' ' << x << std::endl
#define deb2(x, y)          std::cout<< #x << ' ' << x <<' '<< #y << ' ' << y << std::endl
#define deb3(x, y, z)       std::cout<< #x << ' ' << x << ' '<<#y << ' ' << y << ' ' << #z << ' ' << z << std::endl

class Player {
private:
	//Data member decleration
	const int number;
	int no_of_matches;
	int * scores;
	char * status;
	static int total_players;
	int count_no_of_innings() {
		int count = 0;
		for (int i = 0; i < no_of_matches; i++)
			if (status[i] == 'O')
				count++;
		// deb(count);
		return count;
	}
public:
	//constructor
	Player(int no_of_matches, int player_number) : number(player_number) {
		this->no_of_matches = no_of_matches;
		scores = new int[no_of_matches];
		status = new char[no_of_matches];
		total_players++;
	}

	//Calculate Average
	int average() {
		int score(0);
		for (int i = 0; i < no_of_matches; i++)
			score += scores[i];
		return score / count_no_of_innings();
	}
	//Read function
	void read() {
		for (int i = 0; i < no_of_matches; i++)
			std::cin >> scores[i] >> status[i];
	}
	//display
	void show() {
		std::cout << "Player " << number << " has played "
		          << no_of_matches << " matches and " << count_no_of_innings()
		          << " innings\n";

		std::cout << "Scores: ";
		for (int i = 0; i < no_of_matches; i++)
			std::cout << scores[i] << ' ';
		std::cout << '\n';
	}
	//static function to display total players
	void static get_total_players() {
		std::cout << "Number of Players: " << total_players << '\n';
	}
	//destructor
	~Player() {
		delete [] scores;
		delete [] status;
		total_players--;
	}
};

int Player::total_players = 0;

int main() {
	freopen("input.txt", "r", stdin);
	int n1, n2, n3, var1, var2;
	std::cin >> n1 >> n2 >> n3;
	Player *p[4] = {nullptr, new Player(n1, 1), new Player(n2, 2), new Player(n3, 3)};

	std::cin >> n1;
	while (n1--) {
		std::cin >> var1;
		// deb(var1);
		switch (var1) {
		case (1):
			std::cin >> var2;
			// deb(var2);
			std::cout << "Average: " << p[var2]->average() << '\n';
			break;

		case (2):
			std::cin >> var2;
			// deb(var2);
			p[var2]->show();
			break;

		case (3):
			Player::get_total_players(); break;

		case (4):
			std::cin >> var2;
			// deb(var2);
			std::cout << "Average: " << p[var2]->average() << '\n';
			break;

		case (5):
			std::cin >> var2;
			// deb(var2);
			delete p[var2];
			p[var2] = 0;
			break;

		case (6):
			int var3;
			std::cin >> var2 >> var3;
			// deb2(var2, var3);
			if (p[var2])
				delete p[var2];
			p[var2] = new Player(var3, var2);
			break;

		case (7):
			std::cin >> var2;
			// deb(var2);
			p[var2]->read();
			break;
		}
	}
	return 0;
}