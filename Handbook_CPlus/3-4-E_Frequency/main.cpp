#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <tuple>

using namespace std;

bool NextToken(std::string_view& sv, char delim, std::string_view& tok) {
    if (sv.empty()) {
        return 0;
    }
    auto pos = sv.find(delim);
    if (pos != sv.npos) {
        tok = sv.substr(0, pos);
        sv.remove_prefix(pos + 1);
    }
    else {
        tok = sv;
        sv.remove_prefix(sv.size());
    }
    return 1;
}

int main(){
	int k = 0;
    string tmp;

    unordered_map<string, int>data;
	
    ifstream in("input.txt");
    bool b_idx = 1;
    while (getline(in, tmp)) {
        if (b_idx) {
            k = stoi(tmp);
            b_idx = 0;
        }
        else {
            string_view sv = tmp;
            const char delimiter = ' ';
            string_view token;
            while (NextToken(sv, delimiter, token)) {
                string tk_tmp = { token.begin(),token.end() };
                ++data[tk_tmp];
            }
        }
	}
    
    vector<pair<string, int>> data_word (data.begin(),data.end());

    sort(data_word.begin(), data_word.end(), [](const auto& p1, const auto& p2) {
        return tie(p2.second, p1.first) < tie(p1.second, p2.first); 
        }
    );

    int idx = 0;
    for (const auto& [word, num] : data_word) {
        if (idx == k) break;
        cout << word << "\t" << num << "\n";
        ++idx;
    };

	return 0;
}