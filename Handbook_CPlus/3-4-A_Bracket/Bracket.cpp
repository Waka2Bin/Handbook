#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		if (s[0] == '}' || s[0] == ']' || s[0] == ')') {
			cout << "NO";
			break;
		};

		char a = s[0];
		int j = 1;
		if (a == '{') {
			while (j < s.length()) {
				if (s[j] == '}') {
					s.erase(j, 1);
					s.erase(0);
					break;
				}
				j++;
			}
		}
		else if (a == '[') {
			while (j < s.length()) {
				if (s[j] == ']') {
					s.erase(j, 1);
					s.erase(0);
					break;
				}
				j++;
			}
		}
		else if (a == '(') {
			while (j < s.length()) {
				if (s[j] == ')') {
					s.erase(j, 1);
					s.erase(0);
					break;
				}
				j++;
			}
		}
	}

}