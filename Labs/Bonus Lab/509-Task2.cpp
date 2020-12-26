#include <iostream>
#include <iomanip>

template<typename Type1, typename Type2>
void Sum(Type1 x, Type2 y) {
	std::cout << std::setw(5) << std::left << x << " +  "
	          << std::setw(5) << y << " = "
	          << std::setw(5) << x + y << '\n';
}

template<>
void Sum(std::string x, std::string y) {
	std::cout << "Calling string Specialized template of Sum for std::string...\n";
	std::cout << "\"" << x << "\" +  "
	          << "\"" << y << "\" = "
	          << "\"" << x + y << "\"\n";
}

template<typename Type1, typename Type2>
void Subtraction(Type1 x, Type2 y) {
	std::cout << std::setw(5) << x << " -  "
	          << std::setw(5) << y << " = "
	          << std::setw(5) << x + y << '\n';
}


template<>
void Subtraction(std::string x, std::string y) {
	std::cout << "Calling string Specialized template of Subtraction for std::string...\n";

	std::string final = x;
	int it = final.find(y);

	if (it != std::string::npos)
		final.erase(it, y.length());

	std::cout << "\"" << x << "\" -  "
	          << "\"" << y << "\" = "
	          << "\"" << final << "\"\n";
}

int main() {
	int x = 9, y = 56;
	float a = 7.8, b = 80.9;
	double g = 4.98, h = 97.97;
	std::cout << "Displaying Sum Function---------------------\n";
	Sum(x, y);
	Sum(a, b);
	Sum(g, h);
	Sum(g, y);
	Sum(a, h);
	Sum(x, g);
	std::cout << "Displaying Subtraction Function---------------------\n";
	Subtraction(x, y);
	Subtraction(b, a);
	Subtraction(g, h);
	Subtraction(y, g);
	Subtraction(a, h);
	Subtraction(x, g);
	std::cout << "-------------------------------\n";
	std::string str1 = "Hello I hope you are fine! ";
	std::string str2 = "how is your brother?";
	Sum(str1, str2);
	std::cout << "-------------------------------\n";
	str2 = "hope ";
	Subtraction(str1, str2);
	return 0;
}