#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m, num;
	string ln, pos;
	deque<string>StudDeq;
	vector<int> data;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ln >> pos;
		if (pos == "top") StudDeq.push_back(ln);
		else if (pos == "bottom ") StudDeq.push_front(ln);
		cout << StudDeq.front() << "\n";
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> num;
		data.push_back(num-1);
	}
	
	for (int i = 0; i < data.size(); ++i) {
		cout << "data " << i << "=" << data[i] << "\n";
		cout << StudDeq[data[i]] << "\n";
	}
}