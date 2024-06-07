#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	stack<char>tmp;
	bool flag = true;
	for (auto i : s) {
		if (i == '(' || i == '{' || i == '[') {
			tmp.push(i);
		}
		else if ((i == ')' || i == ']' || i == '}') && tmp.empty()) {
			flag = false;
			break;
		}
		else if ((i == ')' && '(' == tmp.top()) || (i == ']' && '[' == tmp.top()) || (i == '}' && '{' == tmp.top())) {
			tmp.pop();
		}
	}

	if (flag == false || !tmp.empty()) {
		cout << "NO";
	}
	else cout << "YES";
}