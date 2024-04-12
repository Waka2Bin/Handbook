#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x2 -= x1;
	y2 -= y1;
	if (x2 == 0 || y2 == 0 || abs(x2) == abs(y2)) {
		cout << "YES";
	}
	else cout << "NO";
}