#include <iostream>
#include <format>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = 1; i < a; i++) {
		cout << "   ";
	}
	for (int i = 1; i <= b; i++) {
		if (i<10) {
			cout << " " << i;
		} else cout << i;
		if ((i + a - 1) % 7 == 0) cout << "\n";
		else if (b == i)cout << "\n";
		else cout << " ";
	}
	cout << "\n";
}