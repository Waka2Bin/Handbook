#include <string>
#include <vector>
#include <iostream>

std::string Join(const std::vector<std::string>& tokens, char delimiter);

int main() {
	using namespace std;
	vector<string> data = { "a", "a", "a", "" };
	cout << Join(data, '_');
}

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
	std::string answ = "";
	int n = 0;
	if (tokens.size() == 1) return tokens.front();
	else if (!tokens.empty()) {
		for (const auto& i : tokens) {
			answ += i;
			if (i == "");
			else if (n+1 < tokens.size()) answ += delimiter;
			n++;
		}
		return answ;
	}
	else return answ;
}