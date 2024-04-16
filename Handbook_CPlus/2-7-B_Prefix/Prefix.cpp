#include <iostream>
#include <vector>
#include <string>

std::string CommonPrefix(const std::vector<std::string>& words);

int main() {
	using namespace std;
	vector<string> word = { "","ssad","s" };
	string answ {CommonPrefix(word)};
	cout << answ;
}

std::string CommonPrefix(const std::vector<std::string>& words) {
	if (!words.empty()) {
		int temp = words[0].length();
		if (temp == 0) return "";
		std::string answ = words[0].substr(0, 1);
		std::string val = answ;
		int len = temp;
		int* point = &len;
		for (int j = 1; j < *point; ++j) {
			for (auto i : words) {
				temp = i.length();
				if (len > temp) len = temp;
				if (temp == 0) return "";
				if (answ != i.substr(0, j)) return val;
				if (int(answ.length()) == temp) return answ;
			}
			val = answ;
			answ += words[0].substr(j, 1);
		}
		return answ;
	}
	else return "";
}