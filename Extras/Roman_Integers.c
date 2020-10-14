//If you have any issue understanding any part or you observe any misfunctioning
//makesure to raise an issue
#include<stdio.h>
#include<string.h>

int arr[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const char *rom[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

//Max INT == 3999

//Function prototypes

void getRomanItr(int num); // This function convert int to roman iteratively
void getRomanRec(int num, int offSet); //This function convert int to roman recurrsively
int getInt(char * roman); //This function converts the valid Roman string into Integer
int getindex(char digit); //helper function for sanity checking and converting to int
void getValidString(char * prompt, char * roman); //Sanity check for the input string
/*********************************************************************************
getInt() function convert the Valid Roman number to equivalent, there is no way
for it to know if the given input is valid or not. getValidString(char *, char *)
is an experimental function that pre process the input string to check if the
input string is a valid one. I integrate number of tests to determine the goodness
of the string, by no means that function is complete and 100% accurate. Try using
getInt() without sanity check it will return unexpected result like XXXX = 40
although XXXX is not a valid Roman number
**********************************************************************************/
//Functionalitty
void intToRoman();
void romanToInt();
void addRomans();
void printTable();

int main() {
	int c;
	while (1) {
		printf("Enter 1 to Convert from Integer to Roman.\n");
		printf("Enter 2 to Convert from Roman to Integer.\n");
		printf("Enter 3 to Add two Romans.\n");
		printf("Enter 4 to print Integer to Romans Table.\n");
		printf("Enter 5 to Exit.\n");
		scanf("%d", &c);
		switch (c) {
		case (1):
			intToRoman();
			break;
		case (2):
			romanToInt();
			break;
		case (3):
			addRomans();
			break;
		case (4):
			printTable();
			break;
		case (5):	return 0;

		}
	}
}

//Maximum Roman Number 3999
void getRomanItr(int num) {
	for (int i = 12; num > 0; ) {
		if (num >= arr[i]) {
			num = num - arr[i];
			printf("%s", rom[i]);
		}
		else {
			i--;
		}
	}
	printf("\n");
}

void getRomanRec(int num, int offSet) {
	//basecase
	if (num == 0) {
		// printf("\n");
		return;
	}
	// recursive case
	int num1 = arr[offSet];
	if (num1 <= num) {
		printf("%s", rom[offSet]);
		getRomanRec(num - num1, offSet);
	}
	else
		getRomanRec(num, offSet - 1);
}

//This function converts the valid Roman string into Integer
int getInt(char * roman) {
	int len = strlen(roman);
	int num = 0;
	int offset = -1;
	for (int i = len - 1; i >= 0; i--) {
		int index = getindex(roman[i]);
		if (index >= offset)
			num += arr[index];
		else
			num -= arr[index];
		offset = index;
	}
	return num;
}

//helper function for sanity checking and converting to int
int getindex(char digit) {
	for (int i = 12; i >= 0; i -= 2)
		if (digit == rom[i][0]) {
			// printf("%c : %d\n", digit, i);
			return i;
		}
	return -1;
}

//Sanity check for the input string
void getValidString(char * prompt, char * roman) {
	printf("%s", prompt);
	fflush(stdin);
	gets(roman);
	int len = strlen(roman);
	int indexArray[len];
	for (int i = 0 ; i < len; i++) {
		int temp = getindex(roman[i]);
		if (temp == -1) {
			printf("You Have Entered the Invalid Roman Number\n");
			return getValidString(prompt, roman);
		}
		indexArray[i] = temp;
	}
	int equal = 0;
	int previous = indexArray[0];
	for (int i = 0 ; i < len; i++) {
		if (previous == indexArray[i])
			equal++;
		else
			equal = 1;
		int temp = indexArray[i] - previous;
		if (temp > 0 && (previous % 4 || temp > 4) || equal > 3) {
			printf("You Have Entered the Invalid Roman Number\n");
			return getValidString(prompt, roman);
		}
		previous = indexArray[i];
		// printf("%d ", indexArray[i]);
	}
	// printf("\n");
}


//Functionalitty

void intToRoman() {
	printf("Enter an Integer: (1-3999): \n");
	int num; scanf("%d", &num);
	if (num < 1 || num > 3999) {
		printf("Enter the number in range.\n");
		intToRoman();
		return;
	}
	printf("Using Iterative function: ");
	getRomanItr(num);
	printf("Using Recursive function: ");
	getRomanRec(num, 12);
	printf("\n\n");
}

void romanToInt() {
	char roman[10];
	getValidString("Enter Roman Number:", roman);
	printf("%d\n\n", getInt(roman));
}

void addRomans() {
	char roman1[10];
	char roman2[10];
	getValidString("Enter First Roman Number:", roman1);
	getValidString("Enter Second Roman Number:", roman2);
	int num1 = getInt(roman1);
	int num2 = getInt(roman2);
	if (num1 + num2 > 3999) {
		printf("It exceeds the limit max number that can be represented is: ");
		getRomanRec(3999, 12); printf("(3999)");
	}
	else {
		printf("Sum of %s(%d) and %s(%d) is: ", roman1, num1, roman2, num2);
		getRomanRec(num1 + num2, 12); printf("(%d)\n\n", num1 + num2);
	}
}

void printTable() {
	printf("--------------------\n");
	printf("|Integer | Roman   |\n");
	for (int i = 0; i < 13; i++) {
		printf("--------------------\n");
		printf("|  %-6d|   %5s |\n" , arr[i], rom[i]);
	}
	printf("--------------------\n");
}
