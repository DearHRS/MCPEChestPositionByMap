/*
Programme to find chest in a chunk

north   = -z
south   = +z
east    = +x
west    = -x

chest spawn in center of chunk ((8,8) relative coordinate from north west corner)
north west corner of chunk is perfectly divisible by 16
*/

#include <iostream>
#include <string>


//gets numeric input
double GetNumericInput(std::string message);

//checks if given string is numeric
bool IsNumeric(std::string givenString);

//gets to closets number divisible by 16
int GetToClosets16Multiple(int givenNumber);


int main()
{
	while (true)
	{
		int x, z;

		std::cout << "enter your coordinates when you are on the chunk with treasure\n";
		
		x = GetToClosets16Multiple((int) GetNumericInput("x = "));
		z = GetToClosets16Multiple((int) GetNumericInput("z = "));

		std::cout << "Chest is at " << (x + 8) << " " << (z + 8) << "\n\n";
	}
    
}

//gets numeric input
double GetNumericInput(std::string message)
{
	while (true)
	{
		std::string givenInput;
		std::cout << message;
		std::cin >> givenInput;

		if (IsNumeric(givenInput)) {
			return std::stod(givenInput);
		}
		else {
			std::cout << "\tError: >" + givenInput + "< isn't numeric.\n\n";
		}
	}
}

//checks if given string is numeric
bool IsNumeric(std::string givenString)
{
	unsigned int pointCounter = 0;	//counter for how many times point char is met in given string

	//checking if last char is point
	if (givenString[givenString.size() - 1] == '.') {
		return false;
	}

	//going over every char in string and checking if such char is allowed for numeric number
	for (unsigned int i = 0; i < givenString.size(); i++) {
		switch (givenString[i]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '-':
			continue;

		case '.':
			pointCounter++;
			if (pointCounter > 1) {
				return false;
			}
			continue;

		default:
			return false;
		}
	}

	return true;
}

//gets to closets number divisible by 16
int GetToClosets16Multiple(int givenNumber)
{
	//readjusting given number to higher level of 16 multiple if negative
	if (givenNumber < 0) {
		givenNumber -= 16;
	}

	return givenNumber - (givenNumber % 16);	
}