#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, num;
	string ln, pos;
	deque<string>StudDeq;
	vector<int> data;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ln >> pos;
		if (pos == "bottom") StudDeq.push_back(ln);
		else if (pos == "top") StudDeq.push_front(ln);
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		data.push_back(num-1);
	}
	
	for (int i = 0; i < int(data.size()); ++i) {
		cout << StudDeq[data[i]] << "\n";
	}
}