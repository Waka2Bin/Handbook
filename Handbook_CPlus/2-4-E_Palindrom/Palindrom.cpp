#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream out("output.txt");
	ifstream in("input.txt");
	bool trigger = true;
	string s;
	getline(in,s);
	erase(s,' ');
	for (int i = 0; i != int(s.length()); ++i) {
		if (s[i] == s[s.length() - 1 - i]) {
		}
		else {
			trigger = false;
			break;
		}
	}
	if (trigger) out << "YES";
	else out << "NO";
}