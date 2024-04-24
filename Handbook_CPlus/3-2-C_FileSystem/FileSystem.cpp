#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	string t,val,key;
	int cntr = 0;
	map<string,map<string,int>> data;
	
	while (!in.eof()) {
		getline(in,t);
		for (auto& i : t) {
			if (i == '\n') break;
			++cntr;
			while (i!='/') {
				val += i;
			}
			if (cntr == 1 && data.count(val) && val != "") {
				key = val;
			}
			else if () {

			}
		}
		

	}
}