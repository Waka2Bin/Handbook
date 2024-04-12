#include <iostream>

using namespace std;

int main() {
	int yr;
	cin >> yr;
	if (yr % 400 ==0) cout << "YES";
	else if (yr % 100 == 0) cout << "NO";
	else if (yr % 4 == 0) cout << "YES";
	else cout << "NO";
}