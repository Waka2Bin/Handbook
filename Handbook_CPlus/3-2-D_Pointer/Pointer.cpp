#include <map>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int num,cnt = 0,tmp;
	in >> num;
	string s = "";
	map<int,set<string>>data;
	while (cnt < num) {
		in >> s>>tmp;
		data[tmp].insert(s);
		cnt++;
	}
	for (const auto& [val,d_set] : data) {
		out << val << " ";
		for (auto& j : d_set) {
			out << j << " ";
		}
		out << "\n";
	}
}