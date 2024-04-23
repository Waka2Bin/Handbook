#include <iostream>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int main() {
	ifstream in("C:/Users/tretyakovaa/Downloads/avidreaders.ru__master-i-margarita.fb2/avidreaders.ru__master-i-margarita.txt");
	ofstream out("output.txt");
	unordered_map <string, int> data;
	string temp;
	while (in >> temp) {
		++data[temp];
	}
	vector<pair<string, int>> results(data.begin(), data.end());
	sort(results.begin(), results.end(), [](const auto& a, const auto& a1) {return tie(a1.second, a.first) < std::tie(a.second, a1.first); });
	for (auto& i : results) {
		out << i.first << ": " << i.second << "\n";
	}
}