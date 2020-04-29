#include <iostream>
#include <vector>
#include <regex>
#include <iomanip>

#define AXIOM "E"
#define END "$"

using namespace std;

//  E → E+T | E-T | T
//  T → T*F | T/F | F
//  F → id  | num | (E)

//  E → TT'
//  T'→ +E  | -E  | e
//  T → FF'
//  F'→ *T  | /T  | e | ^T
//  F → id  | num | (E)

vector<vector<string>> grammar =
{
	/*0  E  →*/{ "T", "T'" },
	/*1  T' →*/{ "+", "E" },
	/*2  T' →*/{ "-", "E" },
	/*3  T' →*/{ "" },
	/*4  T  →*/{ "F", "F'" },
	/*5  F' →*/{ "*", "T" },
	/*6  F' →*/{ "/", "T" },
	/*7  F' →*/{ "" },
	/*8  F  →*/{ "id" },
	/*9  F  →*/{ "num" },
	/*10 F  →*/{ "(", "E", ")" },
	/*11  F' →*/{ "^", "T" },
};

vector<string> terminals = { "+", "-", "*", "/", "(", ")", "id", "num","^" };
vector<string> nonTerminals = { "E", "T", "T'", "F", "F'" };

int rulesMatches[5][9] =
{ 		 //  +   -   *   /   (   )  id   num ^
	/*E */{ -1, -1, -1, -1,  0, -1,  0,   0, -1 },
	/*T */{ -1, -1, -1, -1,  4, -1,  4,   4, -1},
	/*T'*/{ 1,  2,  3,  3,  3,  3,  3,   3, 3 },
	/*F */{ -1, -1, -1, -1, 10, -1,  8,   9, -1 },
	/*F'*/{ 7,  7,  5,  6,  7,  7,  7,   7, 11}
};

int searchNextTerminalIndex(string expression, string &lexeme)
{
	for (int i = 0; i < terminals.size(); i++)
	{
		if (expression.substr(0, terminals[i].length()) == terminals[i])
		{
			lexeme = terminals[i];
			return i;
		}
	}

	return string::npos;
}

int searchNonTerminalIndex(string rule)
{
	for (int i = 0; i < nonTerminals.size(); i++)
	{
		if (rule == nonTerminals[i])
		{
			return i;
		}
	}

	return string::npos;
}

bool match(string exp, bool info)
{
	if (info) cout << "Analysis started: " << endl << endl;

	vector<string> stack = { AXIOM, END };
	string expression = regex_replace(exp, regex("\\s"), "");
	int startLength = expression.length() + 1;

	while (stack.size() > 1)
	{
		if (info)
		{
			cout << setw(startLength) << expression << " | ";
			for (auto el : stack)
			{
				cout << el << " ";
			}
			cout << endl;
		}

		string terminalLexeme = "";
		string stackTop = stack[0];

		int terminalIndex = searchNextTerminalIndex(expression, terminalLexeme);

		if (terminalIndex == string::npos && expression != "")
		{
			return false;
		}

		if (terminalLexeme == stackTop)
		{
			stack.erase(stack.begin(), stack.begin() + 1);
			expression = expression.substr(terminalLexeme.length());
			continue;
		}

		int nonTerminalIndex = searchNextTerminalIndex(stackTop, terminalLexeme);

		if (nonTerminalIndex != string::npos) return false;

		nonTerminalIndex = searchNonTerminalIndex(stackTop);

		stack.erase(stack.begin(), stack.begin() + 1);

		if (terminalIndex == string::npos) terminalIndex = 6;

		int ruleIndex = rulesMatches[nonTerminalIndex][terminalIndex];

		if (ruleIndex == string::npos) return false;

		vector<string> newStackTop = grammar[ruleIndex];

		if (newStackTop[0] != "")
			stack.insert(stack.begin(), newStackTop.begin(), newStackTop.end());
	}

	if (info)
	{
		cout << setw(startLength) << expression << " | ";
		for (auto el : stack)
		{
			cout << el << " ";
		}
		cout << endl;
	}

	return expression.length() == 0;
}

vector<string> tests = {
	"id", "num", "(id)", "(id + num)", "(id * id)", "id + id + id * num",
	"idd", "id *", "id +", "(id) *", "(id + num) - (num + id)", "+-", "+",
	"(id - num * id) / (num + num * id)", "(id - num * id) / (num + num * id(",
	"((((num))))", "(((num))", "(num) + (id)", "id / id * id", "idid", "-id"
};

int main()
{
	for (auto test : tests)
	{
		cout << setw(5) << (match(test, false) ? "True" : "False") << " | " << test << "\n";
	}

	cout << endl;

	while (true)
	{
		char expression[256];
		cin.getline(expression, 256);
		cout << (match(expression, true) ? "True" : "False") << endl;
	}
}