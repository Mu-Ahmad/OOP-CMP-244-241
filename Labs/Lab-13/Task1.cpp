// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)
// ==========================Task1============================
#include "MathProblem.cpp"

int main() {
	srand(time(0));
	MathProblem problems[5];
	for (int i = 0; i < 5; i++)
		problems[i].setProblem();

	for (int i = 0; i < 5; i++) {
		std::cout << "Problem " << i + 1 << ": \n";
		problems[i].displayProblem();
		problems[i].askUserForAnswer();
	}
	int total = 0;
	for (int i = 0; i < 5; i++) {
		std::cout << "-------------\nProblem " << i + 1 << ": ";
		problems[i].displayProblem();
		std::cout << "Correct Ans: ";
		problems[i].displayFraction(problems[i].correctAnswer);
		std::cout << "\nYour Ans: ";
		problems[i].displayFraction(problems[i].userAnswer);
		if (problems[i].isCorrect) {
			std::cout << "\nCorrect Answer!\n";
			total++;
		}
		else
			std::cout << "\nWrong Answer!\n";
	}

	std::cout << "\n-------------------\nCorrect Answers Percentage: " << (total / 5.0) * 100 << "%\n";

	return 0;
}