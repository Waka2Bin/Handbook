#include <iostream>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);

int main() {
	using namespace std;

	int m, n, val;
	cin >> m >> n;
	vector<vector<int>> data(m,vector<int>(n));
	for (int i = 0; i < m;++i) {
		for (int j = 0; j < n; ++j) {
			cin >> val;
			data[i][j] = val;
		}
	}
	pair<int, int> answ = MatrixArgMax(data);
	cout<< answ.first<<" "<< answ.second;
}

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
	struct temp_data {
		int m = 0;
		int n = 0;
		int val= -2147483647;
	};
	temp_data a;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			int t_val = matrix[i][j];
			if (t_val > a.val) {
				a.val = t_val;
				a.m = i;
				a.n = j;
			}
		}
	}
	std::pair<int, int> temp(a.m,a.n);
	return temp;
}