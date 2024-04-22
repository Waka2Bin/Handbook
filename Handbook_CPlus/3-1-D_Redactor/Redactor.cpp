#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

using namespace std;

void Down(vector<string>::iterator& val, const vector<string> & data);
void Up(vector<string>::iterator& val, const vector<string>& data);
string CtrlX(vector<string>::iterator & val, vector<string>& data);
string CtrlV(vector<string>::iterator & val, vector<string>& data, string& str);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s = "";
	vector<string> data;
	vector<string> comands;
	while (!in.eof()) {
		getline(in, s);
		if (s == "Down" || s == "Up" || s == "Ctrl+X" || s == "Ctrl+V") comands.push_back(s);
		else if (!s.empty() && s!="") data.push_back(s);
	}
	s.clear();
	auto it = data.begin();
	for (auto& i : comands) {
		if (i == "Down") Down(it, data);
		else if (i == "Up") Up(it, data);
		else if (i == "Ctrl+X") s = CtrlX(it, data);
		else if (i == "Ctrl+V") s = CtrlV(it, data, s);
		else {}
	}
	for (auto& i : data) {
		out << i << "\n";
	}
}

void Down(vector<string>::iterator& val, const vector<string>& data) {
	if (val != data.end()) ++val;
}
void Up(vector<string>::iterator& val, const vector<string>& data) {
	if (val != data.begin()) --val;
}
string CtrlX(vector<string>::iterator& val, vector<string>& data) {
	string temp = *val;
	int it_t = distance(data.begin(), val);
	data.erase(val);
	val = data.begin() + it_t;
	return temp;
}
string CtrlV(vector<string>::iterator& val, vector<string>& data, string& str) {
	string temp = *val;
	int it_t = distance(data.begin(), val);
	data.insert(val, str);
	val = data.begin() + it_t+1;
	return temp;
}