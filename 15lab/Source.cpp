#include <iostream>
#include <vector>
#include<Windows.h>
#include<string>

using namespace std;

/*
1.E > E+T
2.E > ET
3.E > T
4.T > T*F
5.T > T/F
6.T > F
7.F > (E)
8.F > id
9.F > num
10.F > -E

*/

int main() {
	cout.setf(ios::boolalpha);
	string action[20][10] = {
		//       id    num    +     -     *     /         (     )      $
		/*0 s */{ "s5", "s6", "--", "s8", "--", "--",  "--",  "s4", "--",  "--" },
		/* 1 E */
	{ "--", "--", "s7", "s8", "--", "--",  "--",  "--","--", "acc" },
	/* 2 T */
	{ "--", "--", "r3", "r3", "s9", "s10", "s11", "--", "r3",  "r3" },
	/*3 F */
	{ "--", "--", "r6", "r6", "r6", "r6",  "r6",  "--", "r6",  "r6" },
	/*4 ( */
	{ "s5", "s6", "--", "s8", "--", "--",  "--",  "s4", "--",  "--" },
	/*5 id*/
	{ "--", "--", "r9", "r9", "r9", "r9",  "r9",  "--", "r9",  "r9" },
	/*6num*/
	{ "--", "--","r10","r10","r10","r10", "r10",  "--","r10", "r10" },
	/*7 + */
	{ "s5", "s6", "--", "--", "--", "--",  "--",  "s4", "--",  "--" },
	/*8 - */
	{ "s5", "s6", "--", "--", "--", "--",  "--",  "s4", "--",  "--" },
	/*9 * */
	{ "s5", "s6", "--", "--", "--", "--",  "--",  "s4", "--",  "--" },
	/* 10/ */
	{ "s5", "s6", "--", "--", "--", "--",  "--",  "s4", "--",  "--" },

	/*11 ^ */
	{ "s5", "s6", "--", "--", "--", "--",  "--",  "s4", "--",  "--" },

	/* 12  */
	{ "--", "--", "s7", "s8", "--", "--",  "--",  "--", "s16", "--" },
	/*13 + */
	{ "--", "--", "r1", "r1", "s9", "s10", "s11", "--", "r1",  "r1" },
	/*14 - */
	{ "--", "--", "r2", "r2", "s9", "s10", "s11", "--", "r2",  "r2" },
	/*15 * */
	{ "--", "--", "r4", "r4", "r4", "r4",  "r4",  "--", "r4",  "r4" },
	/* 16/ */
	{ "--", "--", "r5", "r5", "r5", "r5",  "r5",  "--", "r5",  "r5" },
	/*17 ) */
	{ "--", "--", "r8", "r8", "r8", "r8",  "r8",  "--", "r8",  "r8" },
	/* 18^ */
	{ "--", "--", "r4", "r4", "r4", "r4",  "r4",  "--", "r4",  "r4" },
	/*19E*/
	{ "--", "--", "r11", "r11", "r11","r11","r11","--", "r11","r11" },

	};
	int action_i[20][10] = {
		/* s */{ 5, 6, 0, 8, 0, 0,  0,  4, 0,  0 },
		/* E */
	{ 0, 0, 7, 8, 0, 0,  0,  0, 0,  0 },
	/* T */
	{ 0, 0, 3, 3, 9, 10, 11, 0, 3,  3 },
	/* F */
	{ 0, 0, 7, 7, 7, 7,  7,  0, 7,  7 },
	/* ( */
	{ 5, 6, 0, 8, 0, 0,  0,  4, 0,  0, },
	/* id*/
	{ 0, 0, 9, 9, 9, 9,  9,  0, 9,  9 },
	/*num*/
	{ 0, 0,10,10,10,10, 10,  0,10, 10 },
	/* + */
	{ 5, 6, 0, 0, 0, 0,  0,  4, 0,  0, },
	/* - */
	{ 5, 6, 0, 0, 0, 0,  0,  4, 0,  0, },
	/* * */
	{ 5, 6, 0, 0, 0, 0,  0,  4, 0,  0, },
	/* / */
	{ 5, 6, 0, 0, 0, 0,  0,  4, 0,  0, },

	/* ^ */
	{ 5, 6, 0, 0, 0, 0,  0,  4, 0,  0, },

	/*   */
	{ 0, 0, 7, 8, 0, 0,  0,  0, 17, 0 },

	/* + */
	{ 0, 0, 1, 1, 9, 10, 11, 0, 1,  1 },
	/* - */
	{ 0, 0, 2, 2, 9, 10, 11, 0, 2,  2 },
	/* * */
	{ 0, 0, 4, 4, 4, 4,  4,  0, 4,  4 },
	/* / */
	{ 0, 0, 5, 5, 5, 5,  5,  0, 5,  5 },
	/* ) */
	{ 0, 0, 8, 8, 8, 8,  8,  0, 8,  8 },

	/* ^ */
	{ 0, 0, 4, 4, 4, 4,  4,  0, 4,  4 },
	/*E*/
	{ 0, 0, 11,11,11,11, 11,  0,11, 11 },
	};
	int goto_t[20][3] = {
		/* s */{ 1,  2,  3 },
		/* E */
	{ 14,  2,  3 },
	/* T */
	{ 0,  0,  0 },
	/* F */
	{ 0,  0,  0 },
	/* ( */
	{ 12, 2,  3 },
	/* id*/
	{ 0,  0,  0 },
	/*num*/
	{ 0,  0,  0 },
	/* + */
	{ 0,  13, 3 },
	/* - */
	{ 19,  14, 3 },
	/* * */
	{ 0,  0,  15 },
	/* / */
	{ 0,  0,  16 },
	/* ^ */
	{ 0,  0,  18 },
	/*   */
	{ 19,  0,  0 },
	/* + */
	{ 0,  0,  0 },
	/* - */
	{ 0,  0,  0 },
	/* * */
	{ 0,  0,  0 },
	/* / */
	{ 0,  0,  0 },
	/* ) */
	{ 0,  0,  0 },

	/* ^ */
	{ 0,  0,  0 },
	/*E*/
	{ 0, 0, 0 },
	};
	vector<int> stack = { 0 };
	string input;
	//vector <string> rules = { "CB", "+CB", "-CB", "", "ED", "*ED", "/ED", "", "i", "n", "(A)", "^ED" };
	int rules[11] = { 3, 2, 1, 3, 3, 3, 1, 3, 1, 1, 2 },
		production[11] = { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2 };

	bool ans = true;
	getline(cin, input);
	input.push_back('$');
	//    cout << input << endl;

	while (1) {
		int i, j;
		while (input.front() == ' ')
			input.erase(0, 1);

		i = stack.back();
		switch (input.front()) {
		case 'i':
			j = 0;
			break;
		case 'n':
			j = 1;
			break;
		case '+':
			j = 2;
			break;
		case '-':
			j = 3;
			break;
		case '*':
			j = 4;
			break;
		case '/':
			j = 5;
			break;
		case '^':
			j = 6;
			break;
		case '(':
			j = 7;
			break;
		case ')':
			j = 8;
			break;
		case '$':
			j = 9;
			break;
		default:
			j = -1;
			break;
		}
		if (j == -1) {
			ans = false;
			break;
		}

		       cout << i << ' ' << j << endl;

		if (action[i][j].front() == 's') {
			stack.push_back(action_i[i][j]);
			if (input.front() == 'i')
				input.erase(0, 2);
			else if (input.front() == 'n')
				input.erase(0, 3);
			else
				input.erase(0, 1);
			cout << "action " << action_i[i][j] << endl;
		}
		else if (action[i][j].front() == 'r') {
			for (int k = 0; k < rules[action_i[i][j] - 1]; k++)
				stack.pop_back();
			for (auto k : stack) cout << k << ' ';
			cout << endl;
			stack.push_back(goto_t[stack.back()][production[action_i[i][j] - 1]]);
			cout << "goto " << goto_t[stack.back()][production[action_i[i][j] - 1]] << endl;
		}
		else if (action[i][j].front() == 'a') {
			break;
		}
		else {
			ans = false;
			break;
		}
		for (auto k : stack) cout << k << ' ';
		cout << input << endl << endl;
	}
	cout << ans << endl;
	system("pause");
	return 0;

}