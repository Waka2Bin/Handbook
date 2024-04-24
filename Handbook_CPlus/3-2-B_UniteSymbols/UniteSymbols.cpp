#include <string>
#include <map>
#include <fstream>
#include <set>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	string temp,s;
	map<string,int>data;
	set<string>word;
	int counter=0;

	while (!in.eof()) {
		getline(in, temp);
		if (!temp.empty()) counter++;
		for (auto i : temp) {
			s+=i;
			if (!word.contains(s)) word.insert(s);
			s.clear();
		}
		if (counter!=1) {
			for (string i : word) {
				if (data.contains(i)) ++data[i];
			}
		}
		else {
			for (string i : word) ++data[i];
		}
		word.clear();
		temp = "";
	}
	for (auto& i : data) {
		if (i.second == counter) out << i.first;
	}
}