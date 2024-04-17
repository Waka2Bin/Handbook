#include <vector>
#include <string>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

int main() {
	using namespace std;
	vector<std::vector<int>> data;
	vector<std::vector<int>> res;
	res = Transpose(data);

}

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
	using namespace std;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<std::vector<int>> data(n, std::vector<int>(m));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			data[j][i] = matrix[i][j];
		}
	}
	return data;
}