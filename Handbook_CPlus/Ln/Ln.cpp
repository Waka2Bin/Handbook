#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	double result=0;
	for (int i = 1; i <= n; i++) {
		double res = (pow((-1), (i + 1))) / i;
		result += res;
		cout << res << ";" << result << endl;
	}
	cout << result;
}