#include <queue>
#include <vector>
#include <string>
#include <fstream>

int main() {
	using namespace std;
	
	ifstream in("input.txt");
	ofstream out("output.txt");
	priority_queue<int>data;
	vector<string> answ;
	string command;

	while (getline(in, command)) {
		string val = command.substr(0, 3);
		
		if ("CLE" == val) {
			while (!data.empty())
				data.pop();
		}
		else if ("ADD" == val) {
			data.push(stoi(command.substr(3)));
		}
		else if ("EXT" == val) {
			if (!data.empty()) {
				answ.push_back(to_string(data.top()));
				data.pop();
			}
			else answ.push_back("CANNOT");
		}
	}

	for (auto f : answ) {
		out << f << "\n";
	}

	return 0;
}