#include "MathProblem.cpp"

class DoublingMathProblem: public MathProblem {
public:
	void setProblem(Fraction& other) {
		operation = '+';
		operand1.setNominator(other.getnominator());
		operand1.setDeNominator(other.getdenominator());
		operand2.setNominator(other.getnominator());
		operand2.setDeNominator(other.getdenominator());
		correctAnswer = operand1 + operand2;
	}

};