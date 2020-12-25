// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)
// ==========================Task3============================
#include "Exam.cpp"


int main() {
	srand(time(0));
	Exam problems;
	for (int i = 0; i < 10; i++) {
		std::cout << "Problem " << i + 1 << ": \n";
		problems.problems[i]->displayProblem();
		problems.problems[i]->askUserForAnswer();
	}
	int total = 0;
	for (int i = 0; i < 10; i++) {
		std::cout << "-------------\nProblem " << i + 1 << ": ";
		problems.problems[i]->displayProblem();
		std::cout << "Correct Ans: ";
		problems.problems[i]->displayFraction(problems.problems[i]->correctAnswer);
		std::cout << "\nYour Ans: ";
		problems.problems[i]->displayFraction(problems.problems[i]->userAnswer);


		if (problems.problems[i]->isCorrect) {
			std::cout << "\nCorrect Answer!\n";
			total++;
		}
		else
			std::cout << "\nWrong Answer!\n";
	}

	std::cout << "\n-------------------\nCorrect Answers Percentage: " << (total / 5.0) * 100 << "%\n";
	return 0;
}