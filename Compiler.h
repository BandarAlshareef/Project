#include <iomanip>
#include <stack>
#include <stdio.h>
#include <string> 
#include <sstream>
#include <iostream>

using namespace std;

string right_part[5][3] = {
	{ "R", "=", "L" },
	{ "", "", "R" },
	{ "", "R", "*" },
	{ "", "", "id" },
	{ "", "", "L" }
};

string shiftStack[14][7];
string language[7] = { "id", "*", "=", "$", "S", "L", "R" };
string terminals[4] = { "id", "*", "=", "$" };

int left_part[5] = { 4, 4, 5, 5, 6 };

string grammer[14][7] = {
	{ "s5", "s4", "E", "E", "1", "2", "3" },
	{ "E", "E", "E", "acc", "E", "E", "E" },
	{ "E", "E", "s6", "r5", "E", "E", "E" },
	{ "E", "E", "E", "r2", "E", "E", "E" },
	{ "s5", "s4""E", "E", "E", "E", "8", "7" },
	{ "E", "E", "r4", "r4", "E", "E", "E" },
	{ "s12", "s11", "E", "E", "E", "10", "9" },
	{ "E", "E", "r3", "r3", "E", "E", "E" },
	{ "E", "E", "r5", "r5", "E", "E", "E" },
	{ "E", "E", "E", "r1", "E", "E", "E" },
	{ "E", "E", "E", "r5", "E", "E", "E" },
	{ "s12", "s11", "E", "E", "E", "10", "13" },
	{ "E", "E", "E", "r4", "E", "E", "E" },
	{ "E", "E", "E", "r5", "E", "E", "E" }
};



string get_string(string inp) {
	string returned;
	for (int i = 0; i < inp.length(); i++) {
		if (isalpha(inp[i])) returned += inp[i];
		if (inp[i] == '=') returned += inp[i];
		if (inp[i] == '*') returned += inp[i];
	}
	return returned;
}

void writer(string stack, string input, string action) {
	cout << left << setw(15) << stack;
	cout << left << setw(15) << input;
	cout << left << setw(15) << action;
	cout << endl;
}

string readInput(string ary[100], int s) {
	string rtrn;
	for (int i = s; i<100; i++)
		rtrn += ary[i] + " ";

	return rtrn;
}

bool check_if_terminal(string terminal) {
	for (int j = 0; j<4; j++) {
		if (terminals[j] == terminal) {
			return true;
		}
	}
	return false;
}

int get_position_of_input(string input) {
	for (int i = 0; i <= 7; i++) {
		if (input == language[i])
			return i;
	}
}

int convert_stack_to_number(string inp) {
	size_t index = inp.find_last_not_of("0123456789");
	string result = inp.substr(index + 1);
	if (result != "")
		return stoi(result);
	else
		return 0;
}

string get_stack_top(stack<std::string> myStack) {
	string str;
	while (!myStack.empty())
	{
		str = myStack.top() + str;
		myStack.pop();
	}
	return str;
}

std::string toString(int number) {
	std::ostringstream oss;
	oss << number;
	return oss.str();
}


