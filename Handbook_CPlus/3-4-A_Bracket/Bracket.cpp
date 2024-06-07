/*
#include <iostream>
#include <string>
#include <map>

using namespace std;

string getCheckBracket(char& a, string& b) {
	map<char, char> lib{ {'(',')'}, {'{','}'}, {'[',']'} };
	char val = lib[a];
	int idx=0;
	bool trgr = false;
	int value = b.length();
	for (int i = 0; i < value;++i) {
		if (b[i] == val) {
			idx = i;
			trgr = true;
			break;
		}
	}
	if (trgr) {
		b.erase(idx, 1);
		b.erase(0,1);
	}
	else {
		return "NO";
	}
	return b;
}

int main() {
	string s;
	getline(cin, s);
	
	while (s != "NO") {
		char a = s[0];
		s = getCheckBracket(a, s);
		if (s.length() == 0) {
			cout << "YES";
			break;
		}
		else if (a == '}' || a == ']' || a == ')') {
			cout << "NO";
			break;
		}
		else if (s == "NO") {
			cout << "NO";
			break;
		}
	}
}
*/