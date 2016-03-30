#include <iostream>
#include <iomanip>
#include <stack>
#include <sstream>
#include "Compiler.h";
using namespace std;

int main() {

	string input[100];
	string helper_variable;
	cout << "Plase Enter Expression with space: " << endl;

	string line;
	getline(cin, line);

	istringstream iss(line);
	int i = 0;
	while (iss >> helper_variable) {
		input[i] = helper_variable;
		i++;
	}

	input[i] = "$";

	cout << endl;

	stack<std::string> stack;
	stack.push("0");

	int counter = 0;
	while (counter < 100) {
		if (!check_if_terminal(input[counter])) {
			cout << "Input not accepted" << endl;
			system("pause");
			return 0;
		}
		else {
			string stack_top = stack.top();

			int top_no = convert_stack_to_number(stack_top);

			int postion = get_position_of_input(input[counter]);

			string required_action = grammer[top_no][postion];

			int actionNo = convert_stack_to_number(required_action);

			switch (required_action.at(0)) {
			case 's':
				writer(get_stack_top(stack), readInput(input, counter), "Shift" + toString(actionNo));
				stack.push(input[counter] + toString(actionNo));

				counter++;

				break;
			case 'r': {
						  writer(get_stack_top(stack), readInput(input, counter), "Reduce" + toString(actionNo));

						  for (int i = 0; i < 3; i++) {
							  if (right_part[actionNo - 1][i] == "") {
								  continue;
							  }
							  else {
								  string top_element = get_string(stack_top);
								  if (top_element == right_part[actionNo - 1][i]) {
									  stack.pop();
									  stack_top = stack.top();
								  }
							  }
						  }

						  string temp = language[left_part[actionNo - 1]] + grammer[convert_stack_to_number(stack_top)][left_part[actionNo - 1]];
						  stack.push(temp);
			}
				break;
			case 'a':
				writer(get_stack_top(stack), readInput(input, counter), "acc");
				cout << endl << "Accepted" << endl;
				system("pause");
				return 0;
			default:
				writer(get_stack_top(stack), readInput(input, counter), "ERROR");
				cout << endl << "not Accepted" << endl;
				system("pause");
				return 0;

			}

		}

	}

	system("pause");

	return 0;
}