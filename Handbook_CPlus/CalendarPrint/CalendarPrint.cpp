#include <iostream>
#include <format>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	for (int i = 1; i < a; i++) {
		cout << "   ";
	}
	for (int i = 1; i <= 32; i++) {
		cout << format("{:-2}", i) << " ";
		if ((i+a-1) % 7 == 0) cout << "\n";
	}
	cout << endl;
}