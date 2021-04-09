/*
Name: Muhammad Ahmad
Roll: BCSF19M509
*/

#include <iostream>
#include "Stack.cpp"

using namespace std;

char closingBracketOf(char bracket) {
	switch (bracket) {
	case '(': return ')';
	case '{': return '}';
	case '[': return ']';
	}
}

bool isOpeningBracket(char bracket) {
	return (bracket == '(' or bracket == '[' or bracket == '{');
}

bool isBracket(char bracket) {
	return (bracket == '(' or bracket == '[' or bracket == '{' or bracket == ')' or bracket == ']' or bracket == '}');
}

bool checkParenthesis(const char *exp) {
	Stack <char> stack(100);
	try {
		for (int i = 0; exp[i] != 0; i++)
			if (isOpeningBracket(exp[i])) {
				stack.push(exp[i]);
			}
			else if (exp[i] == closingBracketOf(stack.seeTop())) {
				stack.pop();
			}
			else if (isBracket(exp[i])) {
				return false;
			}
	} catch (int i) {
		return false;
	}
	return stack.isEmpty();
}


int main() {
	string ans; // Dont comment this line
	cout << "----------------------------------------------------------\n";

	string str = "[x+{(y+z)*(y-x)+((x+y(2*z)))}]";
	string str1 = "{(y+z)*(y-x)]";
	string str2 = "(X+y))";
	(checkParenthesis(str.c_str())) ? ans = "Correct Expression" : ans = "In-Correct Expression";
	cout << str << " : " << ans << '\n';
	cout << "----------------------------------------------------------\n";

	(checkParenthesis(str1.c_str())) ? ans = "Correct Expression" : ans = "In-Correct Expression";
	cout << str1 << " : " << ans << '\n';
	cout << "----------------------------------------------------------\n";

	(checkParenthesis(str2.c_str())) ? ans = "Correct Expression" : ans = "In-Correct Expression";
	cout << str2 << " : " << ans << '\n';
	cout << "----------------------------------------------------------\n";

	// uncomment following to read input
	// string expression;
	// cout << "\nEnter Expression: ";
	// getline(cin, expression);
	// (checkParenthesis(expression.c_str())) ? ans = "Correct Expression" : ans = "In-Correct Expression";
	// cout << expression << " : " << ans << '\n';
	// cout << "----------------------------------------------------------\n";
	return 0;
}
