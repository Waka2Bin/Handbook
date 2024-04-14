#include <iostream>
#include <string>
#include <map>

using namespace std;

string Soundex(string& val);

int main() {
	string s;
	cin >> s;
	cout<<Soundex(s);
}

string Soundex(string& val) {
	string temp = val;
	string answ;
	answ += temp[0];
	temp.erase(0, 1);
	map <string, int> repl
	{
		{"a",0},{"e",0},{"h",0},{"i",0},{"o",0},{"u",0},{"w",0},{"y",0},
		{"b",1},{"f",1},{"p",1},{"v",1},
		{"c",2},{"g",2},{"j",2},{"k",2},{"q",2},{"s",2},{"x",2},{"z",2},
		{"d",3},{"t",3},
		{"l",4},
		{"m",5},{"n",5},
		{"r",6}
	};
	for (size_t i = 0; i < temp.size();++i) {
		int agd = repl[temp.substr(i, 1)];
		temp.replace(i, 1, to_string(agd));
	}
	erase(temp, '0');
	for (size_t i = 0; i < temp.size(); ++i) {
		if (answ.back() != temp[i]) {
			answ.push_back(temp[i]);
		}
	}
	if (answ.size()>=4) {
		answ.resize(4);
	}
	while (answ.size() < 4) {
		answ.push_back('0');
	}
	return answ;
}