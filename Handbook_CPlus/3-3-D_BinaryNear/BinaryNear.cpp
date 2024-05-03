#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n, k,temp;
	cin >> n >> k;
	vector<int>data_n;
	vector<int>data_k;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		data_n.push_back(temp);
	}
	for (int i = 0; i < k; ++i) {
		cin >> temp;
		data_k.push_back(temp);
	}
	//ranges::sort(data_k);
	for (auto& i : data_k) {
		if (i > data_n.back()) cout << data_n.back() << "\n";
		else {
			auto it = lower_bound(data_n.begin(), data_n.end(), i);
			int val = *it;
			if (i != val && it != data_n.begin()) {
				--it;
				int val_prev = *it;
				if (val - i >= i - val_prev) cout << val_prev << "\n";
				else cout << val << "\n";
			}
			else cout << val << "\n";
		}
	}
}