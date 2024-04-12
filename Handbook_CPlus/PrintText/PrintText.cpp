#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string>data;
	data.push_back("C++ is a general-purpose programming language with a bias towards systems programming that");
	data.push_back("  - is a better C");
	data.push_back("  - supports data abstraction");
	data.push_back("  - supports object-oriented programming");
	data.push_back("  - supports generic programming.");

	for (auto i : data) {
		cout << i << endl;
	}
}