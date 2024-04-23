#include <map>
#include <iostream>

using namespace std;

int main() {
	map<int, int> data;
	int val;
	while (cin >> val) {
		if (data.contains(val)) cout << "YES" << "\n";
		else {
			cout << "NO" << "\n";
			++data[val];
		}
	}
}