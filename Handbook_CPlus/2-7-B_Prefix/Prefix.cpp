#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string CommonPrefix(const std::vector<std::string>& words);

int main() {
	using namespace std;
	vector<string> word = {"application", "apple", "apricot"};
	string answ {CommonPrefix(word)};
	cout << answ;
}

std::string CommonPrefix(const std::vector<std::string>& words) {
	std::sort(words.begin(), words.end());
	std::string answ = words[0].substr(0, 1);
	std::string val = answ;
	for (int j = 1; j < int(words[0].length());++j) {
		for (auto i : words) {
			if (answ != i.substr(0, j)) return val;
		}
		val = answ;
		answ += words[0].substr(j, 1);
	}
	return answ;
}