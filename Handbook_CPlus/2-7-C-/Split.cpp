#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& str, char delimiter);

int main() {
	using namespace std;

	string dat = "What_is_your_name?";
	char sep = '_';
	vector <string> data = Split("What_is_your_name?", '_');
	for (auto i : data) {
		cout << i << "--";
	}
}

std::vector<std::string> Split(const std::string& str, char delimiter) {
	using namespace std;
	vector <string> answ;
	int len = str.length();
	string temp = "";
	for (int i = 0; i <= len;) {
		if ((str[i] == delimiter && int(temp.length())==0)|| str[i] == '\0') answ.push_back(temp);
		else if (str[i] != delimiter) temp += str[i];
		else {
			answ.push_back(temp);
			temp = "";
		}
		++i;
	}
	return answ;
}
