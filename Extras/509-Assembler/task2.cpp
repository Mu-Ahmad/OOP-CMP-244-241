/* =================================================================
Name 	: Muhammad Ahmad
Roll No : BCSF19M509

Hack Assembler: This is two pass version of hack assembler extending
the last version, it translates the hack assembly code with any
symbols or variables and generates a .hack file if translation if
successfull.
(The Assembler logs appropriate error messages with line no and
 possible reason causing error in console. Some examples are shown
 in screenshots)
================================================================= */

#include <bitset>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <unordered_map>

// ======================Lookup-Tables===========================
std::unordered_map <std::string, std::string> computation = {
	{"0", "101010"}, {"1", "111111"}, {"-1", "111010"}, {"D", "001100"}, {"A", "110000"}, {"!D", "001101"},
	{"!A", "110001"}, {"-D", "001111"}, {"-A", "110011"}, {"D+1", "011111"}, {"1+D", "011111"}, {"A+1", "110111"}, {"1+A", "110111"}, {"D-1", "001110"},
	{"A-1", "110010"}, {"D+A", "000010"}, {"A+D", "000010"}, {"D-A", "010011"}, {"A-D", "000111"}, {"D&A", "000000"}, {"D|A", "010101"}, {"A&D", "000000"}, {"A|D", "010101"}
};
std::unordered_map <std::string, std::string> destination = {
	{"null", "000"}, {"M", "001"}, {"D", "010"}, {"MD", "011"}, {"A", "100"}, {"AM", "101"}, {"AD", "110"}, {"AMD", "111"}
};
std::unordered_map <std::string, std::string> jump = {
	{"null", "000"}, {"JGT", "001"}, {"JEQ", "010"}, {"JGE", "011"}, {"JLT", "100"},	{"JNE", "101"}, {"JLE", "110"}, {"JMP", "111"}
};
std::unordered_map <std::string, std::string> symbol_table = {
	{"R0", "0"}, {"R1", "1"}, {"R2", "2"}, {"R3", "3"}, {"R4", "4"}, {"R5", "5"}, {"R6", "6"}, {"R7", "7"}, {"R8", "8"},
	{"R9", "9"}, {"R10", "10"}, {"R11", "11"}, {"R12", "12"}, {"R13", "13"}, {"R14", "14"}, {"R15", "15"},
	{"SCREEN", "16384"}, {"KBD", "24576"}, {"SP", "0"}, {"LCL", "1"}, {"ARG", "2"}, {"THIS", "3"}, {"THAT", "4"}
};

class Assembler {
	std::string fileIn, fileOut, command, status;
	int line;

	bool is_number(const char* s) const { //this subroutine returns true if the string only consists of integers i.e is a number
		return strspn(s, "0123456789") == strlen(s);
	}

	bool stripLine(std::string& command) const { //This sub routine strips whitspace and remove comments
		if (command.find("//") != std::string::npos)
			command.assign(command.begin(), command.begin() + command.find("//")); //Strip the comments from command string
		//Syntax Help from -> https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Erase-Remove
		command.erase(std::remove(command.begin(), command.end(), ' '), command.end()); 	//Remove all the spaces from string
		command.erase(std::remove(command.begin(), command.end(), '\t'), command.end());	//Remove all the tabs from string
		command.erase(std::remove(command.begin(), command.end(), '\r'), command.end());	//Remove all the carriage return character from string
		if (command.length() == 0)
			return false;
		return true;
	}

	//This subroutine loops over input file line by line and if it encounters any labels, it adds them to the symbol table
	void resolve_symbols() const {
		std::ifstream inputFile(fileIn);
		std::string command;
		int pc = 0; //Keep count of the no. of hack assembly commands in script i.e ignoring empty lines, comments and labels
		while (getline(inputFile, command)) {
			if (!this->stripLine(command))	//this private method returns true and a hack assembly statement(in command string) after removing white spaces and comments or returns false if there is no hack assembly command
				continue;
			pc++;
			//label variable
			if (command[0] == '(') {
				command.assign(command.begin() + 1, command.end() - 1);
				symbol_table[command] = std::to_string(--pc);
			}
		}
		inputFile.close();
	}

