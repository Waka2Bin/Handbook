#include <iostream>

using namespace std;

int main() {
	int a, b, c, s_1, s_2, s_3;
	cin >> a >> b >> c;
	s_1 = min(a, b);
	s_2 = min(max(a, b), c);
	s_3 = max(max(a, b), c);
	if ((s_1 + s_2) <= s_3) cout << "UNDEFINED";
	else if (s_3 * s_3 == (s_1 * s_1 + s_2 * s_2)) cout << "YES";
	else cout << "NO";
}