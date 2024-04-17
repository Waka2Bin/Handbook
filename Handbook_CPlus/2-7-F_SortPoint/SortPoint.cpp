#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	struct val {
		double a,b,dist;
	};
	int n;
	cin >> n;
	vector<val> data (n);
	for (int i = 0; i < n; ++i) {
		double x, y;
		cin >> x >> y;
		data[i].a = x;
		data[i].b = y;
		data[i].dist = sqrt(abs(x*y));
	}
	sort(data.begin(), data.end(), [](const val& lhs, const val& rhs) {
		return std::tie(lhs.dist) < std::tie(rhs.dist); });
	for (auto [a, b, dist] : data) {
		cout << a << " " << b << "\n";
	}
}