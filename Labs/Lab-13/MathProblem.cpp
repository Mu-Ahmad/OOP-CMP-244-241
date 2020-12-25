#pragma once

#include <iostream>
#include <ctime>
#include "fraction.cpp"

std::string Operations[4] = {"+", "-", "*", "/"};

class MathProblem {
public:
	Fraction operand1, operand2, userAnswer, correctAnswer;
	bool isCorrect;
	char operation;
	virtual void setProblem(Fraction& other) {}
	void setProblem() {
		operand1.setNominator(rand() % 9 + 1);
		operand1.setDeNominator(rand() % 9 + 1);
		operand2.setNominator(rand() % 9 + 1);
		operand2.setDeNominator(rand() % 9 + 1);
		operation = Operations[rand() % 4].c_str()[0];
		switch (operation) {
		case ('+'):
			correctAnswer = operand1 + operand2;
			break;
		case ('*'):
			correctAnswer = operand1 * operand2;
			break;
		case ('-'):
			correctAnswer = operand1 - operand2;
			break;
		case ('/'):
			correctAnswer = operand1 / operand2;
			break;
		}
		userAnswer.setNominator(0);
		isCorrect = false;
	}

	void displayFraction(Fraction& other) {
		std::cout << other.getnominator() << "/" << other.getdenominator();
	}

	void displayProblem() {
		std::cout << operand1.getnominator() << "/" << operand1.getdenominator() << " "
		          << operation << " " << operand2.getnominator() << "/" << operand2.getdenominator() << "\n";
	}

	void askUserForAnswer() {
		std::cout << "Write Your Answer in Fraction: i.e.(2/7)";
		int temp;
		char ch;
		std::cin >> temp;
		userAnswer.setNominator(temp);
		std::cin >> ch;
		std::cin >> temp;
		userAnswer.setDeNominator(temp);
		isCorrect = checkAnswer(userAnswer);
	}

	bool checkAnswer(Fraction& other) {
		return (correctAnswer.getnominator() == other.getnominator() and
		        correctAnswer.getdenominator() == other.getdenominator());
	}
};