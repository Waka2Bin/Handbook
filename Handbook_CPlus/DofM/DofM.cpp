#include <iostream>
#include <map>

using namespace std;

int main() {
	int mnth,yr,t_yr;
	cin >> mnth >>yr;
	t_yr = 0;

	map<int, int> days{
		{1,31},{2,28},{3,31},{4,30},{5,31},
		{6,30},{7,31},{8,31},{9,30},{10,31},
		{11,30},{12,31},{13,29}
	};

	if (yr % 400 == 0) t_yr = 1;
	else if (yr % 100 == 0);
	else if (yr % 4 == 0) t_yr = 1;
	else;

	if (t_yr && 2 == mnth) {
		cout << days[13];
	} else cout << days[mnth];
}