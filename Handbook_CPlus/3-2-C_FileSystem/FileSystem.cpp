#include <string>
#include <set>
#include <fstream>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	string t;
	set<string> data;
	while (!in.eof()) {
		getline(in,t);
		int tf = t.size()-1;
		
		while (t != "") {
			while (t.back() != '/') {
				t.erase(tf, 1);
				tf = t.size() - 1;
			}
			if (!data.count(t)) data.insert(t);
			tf = t.size() - 1;
			t.erase(tf, 1);
		}
	}
	for (auto& i : data) {
		out << i << "\n";
	}
}