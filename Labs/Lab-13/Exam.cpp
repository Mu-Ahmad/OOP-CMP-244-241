#include "DoublingMathProblem.cpp"

class Exam {
public:
	MathProblem** problems;
	Exam() {
		problems = new MathProblem*[10];
		for (int i = 0; i < 10; i++) {
			if (rand() % 2) {
				problems[i] = new MathProblem();
				problems[i]->setProblem();
			}
			else {
				Fraction temp;
				temp.setNominator(rand() % 9 + 1);
				temp.setDeNominator(rand() % 9 + 1);
				problems[i] = new DoublingMathProblem();
				problems[i]->setProblem(temp);
			}
		}
	}
};