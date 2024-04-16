#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	//ifstream in("input.txt");
	//ofstream out("output.txt");

	int m, n, num;
	cin >> m >> n >> num;
	n+=2;
	m+=2;
	vector <vector<int>>data(m, vector<int>(n));
	for (int i = 0; i < num; i++) {
		int str, col;
		cin >> str >> col;
		data[str][col] = 9;
	}
	for (int i = 1; i+1 < m; i++) {
		for (int j = 1; j+1 < n; j++) {
			int cntr = 0;
			if (data[i][j] == 9) {}
			else {
				if (data[i + 1][j] == 9) cntr++;
				if (data[i + 1][j + 1] == 9) cntr++;
				if (data[i-1][j] == 9) cntr++;
				if (data[i-1][j-1] == 9) cntr++;
				if (data[i][j+1] == 9) cntr++;
				if (data[i][j-1] == 9) cntr++;
				if (data[i-1][j+1] == 9) cntr++;
				if (data[i + 1][j - 1] == 9) cntr++;
				data[i][j] = cntr;
			}
		}
	}
	for (int i = 1; i+1 < m; i++) {
		for (int j = 1; j+1 < n; j++) {
			if (data[i][j] == 9) cout << "*";
			else cout << data[i][j];
			if (j % (n - 2) == 0) cout << "\n";
			else cout << " ";
		}
	}
}