	bool generate_binary_file() {
		this->resolve_symbols(); //First Pass, this subroutine will add all labels to the symbol table
		std::ifstream inputFile(fileIn);
		std::ofstream outputFile(fileOut);
		std::string command;
		int value = 16; //Keep track of the memory allocation to variables
		while (getline(inputFile, command)) { //loops over input file line by line, process it and store the translated binary in a .hack file
			this->line++;
			this->command = command;
			if (!this->stripLine(command) or  command[0] == '(')
				continue; //In case we encounter an empty line or comment line or label
			if (command[0] == '@' and !this->is_number(command.c_str() + 1)) { //Detects a variable
				command.assign(command.begin() + 1, command.end());
				if (symbol_table.find(command) == symbol_table.end()) { //If the variable is encountered first time, itis mapped to an aprropriate memory location
					symbol_table[command] = std::to_string(value++);
				}
				command = '@' + symbol_table[command]; //Replace variable with the memory loactaion it points to
			}
			command = this->translate_command(command);  //This method identifies the Hack assembly command and translate it accordingly into hack machine code
			if (command.size() != 16) { //If the Command is not valid it will not be translated to 16 bit binary hack instruction thus returning false, indicating an error
				this->status = command;
				return false;
			}
			outputFile << command << '\n';
		}
		inputFile.close();
		outputFile.close();
		return true;
	}

	std::string to_binary_string(const int& number) const { //this subroutine converts an input integer into 16 bit binary string making use of bitset datastructure
		return std::bitset<16>(number).to_string();
	}

	std::string translate_command(std::string command)  const {
		// A-command
		if (command[0] == '@') {
			command.assign(command.begin() + 1, command.end());
			return this->to_binary_string(std::stoi(command));
		}
		std::string ans = "111"; //In case of C-command first three bits are fixed-(111)
		if (command.find("=") != std::string::npos) {
			if (command.find(";") == std::string::npos)
				command = command + ";null";
		}
		else if (command.find(";") != std::string::npos)
			command = "null=" + command;
		else
			return "Invalid Comment(format)......";

		std::string temp(command.begin() + command.find("=") + 1, command.begin() + command.find(";")); //Extracting computation part from command string
		//if computation part has 'M', '1' is appended to answer string and 'M' is replaced by 'A' and then used to lookup remaining 6-bit binary in computation map
		if (temp.find("M") != std::string::npos) {
			ans += "1";
			temp[temp.find("M")] = 'A';
		}
		else ans += "0";
		ans += computation[temp]; // appending 6-bit binary against computation in ans string
		if (ans.size() != 10) return "Invalid Computation...... \"" + temp + "\"";
		temp.assign(command.begin(), command.begin() + command.find("=")); //Extracting destination part from command string
		ans += destination[temp]; // appending 3-bit binary against destination in ans string
		if (ans.size() != 13) return "Invalid Destination...... \"" + temp + "\"";
		temp.assign(command.begin() + command.find(";") + 1, command.end()); //Extracting jump part from command string
		ans += jump[temp]; // appending 3-bit binary against jump in ans string
		if (ans.size() != 16) return "Invalid Jump or Invalid Comment(format)...... \"" + temp + "\"";
		return ans;
	}
public:
	Assembler(std::string fileIn) {
		this->fileIn = this->fileOut = fileIn;
		this->fileOut.replace(fileOut.length() - 3, 3, "hack"); //Creates name of output file from input file name
	}

	void translate()  {
		//Checks if the file with input address exists and proceed accordingly
		std::ifstream inputFile(fileIn);
		if (inputFile.fail()) {
			std::cout << "Did not find the file with the this name!";
			return;
		}
		inputFile.close();
		if (this->generate_binary_file()) //this sub-routine opens input file and translate the commands and generate a .hack file conatining the translated binary instructions
			std::cout << "  --------------------------------------------------------------------------------\n"
			          << "  | Assembly code translated to binary code and .hack file created successfully! |"
			          << "\n  --------------------------------------------------------------------------------\n";
		else {
			std::cout << "\t---------------------\n"
			          << "\t|Error : LINE " << std::setw(5) << this->line
			          << " |\n\t---------------------\n"
			          << "Unable to Understand statement -> " << this->command
			          << "\n\n\t<<<< Diagnostic Message >>>>\n" << this->status << '\n'
			          << "\n  ---------------------------------------------------\n"
			          << "  | Assembly code couldn't be translated to binary! |"
			          << "\n  ---------------------------------------------------\n";
			remove(fileOut.c_str()); //Remove the outputfile
		}
	}
};

int main() {
	//Input file name and check if its with valid extension
	std::string fileIn;
	std::cout << "Enter the file name: ";
	std::cin >> fileIn;
	if (fileIn.find("asm") == std::string::npos) {
		std::cout << "The program only works with .asm files.\nEnter a valid file address......\n--------------------------\n";
		return main();
	}
	Assembler a(fileIn);
	a.translate();
	std::cout << "press any key to exit............";
	std::cin.ignore(); std::cin.get();
	return 0;
}