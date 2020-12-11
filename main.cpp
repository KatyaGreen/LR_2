#include <iostream>
#include <stack>
using namespace std;

int prioritySet(const char current) {
	switch (current) {
	case 40:
		return 1;
		break;
	case 41:
		return 1;
		break;
	case 42:
		return 3;
		break;
	case 43:
		return 2;
		break;
	case 45:
		return 2;
		break;
	case 47:
		return 3;
		break;
	}
	return 0;
}

bool isNumber(char current) {
	return current >= 48 && current <= 57;
}
bool isOpSymbol(char current) {
	return current >= 42 && current <= 47;
}
bool isOpenBracket(char current) {
	return current == 40;
}
bool isCloseBracket(char current) {
	return current == 41;
}
void printNum(char number) {
	cout << number;
}
void printAndDelete(stack <char>& toPrint){
	cout << toPrint.top();
	toPrint.pop();
}
void printAndEditBracketContent(stack <char>& toEdit) {
	while (!isOpenBracket(toEdit.top())) {
		printAndDelete(toEdit);
	}
	toEdit.pop();
}
void printIfHighPriorityAndPush(stack <char>& toEdit, char current){             
	while (!toEdit.empty() && prioritySet(toEdit.top()) >= prioritySet(current)) {
		printAndDelete(toEdit);
	}
	toEdit.push(current);
}

int main() {
	stack<char> bufferStack;
	char current;
	while (cin.get(current) && current != '\n') { 

		if (isNumber(current)) {
			printNum(current);
		} else if (isOpSymbol(current)) {
			printIfHighPriorityAndPush(bufferStack, current);
		} else if (isOpenBracket(current)) {
			bufferStack.push(current);
		} else if (isCloseBracket(current)) {
			printAndEditBracketContent(bufferStack);
		}
	}

	while (!bufferStack.empty()) {
		printAndDelete(bufferStack);
	}

	return 0;
}
