#include <string>
#include <fstream>
#include <deque>
#include <sstream>

using namespace std;

struct Data {
	std::string op; std::string side; long long val;
};

void MakeTrain();

int main() {
	MakeTrain();
}

void MakeTrain() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	deque<long long>data;
	string s, t;
	while (!in.eof()) {
		getline(in, s);
		Data dt;
		dt.op = s[0];
		s.erase(0, 1);
		istringstream is(s);
		is >> dt.side >> dt.val;
		long long a = data.size();
		if (dt.op == "+") {
			if (dt.side == "right") data.push_back(dt.val);
			else data.push_front(dt.val);
		}
		else if (dt.op == "-") {
			if (dt.side == "right") {
				if (dt.val + 1 > a) data.resize(0);
				else {
					auto it = data.end();
					data.erase(it -= dt.val, data.end());
				}
			}
			else {
				if (dt.val + 1 > a) data.resize(0);
				else {
					auto it = data.begin();
					data.erase(data.begin(), it += dt.val);
				}
			}
		}
	}
	for (auto i : data) {
		if (i != data.back()) out << i << " ";
		else out << i << "\n";
	}
	out.close();
}