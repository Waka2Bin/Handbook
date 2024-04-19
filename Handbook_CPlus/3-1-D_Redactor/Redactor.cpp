#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

using namespace std;

void Down(list<string>::iterator &val, const list<string> &dat);
void Up(list<string>::iterator& val, const list<string>& dat);
string CtrlX(const list<string>& s);
string CtrlV(const list<string>& s);

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s,bufer;
	list<string> data;
	vector<string> comands;
	while (!in.eof()) {
		getline(in, s);
		data.push_back(s);
		if (s == "Down" || s == "Up" || s == "CtrlX" || s == "CtrlV")) comands.push_back(s);
	}
	auto it = data.begin();





	for (auto& i : data) {
		out << i << "\n";
	}
}

void Down(list<string>::iterator& val, const list<string>& dat) {
	if (val != dat.cend()) ++val;
}
void Up(list<string>::iterator& val, const list<string>& dat) {
	if (val != dat.cbegin()) --val;
}
string CtrlX(const list<string>& s) {

}
string CtrlV(const list<string>& s) {

}