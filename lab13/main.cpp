#include <string>
#include <iostream>
#include <regex>
#include<windows.h>

#define START_STATE 0
#define END_STATE 6

using namespace std;

// (a|b)*(cd*e)*
int statesAccess[7][7] =
{ 	 //start  a  b  c  d  e  end
/*start*/{ 0, 1, 1, 1, 0, 0, 1 },
	/*a*/{ 0, 1, 1, 1, 0, 0, 1 },
	/*b*/{ 0, 1, 1, 1, 0, 0, 1 },
	/*c*/{ 0, 0, 0, 0, 1, 1, 0 },
	/*d*/{ 0, 0, 0, 0, 1, 1, 0 },
	/*e*/{ 0, 0, 0, 1, 0, 0, 1 },
  /*end*/{ 0, 0, 0, 0, 0, 0, 0 }
}; //column - from, row - to;

bool match(string input)
{
	int position = START_STATE, currentState = START_STATE;
	int nextState = input.length() ? (input[position++] - 'a' + 1) : END_STATE;

	for (int i = 0; i < input.length(); i++)
	{
		if (statesAccess[currentState][nextState])
		{
			currentState = nextState;
			nextState = (input[position++] - 'a' + 1);
		}
		else return false;
	}

	nextState = END_STATE;

	return statesAccess[currentState][nextState];
}

vector<string> tests{
	"","a","b","c", "d","e", "de", "cde", "acde", "aacde", "bbcdeed",
	"bbcdee", "aaa", "dd", "abc", "acacac", "acacacd", "abbbccc",
	 "dedede", "dedeedeee", "bbbbb", "bc", "bcd"
};

void writeTest(string input)
{
	cout  << input << "; Результат: "  << (match(input) ? "True" : "False")<<endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < tests.size(); i++)
		writeTest(tests[i]);

	while (true)
	{
		char name[256];
		cin.getline(name, 256);
		writeTest(name);
	}
	system("pause");
	return 0;
}
