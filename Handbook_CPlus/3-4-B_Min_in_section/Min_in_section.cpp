#include <iostream>
#include <queue>
#include <vector>
#include <map>

void AddMinToVector(std::queue<int> &t,auto &a, auto& k, std::vector<int>& res,std::map<int,int>&max_val) {
	using namespace std;
	t.push(a); // add value to queue
	max_val[a] += 1; // add value to map

	if (t.size() >= k) { //change queue and map
		int val = t.front();
		if (t.size() > k) {
			t.pop(); // del first element
			if (max_val.contains(val)) {
				max_val[val] -= 1;
				if (max_val[val] <= 0) {
					max_val.erase(val);
				}
			}
		}
	}
	if (t.size() == k) {
		auto iter{ max_val.cbegin() };
		auto answ = iter->first;
		res.push_back(answ);
	}
}

int main() {
	int n, k, val;
	std::cin >> n >> k;
	std::queue<int> tmp;
	std::vector<int> answ;
	std::map<int, int>max;

	for (int i = 0; i < n ; ++i) {
		std::cin >> val;
		AddMinToVector(tmp,val,k,answ,max);
	}
	for (auto i : answ) {
		std::cout << i << "\n";
	}

	return 0;
}