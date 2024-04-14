#include <iostream>

using namespace std;

struct st {
	string val;
	bool larg = false;
	bool small = false;
	bool num = false;
	bool other = false;
	bool ascii = true;
};

int main() {
	string s;
	st data;
	
	cin >> s;
	data.val = s;
	
	if (data.val.size() < 8 || data.val.size() > 14) {
		cout << "NO";
	}
	else {
		for (auto i : data.val) {
			int b = int(i);
			if (b > 32 && b < 127) {
				if (isdigit(i)) {
					data.num = true;
				}
				else if (isupper(i)) {
					data.larg = true;
				}
				else if (islower(i)) {
					data.small = true;
				}
				else if (ispunct(i)) {
					data.other = true;
				}
			}
			else {
				data.ascii = false;
			}
		}

		int answ = 0;
		if (data.larg) answ++;
		if (data.small) answ++;
		if (data.num) answ++;
		if (data.other) answ++;

		if (answ > 2 && data.ascii == true) {
			cout << "YES";
		}
		else cout << "NO";
	}
}