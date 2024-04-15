#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>data(n);
	for (int i = 0; i < int(data.size()); ++i) {
		int temp;
		cin >> temp;
		data[temp-1] = i;
	}
	for (auto i : data) {
		cout << i+1 << " ";
	}
}
