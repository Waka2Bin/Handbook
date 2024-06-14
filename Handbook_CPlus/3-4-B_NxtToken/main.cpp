#include <iostream>
#include <string>
#include <string_view>
#include <fstream>

/*
bool NextToken(std::string_view& _sv, const char _delimiter, std::string_view& _token) {
    using namespace std;
    int idx = 1;
    if (!_sv.empty()) {
        for (auto i : _sv) {
            if (i == _delimiter || idx == _sv.length() ) {
                _token = _sv.substr(0,idx-1);
                _sv.remove_prefix(idx);
                return 1;
            }
            else ++idx;
        }
    }
    return 0;
}
*/

bool NextToken(std::string_view& sv, char delim, std::string_view& tok) {
    if (sv.empty()) {
        return false;
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
    return true;
}

int main() {
    //std::ofstream out("output.txt");
    
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }

	return 0;
}