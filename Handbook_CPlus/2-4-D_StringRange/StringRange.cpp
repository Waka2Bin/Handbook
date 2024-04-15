#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	ofstream out("output.txt");
	ifstream in("input.txt");
	
	vector<string>data;
	string s;
	bool trigger = true;
	for (int i = 0; i < 1000; ++i)
	{
		getline(in, s);
		for (auto i : s) {
			int j = i - 0;
			if (j < 32 || j > 126 || s.size() > 100 || s.size() == 0) {
				trigger = false;
				break;
			}
		}
		if (!trigger) break;
		data.push_back(s);
	}
	sort(data.rbegin(), data.rend());
	for (auto i : data) {
		out << i << endl;
	}
}